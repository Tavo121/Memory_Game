//
// Created by tavo on 11/4/22.
//

#include <iostream>
#include <bits/stdc++.h>
#include "../headers/PagedArray.h"

/**
 * Este metodo se encarga realizar la carga inical de tarjetas a memoria, carga la tercera parte de las tarjetas totales.
 */
void PagedArray::allocateCards() {//Carga de tarjeta inicial a memoria
    int count = 0;
    while(count < 10){//carga 10 tarjetas random a memoria
        int iRandom = binarMatrix.randomGenerator(0,5);
        int jRandom = binarMatrix.randomGenerator(0,4);
        if(binarMatrix.checkCard(iRandom, jRandom, "Memory") == 0){
            auto card = generateCard(iRandom, jRandom);
            memoryCards.push_back(card);
            size++;
            count++;
            TESTi = iRandom;
            TESTj = jRandom;
            positionsInMemory.push_back(to_string(iRandom) + "," + to_string(jRandom));
            cout << "Tarjeta random cargada: " << iRandom << jRandom << endl;
        }
    }
}

/**
 * Este metodo se encarga de crear las tarjetas que se van a cargar a memoria.
 * @param diskCard contiene informacion de la tarjeta en disco.
 * @param i fila de la tarjeta.
 * @param j columna de la tarjeta.
 * @return tarjeta creada y lista para ser cargada a memoria.
 */
Card* PagedArray::generateCard(int i, int j) {
    Card* card = new Card();
    string position = to_string(i) + "," + to_string(j);
    int cardID = binarMatrix.getCard(i, j, 0);
    int Status = binarMatrix.getCard(i, j, 1);
    card->status = Status;
    card->isInMemory = 1;
    card->pos = position;
    card->ID = cardID;
    binarMatrix.updateCardStatus(i, j, card);
    //byte array
    return card;
}

void PagedArray::saveCardToDisk(){
    Card* temp = memoryCards[size-1];
    vector<string> tokens;
    stringstream stream(temp->pos);
    string intermediate;
    while(getline(stream, intermediate, ',')){
        tokens.push_back(intermediate);
    }
    int i = stoi(tokens[0]);
    int j = stoi(tokens[1]);
    binarMatrix.updateCardStatus(i, j, temp);
    free(memoryCards[size-1]);
}

void PagedArray::loadCard(int i, int j) {
    Card* temp = generateCard(i, j);
    memoryCards[size-1] = temp;
}

/**
 * Este metodo se encarga de buscar el vector paginado la tarjeta solicitada.
 * @param i fila de la tarjeta buscada.
 * @param j columna de la tarjeta buscada.
 * @return retorna la tarjeta solicitada.
 */
int PagedArray::getCardInMemory(int i, int j) {
    string place = to_string(i) + "," + to_string(j);
    cout << binarMatrix.checkCard(TESTi,TESTj,"ID") << endl;
/*    if(binarMatrix.checkCard(i, j, "Memory") == 0) {//paginacion

        cout << "Paginacion" << endl;
        saveCardToDisk();
        loadCard(i, j);
        return memoryCards[size - 1]->ID;

    }else if(binarMatrix.checkCard(i, j, "Memory") == 1){
        cout << "En memoria" << endl;
        for(int x=0; x<size; x++) {
            if (memoryCards[x]->pos == place) {
                cout << memoryCards[x]->ID << endl;
                return memoryCards[x]->ID;
            }
        }
    }*/
}

PagedArray::PagedArray() {
    allocateCards();
}
