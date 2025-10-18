#pragma once
#include"const.h"
#include "LogicSystem.h"
class HttpConnection:public std::enable_shared_from_this<HttpConnection>
{
public:
	friend class LogicSystem;
	HttpConnection(boost::asio::io_context& ioc);
	void Start();
	tcp::socket& GetSocket() {
		return m_socket;
	}
private:
	void CheckDeadline();//check if the connection is dead
	void WriteResponse();//write response to client
	void HandleRequest();//handle the request from client
	tcp::socket m_socket;//socket of the connection
	void PreParseGetParam();//get参数预解析
	beast::flat_buffer m_buffer{ 8192 };//buffer to store the request
	http::request<http::dynamic_body> m_request;//request from client
	http::response<http::dynamic_body> m_response;//response to client
	net::steady_timer m_deadline_timer{
	m_socket.get_executor(), std::chrono::seconds(30)
	};//timer to check if the connection is dead,构造，初始化列表
	std::string _get_url;//url of the request
	std::unordered_map<std::string, std::string> _get_params;//get参数
};

