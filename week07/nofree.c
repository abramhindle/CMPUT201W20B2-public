#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * testAllocArray(int arrLen) {
  int* array = calloc( sizeof(int), arrLen );
  assert(array!=NULL);
  for(int idx=0; idx<arrLen; idx++) {
    array[idx] = idx;
  }
  return array;
}

// this example doesn't free memory!

int main() {
    for (int i = 1; i < 10000000; i+=1*1024*1024) {
        int * bigArray = testAllocArray( i );
        printf("%u ints allocated!\n",1+bigArray[i-1]);
        printf("%lu bytes!\n", sizeof(int)*i);
        // free(bigArray); // remember to free it when done!
    }
}
