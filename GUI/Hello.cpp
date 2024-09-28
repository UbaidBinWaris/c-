#include <iostream>
#include <string>
#include <boost/asio.hpp>

using namespace boost::asio;
using ip::tcp;
using std::cout;
using std::endl;

// Function to handle HTTP requests
void handle_request(tcp::socket& socket) {
    // Define the HTTP response with HTML content
    std::string response = "HTTP/1.1 200 OK\r\n"
                           "Content-Type: text/html\r\n"
                           "\r\n"
                           "<!DOCTYPE html>\n"
                           "<html>\n"
                           "<head>\n"
                           "<title>Hello, World!</title>\n"
                           "</head>\n"
                           "<body>\n"
                           "<h1>Hello, World!</h1>\n"
                           "</body>\n"
                           "</html>\n";

    // Write the response to the socket
    boost::system::error_code ignored_error;
    write(socket, buffer(response), ignored_error);
}

int main() {
    // Create an io_context
    io_context io_context;

    // Create a TCP acceptor to listen for incoming connections on port 8080
    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 8080));

    // Accept and handle incoming connections
    while (true) {
        // Create a socket
        tcp::socket socket(io_context);

        // Accept a new connection
        acceptor.accept(socket);

        // Handle the request
        handle_request(socket);
    }

    return 0;
}
