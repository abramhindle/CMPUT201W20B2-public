#include <stdio.h>

int main(int argc, char ** argv) {
    for (int i = 0 ; i < argc; i++) {
        printf("arg %d: %s\t", i, argv[i]);
    }
    puts("");
}
