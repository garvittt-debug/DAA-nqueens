//GARVIT GANGWAR,25/DA/027
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {

    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    int i = row - 1;
    int j = col - 1;

    while (i >= 0 && j >= 0) {
        if (board[i][j] == 1) {
            return false;
        }
        i--;
        j--;
    }

    i = row - 1;
    j = col + 1;

    while (i >= 0 && j < n) {
        if (board[i][j] == 1) {
            return false;
        }
        i--;
        j++;
    }

    return true;
}

bool solve(vector<vector<int>>& board, int row, int n) {

    if (row == n) {
        return true;
    }

    for (int col = 0; col < n; col++) {

        if (isSafe(board, row, col, n)) {

            board[row][col] = 1;

            if (solve(board, row + 1, n)) {
                return true;
            }

            board[row][col] = 0;
        }
    }

    return false;
}

int main() {

    int n;

    cout << "Enter value of N: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solve(board, 0, n)) {

        cout << "One possible solution:\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "No solution exists.";
    }

    return 0;
}
