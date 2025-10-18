#pragma once
#include <boost/beast/http.hpp>
#include <boost/beast.hpp>
#include <boost/asio.hpp>
#include <memory>
#include "Singleton.h"
#include <functional>
#include <map>
#include <iostream>
#include <unordered_map>
#include "queue"
//#include "atomic"

#include <json/json.h>
#include <json/value.h>
#include <json/reader.h>
#include <boost/filesystem.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <hiredis/hiredis.h>
#include <cassert>
namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>
enum ErrorCodes {
	Success=0,
	Error_json=1001,
	RPCFailed=1002,
	VarifyExpired=1003,//验证码过期
	VarifyCodeErr=1004,//验证码错误
	UserExist=1005,		//用户不存在
	PasswdErr=1006,		//密码错误
	EmailMotMatch=1007,	//邮箱不匹配
	PasswdUpFailed=1008,//更新密码失败
	PasswdInvalid=1009,	//密码更新失败
};
#define CODEPREFIX "code_"

class Defer {
public:
	Defer(std::function<void()> func) : _func(func) {}
	~Defer() {
		if (_func) {
			_func();
		}
	}
private:	
	std::function<void()> _func;
};

//class ConfigMgr;
//extern ConfigMgr gCfgMgr;