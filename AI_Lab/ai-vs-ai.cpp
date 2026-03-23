#include <iostream>
#include <utility>
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

// Evaluate board
int evaluate() {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if(board[i][0] == 'O') return +10;
            if(board[i][0] == 'X') return -10;
        }
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if(board[0][i] == 'O') return +10;
            if(board[0][i] == 'X') return -10;
        }
    }

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

    if(score == 10 || score == -10)
        return score;

    if(!isMovesLeft())
        return 0;

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

// Best move finder
pair<int,int> findBestMove(bool isO) {
    int bestVal = isO ? -1000 : 1000;
    pair<int,int> bestMove = {-1, -1};

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ') {

                board[i][j] = isO ? 'O' : 'X';

                int moveVal = minimax(!isO);

                board[i][j] = ' ';

                if(isO) {
                    if(moveVal > bestVal) {
                        bestMove = {i, j};
                        bestVal = moveVal;
                    }
                } else {
                    if(moveVal < bestVal) {
                        bestMove = {i, j};
                        bestVal = moveVal;
                    }
                }
            }
        }
    }

    return bestMove;
}

// Main
int main() {
    // Initialize
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            board[i][j] = ' ';

    cout << "=== Computer vs Computer (Minimax) ===\n";

    bool isOTurn = true; // O starts

    while(true) {
        printBoard();

        pair<int,int> move = findBestMove(isOTurn);
        board[move.first][move.second] = isOTurn ? 'O' : 'X';

        cout << (isOTurn ? "O" : "X") << " played (" 
             << move.first + 1 << "," << move.second + 1 << ")\n";

        int score = evaluate();

        if(score == 10) {
            printBoard();
            cout << "O wins!\n";
            break;
        }
        if(score == -10) {
            printBoard();
            cout << "X wins!\n";
            break;
        }
        if(!isMovesLeft()) {
            printBoard();
            cout << "Draw!\n";
            break;
        }

        isOTurn = !isOTurn;
    }

    return 0;
}