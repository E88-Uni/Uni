typedef struct {
    double re, im;
} complex;
complex new(double, double);
complex add(complex, complex);
complex sub(complex, complex);
complex mult(complex, complex);
complex quot(complex, complex);
double mod(complex);
