//
// Created by tavo on 19/04/22.
//

#ifndef MEMORY_GAME_SERVERINTERFACE_H
#define MEMORY_GAME_SERVERINTERFACE_H

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class ServerInterface {
public:
    void launchWindow();
    void setPlayerNames(string P1, string P2);
    void threadRender();

private:
    RenderWindow window;
    Text player1, player2;
    Font font;
    Text name1, name2;
    void createText();
};


#endif //MEMORY_GAME_SERVERINTERFACE_H
