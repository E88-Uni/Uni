#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


void monteCarlo(int n) {
    int c_points = 0, i = 0;
    double x, y, pi;
    srand(time(NULL));

    for(; i < n; i++) {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;

        if(x*x + y*y <= 1) {
            c_points++;
        }
    }
    pi = 4* (double)c_points / n;
    printf("\nPi MonteCarlo = %f\n", pi);
}

void leibniz(int n) {
    double pi = 0;
    int sign = 1, i =1;
    for(; i<=n; i+=2){
        pi += sign * 1.0 / i;
        sign *= -1;
    }

    pi *= 4;
    printf("\nPi Leibniz = %f\n", pi);

}

/* int max = 2 147 483 647*/
int main() {
    int n = 200000;
    monteCarlo(n);
    leibniz(n*10);
    printf("\n3,14159 26535");
    return 0;
}