//
// Created by tavo on 17/3/22.
//

#ifndef MEMORY_GAME_SERVER_H
#define MEMORY_GAME_SERVER_H

#include <netinet/in.h>
#include <nlohmann/json.hpp>
#include "CommandHandler.h"

using namespace nlohmann;
using namespace std;

class Server {
public:
    void run(), connect();
    Server();
    static string J1;

private:
    int client, server, portNum = 5000, bufSize = 1024;
    bool isExit = false;
    char buff[1024];
    socklen_t size;
    struct sockaddr_in server_addr;
    void sender(char text[], int socket);
    CommandHandler* parser;

};


#endif //MEMORY_GAME_SERVER_H
