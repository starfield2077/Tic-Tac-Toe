#ifndef TIC_TAC_TOE_BOARD_H
#define TIC_TAC_TOE_BOARD_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Board {
public:
    vector<vector<char>> board;

    Board();

    Board(vector<vector<char>> board);

    string victory() ;

    string inARow(const vector<char> &line);

    bool isFull();

    bool canContinue();

    void display();
};

#endif //TIC_TAC_TOE_BOARD_H
