//
// Created by tavo on 11/4/22.
//

#include <iostream>
#include "../headers/PagedArray.h"

void PagedArray::allocateCards() {//Carga de tarjeta inicial a memoria
    int count = 0;
    while(count < 10){//carga 10 tarjetas random a memoria
        int iRandom = randomGenerator(0,5);
        int jRandom = randomGenerator(0,4);
        if(checkCard(iRandom, jRandom, "Memory") == 0){
            auto card = generateCard(getCard(iRandom, jRandom), iRandom, jRandom);
            memoryCards.push_back(card);
            size++;
            count++;
        }
    }
}

Card* PagedArray::generateCard(DiskMatrix::TarjetaDisk diskCard, int i, int j) {
    auto card = new Card();
    string position = to_string(i) + "," + to_string(j);
    card->status = diskCard.status;
    card->isInMemory = 1;
    card->pos = position;
    //byte array
    return card;
}

Card *PagedArray::getCardInMemory(int i, int j) {
    string place = to_string(i) + "," + to_string(j);
    for(int x=0; x<size; x++) {
        if (memoryCards[x]->pos == place) {
            return memoryCards[x];
        }
    }
}

PagedArray::PagedArray() {
    allocateCards();
}
