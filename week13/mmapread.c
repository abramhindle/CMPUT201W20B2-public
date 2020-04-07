#include <assert.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 2
struct demo {
    int i;
    float f;
    double d;
    char c;
    // char cc[7]; // you can make padding explicit
};
int main() {
    srand(time(NULL));
    FILE * file = fopen("binary.bin", "r+"); 
    if (file == NULL) {
        perror("Couldn't open binary.bin");
        abort();
    }
    int fd = fileno(file);
    int rsize = 0;
    assert(1==fread(&rsize, sizeof(rsize), 1, file));
    const size_t size = sizeof(struct demo) * rsize;
    printf("N %d struct demos are in binary.bin\n", rsize);
    printf("mmapping %u bytes of memory from the file\n", size);
    int * mapped = mmap(0, 
        size,
        PROT_READ | PROT_WRITE, 
        MAP_SHARED, 
        fd, 
        0);
    if (mapped == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }
    // read 4 bytes from the head
    assert(rsize == (int)*mapped);
    // really abusive but we're 1 int after the start eh
    struct demo * demos = (struct demo *)(mapped+1);
    // OK now look for the read ?
    for (int i = 0 ; i < rsize; i++) {
        struct demo randd = demos[i];
        printf("Reading %d\n", randd.i);
        printf("\tReading %g\n", randd.f);
        printf("\tReading %g\n", randd.d);
        printf("\tReading %c\n", randd.c);
    }
    // demo we can write a -1
    // run the program twice and you'll the last integer is -1
    demos[rsize-1].i = -1;
    munmap(demos, size);
    fclose(file);
}
