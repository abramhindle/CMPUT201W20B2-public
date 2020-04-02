#include <inttypes.h>
#include <stdlib.h>
int sum(int * array, size_t n) {
    int sum = 0; // N+=1
    for (size_t i = 0 ; i < n ; i+=4 ) { // N+=1
        sum += array[i]; // N+=1
    } // N+=1 E+=1
    for (size_t i = 1 ; i < n ; i+=4 ) { // N+=1
        sum += array[i]; // N+=1
    } // N+=1 E+=1
    for (size_t i = 2 ; i < n ; i+=4 ) { // N+=1
        sum += array[i]; // N+=1
    } // N+=1 E+=1
    for (size_t i = 3 ; i < n ; i+=4 ) { // N+=1
        sum += array[i]; // N+=1
    } // N+=1 E+=1
    return sum; // N+=1
}
