#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define DIM1 10
#define DIM2 8

/*
char c1[10] standard
char c2[8] input

Quanti caratteri in comune anche se uno minuscolo e l'altro maiuscolo
*/

char up_down(char c) {
    if (c >= 'a' && c <= 'z') { 
        return c - ('a' - 'A'); // Converte minuscolo in maiuscolo
    } else {
        return c;
    }
}

int match(char c1[], char c2[]) {
    char c1_l[DIM1]; // Array per c1 convertito in maiuscolo
    char c2_l[DIM2]; // Array per c2 convertito in maiuscolo
    int i, j;
    int common_count = 0; // Conta i caratteri in comune

    // Converti c1 in maiuscolo
    for (i = 0; i < strlen(c1); i++) {
        c1_l[i] = up_down(c1[i]);
    }
    c1_l[i] = '\0'; // Termina la stringa

    // Converti c2 in maiuscolo
    for (i = 0; i < strlen(c2); i++) {
        c2_l[i] = up_down(c2[i]);
    }
    c2_l[i] = '\0'; // Termina la stringa

    printf("\nc1_l : %s", c1_l);
    printf("\nc2_l : %s\n", c2_l);

    // Conta i caratteri in comune
    for (i = 0; i < strlen(c1_l); i++) {
        for (j = 0; j < strlen(c2_l); j++) {
            if (c1_l[i] == c2_l[j]) {
                common_count++;
                break; // Esci dal ciclo interno per evitare doppie conte
            }
        }
    }

    return common_count; // Ritorna il conteggio
}

int main() {
    char c1[DIM1] = "La Tua Psw";
    char c2[DIM2];
    int i = 0;
    
    printf("c1 : %s\n", c1);
    printf("Inserisci stringa : ");
    scanf("%s", c2);
    printf("c2 : %s\n", c2);
    
    int in_str = match(c1, c2);
    printf("In comune %d caratteri\n", in_str);

    scanf("%d", &i);
    return 0;
}
