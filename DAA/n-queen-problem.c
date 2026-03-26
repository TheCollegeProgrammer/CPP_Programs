#include <stdio.h>
#include <stdbool.h>

#define N 8   // Change this value for different board sizes

int board[N][N];

// Function to print the board
void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j])
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

// Check if it's safe to place a queen
bool isSafe(int row, int col) {
    int i, j;

    // Check column
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check left diagonal
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check right diagonal
    for (i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

// Backtracking function
bool solveNQueens(int row) {
    if (row == N) {
        printBoard();
        return true;  // return false here if you want only one solution
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;

            if (solveNQueens(row + 1))
                return true;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

// Main function
int main() {
    // Initialize board with 0
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    if (!solveNQueens(0))
        printf("No solution exists\n");

    return 0;
}