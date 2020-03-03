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

int function(int count) {
    printf("depth: %d\n", count);
    return function(count + 1);
}

int main() {
    function(1);
}
