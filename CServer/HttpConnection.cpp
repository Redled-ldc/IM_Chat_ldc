#include "HttpConnection.h"
class LogicSystem;
HttpConnection::HttpConnection(boost::asio::io_context& ioc)
	: m_socket(std::move(ioc.get_executor()))
{

}
void HttpConnection::Start()
{
	auto self(shared_from_this());
	
	http::async_read(m_socket, m_buffer,m_request, [self](beast::error_code ec,std::size_t bytes_transferred) {
		try
		{
			if (ec)
			{
				std::cout << "http read erro is:" << ec.what() << std::endl;
				return;
			}
			boost::ignore_unused(bytes_transferred);
			self->HandleRequest();
			self->CheckDeadline();
		}
		catch (std::exception& exp)
		{
			std::cout << "exception is" << exp.what() << std::endl;
		}
	});

}
//10进制转16进制
unsigned char ToHex(unsigned char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	if (c >= 'a' && c <= 'f')
		return c - 'a' + 10;
	if (c >= 'A' && c <= 'F')
		return c - 'A' + 10;
	return 0;
}
//16进制转10进制
unsigned char FromHex(unsigned char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	if (c >= 'a' && c <= 'f')
		return c - 'a' + 10;
	if (c >= 'A' && c <= 'F')
		return c - 'A' + 10;
	return 0;
}	
//url编码
std::string UrlEncode(const std::string& str)
{
	std::string ret;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			ret += '+';
		}
		else if ((str[i] >= '0' && str[i] <= '9') ||
			(str[i] >= 'a' && str[i] <= 'z') ||
			(str[i] >= 'A' && str[i] <= 'Z') ||
			str[i] == '-' || str[i] == '_' ||
			str[i] == '.' || str[i] == '~')
		{
			ret += str[i];
		}
		else
		{
			ret += '%';
			ret += ToHex(str[i] >> 4);
			ret += ToHex(str[i] & 0x0F);
		}
	}
	return ret;
}
//url解析
std::string UrlDecode(const std::string& str)
{
	std::string ret;
	for (size_t i = 0; i < str.size(); i++)  
	{
		if (str[i] == '%')
		{
			if (i + 2 >= str.size())
				break;
			unsigned char high = ToHex(str[i + 1]);
			unsigned char low = ToHex(str[i + 2]);
			if (high == 0 || low == 0)
				break;
			ret += (high << 4) + low;
			i += 2;
		}
		else if (str[i] == '+')
		{
			ret +=' ';
		}
		else
		{
			ret += str[i];
		}
	}	
	return ret;
}
//解析get参数
void HttpConnection::PreParseGetParam() {
	// 提取 URI get_test?key1=value1&key2=value2
	auto uri = m_request.target();
	// 查找查询字符串的开始位置（即 '?' 的位置）  
	auto query_pos = uri.find('?');
	if (query_pos == std::string::npos) {
		_get_url = uri;
		return;
	}

	_get_url = uri.substr(0, query_pos);
	std::string query_string = uri.substr(query_pos + 1);
	std::string key;
	std::string value;
	size_t pos = 0;
	while ((pos = query_string.find('&')) != std::string::npos) {
		auto pair = query_string.substr(0, pos);
		size_t eq_pos = pair.find('=');
		if (eq_pos != std::string::npos) {
			key = UrlDecode(pair.substr(0, eq_pos)); // 假设有 url_decode 函数来处理URL解码  
			value = UrlDecode(pair.substr(eq_pos + 1));
			_get_params[key] = value;
		}
		query_string.erase(0, pos + 1);
	}
	// 处理最后一个参数对（如果没有 & 分隔符）  
	if (!query_string.empty()) {
		size_t eq_pos = query_string.find('=');
		if (eq_pos != std::string::npos) {
			key = UrlDecode(query_string.substr(0, eq_pos));
			value = UrlDecode(query_string.substr(eq_pos + 1));
			_get_params[key] = value;
		}
	}
}
void HttpConnection::HandleRequest()
{
	//设置版本
	m_response.version(m_request.version());
	m_response.keep_alive(false);
	
	//get
	if (m_request.method() == http::verb::get)
	{
		PreParseGetParam();
		bool success=LogicSystem::GetInstance()->HandleGet(_get_url, shared_from_this());
		if (!success)
		{
			m_response.result(http::status::not_found);
			m_response.set(http::field::content_type, "text/plain");
			beast::ostream(m_response.body()) << "url not found\r\n";
			WriteResponse();
			return;
		}
		m_response.result(http::status::ok);
		m_response.set(http::field::server, "GateServer");
		WriteResponse();
		return;
	}
	//post
	if (m_request.method() == http::verb::post)
	{
		// 新增：打印所有到达的请求（无论方法和 URL）
		std::cout << "服务器收到请求 - 方法: " << http::to_string(m_request.method())
			<< ", URL: " << m_request.target()
			<< ", 客户端: " << m_socket.remote_endpoint().address().to_string() << std::endl;
		bool success = LogicSystem::GetInstance()->HandlePost(m_request.target(), shared_from_this());
		if (!success)
		{
			m_response.result(http::status::not_found);
			m_response.set(http::field::content_type, "text/plain");
			beast::ostream(m_response.body()) << "url not found\r\n";
			WriteResponse();
			return;
		}
		m_response.result(http::status::ok);
		m_response.set(http::field::server, "GateServer");
		std::string response_body = boost::beast::buffers_to_string(m_response.body().data());
		std::cout << "服务器发送响应: " << response_body << std::endl;
		WriteResponse();
		return;
	}
	
}//handle the request from client
void HttpConnection::WriteResponse()
{
	auto self(shared_from_this());
	m_response.content_length(m_response.body().size());
	http::async_write(m_socket, m_response, [self](beast::error_code ec, std::size_t bytes_transferred) {
		self->m_socket.shutdown(tcp::socket::shutdown_send,ec);
		self->m_deadline_timer.cancel();
		});
}

void HttpConnection::CheckDeadline()
{
	auto self(shared_from_this());
	m_deadline_timer.async_wait([self](beast::error_code ec) {
		if (!ec){
			self->m_socket.close(ec);
		}

	});
}//check if the connection is dead