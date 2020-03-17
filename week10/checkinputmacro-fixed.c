#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// if checkinput is true then you have an error
// horrible and bad style don't do this at home!
static int __ret;
#define CHECKINPUT(scanfReturn)  (__ret = scanfReturn, (__ret== EOF || !__ret ))

int main() {
    int myInt = 0;
    if (CHECKINPUT(scanf("%d", &myInt))) {
        printf("Invalid input!\n");
        exit(1);
    }
    printf("My int: %d\n", myInt);
}
