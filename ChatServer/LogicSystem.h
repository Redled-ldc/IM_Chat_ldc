#pragma once
#include "Singleton.h"
#include <queue>
#include <thread>
#include "CSession.h"
#include <queue>
#include <map>
#include <functional>
#include "const.h"
#include <json/json.h>
#include <json/value.h>
#include <json/reader.h>
#include <unordered_map>
#include "data.h"

typedef  function<void(shared_ptr<CSession>, const short &msg_id, const string &msg_data)> FunCallBack;
class LogicSystem:public Singleton<LogicSystem>
{
	friend class Singleton<LogicSystem>;
public:
	~LogicSystem();
	void PostMsgToQue(shared_ptr < LogicNode> msg);
private:
	LogicSystem();
	// 消息处理线程
	void DealMsg();
	//注册回调函数
	void RegisterCallBacks();
	//登录
	void LoginHandler(shared_ptr<CSession> session, const short &msg_id, const string &msg_data);
	//注册
	void SearchInfo(std::shared_ptr<CSession> session, const short& msg_id, const string& msg_data);
	//添加好友
	void AddFriendApply(std::shared_ptr<CSession> session, const short& msg_id, const string& msg_data);
	// 同意好友申请
	void AuthFriendApply(std::shared_ptr<CSession> session, const short& msg_id, const string& msg_data);
	// 获取好友列表
	void DealChatTextMsg(std::shared_ptr<CSession> session, const short& msg_id, const string& msg_data);
	// 聊天消息
	bool isPureDigit(const std::string& str);
	// 根据uid获取用户信息
	void GetUserByUid(std::string uid_str, Json::Value& rtvalue);
	// 根据用户名获取用户信息
	void GetUserByName(std::string name, Json::Value& rtvalue);
	// 根据手机号获取用户信息
	bool GetBaseInfo(std::string base_key, int uid, std::shared_ptr<UserInfo> &userinfo);
	// 获取好友申请信息
	bool GetFriendApplyInfo(int to_uid, std::vector<std::shared_ptr<ApplyInfo>>& list);
	// 获取好友列表
	bool GetFriendList(int self_id, std::vector<std::shared_ptr<UserInfo>> & user_list);
	// 获取离线消息
	std::thread _worker_thread;
	// 消息队列
	std::queue<shared_ptr<LogicNode>> _msg_que;
	std::mutex _mutex;
	std::condition_variable _consume;
	bool _b_stop;
	// 回调函数映射表
	std::map<short, FunCallBack> _fun_callbacks;
};

