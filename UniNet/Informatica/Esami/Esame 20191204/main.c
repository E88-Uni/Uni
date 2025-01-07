#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SI 1
#define NO 0
#define DATALEN 11
#define NUMTEMP 24
#define OUTPUTFILE "Fuori_media.txt"
#define SCOSTMAX 0.05   /* scostamento max dalla media del 5% */

int main()
{

    FILE *fpIN, *fpOUT;
    char filename[FILENAME_MAX];
    float temperature[NUMTEMP];
    float temp; /* temperatura letta di volta in volta */
    float mediatemp; /* inizialmente contiene la somma, poi la media */
    char data[DATALEN]; /* contiene la data nel formato gg/mm/aaaa (10 char + \0) */
    int fuorimedia; /* flag che diventa SI se un valore è fuori media */
    int i;

    printf("Nome del file in input: ");
    gets(filename);
    if ((fpIN=fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Errore nell'apertura del file di input %s\n", filename);
        return EXIT_FAILURE;
    }

    if ((fpOUT=fopen(OUTPUTFILE, "w")) == NULL)
    {
        fprintf(stderr, "Errore nell'apertura del file di output %d\n", OUTPUTFILE);
        return EXIT_FAILURE;
    }

    while (fscanf(fpIN, "%s", data)==1) /* legga la data, così verifica anche se c'è una riga da leggere */
    {
        mediatemp = 0.0F;
        for (i=0; i<NUMTEMP; i++) /* legge le temperature */
        {
            fscanf(fpIN, "%f", &temp);
            temperature[i]= temp;
            mediatemp += temp;
        }
        mediatemp = mediatemp/NUMTEMP;

        /* verifica se uno dei valori e fuori media */
        fuorimedia = NO;    /* supponiamo non ci siano valori fuori media */
        for (i=0; i<NUMTEMP && !fuorimedia; i++)
            if (fabs(temperature[i]-mediatemp)/mediatemp > SCOSTMAX)
                fuorimedia = SI;  /* c'è un valore fuori media */
        if (fuorimedia) /* se ci sono fuori media manda in output sul file la riga */
            fprintf(fpOUT, "%s %.2f\n", data, mediatemp);
    }

    fclose(fpIN);
    fclose(fpOUT);

    return EXIT_SUCCESS;
}
