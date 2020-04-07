#include <stdio.h>
int main() {
    printf("OK this is to stdout!\n");
    fprintf(stdout,"OK this is to stdout as well!\n");
    fprintf(stderr,"OK this is to stderr!\n");
    return 0;
}
