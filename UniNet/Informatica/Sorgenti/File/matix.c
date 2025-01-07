#include <stdio.h>
#define N 7
#define M 4

int printM(int Mat[M][N]){
    int i = 0,j;
    int max = 0;
    for(;i<(M-2);i++){
        int sum = 0;
        for(j=0; j<(N-2);j++){
            sum = Mat[i][j]+Mat[i+1][j]+Mat[i+2][j]+Mat[i][j+1]+Mat[i][j+2]+Mat[i+1][j+1];
            sum = sum + Mat[i+2][j+1]+Mat[i+1][j+2]+Mat[i+2][j+2];
            if(sum>max){
                max = sum;
            }
        }
    }
    return max;
}

int main(){
    FILE *f;
    int flag=0;
    int Mat[M][N];
    int col=0, rig=0, max;
    f = fopen("matrix.dat", "r");
    while(feof(f)==0 && flag==0){
        int k;
        fscanf(f, "%d", &k);
        if(rig<M && col<N){
            Mat[rig][col]=k;
            col++;
        } else if((rig+1)<M){
            col = 0;
            rig++;
            Mat[rig][col]=k;
            col++;
        }else{
            flag=1;
        }


    }
    max = printM(Mat);
    printf("\nSomma massima 3x3 : %d\n", max);
    if(fclose(f) != 0){
        printf("Chiusura fallita");
    }


    scanf("%d", &flag);
    return 0;
}