#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// RELU is a rectified linear unit. These are popular in convolutional neural networks
// they are 0 for 0 and negative numbers and they are the identity for positive numbers.
// RELU(-100) = RELU(-1) = 0 && RELU(1) = 1 && RELU(100) = 100
#define RELU(x)  (( x < 0 )?0:x)

int main() {
    // ints
    for (int i = -10; i < 10; i++) {
        printf("RELU(%d)=%d\n", i, RELU(i));
    }
    puts("\n");
    // more in the range of neural networks
    for (double i = -1; i < 1; i+=0.1) {
        printf("RELU(%f)=%f\n", i, RELU(i));
    }
    puts("\n");
}
