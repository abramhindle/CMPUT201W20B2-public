# build checkinput.o
gcc  -std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3 \
       -c checkinput.c
# build checkinput-driver and link it to checkinput.o
gcc  -std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3 \
       -o checkinput-driver checkinput-driver.c \
       checkinput.o
