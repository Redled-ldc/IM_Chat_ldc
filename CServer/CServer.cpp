
#include "CServer.h"
#include "HttpConnection.h"
#include "AsioIOServicePool.h"
CServer::CServer(net::io_context& ioc, unsigned short& port):
    ioc_(ioc),
    acceptor_(ioc, net::ip::tcp::endpoint(net::ip::tcp::v4(), port))
{

}

void CServer::Start()
{
    auto self=shared_from_this();
    auto& io_context = AsioIOServicePool::GetInstance()->GetIOService();
    std::shared_ptr<HttpConnection> new_con = std::make_shared<HttpConnection>(io_context);
    acceptor_.async_accept(new_con->GetSocket(), [self,new_con](const boost::system::error_code& ec)
        {
            try {
                if (ec) {
                    std::cerr << "Accept error: " << ec.message() << "\n";
                    return;
                }
                //创建新的Http连接，并用HttpConnection类管理连接
                new_con->Start();
				//继续接受新的连接
				self->Start();
            }
            catch (const std::exception& e) {
                std::cerr << "Exception: " << e.what() << "\n";
            }
        });

}
