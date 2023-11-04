#ifndef TIC_TAC_TOE_GAME_H
#define TIC_TAC_TOE_GAME_H

#include <vector>
#include <string>
#include <iostream>
#include "Board.h"
#include "Player.h"

using namespace std;

class Game {
public:
    Board board;
    Player *player1 = nullptr, *player2 = nullptr;
    Player *currentPlayer = nullptr;

    Game(Player player1, Player player2);

    bool canPlacePiece(int i, int j);

    void play();
};

#endif //TIC_TAC_TOE_GAME_H
