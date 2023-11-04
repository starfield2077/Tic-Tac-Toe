#ifndef TIC_TAC_TOE_PLAYER_H
#define TIC_TAC_TOE_PLAYER_H

#include <vector>
#include <string>
#include <iostream>
#include "Board.h"

using namespace std;

class Player {
public:
    char piece;

    Player(char piece);

    vector<int> makeMove();
};

#endif //TIC_TAC_TOE_PLAYER_H
