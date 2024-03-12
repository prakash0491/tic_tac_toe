#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];
char currentPlayer = 'X';

// Function to initialize the board with empty spaces
void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the board
void displayBoard() {
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to check if the given player has won
int checkWin(char player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        // Check rows
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
        // Check columns
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

// Function to check if the board is full
int isBoardFull() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0; // Board is not full
            }
        }
    }
    return 1; // Board is full
}

// Function to get the next move from the player
void getNextMove() {
    int row, col;
    printf("Player %c's turn. Enter row (1-3) and column (1-3) separated by space: ", currentPlayer);
    scanf("%d %d", &row, &col);
    row--; // Adjust to array index
    col--; // Adjust to array index
    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ') {
        board[row][col] = currentPlayer;
    } else {
        printf("Invalid move! Try again.\n");
        getNextMove(); // Recursive call to get a valid move
    }
}

int main() {
    initializeBoard();
    displayBoard();

    while (1) {
        getNextMove();
        displayBoard();
        if (checkWin(currentPlayer)) {
            printf("Player %c wins!\n", currentPlayer);
            break;
        } else if (isBoardFull()) {
            printf("It's a draw!\n");
            break;
        }
        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
