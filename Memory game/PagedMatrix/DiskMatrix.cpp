//
// Created by tavo on 9/4/22.
// 6 paginas, 5 tarjetas por pagina
//
#include <fstream>
#include <iostream>
#include <random>
#include "../headers/DiskMatrix.h"

using namespace std;

void DiskMatrix::generateMatrix() {//genera la matriz en disco de manera aleatoria
    int pairsID[15];
    ofstream file("BinaryMatrix.dat", ios::out | ios::binary);
    if(!file) {
        cout << "Error creating the file" << endl;
        exit(1);
    }

    for(int i=0; i<15; i++){//genera mitad de tarjetas aleatorias
        TarjetaDisk card;
        card.ID = randomGenerator(0, 10);
        card.status = 0;
        card.isInMemory = 0;
        file.write((char*)&card, sizeof(TarjetaDisk));
        pairsID[i] = card.ID;
    }

    for(int j=0; j<15; j++){//genera parejas para mitad de tarjetas
        TarjetaDisk cardTemp;
        cardTemp.ID = pairsID[j];
        cardTemp.status = 0;
        cardTemp.isInMemory = 0;
        file.write((char*)&cardTemp, sizeof(TarjetaDisk));
    }
    file.close();
}

int DiskMatrix::checkCard(int i, int j, string option) {//verifica si una carta esta en memoria o su estado
    TarjetaDisk temp;
    ifstream file("BinaryMatrix.dat", ios::in | ios::binary);
    if(!file){
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    file.seekg(i*pageSize+j*cardSize);
    file.read((char*)&temp, sizeof(TarjetaDisk));
    file.close();
    if(option == "Memory"){
        return temp.isInMemory;

    }else if(option == "Status"){
        return temp.status;
    }
    return 0;
}

void DiskMatrix::updateCardStatus(int i, int j) {
    ofstream file("BinaryMatrix.dat", ios::out | ios::binary);
    TarjetaDisk card;
    card.status = 1;
    if(!file){
        cout << "Error opening the file" << endl;
        exit(1);
    }
    file.seekp(i*pageSize+j*cardSize);
    file.write((char*)&card, cardSize);
    file.close();
}

int DiskMatrix::randomGenerator(int min, int max) {
    random_device engine;
    mt19937 mt(engine());
    uniform_int_distribution<int> generator(min, max);
    return generator(mt);
}

DiskMatrix::TarjetaDisk DiskMatrix::getCard(int i, int j) {//busca y retorna la tarjeta en la posicion especificada
    TarjetaDisk tempCard;
    ifstream file("BinaryMatrix.dat", ios::in | ios::binary);
    if(!file){
        cout << "Error opening the file" << endl;
        exit(1);
    }
    file.seekg(i*pageSize+j*cardSize);
    file.read((char*)&tempCard, cardSize);
    file.close();
    return tempCard;
}

DiskMatrix::DiskMatrix() {
    generateMatrix();
}
