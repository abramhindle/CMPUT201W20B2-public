#include <stdio.h>

int main(int argc, char**argv) {
    int done = 0;    // done or not
    char input[256]; // store characters from keyboard
    while( ! done ) { // not done!
        fgets(input, 256, stdin); // read from stdin up to 255 chars;
        puts("Your input was:\n");
        puts(input);
        if (input[0] == 'n') { // the first character of input is an n?
            done = 1;
        }
    }
    return 0;
}
