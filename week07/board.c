#include <stdint.h>
#include <stdio.h>
#include <stdlib.h> // <-- malloc is in stdlib.h

#define KIBI 1024L
#define MEGA (KIBI*KIBI)
#define SIZE 1024*8

/*
 * malloc: Memory ALLOCate, in number of bytes
 * free: deallocate the memory
 *  takes the pointer returned by malloc
 * 
 * Memory still needs to be initialized!
 */

uint8_t * get_board() {
    void * allocated = malloc(sizeof(uint8_t) * SIZE * SIZE);
    if (allocated == NULL) {
        printf("Error: Out of memory!\n");
        abort();
    }
    return allocated;
}

int main() {
    uint8_t (*board)[SIZE] = NULL;
    size_t total_size = sizeof(uint8_t) * SIZE * SIZE;
    board = (uint8_t (*)[SIZE])get_board();
    // board = malloc(total_size);
    for (size_t row = 0; row < SIZE; row++) {
        for (size_t col = 0; col < SIZE; col++) {
            board[row][col] = rand() % 26 + 'A';
        }
    }
    
    for (size_t row = 0; row < SIZE; row++) {
        for (size_t col = 0; col < SIZE; col++) {
            printf("%c", (char) board[row][col]);
        }
        printf("\n");
    }
    printf("board is %zu mebibytes!\n", total_size/MEGA);
    free(board);
    for (size_t row = 0; row < SIZE; row++) {
        for (size_t col = 0; col < SIZE; col++) {
            printf("%c", (char) board[row][col]);
        }
        printf("\n");
    }
}
