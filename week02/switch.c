// Copyright (c) 2020 Hazel Campbell
// Licensed under AGPL3.0+
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int number = -1;
    printf("enter number number from 0-3: ");
    int scanned = scanf("%d", &number);
    if (scanned != 1) {
        printf("Eh?\n");
        abort();
    }
    switch(number) {
        case 0:
            printf("zero\n");
            break;
        case 1:
            printf("one\n");
            break;
        case 2:
            printf("two\n");
        case 3:
            printf("two or three\n");
            break;
        default:
            printf("not a number from 0-3\n");
    }
    return 0;
}
