//
// Created by tavo on 9/4/22.
//

#ifndef MEMORY_GAME_DISKMATRIX_H
#define MEMORY_GAME_DISKMATRIX_H
#include <string>

using namespace std;

class DiskMatrix {
public:
    struct TarjetaDisk{
        int ID;
        int status; //0=sinVoltear, 1=volteada
        int isInMemory; // 0=no, 1=si
    };
    DiskMatrix();
    void generateMatrix(), updateCardStatus(int i, int j);
    int checkCard(int i, int j, string option);
    static int randomGenerator(int min, int max);
    TarjetaDisk getCard(int i, int j);

private:
    int cardSize = sizeof(TarjetaDisk);
    int pageSize = cardSize*5;
};


#endif //MEMORY_GAME_DISKMATRIX_H
