#include <stdio.h>
#include <stdlib.h>

#define MAXESAME 30 /* valore arbitrario, ma ragionevole */
#define DIMCODICE 5

int main()
{

    FILE *fpIN;
    char filename[FILENAME_MAX];
    char codice[DIMCODICE+1]; /* c'e' il \0 in fondo */
    char esame[MAXESAME];
    int anno;
    int esamiSuperati;
    int crediti, creditiTot, creditiAnno[3]={0};


    printf("Nome del file in input: ");
    gets(filename);
    if ((fpIN=fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Errore nell'apertura del file di input %s\n", filename);
        return EXIT_FAILURE;
    }

    /* legge la prima riga, il file potrebbe essere vuoto */
    if (fscanf(fpIN, "%s%d%s%d", codice, &anno, esame, &crediti) != 4)
    {
        printf("Il file %s e' vuoto.\n", filename);
        fclose(fpIN);
        return EXIT_FAILURE;
    }

    esamiSuperati = 1;
    creditiTot = crediti;
    creditiAnno[anno-1] += crediti; /* si autoseleziona l'anno */

    while (fscanf(fpIN, "%s%d%s%d", codice, &anno, esame, &crediti) == 4)
    {
        esamiSuperati++;
        creditiTot += crediti;
        creditiAnno[anno-1] += crediti;
    }

    printf("Esami superati: %d\n", esamiSuperati);
    printf("Crediti conseguiti: %d\n", creditiTot);
    printf("Crediti anno 1: %d\n", creditiAnno[0]); /* per 3 valori si puo' anche ripetere, se sono molti si fa un ciclo for */
    printf("Crediti anno 2: %d\n", creditiAnno[1]);
    printf("Crediti anno 3: %d\n", creditiAnno[2]);

    fclose(fpIN);

    return EXIT_SUCCESS;
}
