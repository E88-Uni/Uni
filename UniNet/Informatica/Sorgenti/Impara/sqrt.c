#include <stdio.h> 

double sqrt_a(double a, double prec){
    int i = 0;
    double x0 = a;
    for(; (x0-((1.0/2)*(x0+(a/x0)))>prec); i++){
        x0=(1.0/2)*(x0+(a/x0));
    } 
    return x0;
}

int main() {
  double n = 8.0;
  float sqrt_n = sqrt_a(n, 0.1);
  printf("Radice %f : %f\n", n, sqrt_n);
  scanf("%f", &n);
  return 0;
}