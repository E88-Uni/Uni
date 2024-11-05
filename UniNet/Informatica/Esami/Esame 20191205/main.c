#include <stdio.h>
#include <stdlib.h>

#define MAXNOMEPRODOTTO 100 /* scelta arbitraria, ma ragionevole */

int main()
{

    FILE *fpIN;
    char filename[FILENAME_MAX];
    char prodotto[MAXNOMEPRODOTTO];
    float costo, ricavo;
    int quanti, numOggetti;
    int data, dataPrecedente;
    int ora;

    printf("Nome del file in input: ");
    gets(filename);
    if ((fpIN=fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Errore nell'apertura del file di input %s\n", filename);
        return EXIT_FAILURE;
    }

    numOggetti = 0; /* serve per evitare printf se il file e' vuoto a fine programma */
    /* legge la prima riga, il file potrebbe essere vuoto */
    if (fscanf(fpIN, "%s%d%f%d%d", prodotto, &quanti, &costo, &dataPrecedente, &ora) == 5)
    {
        numOggetti = quanti;
        ricavo = costo * quanti;
    }

    while (fscanf(fpIN, "%s%d%f%d%d", prodotto, &quanti, &costo, &data, &ora)==5)
    {
        if (data == dataPrecedente)
        {
            numOggetti += quanti;
            ricavo += costo * quanti;
        }
        else
        {
            printf("Data: %d, Oggetti: %d, Ricavo: %.2f\n", dataPrecedente, numOggetti, ricavo);
            numOggetti = quanti;
            ricavo = costo * quanti;
            dataPrecedente = data;
        }
    }
    if (numOggetti != 0) /* se il file non e' vuoto, visualizza l'ultima riga */
        printf("Data: %d, Oggetti: %d, Ricavo: %.2f\n", dataPrecedente, numOggetti, ricavo);
    else
        printf("Il file %s e' vuoto.\n", filename);

    fclose(fpIN);

    return EXIT_SUCCESS;
}
