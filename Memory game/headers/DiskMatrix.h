//
// Created by tavo on 9/4/22.
//

#ifndef MEMORY_GAME_DISKMATRIX_H
#define MEMORY_GAME_DISKMATRIX_H
#include <string>
#include "Card.h"

using namespace std;

/**
 * Instituto Tecnologico de Costa Rica
 * Area de Ingenieria en Computadores
 *
 * Lenguaje: C++.
 * Clase DiskMatrix.
 * @author Gustavo Alvarado Aburto.
 * @version 1.0.
 *
 * Descripcion: Esta clase se encarga de crear y modelar la matriz de tarjetas en disco, las tarjetas se almacenan en un archivo binario.
 */
class DiskMatrix {
public:
    /**
     * Modelo de tarjeta almacenada en el archivo binario, 12 bytes por tarjeta.
     */
    struct TarjetaDisk{
        int ID;
        int status; // 0=sinVoltear, 1=volteada
        int isInMemory; // 0=no, 1=si
    };
    DiskMatrix();
    void generateMatrix(), updateCardStatus(int i, int j, int option);
    int checkCard(int i, int j, string option);
    static int randomGenerator(int min, int max);
    int getCard(int i, int j, int option);

private:
    int cardSize = sizeof(TarjetaDisk);
    int pageSize = cardSize*5;
    int getCardStatus(TarjetaDisk tarjeta), getCardID(TarjetaDisk tarjeta), getCardisInMemory(TarjetaDisk tarjeta);
};


#endif //MEMORY_GAME_DISKMATRIX_H
