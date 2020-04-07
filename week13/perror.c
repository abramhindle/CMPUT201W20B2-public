#include <stdio.h>
int main() {
    // open a file I can't open
    FILE * f_cb  = fopen("/proc/whatever", "w"); 
    if (f_cb == NULL) {
        perror("Couldn't open /proc/whatever");
        abort();
    }
    printf("We shouldn't be here!\n");
}
