#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>

using namespace std;
using namespace boost::asio;
#define PORT 13014

int main(int argc, char** argv) {
    try {
        boost::system::error_code ec;
        io_service service;
        ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), PORT);
        ip::tcp::socket sock(service);
        sock.connect(ep,ec);

        for(;;)
        {
            boost::array<char, 128> buf;

            sock.write_some(buffer("connected!"), ec);
            size_t len = sock.read_some(boost::asio::buffer(buf), ec);
            if (ec == boost::asio::error::eof)
            {
                //break;
            }
            else if (ec)
            {
                throw boost::system::system_error(ec);
            }
            cout.write(buf.data(), len);
            //sleep(1);
        }
    } catch (exception& e) {
        cout << e.what() << endl;
    }

}