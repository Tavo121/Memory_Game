//
// Created by tavo on 19/04/22.
//

#include "../headers/ServerInterface.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

void ServerInterface::createText() {
    if(!font.loadFromFile("/home/tavo/Descargas/arial/arial.ttf")){
        cout << "Error loading the file" << endl;
    }
    player1.setFont(font);
    player1.setString("Jugador 1");
    player1.setCharacterSize(20);
    player1.setFillColor(Color::White);
    player1.setPosition(0,5);

    player2.setFont(font);
    player2.setString("Jugador 2");
    player2.setCharacterSize(20);
    player2.setFillColor(Color::White);
    player2.setPosition(player1.getGlobalBounds().width+20, 5);

    tarjetas.setFont(font);
    tarjetas.setCharacterSize(25);
    tarjetas.setFillColor(Color::White);
    tarjetas.setString("Tarjetas en memoria:");
    tarjetas.setPosition(10, 100);
    texts.push_back(tarjetas);
}

void ServerInterface::setPlayerNames(string P1, string P2) {
    name1.setFont(font);
    name1.setString(P1);
    name1.setCharacterSize(20);
    name1.setFillColor(Color::White);
    name1.setPosition(0,30);

    name2.setFont(font);
    name2.setString(P2);
    name2.setCharacterSize(20);
    name2.setFillColor(Color::White);
    name2.setPosition(100,30);
}

void ServerInterface::setCardsInMemory(string pos) {
    string name = "Tarjeta: " + pos;
    Text tarjeta;
    tarjeta.setFont(font);
    tarjeta.setString(name);
    tarjeta.setCharacterSize(20);
    tarjeta.setFillColor(Color::White);
    if(count == 3){
        count = 0;
        X = 10;
        Y = Y + tarjeta.getGlobalBounds().height + 20;

        cout << count << endl;
    }
    tarjeta.setPosition(X,Y);
    texts.push_back(tarjeta);
    X = X + tarjeta.getGlobalBounds().width + 15;
    count++;

}

void ServerInterface::launchWindow() {
    window.create(VideoMode(500, 800), "Server Interface");
    createText();
}

void ServerInterface::threadRender() {
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case Event::Closed:
                    window.close();
            }
        }
        window.clear();
        window.draw(player1);
        window.draw(player2);
        window.draw(name1);
        window.draw(name2);
        for(int i=0; i<texts.size(); i++)
            window.draw(texts[i]);
        window.display();
    }
}
