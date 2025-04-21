#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board) {
    int n = board.size();
    for (int i = 0; i < col; i++) {
        if (board[row][i])
            return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j])
            return false;
    }
    return true;
}

void solveNQueen(int col, vector<vector<int>> &board, int &count) {
    int n = board.size();
    if (col == n) {
        count++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (isSafe(i, col, board)) {
            board[i][col] = 1;
            solveNQueen(col + 1, board, count);
            board[i][col] = 0;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the board: ";
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    int count = 0;
    solveNQueen(0, board, count);
    cout << "Number of solutions: " << count << endl;
    return 0;
}
