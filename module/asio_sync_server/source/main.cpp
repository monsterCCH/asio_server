#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/array.hpp>
#include <iostream>

using namespace std;
using namespace boost::asio;
#define PORT 13014
typedef boost::shared_ptr<ip::tcp::socket> socket_ptr;
char data[512];

void client_session(socket_ptr sock, boost::system::error_code& ec) {
    while (true) {
        size_t len = sock->read_some(buffer(data));
        if (ec == boost::asio::error::eof)
        {
            break;
        }
        else if (ec)
        {
            throw boost::system::system_error(ec);
        }
    }
}

int main(int argc, char** argv) {

    io_service service;
    ip::tcp::endpoint ep(ip::tcp::v4(), PORT);
    ip::tcp::acceptor acc(service, ep);
    boost::system::error_code ec;
    boost::array<char, 128> buf{};
    while (true) {
        socket_ptr sock(new ip::tcp::socket(service));
        acc.accept(*sock);
        std::cout << sock->remote_endpoint().address() << std::endl;
        sock->write_some(buffer("hello world!"), ec);
        if (ec) {
            std::cout << boost::system::system_error(ec).what() << std::endl;
        }

        size_t len = sock->read_some(boost::asio::buffer(buf), ec);
        cout.write(buf.data(), len);
        if (ec == boost::asio::error::eof)
        {
            //break;
        }
        else if (ec)
        {
            throw boost::system::system_error(ec);
        }

        //boost::thread(boost::bind(client_session, sock, ec));
        sleep(1);
    }

}
