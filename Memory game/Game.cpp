//
// Created by tavo on 9/4/22.
//

#include <thread>
#include "headers/Game.h"
#include "headers/PagedArray.h"

/**
 * Constructor, se encarga de lanzar todos los componentes necesarios para la ejecucion del juego.
 */
Game::Game() {
    window->launchWindow();
    sf::Thread graphics(&ServerInterface::threadRender, window); //hilo que renderiza constantemente la ventana del servidor
    graphics.launch();
    server->run(window);
    thread thread(&Server::connect, server); //hilo atento a peticiones del cliente.
    while(true){
        //
    }
}
