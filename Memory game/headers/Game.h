//
// Created by tavo on 9/4/22.
//

#ifndef MEMORY_GAME_GAME_H
#define MEMORY_GAME_GAME_H

#include "DiskMatrix.h"
#include "Server.h"
#include "ServerInterface.h"
/**
 * Instituto Tecnologico de Costa Rica
 * Area de Ingenieria en Computadores
 *
 * Lenguaje: C++.
 * Clase Game.
 * @author Gustavo Alvarado Aburto.
 * @version 1.0.
 *
 * Descripcion: Esta clase se encarga de inicalizar todos los componente necesarios para el juego.
 */
class Game {
public:
    Game();

private:
    Server* server = new Server();
    ServerInterface* window = new ServerInterface();
};


#endif //MEMORY_GAME_GAME_H
