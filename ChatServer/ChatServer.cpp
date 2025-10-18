// ChatServer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "CServer.h"
#include "ConfigMgr.h"
#include "AsioIOServicePool.h"
#include "LogicSystem.h"
#include <csignal>
#include <iostream>
#include <thread>
#include <mutex>
#include "boost/asio.hpp"
std::condition_variable cond_quit;
std::mutex mutex_quit;
int main()
{
    try {
        auto& cfg = ConfigMgr::Inst();
        auto pool = AsioIOServicePool::GetInstance();
        boost::asio::io_context  io_context;
        boost::asio::signal_set signals(io_context, SIGINT, SIGTERM);
		//捕捉退出信号，异步处理
        signals.async_wait([&io_context, pool](auto, auto) {
            io_context.stop();
            pool->Stop();
            });
        auto port_str = cfg["SelfServer"]["Port"];
        CServer s(io_context, atoi(port_str.c_str()));
        io_context.run();
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;

    }
        return 0;
}


