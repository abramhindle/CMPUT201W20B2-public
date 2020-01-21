#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> // <-- _MIN _MAX
#include <float.h>
#include <stdint.h>

int main() {
    signed char scmax = SCHAR_MAX;
    signed char scmin = SCHAR_MIN;
    printf("char: %zu bytes %zu bits %hhd to %hhd\n",                     
           sizeof(char),
           sizeof(char) * 8,
           scmin,
           scmax
    );
    short smax = SHRT_MAX;
    short smin = SHRT_MIN;
    printf("short: %zu bytes %zu bits %hd to %hd\n",                     
           sizeof(short),
           sizeof(short) * 8,
           smin,
           smax
    );
    int imax = INT_MAX;
    int imin = INT_MIN;
    printf("int: %zu bytes %zu bits %d to %d\n",                     
           sizeof(int),
           sizeof(int) * 8,
           imin,
           imax
    );
    long lmax = LONG_MAX;
    long lmin = LONG_MIN;
    printf("long: %zu bytes %zu bits %ld to  %ld\n",                     
           sizeof(long),
           sizeof(long) * 8,
           lmin,
           lmax
    );
    long long llmax = LLONG_MAX;
    long long llmin = LLONG_MIN;
    printf("long long: %zu bytes %zu bits %lld to %lld\n",                     
           sizeof(long long),
           sizeof(long long) * 8,
           llmin,
           llmax
    );
    float fmax = FLT_MAX;
    float fmin = FLT_MIN;
    printf("float: %zu bytes %zu bits %e to %e\n",
           sizeof(float),
           sizeof(float) * 8,
           fmin,
           fmax
    );
    double dmax = DBL_MAX;
    double dmin = DBL_MIN;
    printf("double: %zu bytes %zu bits max %e to %e\n",
           sizeof(double),
           sizeof(double) * 8,
           dmin,
           dmax
    );
    long double ldmax = LDBL_MAX;
    long double ldmin = LDBL_MIN;
    printf("long double: %zu bytes %zu bits  %Le to %Le\n",
           sizeof(long double),
           sizeof(long double) * 8,
           ldmin,
           ldmax
    );
    return 0;
}
