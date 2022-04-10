//
// Created by tavo on 9/4/22.
// 6 paginas, 5 tarjetas por pagina
//
#include <fstream>
#include <iostream>
#include <random>
#include "headers/DiskMatrix.h"

using namespace std;

struct TarjetaDisk{
    int ID;
    int status;
};

void DiskMatrix::generateMatrix() {
    random_device engine;
    mt19937 mt(engine());
    uniform_int_distribution<int> generator(1, 10);
    int pairsID[15];
    ofstream file("BinaryMatrix.dat", ios::out | ios::binary);
    if(!file) {
        cout << "Error creating the file" << endl;
        exit(1);
    }

    for(int i=0; i<15; i++){//genera mitad de tarjetas aleatorias
        TarjetaDisk card;
        card.ID = generator(mt);
        card.status = 0;
        file.write((char*)&card, sizeof(TarjetaDisk));
        pairsID[i] = card.ID;
    }

    for(int j=0; j<15; j++){//genera parejas para mitad de tarjetas
        TarjetaDisk cardTemp;
        cardTemp.ID = pairsID[j];
        cardTemp.status = 0;
        file.write((char*)&cardTemp, sizeof(TarjetaDisk));
    }
    file.close();
}

void DiskMatrix::checkMatrix(){
    TarjetaDisk temp;
    TarjetaDisk temp2;
    ifstream file("BinaryMatrix.dat", ios::in | ios::binary);
    if(!file){
        cout << "No se pudo abrir el archivo" << endl;
        //exit(1);
    }
    file.read((char*)&temp, sizeof(TarjetaDisk));
    file.seekg(sizeof(TarjetaDisk)*15);
    file.read((char*)&temp2, sizeof(TarjetaDisk));

    cout << "ID of first card: " << temp.ID << endl;
    cout << "ID of second card: " << temp2.ID << endl;

    file.close();
}

DiskMatrix::DiskMatrix() {
    generateMatrix();

}

