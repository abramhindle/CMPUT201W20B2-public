# build coolbears.o
gcc  -std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3 \
       -c coolbears.c
# build coolbears-driver and link it to coolbears.o
gcc  -std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3 \
       -o coolbears-driver coolbears-driver.c \
       coolbears.o 
./coolbears-driver
