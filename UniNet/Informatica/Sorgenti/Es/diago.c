#include <stdio.h>
/*Ritornare la diagonale con somma maggiore 
 1 2 3
 4 5 6
 7 8 10
 Diag1 ; (0, 0)+(1, 1)+(2, 2) : 16

 Diag2 : (0, 2)+(1, 1)+(2, 0) : 15
*/

int main(){
    int M[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 10}};
    int wait;
    int dig1 = M[0][0]+M[1][1]+M[2][2];
    int dig2 = M[0][2]+M[1][1]+M[2][0];
    int dig = (dig1>dig2)?dig1:dig2;
    printf("Diagonale massima : %d", dig);
    scanf("%d", wait);
    return 0;
}