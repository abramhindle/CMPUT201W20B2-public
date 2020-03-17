#include <stdio.h>
#include <math.h>

int main() {
    double x = 0.0;
    double th = tanh(x);
    double lh = th;
    do {
        lh = th;
        x += 0.5;
        th = tanh(x);
        printf("tanh(%e) == %e\n", x, th);
    } while( lh != th );
}
