//
// Created by tavo on 9/4/22.
//

#ifndef MEMORY_GAME_GAME_H
#define MEMORY_GAME_GAME_H

#include "DiskMatrix.h"
#include "Server.h"

class Game {
public:
    Game();

private:
    Server server;
    DiskMatrix diskMatrix;
};


#endif //MEMORY_GAME_GAME_H
