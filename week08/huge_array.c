#define _POSIX_C_SOURCE 200809L
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This is an example of BAD CODE!
 * Can you use valgrind and gdb 
 * to figure out what's wrong with it?
 */

int main() {
    int array[1024 * 1024 * 2] = { 0 };
    printf("%d\n", array[0]);
    return 0;
}
