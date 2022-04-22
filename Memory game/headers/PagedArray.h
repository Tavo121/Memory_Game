//
// Created by tavo on 11/4/22.
//

#ifndef MEMORY_GAME_PAGEDARRAY_H
#define MEMORY_GAME_PAGEDARRAY_H


#include "Card.h"
#include "DiskMatrix.h"
#include "ServerInterface.h"
#include <vector>

using namespace std;

/**
 * Instituto Tecnologico de Costa Rica
 * Area de Ingenieria en Computadores
 *
 * Lenguaje: C++.
 * Clase PagedArray, hereda DiskMatrix.
 * @author Gustavo Alvarado Aburto.
 * @version 1.0.
 *
 * Descripcion: Esta clase se encarga de la paginacion, carga y descarga de tarjetas en memoria.
 */
class PagedArray {
public:
    int operator()(int i, int j){
        return getCardInMemory(i, j);
    }
    int getCardInMemory(int i, int j);
    vector<string> positionsInMemory;
    PagedArray();

private:
    int size, TESTi, TESTj;
    vector<Card*> memoryCards;
    void allocateCards(), saveCardToDisk(), loadCard(int i, int j);
    Card* generateCard(int i, int j);
    DiskMatrix binarMatrix;
};


#endif //MEMORY_GAME_PAGEDARRAY_H
