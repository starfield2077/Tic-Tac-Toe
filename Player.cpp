#include "Player.h"

Player::Player(char piece) : piece(piece) {}

vector<int> Player::makeMove() {
    int playerNum = piece == 'X' ? 1 : 2;
    cout << "Player" << playerNum << endl << "Place (row, col):\n";
    int i, j;
    cin >> i >> j;
    return {i, j};
}
