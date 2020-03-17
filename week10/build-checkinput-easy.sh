# build checkinput-driver
gcc  -std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3 \
       -o checkinput-driver checkinput-driver.c && \
( echo YES | ./checkinput-driver  || \
  echo 100 | ./checkinput-driver )

# build checkinput-driver
gcc  -std=c99 -pedantic -Wall -Wextra -ftrapv -ggdb3 \
       -o checkinput-driver checkinput-driver.c \
       checkinput.c && \
( echo YES | ./checkinput-driver  || \
  echo 100 | ./checkinput-driver )
