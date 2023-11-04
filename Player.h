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

    Player(char piece) : piece(piece) {}

    vector<int> makeMove() {
        int playerNum = piece == 'X' ? 1 : 2;
        cout << "Player" << playerNum << endl << "Place (row, col):\n";
        int i, j;
        cin >> i >> j;
        return {i, j};
    }
};

#endif //TIC_TAC_TOE_PLAYER_H
