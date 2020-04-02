#include <inttypes.h>
#include <stdlib.h>
int sum(int * array, size_t n) {
    int sum = 0;
    for (size_t i = 0 ; i < n ; i++ ) {
        sum += array[i];
    }
    return sum;
}
