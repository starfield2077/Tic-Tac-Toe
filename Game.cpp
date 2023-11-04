#include "Game.h"

Game::Game(Player player1, Player player2) {
    this->board = Board(vector<vector<char>>(3, vector<char>(3, '-')));
    this->player1 = &player1;
    this->player2 = &player2;
    this->currentPlayer = this->player1;
}

bool Game::canPlacePiece(int i, int j) {
    return i >= 0 && i < 3 && j >= 0 && j < 3 && board.board[i][j] == '-';
}

void Game::play() {
    board.display();
    while (board.canContinue()) {
        vector<int> move;
        move = currentPlayer->makeMove();
        while (!canPlacePiece(move[0], move[1])) {
            cout << "Please make another move!" << endl;
            move = currentPlayer->makeMove();
        }
        board.board[move[0]][move[1]] = currentPlayer->piece;
        currentPlayer = currentPlayer == player1 ? player2 : player1;
        board.display();
    }
    string winner = board.victory();
    if (winner.empty()) {
        cout << "Draw" << endl;
    } else {
        cout << winner << endl;
    }
}