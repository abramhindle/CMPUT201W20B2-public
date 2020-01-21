#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char ** argv) {
  char c = '!';
  int count = 0;
  do {
    c = getchar();
    printf( "%d-", count++);
    putchar(c);
    putchar(' ');
  } while( c != '!' ); // Do while is while loop in reverse!
  return 0;
}
