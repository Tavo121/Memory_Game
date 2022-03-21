//
// Created by tavo on 17/3/22.
//

#include <cstring>
#include <unistd.h>
#include "Server.h"
#include "iostream"
using namespace std;

void Server::sender(char text[], int socket){
    int textLenght = strlen(text) + 1;
    send(socket, text, textLenght, 0);
}

void Server::connect(int server){
    cout << "Server started" << endl;
    while(server > 0){
        sender("Server connected...\n", server);

        int bytesRecieved = recv(server, buff, bufSize, 0);
        cout << "Client: " + string(buff, 0, bytesRecieved) << endl;

        if(string(buff, 0, bytesRecieved) == "Exit"){
            close(client);
            break;
        }
        //memset(buff, 0, 1024);
    }
}

void Server::run(){
    client = socket(AF_INET, SOCK_STREAM, 0);

    if (client < 0){
        cout << "Error connection" << endl;
        exit(1);
    }

    cout << "Server socket connection created " << endl;

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(portNum);

    if(bind(client, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        cout << "Error biding socket" << endl;
        exit(1);
    }

    size = sizeof(server_addr);
    cout << "Looking for clients" << endl;

    listen(client, 1);

    server = accept(client, (struct sockaddr*)&server_addr, &size);
    connect(server);
}
