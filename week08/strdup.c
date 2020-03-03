#define _POSIX_C_SOURCE 200809L // <-- needed for strdup
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // <-- strdup is in string.h

/*
 * strdup = malloc + strcpy
 */

int main() {
    const char * message = "hello, world!";
    // char buffer[14];
    // strncpy(buffer, message, 14);
    
    // char * copy = malloc((strlen(message) + 1) * sizeof(char));
    // strcpy(copy, message);
    
    char * copy = strdup(message);
    printf("%s\n", copy);
    message[0] = 'H';
    copy[0] = 'H';
    printf("%s\n", copy);
    free(copy);
}
