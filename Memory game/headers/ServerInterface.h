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
    void launchWindow(), setPlayerNames(string P1, string P2), threadRender(), setCardsInMemory(string pos),
        updateCards(string pos), setPageFaults(), updatePageFault(), setPageHits(), updatePageHit();

private:
    RenderWindow window;
    Text player1, player2, tarjetas, name1, name2, pageFault, pageFaultCount, pageHit, pageHitCount;
    vector<Text> texts;
    Font font;
    void createText();
    int X = 10, Y = 150, count = 0, faultCount = 0, hitCount = 0;
};


#endif //MEMORY_GAME_SERVERINTERFACE_H
