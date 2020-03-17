#include <stdio.h>

#define CHECKINPUT(scanfReturn)  (!scanfReturn||scanfReturn==EOF)?abort():scanfReturn

int main() {
    int myInt = 0;
    CHECKINPUT(scanf("%d", &myInt));
    printf("My int: %d\n", myInt);
}
