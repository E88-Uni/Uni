//complex.c
#include <math.h>
#include "complex.h"

complex new(double re, double im){
    complex temp;
    temp.re = re;
    temp.im = im;
    return temp;
}

complex add(complex x, complex y){
    complex temp;
    temp.re = x.re + y.re;
    temp.im = x.im + y.im;
    return temp;
}

complex sub(complex x, complex y){
    complex temp;
    temp.re = x.re - y.re;
    temp.im = x.im - y.im;
    return temp;
}

complex quot(complex x, complex y){
    complex temp;
    temp.re = x.re / y.re;
    temp.im = x.im / y.im;
    return temp;
}

complex mult(complex x, complex y){
    complex temp;
    temp.re = x.re * y.re;
    temp.im = x.im * y.im;
    return temp;
}

double mod(complex x){
    double z = sqrt(x.re*x.re+x.im*x.im);
    return z;
}
