//
// Created by tavo on 9/4/22.
//

#include "headers/Game.h"

Game::Game() {
    server.run();
    server.connect();
}
