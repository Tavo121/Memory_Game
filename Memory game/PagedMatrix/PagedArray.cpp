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
            positionsInMemory.push_back(to_string(iRandom) + "," + to_string(jRandom));
            count++;
            cout << "Tarjeta random cargada: " << iRandom << jRandom << endl;
        }
    }
    size = memoryCards.size();
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
    //byte array
    return card;
}
/**
 * Este metodo se encarga de habilitar 1 espacio en el vector para cargar una tarjeta nueva.
 * Mediante otro metodos se realiza el guardado de la tarjeta liberada del vector a disco.
 */
void PagedArray::saveCardToDisk(){
    Card* temp = memoryCards[size-1];
    vector<int> data;
    //descomponiendo string pos
    vector<string> tokens;
    stringstream stream(temp->pos);
    string intermediate;
    while(getline(stream, intermediate, ',')){
        tokens.push_back(intermediate);
    }
    int i = stoi(tokens[0]);
    int j = stoi(tokens[1]);
    binarMatrix.updateCardStatus(i, j, generateData(temp));
    free(memoryCards[size-1]);
}

void PagedArray::loadCard(int i, int j) {
    Card* temp = generateCard(i, j);
    memoryCards[size-1] = temp;
}
/**
 * Este metodo crea una tarjeta temporal con lo datos de la tarjeta en memoria para actualizarlos en disco.
 * @param card tarjeta en memoria con datos a actualizar.
 * @return tarjeta temporal lista para ser actualizada en disco
 */
DiskMatrix::TarjetaDisk PagedArray::generateData(Card *card) {
    DiskMatrix::TarjetaDisk tarjeta;
    tarjeta.ID = card->ID;
    tarjeta.status = card->status;
    tarjeta.isInMemory = card->isInMemory;
    cout << tarjeta.ID << endl;
    return tarjeta;
}

/**
 * Este metodo se encarga retornar el ID de la tarjeta solicitada. Dependiendo de la tarjeta se realiza la paginacion.
 * @param i fila de la tarjeta buscada.
 * @param j columna de la tarjeta buscada.
 * @return retorna el ID de la tarjeta solicitada.
 */
int PagedArray::getCardInMemory(int i, int j) {
    string place = to_string(i) + "," + to_string(j);
    if(searchCardInMemory(place)){
        for(int i=0; i<memoryCards.size(); i++){
            if(memoryCards[i]->pos == place){
                memoryCards[i]->status = 1; // volteada
                return memoryCards[i]->ID;
            }
        }
    }else{ //paginacion
        cout << "paginacion" << endl;
        saveCardToDisk(); //descarga a disco de tarjeta
        loadCard(i, j); //carga de tarjeta a memoria
        interfaceInstance->updateCards(place);
        memoryCards[size-1]->status = 1;
        return memoryCards[size-1]->ID;
    }
}

/**
 * Este metodo se encarga de buscar la tarjeta en memoria.
 * @param pos posicion de la tarjeta.
 * @return true si la tarjeta se encuentra en memoria, caso contrario retorna false.
 */
bool PagedArray::searchCardInMemory(string pos){
    for(int i=0; i<memoryCards.size(); i++){
        if(memoryCards[i]->pos == pos){
            return true;
        }
    }
    return false;
}

PagedArray::PagedArray() {
    allocateCards();
}
