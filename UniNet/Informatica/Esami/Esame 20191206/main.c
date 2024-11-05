#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *fpIN;
    char filename[FILENAME_MAX];
    float livello, lmin, lmax;
    float temperatura, tmin, tmax;
    int data, dataPrecedente;
    int ora;

    printf("Nome del file in input: ");
    gets(filename);
    if ((fpIN=fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Errore nell'apertura del file di input %s\n", filename);
        return EXIT_FAILURE;
    }

    /* legge la prima riga, il file potrebbe essere vuoto */
    if (fscanf(fpIN, "%d%d%f%f", &dataPrecedente, &ora, &livello, &temperatura) != 4)
    {
        printf("Il file %s e' vuoto.\n", filename);
        fclose(fpIN);
        return EXIT_FAILURE;
    }
    lmin = lmax = livello; /* il primo livello e' il massimo e il minimo di quelli introdotti */
    tmin = tmax = temperatura; /* idem per le temperature */

    while (fscanf(fpIN, "%d%d%f%f", &data, &ora, &livello, &temperatura) == 4)
    {
        if (data == dataPrecedente)
        {
            /* verifica se livello e temperatura sono maggiori del max o minori del min */
            if (livello > lmax)
                lmax = livello;
            else if (livello < lmin)
                lmin = livello;

            if (temperatura > tmax)
                tmax = temperatura;
            else if (temperatura < tmin)
                tmin = temperatura;
        }
        else
        {
            printf("Data: %d Lmin: %.2f Lmax: %.2f Tmin: %.2f Tmax: %.2f\n", dataPrecedente, lmin, lmax, tmin, tmax);
            dataPrecedente = data;
            lmin = lmax = livello;
            tmin = tmax = temperatura;
        }
    }
    printf("Data: %d Lmin: %.2f Lmax: %.2f Tmin: %.2f Tmax: %.2f\n", dataPrecedente, lmin, lmax, tmin, tmax);

    fclose(fpIN);

    return EXIT_SUCCESS;
}
