#include <bits/stdc++.h>
using namespace std;

int totalWays = 0;

bool possible(int y, int x, vector<string>& board) {
    // Horizontal
    for (int i = 0; i < x; i++) {
        if (board[y][i] == 'Q') {
            return false;
        }
    }

    // Up left diagonal
    int row = y;
    int col = x; 
    while (row >= 0 && col >=0) {
        if (board[row][col] == 'Q') {
            return false;
        }
        row--;
        col--;
    }

    // Down left diagonal
    row = y;
    col = x;
    while (row < 8 && col >= 0){
        if (board[row][col] == 'Q') {
            return false;
        }
        row++;
        col--;
    }

    return true;
}

void backtrack(int y, int x, vector<string>& board, int queenCount) {
    if (queenCount >= 8) {
        totalWays++;
        return ;
    }
    for (int i =0 ; i < 8; i++) {
        char tmp = board[i][x];
        if (board[i][x] == '.' && possible(i, x, board)) {
            board[i][x] = 'Q';
            backtrack(y, x + 1, board, queenCount + 1);
        }
        board[i][x] = tmp;
    }

}

int main() {
    vector<string> board;
    for (int i =0 ; i < 8; i++) {
        string row;
        cin >> row ;
        board.emplace_back(row);
    }
    backtrack(0, 0, board, 0);
    cout << totalWays;
}