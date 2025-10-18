
#include "LogicSystem.h"
#include "VerifyGrpcClient.h"
#include "RedisMgr.h"
#include "MysqlMgr.h"
#include "StatusGrpcClient.h"
//#include <map>
void LogicSystem::RegGet(std::string url, HttpHandler handler){
	_get_handlers.insert(make_pair(url, handler));
}
void LogicSystem::RegPost(std::string url, HttpHandler handler) {
	_post_handlers.insert(make_pair(url, handler));
}
LogicSystem::LogicSystem() {
	RegGet("/get_test", [](std::shared_ptr<HttpConnection> connection) {
		beast::ostream(connection->m_response.body()) << "receive get_test req";
		int i = 0;
		for (auto& p : connection->_get_params) {
			i++;
			beast::ostream(connection->m_response.body()) << "param: " << i << "key: " << p.first;
			beast::ostream(connection->m_response.body()) << "param: " << i << "value: " << p.second << "\n";
		}
		connection->m_response.result(beast::http::status::ok);
		});

	RegPost("/get_varifycode", [](std::shared_ptr<HttpConnection>conn) {
		auto body_str = boost::beast::buffers_to_string(conn->m_request.body().data());
		std::cout << "revive body is" << body_str << std::endl;
		conn->m_response.set(http::field::content_type, "text/json");
		Json::Value root;
		Json::Reader reader;
		Json::Value src_root;
		bool parse_success = reader.parse(body_str, src_root);
		//如果body_str为空，或者解析失败，或者email不存在，则返回错误码
		if (body_str.empty()) {
			std::cout << "Received empty JSON data:" << std::endl;
			root["error"] = ErrorCodes::Error_json;
			std::string jsonstr = root.toStyledString();
			boost::beast::ostream(conn->m_response.body()) << jsonstr;
			return true;
		}
		if (!parse_success) {
			std::cout << "failed to parse Json data:" << std::endl;
			root["error"] = ErrorCodes::Error_json;
			std::string jsonstr = root.toStyledString();
			boost::beast::ostream(conn->m_response.body()) << jsonstr;
			return true;
		}
		if (!src_root.isMember("email")) {
			//key不存在
			std::cout << "failed to email Json data:" << std::endl;
			root["error"] = ErrorCodes::Error_json;
			std::string json_str = root.toStyledString();
			boost::beast::ostream(conn->m_response.body()) << json_str;
			return true;
		}
		else {
			//key存在

			auto email = src_root["email"].asString();

			GetVarifyRsp rsp = VerifyGrpcClient::GetInstance()->GetVarifyCode(email);

			std::cout << "email data is:" << email << std::endl;
			root["error"] = rsp.error();
			root["email"] = src_root["email"];
			std::string json_str = root.toStyledString();
			boost::beast::ostream(conn->m_response.body()) << json_str;
			return true;

		}});

		//注册用户
		RegPost("/user_register", [](std::shared_ptr<HttpConnection> conn) {
		//std::cout << "0" << std::endl;
		
		auto body_str = boost::beast::buffers_to_string(conn->m_request.body().data());
		std::cout << "收到 POST 请求: " << body_str << std::endl; // 输出请求路径
		std::cout << "revive body is" << body_str << std::endl;
		conn->m_response.set(http::field::content_type, "text/json");
		Json::Value root;
		Json::Reader reader;
		Json::Value src_root;
		bool parse_success = reader.parse(body_str, src_root);
		if (!parse_success) {
			std::cout << "failed to parse Json data:" << std::endl;
			root["error"] = ErrorCodes::Error_json;
			std::string jsonstr = root.toStyledString();
			beast::ostream(conn->m_response.body()) << jsonstr;
			return true;
		}
		
		auto email = src_root["email"].asString();
		auto user = src_root["user"].asString();
		auto pwd = src_root["passwd"].asString();
		auto confirm = src_root["confirm"].asString();
		if (pwd != confirm) {
			std::cout << "password err" << std::endl;
			root["error"] = ErrorCodes::PasswdErr;
			std::string jsonstr = root.toStyledString();
			beast::ostream(conn->m_response.body()) << jsonstr;
			return true;
		}

		//先查找redis中email对应的验证码是否合理    
		std::string varify_code;
		bool b_get_varify = RedisMgr::GetInstance()->Get(CODEPREFIX+src_root["email"].asString(), varify_code);
		if (!b_get_varify) {
			std::cout << " get varify code expired" << std::endl;
			root["error"] = ErrorCodes::VarifyExpired;
			std::string jsonstr = root.toStyledString();
			beast::ostream(conn->m_response.body()) << jsonstr;
			return true;
		}

		if (varify_code != src_root["varifycode"].asString()) {
			std::cout << " varify code error" << std::endl;
			root["error"] = ErrorCodes::VarifyCodeErr;
			std::string jsonstr = root.toStyledString();
			beast::ostream(conn->m_response.body()) << jsonstr;
			return true;
		}
		std::cout << "1" << std::endl;
		//查找数据库判断用户是否存在
		int uid = MysqlMgr::GetInstance()->RegUser(user, email, pwd);
		if (uid == 0 || uid == -1) {
			std::cout << " user or eamil exist in db" << std::endl;
			root["error"] = ErrorCodes::UserExist;
			std::string jsonstr = root.toStyledString();
			beast::ostream(conn->m_response.body()) << jsonstr;
			return true;
		}
		root["error"] = 0;
		root["email"] = src_root["email"];
		root["uid"] = uid;
		root["user"] = src_root["user"].asString();
		root["passwd"] = src_root["passwd"].asString();
		root["confirm"] = src_root["confirm"].asString();
		root["varifycode"] = src_root["varifycode"].asString();
		std::string jsonstr = root.toStyledString();
		beast::ostream(conn->m_response.body()) << jsonstr;
		std::cout << "3" << std::endl;
		return true;
		});

		//重置回调逻辑
		RegPost("/reset_pwd", [](std::shared_ptr<HttpConnection> connection) {
			auto body_str = boost::beast::buffers_to_string(connection->m_request.body().data());
			std::cout << "receive body is " << body_str << std::endl;
			connection->m_response.set(http::field::content_type, "text/json");
			Json::Value root;
			Json::Reader reader;
			Json::Value src_root;
			bool parse_success = reader.parse(body_str, src_root);
			if (!parse_success) {
				std::cout << "Failed to parse JSON data!" << std::endl;
				root["error"] = ErrorCodes::Error_json;
				std::string jsonstr = root.toStyledString();
				beast::ostream(connection->m_response.body()) << jsonstr;
				return true;
			}

			auto email = src_root["email"].asString();
			auto name = src_root["user"].asString();
			auto pwd = src_root["passwd"].asString();

			//先查找redis中email对应的验证码是否合理
			std::string  varify_code;
			bool b_get_varify = RedisMgr::GetInstance()->Get(CODEPREFIX + src_root["email"].asString(), varify_code);
			if (!b_get_varify) {
				std::cout << " get varify code expired" << std::endl;
				root["error"] = ErrorCodes::VarifyExpired;
				std::string jsonstr = root.toStyledString();
				beast::ostream(connection->m_response.body()) << jsonstr;
				return true;
			}

			if (varify_code != src_root["varifycode"].asString()) {
				std::cout << " varify code error" << std::endl;
				root["error"] = ErrorCodes::VarifyCodeErr;
				std::string jsonstr = root.toStyledString();
				beast::ostream(connection->m_response.body()) << jsonstr;
				return true;
			}
			//查询数据库判断用户名和邮箱是否匹配
			bool email_valid = MysqlMgr::GetInstance()->CheckEmail(name, email);
			if (!email_valid) {
				std::cout << " user email not match" << std::endl;
				root["error"] = ErrorCodes::EmailMotMatch;
				std::string jsonstr = root.toStyledString();
				beast::ostream(connection->m_response.body()) << jsonstr;
				return true;
			}

			//更新密码为最新密码
			bool b_up = MysqlMgr::GetInstance()->UpdatePwd(name, pwd);
			if (!b_up) {
				std::cout << " update pwd failed" << std::endl;
				root["error"] = ErrorCodes::PasswdUpFailed;
				std::string jsonstr = root.toStyledString();
				beast::ostream(connection->m_response.body()) << jsonstr;
				return true;
			}

			std::cout << "succeed to update password" << pwd << std::endl;
			root["error"] = 0;
			root["email"] = email;
			root["user"] = name;
			root["passwd"] = pwd;
			root["varifycode"] = src_root["varifycode"].asString();
			std::string jsonstr = root.toStyledString();
			beast::ostream(connection->m_response.body()) << jsonstr;
			return true;
			});
		//用户登录逻辑
		RegPost("/user_login", [](std::shared_ptr<HttpConnection> connection) {
			auto body_str = boost::beast::buffers_to_string(connection->m_request.body().data());
			std::cout << "receive body is " << body_str << std::endl;
			connection->m_response.set(http::field::content_type, "text/json");
			Json::Value root;
			Json::Reader reader;
			Json::Value src_root;
			bool parse_success = reader.parse(body_str, src_root);
			if (!parse_success) {
				std::cout << "Failed to parse JSON data!" << std::endl;
				root["error"] = ErrorCodes::Error_json;
				std::string jsonstr = root.toStyledString();
				beast::ostream(connection->m_response.body()) << jsonstr;
				return true;
			}

			auto email = src_root["email"].asString();
			auto pwd = src_root["passwd"].asString();
			UserInfo userInfo;
			//查询数据库判断用户名和密码是否匹配
			bool pwd_valid = MysqlMgr::GetInstance()->CheckPwd(email, pwd, userInfo);
			if (!pwd_valid) {
				std::cout << " user pwd not match" << std::endl;
				std::cout << pwd_valid << std::endl;
				root["error"] = ErrorCodes::PasswdInvalid;
				std::string jsonstr = root.toStyledString();
				beast::ostream(connection->m_response.body()) << jsonstr;
				return true;
			}

			//查询StatusServer找到合适的连接
			auto reply = StatusGrpcClient::GetInstance()->GetChatServer(userInfo.uid);
			if (reply.error()) {
				std::cout << " grpc get chat server failed, error is " << reply.error() << std::endl;
				root["error"] = ErrorCodes::RPCFailed;
				std::string jsonstr = root.toStyledString();
				beast::ostream(connection->m_response.body()) << jsonstr;
				return true;
			}

			std::cout << "succeed to load userinfo uid is " << userInfo.uid << std::endl;
			root["error"] = 0;
			root["email"] = email;
			root["uid"] = userInfo.uid;
			root["token"] = reply.token();
			root["host"] = reply.host();
			root["port"] = reply.port();
			std::string jsonstr = root.toStyledString();
			beast::ostream(connection->m_response.body()) << jsonstr;
			return true;
			});

}

bool LogicSystem::HandleGet(std::string path, std::shared_ptr<HttpConnection> conn){
	if (_get_handlers.find(path) == _get_handlers.end()){
		return false;
	}
	_get_handlers[path](conn);
	return true;
}
bool LogicSystem::HandlePost(std::string path, std::shared_ptr<HttpConnection> conn) {
	if (_post_handlers.find(path) == _post_handlers.end()) {
		return false;
	}
	_post_handlers[path](conn);
	return true;
}