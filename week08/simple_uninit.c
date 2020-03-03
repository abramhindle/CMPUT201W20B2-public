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
    int x;
    printf("Enter an int:\n");
    scanf("%d", &x);
    printf("%d\n", x);
    return 0;
}
