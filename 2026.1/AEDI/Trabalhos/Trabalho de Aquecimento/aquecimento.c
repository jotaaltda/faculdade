// Bibliotecas ==============================================================================================

#include <stdio.h>
#include <stdlib.h>

// Variáveis globais e protótipos ===========================================================================

FILE *arquivoinput;
FILE *arquivooutput;

int caractere;

// Função main ==============================================================================================

int main()
{

    arquivoinput = fopen("input.dat", "r");
    arquivooutput = fopen("output.dat", "w");

    if (arquivoinput == NULL)
    {

        printf("Arquivo input não encontrado!");
        exit(1);
    }
    else if (arquivooutput == NULL)
    {

        printf("Arquivo output não encontrado!");
        exit(1);
    }

    do
    {

        caractere = fgetc(arquivoinput);

        if (caractere != EOF)
        {

            fprintf(arquivooutput, "%c", caractere);
        }

    } while (caractere != EOF);

    printf("\n");

    fclose(arquivoinput);
    fclose(arquivooutput);

    return 0;
}