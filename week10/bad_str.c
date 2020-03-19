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
    char * message = malloc(sizeof(char) * 5);
    printf("Enter a message:\n");
    scanf("%s", message);
    printf("You entered: %s\n", message);
    return 0;
}
