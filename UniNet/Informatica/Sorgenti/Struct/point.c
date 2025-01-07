#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*Definisci tipo Point
Alloca N Punti
'double DistanzaDaOrigine (Point p)'
'double Distanza (Point p1, Point p2)'
*/

typedef struct point{
    double x, y;
} Point;
double DistanzaDaOrigine (Point p){
    return sqrt(p.x * p.x + p.y * p.y);
}

double Distanza (Point p1, Point p2){
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() {
    Point p1, p2;
    int i, flag;
    
    printf("\nInserisci x P1: ");
    scanf("%lf", &p1.x);
    printf("\nInserisci y P1: ");
    scanf("%lf", &p1.y);
    printf("\nInserisci x P2: ");
    scanf("%lf", &p2.x);
    printf("\nInserisci y  P2 ");
    scanf("%lf", &p2.y);
        
    printf("\nDistanza da origineP1: %.2lf", DistanzaDaOrigine(p1));
    printf("\nDistanza da origineP2: %.2lf", DistanzaDaOrigine(p2));

    printf("\nDistanza P1-P2: %.2lf", Distanza(p1,p2));
    scanf("%d", &flag);
    return 0;
}