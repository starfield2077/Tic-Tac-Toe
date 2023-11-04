#ifndef TIC_TAC_TOE_BOARD_H
#define TIC_TAC_TOE_BOARD_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Board {
public:
    vector<vector<char>> board;

    Board() {

    }

    Board(vector<vector<char>> board) {
        this->board = board;
    }

    string victory() {
        string winner;
        for (int i = 0; i < 3; ++i) {
            winner = inARow(board[i]);
            if (!winner.empty()) {
                return winner;
            }
        }
        for (int j = 0; j < 3; ++j) {
            winner = inARow({board[0][j], board[1][j], board[2][j]});
            if (!winner.empty()) {
                return winner;
            }
        }
        winner = inARow({board[0][0], board[1][1], board[2][2]});
        if (!winner.empty()) {
            return winner;
        }
        winner = inARow({board[0][2], board[1][1], board[2][0]});
        if (!winner.empty()) {
            return winner;
        }
        return "";
    }

    string inARow(const vector<char> &line) {
        if (line[0] == line[1] && line[1] == line[2]) {
            if (line[0] == 'X') {
                return "Player 1 Wins";
            } else if (line[0] == 'O') {
                return "Player 2 Wins";
            }
        }

        return "";
    }

    bool isFull() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == '-') {
                    return false;
                }
            }
        }
        return true;
    }

    bool canContinue() {
        return !isFull() && victory().empty();
    }

    void display() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << board[i][j] << "\t";
            }
            cout << "\n";
        }
    }
};

#endif //TIC_TAC_TOE_BOARD_H
