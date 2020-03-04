#include "board_print_plain.h"

int main()
{
    Figure board[SIZE][SIZE];
    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            Name name = r;
            for (int j = 0; j <= SIZE / 2; j++) {
                board[0][j].first_move = true;
                board[0][j].name = name;
                board[0][j].side = white;
                name++;
            }
        } else {
            Name name = e;
            for (int j = (SIZE / 2) + 1; j < SIZE; j++) {
                board[0][j].first_move = true;
                board[0][j].name = name;
                board[0][j].side = white;
                name--;
            }
        }
    }

    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            Name name = r;
            for (int j = 0; j <= SIZE / 2; j++) {
                board[SIZE - 1][j].first_move = true;
                board[SIZE - 1][j].name = name;
                board[SIZE - 1][j].side = black;
                name++;
            }
        } else {
            Name name = e;
            for (int j = (SIZE / 2) + 1; j < SIZE; j++) {
                board[SIZE - 1][j].first_move = true;
                board[SIZE - 1][j].name = name;
                board[SIZE - 1][j].side = black;
                name--;
            }
        }
    }

    for (int i = 0; i < SIZE; i++) {
        board[SIZE - 2][i].first_move = true;
        board[SIZE - 2][i].name = p;
        board[SIZE - 2][i].side = black;
    }

    for (int i = 0; i < SIZE; i++) {
        board[1][i].first_move = true;
        board[1][i].name = p;
        board[1][i].side = white;
    }

    for (int i = 2; i <= 5; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j].first_move = true;
            board[i][j].name = no;
            board[i][j].side = empty;
        }
    }

    board_print(board);
    return 0;
}