#include <stdio.h>
int main() {
    int input;
    if (scanf("%d", &input)!=1) abort();
    fprintf(stdout, "From stdin %d\n", input);
    fprintf(stderr, "ERR: From stdin %d\n", input);
    return 0;
}
