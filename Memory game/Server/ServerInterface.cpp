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

void ServerInterface::setPageFaults() {
    pageFault.setFont(font);
    pageFault.setCharacterSize(25);
    pageFault.setFillColor(Color::Yellow);
    pageFault.setString("Page Faults:");
    pageFault.setPosition(10, 500);

    pageFaultCount.setFont(font);
    pageFaultCount.setString(to_string(faultCount));
    pageFaultCount.setCharacterSize(20);
    pageFaultCount.setPosition(pageFault.getGlobalBounds().width + 20, 500);
}

void ServerInterface::setPageHits() {
    pageHit.setFont(font);
    pageHit.setCharacterSize(25);
    pageHit.setFillColor(Color::Red);
    pageHit.setString("Page Hits:");
    pageHit.setPosition(10, pageFault.getGlobalBounds().height + 530);

    pageHitCount.setFont(font);
    pageHitCount.setString(to_string(hitCount));
    pageHitCount.setCharacterSize(20);
    pageHitCount.setPosition(pageHit.getGlobalBounds().width + 20, pageFault.getGlobalBounds().height + 530);
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
    }
    tarjeta.setPosition(X,Y);
    texts.push_back(tarjeta);
    X = X + tarjeta.getGlobalBounds().width + 15;
    count++;

}

void ServerInterface::updateCards(string pos) {
    texts.pop_back();
    Text tarjeta;
    string name = "Tarjeta: " + pos;
    tarjeta.setFont(font);
    tarjeta.setString(name);
    tarjeta.setCharacterSize(20);
    tarjeta.setFillColor(Color::White);
    tarjeta.setPosition(X, Y);
    texts.push_back(tarjeta);
}

void ServerInterface::updatePageFault(){
    faultCount++;
    pageFaultCount.setString(to_string(faultCount));
}

void ServerInterface::updatePageHit(){
    hitCount++;
    pageHitCount.setString(to_string(hitCount));
}

void ServerInterface::launchWindow() {
    window.create(VideoMode(500, 800), "Server Interface");
    createText();
    setPageFaults();
    setPageHits();
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
        window.draw(pageFault);
        window.draw(pageHit);
        window.draw(pageFaultCount);
        window.draw(pageHitCount);
        window.display();
    }
}
