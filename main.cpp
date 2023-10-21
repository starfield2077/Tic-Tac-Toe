#include <iostream>
#include <vector>

using namespace std;

void makeMove(int i, int j, vector<vector<char>> &board, char c) {
    board[i][j] = c;
}

string victory(const vector<vector<char>> &board) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'X') {
                return "Player 1";
            } else if (board[i][0] == 'O') {
                return "Player 2";
            } else {
                return "";
            }
        }
    }
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == board[1][j] && board[2][j] == board[2][j]){
            if (board[0][j] == 'X') {
                return "Player 1 Win";
            } else if (board[0][j] == 'O') {
                return "Player 2 Win";
            } else {
                return "";
            }
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'X') {
            return "Player 1 Win";
        } else if (board[0][0] == 'O') {
            return "Player 2 Win";
        } else {
            return "";
        }
    }
    return "";
}

bool isFull(const vector<vector<char>> &board) {
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

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<vector<char>> board(3, vector<char>(3, '-'));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << "\t";
        }
        cout << "\n";
    }


    return 0;
}

