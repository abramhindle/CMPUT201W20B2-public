#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define KIBI 1024
#define MEBI (KIBI*KIBI)
#define ROWS (KIBI*8)
#define COLS KIBI

uint8_t (*)[COLS] get_board() {
    uint8_t board[ROWS][COLS];
    return board;
}

int main() {
    uint8_t board[ROWS][COLS];
    for (size_t row = 0; row < ROWS; row++) {
        for (size_t col = 0; col < COLS; col++) {
            board[row][col] = rand() % 26 + 'A';
        }
    }
    
    for (size_t row = 0; row < ROWS; row++) {
        for (size_t col = 0; col < COLS; col++) {
            printf("%c", (char) board[row][col]);
        }
        printf("\n");
    }
    
    printf("board is %zu mebibytes!\n", sizeof(board)/MEBI);
}
