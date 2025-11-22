#include <stdio.h>

char board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void pboard() {
    printf("=TIC TAC TOE=\n");
    printf("    |   |   \n");
    printf("  %c | %c | %c \n", board[1], board[2], board[3]);
    printf(" ___|___|___\n");
    printf("    |   |   \n");
    printf("  %c | %c | %c \n", board[4], board[5], board[6]);
    printf(" ___|___|___\n");
    printf("    |   |   \n");
    printf("  %c | %c | %c \n", board[7], board[8], board[9]);
    printf("    |   |   \n");
}

int checkwin() {

    if (board[1] == board[2] && board[2] == board[3]) return 1;
    if (board[4] == board[5] && board[5] == board[6]) return 1;
    if (board[7] == board[8] && board[8] == board[9]) return 1;
    if (board[1] == board[4] && board[4] == board[7]) return 1;
    if (board[2] == board[5] && board[5] == board[8]) return 1;
    if (board[3] == board[6] && board[6] == board[9]) return 1;
    if (board[1] == board[5] && board[5] == board[9]) return 1;
    if (board[3] == board[5] && board[5] == board[7]) return 1;

    int count = 0;
    for (int i = 1; i <= 9; i++) {
        if (board[i] == 'X' || board[i] == 'O') count++;
    }
    if (count == 9) return 0;

    return -1; 
}

int main() {
    int player = 1, input, status = -1;
    pboard();

    while (status == -1) {
        player = (player % 2 == 0) ? 2 : 1;
        char mark = (player == 1) ? 'X' : 'O';

        while (1) {
            printf("Enter number (Player %d): ", player);
            scanf("%d", &input);

            if (input < 1 || input > 9) {
                printf("Invalid input. Please choose a number between 1 and 9.\n");
            } else if (board[input] == 'X' || board[input] == 'O') {
                printf("Position already taken. Choose another.\n");
            } else {
                break;
            }
        }

        board[input] = mark;
        pboard();

        status = checkwin();
        if (status == 1) {
            printf("Player %d wins!\n", player);
            break;
        } else if (status == 0) {
            printf("It's a draw!\n");
            break;
        }

        player++;
    }

    return 0;
}
