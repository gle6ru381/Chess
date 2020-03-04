#include "board_print_plain.h"

void board_print(Figure board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j].side == white)
                printf("%c", board[i][j].name);
            else
                printf("%c", toupper(board[i][j].name));
        }
        printf("\n");
    }
}