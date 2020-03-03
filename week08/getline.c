#define _POSIX_C_SOURCE 200809L // <-- needed for getline
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * getline = malloc + fgets
 */

int main() {
    char * line = NULL;
    size_t alloc_len = 0;
    ssize_t got = 0;
    
    printf("line = %p\n", (void *) line);
    printf("alloc_len = %zu\n", alloc_len);
    
    printf("Enter your name: ");
    got = getline(&line, &alloc_len, stdin);
    
    printf("got = %zu\n", got);
    if (got < 0) {
        abort();
    }
        
    printf("line = %p\n", (void *) line);
    printf("alloc_len = %zu\n", alloc_len);
    printf("strlen(line) = %zu\n", strlen(line));
    
    size_t line_len = strlen(line);
    if (
        line_len > 0 
        && line[line_len - 1] == '\n'
    ) {
        line[line_len - 1] = '\0';
    }
    printf("Hello, %s!\n", line);
    
    // Don't forget to free!
    free(line);
}
