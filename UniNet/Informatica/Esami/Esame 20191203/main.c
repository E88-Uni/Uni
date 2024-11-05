#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNOMEPRODOTTO 100 /* scelta arbitraria, ma ragionevole */

int main()
{

    FILE *fpIN, *fpOUT;
    char filename[FILENAME_MAX];
    char prodottoMod[MAXNOMEPRODOTTO]; /* prodotto da modificare */
    int variazione;
    char prodotto[MAXNOMEPRODOTTO]; /* prodotto letto di volta in volta */
    float costo;
    int scorta;
    float valoreComplessivo, variazioneValoreComplessivo;

    printf("Nome del file in input: ");
    gets(filename);
    if ((fpIN=fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Errore nell'apertura del file di input %s\n", filename);
        return EXIT_FAILURE;
    }

    printf("Nome del file in output: ");
    gets(filename);
    if ((fpOUT=fopen(filename, "w")) == NULL)
    {
        fprintf(stderr, "Errore nell'apertura del file di output %s\n", filename);
        return EXIT_FAILURE;
    }

    printf("Nome del prodotto di cui modificare le scorte: ");
    scanf("%s", prodottoMod);

    printf("Di quanto variare le scorte: ");
    scanf("%d", &variazione);

    variazioneValoreComplessivo = 0.0F;
    valoreComplessivo = 0.0F;
    while (fscanf(fpIN, "%s%f%d", prodotto, &costo, &scorta)==3)
    {
        valoreComplessivo += costo * scorta;
        if (strcmp(prodotto, prodottoMod) == 0)
        {
            scorta += variazione;
            variazioneValoreComplessivo = variazione * costo;
        }
        fprintf(fpOUT, "%s %.2f %d\n", prodotto, costo, scorta);
    }
    fclose(fpIN);
    fclose(fpOUT);

    if (variazioneValoreComplessivo != 0.0)
    {
        printf("Valore precedente: %.2f\n", valoreComplessivo);
        printf("Valore attuale: %.2f\n", valoreComplessivo+variazioneValoreComplessivo);
    }
    else
        printf("Prodotto inesistente\n");

    return EXIT_SUCCESS;
}
