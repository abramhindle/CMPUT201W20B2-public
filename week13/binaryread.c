#include <assert.h>
#include <time.h>
#include <stdio.h>
#define BUFF 1024
struct demo {
    int i;
    float f;
    double d;
    char c;
    char padding[7];
};
int main() {
    char buffer[BUFF];
    FILE * file = fopen("binary.bin", "rb"); 
    if (file == NULL) {
        perror("Couldn't open binary.bin");
        abort();
    }
    int size=0;
    assert(1==fread(&size, sizeof(size), 1, file));
    // we'll just ignore the size and just keep reading until we have
    // to stop.
    while(!feof(file)) {
        struct demo readDemo;
        if (1!=fread(&readDemo, sizeof(readDemo), 1, file)) {
           break;
        }
        printf("Reading %d\n", readDemo.i);
        printf("\tReading %f\n", readDemo.f);
        printf("\tReading %g\n", readDemo.d);
        printf("\tReading %c\n", readDemo.c);
    }
    fclose(file);
}
