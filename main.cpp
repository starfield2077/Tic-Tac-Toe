#include <iostream>
#include <vector>

using namespace std;

bool canPlacePiece(int i, int j, vector<vector<char>> &board) {
    return i >=0 && i< 3 && j>=0 && j< 3 && board[i][j] == '-';
}

void makeMove(vector<vector<char>> &board, char c) {
    int p = c == 'X' ? 1 : 2;
    cout << "Player" << p << endl << "Place (row, col):\n";
    int i, j;
    cin >> i >> j;
    while (!canPlacePiece(i, j, board)) {
        cout << "Please make another move!" << endl;
        cin >> i >> j;
    }
    board[i][j] = c;
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

string victory(const vector<vector<char>> &board) {
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

bool canContinue(const vector<vector<char>> &board) {
    return !isFull(board) && victory(board).empty();
}

void display(const vector<vector<char>> &board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main() {
    std::cout << "___________.__         ___________               ___________            \n"
                 "\\__    ___/|__| ____   \\__    ___/____    ____   \\__    ___/___   ____  \n"
                 "  |    |   |  |/ ___\\    |    |  \\__  \\ _/ ___\\    |    | /  _ \\_/ __ \\ \n"
                 "  |    |   |  \\  \\___    |    |   / __ \\\\  \\___    |    |(  <_> )  ___/ \n"
                 "  |____|   |__|\\___  >   |____|  (____  /\\___  >   |____| \\____/ \\___  >\n"
                 "                   \\/                 \\/     \\/                      \\/" <<
              std::endl;
    vector<vector<char>> board(3, vector<char>(3, '-'));
    display(board);
    char c = 'X';
    while (canContinue(board)) {
        makeMove(board, c);
        c = c == 'X' ? 'O' : 'X';
        display(board);
    }
    string winner = victory(board);
    if (winner.empty()) {
        cout << "Draw" << endl;
    } else {
        cout << winner << endl;
    }

    return 0;
}
