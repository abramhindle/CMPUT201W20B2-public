# build checkinput-driver and link it to checkinput.o
gcc  -std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3 \
       -o poor-tanh-example poor-tanh-example.c \
       -lm
file poor-tanh-example
./poor-tanh-example | wc
ldd ./poor-tanh-example
