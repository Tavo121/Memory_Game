//
// Created by tavo on 17/3/22.
//

#ifndef MEMORY_GAME_SERVER_H
#define MEMORY_GAME_SERVER_H

#include <netinet/in.h>

class Server {
public:
    void run();

private:
    int client, server;
    int portNum = 5000;
    bool isExit = false;
    int bufSize = 1024;
    char buff[1024];
    socklen_t size;
    struct sockaddr_in server_addr;
    void connect(int server), sender(char text[], int socket);

};


#endif //MEMORY_GAME_SERVER_H
