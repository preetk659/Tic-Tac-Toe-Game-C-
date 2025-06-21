#include <stdio.h>

char board[3][3] = { {'1', '2', '3'},
                     {'4', '5', '6'},
                     {'7', '8', '9'} };

void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("\n---|---|---\n");
    }
    printf("\n");
}

int checkWin() {
    // Rows, columns and diagonals
    for (int i = 0; i < 3; i++)
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            return 1;

    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return 1;

    return 0;
}

int main() {
    int move, row, col, turns = 0;
    char player = 'X';

    while (1) {
        printBoard();
        printf("Player %c, enter your move (1-9): ", player);
        scanf("%d", &move);

        if (move < 1 || move > 9) {
            printf("Invalid input!\n");
            continue;
        }

        row = (move - 1) / 3;
        col = (move - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Cell already taken!\n");
            continue;
        }

        board[row][col] = player;
        turns++;

        if (checkWin()) {
            printBoard();
            printf("Player %c wins!\n", player);
            break;
        }

        if (turns == 9) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
