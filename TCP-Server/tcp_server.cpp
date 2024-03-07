#include <sys/socket.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>
#include <thread>
#include <unordered_map>

static std::unordered_map<std::string, int> exchanged_messages;
static const size_t MAX_BUFFER_SIZE = 10000; // Adjustable
static const std::string STATS_MESSAGE = "stats";

class TCPServer
{
public:
    TCPServer(int server_port)
        : server_port(server_port) { }

    void set_up()
    {
        sockaddr_in server;

        int server_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (server_socket == -1)
        {
            std::cerr << "Error - socket creation failed" << std::endl;
            return;
        } else
        {
            std::cout << "Server socket created successfully" << std::endl;
        }

        memset(&server, 0, sizeof(server));

        server.sin_family = AF_INET;
        server.sin_addr.s_addr = INADDR_ANY;
        server.sin_port = htons(server_port);

        int binding_status = bind(server_socket, reinterpret_cast<sockaddr*>(&server), sizeof(server));
        if (binding_status == -1)
        {
            std::cerr << "Error - socket binding failed" << std::endl;
            return;
        } else
        {
            std::cout << "Socket binded successfully" << std::endl;
        }

        int listening_status = listen(server_socket, SOMAXCONN);
        if (listening_status == -1)
        {
            std::cerr << "Error - server listening failed" << std::endl;
            return;
        } else
        {
            std::cout << "Server started listening on port " << server_port << std::endl;
        }

        while (true)
        {
            sockaddr_in client;
            socklen_t client_addr_len = sizeof(client);

            int new_socket = accept(server_socket, reinterpret_cast<sockaddr*>(&client), &client_addr_len);
            if (new_socket == -1)
            {
                std::cerr << "Error - accept failed" << std::endl;
                continue;
            }

            std::string client_address = inet_ntoa(client.sin_addr);
            std::cout << "Connection is established with client " << client_address << std::endl;

            std::thread client_thread(receive_message, new_socket, client_address);
            client_thread.detach();
        }
    }

    static void receive_message(int client_socket, std::string client_address)
    {
        char buffer[MAX_BUFFER_SIZE + 1];
        int bytes_received;

        while ((bytes_received = recv(client_socket, buffer, sizeof(buffer), 0)) > 0)
        {
            exchanged_messages[client_address]++;

            buffer[bytes_received] = '\0';
            std::string message(buffer);

            if (message == STATS_MESSAGE)
            {
                message = std::to_string(exchanged_messages.size()) + " Clients: [";
                for (const auto& client_data: exchanged_messages)
                {
                    message += client_data.first + ": " + std::to_string(client_data.second) + " messages sent, ";
                }
                message.erase(message.size() - 2, 2);
                message += "]\n";
            } else
            {
                // Process message; currently empty
            }

            send(client_socket, message.c_str(), message.size(), 0);
        }

        if (exchanged_messages.find(client_address) != exchanged_messages.end())
        {
            exchanged_messages.erase(client_address);
        }

        std::cout << "Connection wtih " << client_address << " ended" << std::endl;
    }

private:
    int server_port;
};

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <server_port>" << std::endl;
        return 1;
    }

    int server_port = std::stoi(argv[1]);
    TCPServer server(server_port);
    
    server.set_up();

    return 0;
}