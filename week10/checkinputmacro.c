#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// if checkinput is true then you have an error
#define CHECKINPUT(scanfReturn)  ( scanfReturn == EOF || !scanfReturn )

int main() {
    int myInt = 0;
    if (CHECKINPUT(scanf("%d", &myInt))) {
        printf("Invalid input!\n");
        exit(1);
    }
    printf("My int: %d\n", myInt);
}
