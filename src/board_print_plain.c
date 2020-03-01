#include "board_print_plain.h"

void board_print(Figure board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j].name);
        }
        printf("\n");
    }
}