#include <time.h>
#include <stdio.h>
#include <unistd.h>
#define SIZE 20
#define BUFF 1024
int main() {
    char buffer[BUFF];
    FILE * file = fopen("fflush.txt", "r"); 
    if (file == NULL) {
        perror("Couldn't open fflush.txt");
        abort();
    }
    while(!feof(file)) {
        if (!fgets(buffer,BUFF,file)) {
            break;
        }
        printf("%s", buffer);
        sleep(1);
    }
    fclose(file);
}
