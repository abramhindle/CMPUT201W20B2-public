#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
    if (argc != 2) { exit(1); }
    int n = atoi(argv[1]);
    for (int i = 0 ; i < n; i++) {
        printf("%d\t", rand());
    }
    printf("\n");
}
