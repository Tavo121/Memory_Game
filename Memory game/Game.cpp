//
// Created by tavo on 9/4/22.
//

#include <thread>
#include "headers/Game.h"
#include "headers/PagedArray.h"

Game::Game() {
    server->run();
    thread thread(&Server::connect, server);
    PagedArray pagedArray;
    while(true){
        //
    }
}
