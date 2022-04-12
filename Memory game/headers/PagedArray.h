//
// Created by tavo on 11/4/22.
//

#ifndef MEMORY_GAME_PAGEDARRAY_H
#define MEMORY_GAME_PAGEDARRAY_H


#include "Card.h"
#include "DiskMatrix.h"
#include <vector>

using namespace std;

class PagedArray : public DiskMatrix {
public:
    void operator()(int i, int j){
        getCard(i, j);
    }
    Card* getCardInMemory(int i, int j);
    PagedArray();

private:
    int size;
    vector<Card*> memoryCards;
    void allocateCards();
    Card* generateCard(TarjetaDisk diskCard, int i, int j);
};


#endif //MEMORY_GAME_PAGEDARRAY_H
