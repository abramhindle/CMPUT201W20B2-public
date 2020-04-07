#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 5
struct demo {
    int i;
    float f;
    double d;
    char c;
};
int main() {
    srand(time(NULL));
    FILE * file = fopen("binary.bin", "wb"); 
    if (file == NULL) {
        perror("Couldn't open binary.bin");
        abort();
    }

    int realSize = 1 + (rand() % SIZE);
    assert(1==fwrite(&realSize, sizeof(int), 1, file));
    for (int i = 0 ; i < realSize; i++) {
        struct demo randd;
        randd.i = rand();
        randd.f = rand() / 2.0F;
        randd.d = 1.0 / (rand()+1.0);
        randd.c = 'X';
        printf("Writing %d\n", randd.i);
        printf("\tWriting %g\n", randd.f);
        printf("\tWriting %g\n", randd.d);
        printf("\tWriting %c\n", randd.c);
        assert(1==fwrite(&randd, sizeof(randd), 1, file));
    }
    fclose(file);
}
