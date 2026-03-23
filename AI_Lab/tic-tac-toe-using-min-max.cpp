#include <iostream>
using namespace std;

char board[3][3];

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

// Check winner
int evaluate() {
    for(int i = 0; i < 3; i++) {
        // Rows
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if(board[i][0] == 'O') return +10;
            if(board[i][0] == 'X') return -10;
        }

        // Columns
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if(board[0][i] == 'O') return +10;
            if(board[0][i] == 'X') return -10;
        }
    }

    // Diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if(board[0][0] == 'O') return +10;
        if(board[0][0] == 'X') return -10;
    }

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if(board[0][2] == 'O') return +10;
        if(board[0][2] == 'X') return -10;
    }

    return 0;
}

// Check moves left
bool isMovesLeft() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] == ' ')
                return true;
    return false;
}

// Minimax
int minimax(bool isMax) {
    int score = evaluate();

    // Terminal states
    if(score == 10) return score;
    if(score == -10) return score;
    if(!isMovesLeft()) return 0;

    if(isMax) {
        int best = -1000;

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == ' ') {
                    board[i][j] = 'O';
                    best = max(best, minimax(false));
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    } else {
        int best = 1000;

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == ' ') {
                    board[i][j] = 'X';
                    best = min(best, minimax(true));
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
}

// Find best move
pair<int,int> findBestMove() {
    int bestVal = -1000;
    pair<int,int> bestMove = {-1, -1};

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ') {
                board[i][j] = 'O';
                int moveVal = minimax(false);
                board[i][j] = ' ';

                if(moveVal > bestVal) {
                    bestMove = {i, j};
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

// Player move
void playerMove() {
    int row, col;
    while(true) {
        cout << "Enter row (1-3) and col (1-3): ";
        cin >> row >> col;
        row--; col--;

        if(row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = 'X';
            break;
        } else {
            cout << "Invalid move!\n";
        }
    }
}

// Main
int main() {
    // Initialize board
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            board[i][j] = ' ';

    cout << "=== Tic Tac Toe (Unbeatable AI) ===\n";

    while(true) {
        printBoard();

        playerMove();

        if(evaluate() == -10) {
            printBoard();
            cout << "🎉 You win!\n";
            break;
        }

        if(!isMovesLeft()) {
            printBoard();
            cout << "Draw!\n";
            break;
        }

        pair<int,int> bestMove = findBestMove();
        board[bestMove.first][bestMove.second] = 'O';

        cout << "Computer played...\n";

        if(evaluate() == 10) {
            printBoard();
            cout << "Computer wins!\n";
            break;
        }

        if(!isMovesLeft()) {
            printBoard();
            cout << "Draw!\n";
            break;
        }
    }

    return 0;
}