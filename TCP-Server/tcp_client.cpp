#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

static const size_t MAX_BUFFER_SIZE = 10000; // Adjustable

class TCPClient
{
public:
    void set_up(int server_port)
    {
        int client_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (client_socket == -1)
        {
            std::cerr << "Error - socket creation failed" << std::endl;
            return;
        } else
        {
            std::cout << "Client socket created successfully" << std::endl;
        }
        
        sockaddr_in server_address;
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(server_port);

        int address = inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);  
        if (address <= 0)
        {
            std::cerr << "Error - invalid address detected" << std::endl;
            return;
        }

        int conenction_status = connect(client_socket, reinterpret_cast<sockaddr*>(&server_address), sizeof(server_address));
        if (conenction_status == -1)
        {
            std::cerr << "Error - connection to server failed" << std::endl;
            return;
        } else
        {
            std::cout << "Connection to server is successful" << std::endl;
        }

        while (true)
        {
            std::string message;

            std::cout << "\nEnter a message to send: ";
            std::getline(std::cin, message);

            send(client_socket, message.c_str(), message.size() + 1, 0);

            char buffer[MAX_BUFFER_SIZE + 1];
            int bytes_received = read(client_socket, buffer, MAX_BUFFER_SIZE);

            buffer[bytes_received] = '\0';
            std::cout << "Received: \n" << buffer << std::endl;
        }
    }
};

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Use " << argv[0] << " <server_port>" << std::endl;
        return 1;
    }

    TCPClient client;
    int server_port = std::stoi(argv[1]);
    
    client.set_up(server_port);

    return 0;
}