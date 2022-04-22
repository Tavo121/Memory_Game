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

/**
 * Instituto Tecnologico de Costa Rica
 * Area de Ingenieria en Computadores
 *
 * Lenguaje: C++.
 * Clase Server.
 * @author Gustavo Alvarado Aburto.
 * @version 1.0.
 *
 * Descripcion: Esta clase se encarga de realizar la conexion entre el cliente y servidor, asi como mantenerse atento a las peticiones
 * del cliente.
 */
class Server {
public:
    void run(ServerInterface* instance), connect();
    static void sender(string response, int socket);
    Server();

private:
    int client, server, portNum = 5000, bufSize = 1024;
    char buff[1024];
    socklen_t size;
    struct sockaddr_in server_addr;
    CommandHandler* parser;
};


#endif //MEMORY_GAME_SERVER_H
