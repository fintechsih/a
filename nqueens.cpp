#include <iostream>
using namespace std;

int n;
int board[20][20];
int solutions = 0;

bool isSafe(int row, int col) {
    // Check same column above
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1) return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1) return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1) return false;

    return true;
}

void solve(int row) {
    if (row == n) {
        solutions++;
        cout << "Solution " << solutions << ":\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << (board[i][j] ? "Q " : ". ");
            cout << "\n";
        }
        cout << "\n";
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;   // place queen
            solve(row + 1);        // go to next row
            board[row][col] = 0;   // backtrack: remove queen
        }
    }
}

int main() {
    cout << "Enter N: ";
    cin >> n;

    solve(0);

    if (solutions == 0) cout << "No solution exists\n";
    else cout << "Total solutions: " << solutions << "\n";

    return 0;
}
