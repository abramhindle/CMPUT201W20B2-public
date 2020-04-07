#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define SIZE 5
int main() {
    srand(time(NULL));
    FILE * file = fopen("fflush.txt", "w"); 
    if (file == NULL) {
        perror("Couldn't open fflush.txt");
        abort();
    }
    for (int i = 0 ; i < SIZE; i++) {
        fprintf(file, "%d\n", rand());
        fflush(file); // WE'RE FLUSHING!
        sleep(1);
    }
    fclose(file);
}
