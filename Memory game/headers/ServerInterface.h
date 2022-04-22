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
    void setCardsInMemory(string pos);
    void updateCards(string pos);

private:
    RenderWindow window;
    Text player1, player2, tarjetas;
    vector<Text> texts;
    Font font;
    Text name1, name2;
    void createText();
    int X = 10, Y = 150, count = 0;
};


#endif //MEMORY_GAME_SERVERINTERFACE_H
