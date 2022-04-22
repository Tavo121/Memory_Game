//
// Created by tavo on 9/4/22.
// 6 paginas, 5 tarjetas por pagina
//
#include <fstream>
#include <iostream>
#include <random>
#include "../headers/DiskMatrix.h"

using namespace std;

/**
 * Este metodo genera la matriz en un archivo binario que se almacena en disco, las tarjetas se generan con IDs aleatorios.
 */
void DiskMatrix::generateMatrix() {
    int pairsID[15]; //lista de IDs de la mitad de tarjetas para generar parejas.
    ofstream file("BinaryMatrix.dat", ios::out | ios::binary);
    if(!file) {
        cout << "Error creating the file" << endl;
        exit(1);
    }

    for(int i=0; i<15; i++){//genera mitad de tarjetas aleatorias
        TarjetaDisk card;
        card.ID = randomGenerator(1, 10); //ID aleatorio de 1 a 10
        card.status = 0;
        card.isInMemory = 0;
        file.write((char*)&card, sizeof(TarjetaDisk));
        pairsID[i] = card.ID; //guardado de ID para generar parejas
        cout << i << " " << card.ID << endl;
    }

    for(int j=0; j<15; j++){//genera parejas para mitad de tarjetas
        TarjetaDisk cardTemp;
        cardTemp.ID = pairsID[j];
        cardTemp.status = 0;
        cardTemp.isInMemory = 0;
        file.write((char*)&cardTemp, sizeof(TarjetaDisk));
        cout << j + 15 << " " << cardTemp.ID << endl;
    }
    file.close();
}

/**
 * Este metodo se encarga de verificar si una carta esta en memoria o si esta volteada.
 * @param i fila de la tarjeta.
 * @param j columna de la tarjeta.
 * @param option opcion para verificar si esta en memoria o su estado.
 * @return estado en memoria de la tarjeta o estado de volteo, segun el parametro option.
 */
int DiskMatrix::checkCard(int i, int j, string option) {//verifica si una carta esta en memoria o su estado
    TarjetaDisk temp;
    ifstream file("BinaryMatrix.dat", ios::in | ios::binary);
    if(!file){
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    file.seekg(i*pageSize+j*cardSize); //se posiciona el pntero en el archivo justo donde esta la tarjeta solicitada.
    file.read((char*)&temp, sizeof(TarjetaDisk));
    file.close();
    if(option == "Memory"){ //verifica estado en memoria
        return temp.isInMemory;

    }else if(option == "Status"){ //verifica estado de volteo
        return temp.status;

    }else if (option == "ID"){
        return temp.ID;
    }
    return 0;
}

/**
 * Este metodo se encarga de actualizar el estado de las tarjetas en disco.
 * @param i fila de la tarjeta.
 * @param j columna de la tarjeta.
 * @param option opcion para actualizar el estado de la tarjeta
 */
void DiskMatrix::updateCardStatus(int i, int j, int option) {
    TarjetaDisk data;
    ifstream read("BinaryMatrix.dat", ios::in | ios::binary);
    if(!read){
        cout << "Error opening the file" << endl;
        exit(1);
    }
    read.seekg(i*pageSize+j*cardSize); //se posiciona el puntero en el archivo justo en la tarjeta buscada.
    read.read((char*)&data, cardSize);
    read.close();

    switch (option) {
        case 0:
            //No en memoria
            data.isInMemory = 0;
        case 1:
            //En memoria
            data.isInMemory = 1;
        case 2:
            //No volteada
            data.status = 0;
        case 3:
            //Volteada
            data.status = 1;
    }
    cout << data.ID << data.status << data.isInMemory << endl;
    ofstream file;
    file.open("BinaryMatrix.dat", ios::out | ios::binary);
    if(!file){
        cout << "Error opening the file" << endl;
        exit(1);
    }
    file.seekp(i*pageSize+j*cardSize);
    file.write((char*)&data, cardSize);
    file.close();
}

int DiskMatrix::randomGenerator(int min, int max) { //generador random en el intervalo min-max
    random_device engine;
    mt19937 mt(engine());
    uniform_int_distribution<int> generator(min, max);
    return generator(mt);
}

/**
 * Este metodo se encarga de buscar la tarjeta en disco y retornarla
 * @param i fila de la tarjeta.
 * @param j columna de la tarjeta.
 * @param option opcion para obtener ID, estado o si la tarjeta se encuentra en memoria.
 * @return tarjeta buscada en la matriz binaria.
 */
int DiskMatrix::getCard(int i, int j, int option) {//busca y retorna la tarjeta en la posicion especificada
    TarjetaDisk tempCard;
    ifstream file("BinaryMatrix.dat", ios::in | ios::binary);
    if(!file){
        cout << "Error opening the file" << endl;
        exit(1);
    }
    file.seekg(i*pageSize+j*cardSize); //se posiciona el puntero en el archivo justo en la tarjeta buscada.
    file.read((char*)&tempCard, cardSize);
    file.close();
    switch(option){
        case 0:
            return getCardID(tempCard);
        case 1:
            return getCardStatus(tempCard);
        case 2:
            return getCardisInMemory(tempCard);
    }
}

int DiskMatrix::getCardStatus(TarjetaDisk tarjeta){
    return tarjeta.status;
}
int DiskMatrix::getCardID(TarjetaDisk tarjeta){
    return tarjeta.ID;
}
int DiskMatrix::getCardisInMemory(TarjetaDisk tarjeta){
    return tarjeta.isInMemory;
}

DiskMatrix::DiskMatrix() { //constructor, genera la matriz.
    generateMatrix();
}
