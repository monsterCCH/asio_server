#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using namespace std;
using boost::asio::ip::tcp;

#define PORT 514

class async_server {
public:
    async_server(boost::asio::io_service& io,tcp::endpoint& ep):ios(io),acceptor(io,ep) {
        start();
    }

    void start() {
        sock_ptr sock(new tcp::socket(ios));
        acceptor.async_accept(*sock, boost::bind(&async_server::accept_handler, this, placeholders::error, sock));
    }

private:
    boost::asio::io_service &ios;
    tcp::acceptor acceptor;
    typedef boost::shared_ptr<tcp::socket> sock_ptr;

    void accept_handler(const boost::system::error_code &ec, sock_ptr sock) {
        if (ec)
            return;
        std::cout <<"remote ip:"<<sock->remote_endpoint().address()<<endl;
        std::cout <<"remote port:"<<sock->remote_endpoint().port() << std::endl;
    }

};

int main() {
    try {
        boost::asio::io_service tcp_io_service;
        tcp::socket t_tcp_sock(tcp_io_service, tcp::endpoint(tcp::v6(), PORT));

        for (;;) {

        }


    }catch (exception& e) {
        cout << e.what() << endl;
    }


    return 0;
}
