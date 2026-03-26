#include <stdio.h>
#include <stdbool.h>

#define N 4

int board[N][N];
int solutionCount = 0;

// Print labeled grid
void printGrid() {
    printf("\nGrid:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c%d ", 'A' + j, i + 1);
        }
        printf("\n");
    }
}

// Print solution with queen positions
void printSolution() {
    solutionCount++;
    printf("\nSolution %d:\n", solutionCount);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j]) {
                printf("Q%d => %c%d\n", i + 1, 'A' + j, i + 1);
            }
        }
    }
}

// Safety check
bool isSafe(int row, int col) {
    int i, j;

    for (i = 0; i < row; i++)
        if (board[i][col]) return false;

    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    for (i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j]) return false;

    return true;
}

// Backtracking
void solve(int row) {
    if (row == N) {
        printSolution();
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;
            solve(row + 1);
            board[row][col] = 0; // backtrack
        }
    }
}

int main() {
    printGrid();
    solve(0);

    printf("\nTotal Solutions = %d\n", solutionCount);
    return 0;
}