#include "board_print_plain.h"

void board_print(Figure board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            switch (board[i][j].name) {
            case p: {
                if (board[i][j].side == white)
                    printf("p ");
                else
                    printf("P ");
                break;
            }
            case r: {
                if (board[i][j].side == white)
                    printf("r ");
                else
                    printf("R ");
                break;
            }
            case h: {
                if (board[i][j].side == white)
                    printf("h ");
                else
                    printf("H ");
                break;
            }
            case e: {
                if (board[i][j].side == white)
                    printf("e ");
                else
                    printf("E ");
                break;
            }
            case q: {
                if (board[i][j].side == white)
                    printf("q ");
                else
                    printf("Q ");
                break;
            }
            case k: {
                if (board[i][j].side == white)
                    printf("k ");
                else
                    printf("K ");
                break;
            }
            default: {
                printf(" ");
                break;
            }
            }
        }
        printf("\n");
    }
}