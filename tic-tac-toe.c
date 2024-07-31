#include <stdio.h>
#include <stdlib.h>

char board[3][3];
char current_player;

void initialize_board();

void print_board();

int check_winner();

int is_board_full();

void switch_player();

void play_game();

int main() {
    play_game();
    return 0;
}

void initialize_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board() {
    printf("\n");
    printf("     1   2   3\n");
    for (int i = 0; i < 3; i++) {
        printf("   +---+---+---+\n");
        printf(" %d ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("   +---+---+---+\n\n");
}

int check_winner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == current_player && board[i][1] == current_player && board[i][2] == current_player) return 1;
        if (board[0][i] == current_player && board[1][i] == current_player && board[2][i] == current_player) return 1;
    }
    if (board[0][0] == current_player && board[1][1] == current_player && board[2][2] == current_player) return 1;
    if (board[0][2] == current_player && board[1][1] == current_player && board[2][0] == current_player) return 1;
    return 0;
}

int is_board_full() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

void switch_player() {
    if (current_player == 'X') {
        current_player = 'O';
    } else {
        current_player = 'X';
    }
}

void play_game() {
    int row, col;
    initialize_board();
    current_player = 'X';
    while (1) {
        print_board();
        printf("Player %c, enter your move (row and column): ", current_player);
        scanf("%d %d", &row, &col);
        row--;
        col--;
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = current_player;
            if (check_winner()) {
                print_board();
                printf("Player %c wins!\n", current_player);
                break;
            }
            if (is_board_full()) {
                print_board();
                printf("The game is a draw!\n");
                break;
            }
            switch_player();
        } else {
            printf("This move is not valid. Try again.\n");
        }
    }
}
