#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char board[3][3];

// Initialize board
void initBoard() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

// Print board
void printBoard() {
    cout << "\n";
    for(int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
        if(i < 2)
            cout << "---+---+---\n";
    }
    cout << "\n";
}

// Check win
bool checkWin() {
    for(int i = 0; i < 3; i++) {
        // Rows
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return true;

        // Columns
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return true;
    }

    // Diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return true;

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return true;

    return false;
}

// Check draw
bool isDraw() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] == ' ')
                return false;

    return true;
}

// Player move
void playerMove() {
    int row, col;

    while(true) {
        cout << "Enter row (1-3) and column (1-3): ";
        cin >> row >> col;

        row--; col--;

        if(row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = 'X';
            break;
        } else {
            cout << "Invalid move! Try again.\n";
        }
    }
}

// Computer move (random)
void computerMove() {
    int row, col;

    while(true) {
        row = rand() % 3;
        col = rand() % 3;

        if(board[row][col] == ' ') {
            board[row][col] = 'O';
            cout << "Computer played at (" << row + 1 << ", " << col + 1 << ")\n";
            break;
        }
    }
}

// Main function
int main() {
    srand(time(0));
    initBoard();

    cout << "=== TIC TAC TOE ===\n";
    printBoard();

    while(true) {
        playerMove();
        printBoard();

        if(checkWin()) {
            cout << "You win!\n";
            break;
        }

        if(isDraw()) {
            cout << "It's a draw!\n";
            break;
        }

        computerMove();
        printBoard();

        if(checkWin()) {
            cout << "Computer wins!\n";
            break;
        }

        if(isDraw()) {
            cout << "It's a draw!\n";
            break;
        }
    }

    return 0;
}