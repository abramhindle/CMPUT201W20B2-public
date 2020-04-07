#include <time.h>
#include <stdio.h>
#define BUFF 1024
struct demo {
    int i;
    float f;
    double d;
    char c;
};
int main() {
    char buffer[BUFF];
    FILE * file = fopen("binary.bin", "r"); 
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