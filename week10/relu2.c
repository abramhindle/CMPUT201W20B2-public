#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// RELU is a rectified linear unit. These are popular in convolutional neural networks
// they are 0 for 0 and negative numbers and they are the identity for positive numbers.
// RELU(-100) = RELU(-1) = 0 && RELU(1) = 1 && RELU(100) = 100
#define RELU(x)  (( x < 0 )?0:x)

int main() {
    double x = 2.0;
    double y = 127.1;
    // How many times will pow(x,y) run?
    printf("%f\n", RELU(pow(x,y)));

}
