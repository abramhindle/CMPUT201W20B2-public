#include <stdio.h>

int main(int argc, char**argv) {
  int size_of_character_array = 256;
  char your_character_array[size_of_character_array];
  char dump[16];
  puts("fgets");
  fgets(your_character_array, size_of_character_array, stdin);
  puts(your_character_array);
  puts("scanf");
  scanf("%256[^\n]", your_character_array);
  scanf("%1[\n]",dump); // gotta eat that newline up eh
  puts(your_character_array);
  puts("fgets");
  fgets(your_character_array, size_of_character_array, stdin);
  puts(your_character_array);
  puts("scanf");
  scanf("%256[^\n]", your_character_array);
  scanf("%1[\n]",dump);  // gotta eat that newline up eh
  puts(your_character_array);

}
