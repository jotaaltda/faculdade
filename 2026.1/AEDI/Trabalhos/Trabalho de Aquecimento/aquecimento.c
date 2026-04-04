// Bibliotecas ==============================================================================================

#include <stdio.h>
#include <stdlib.h>

// Defines ==================================================================================================

#define MAX 1000

// Variáveis globais e protótipos ===========================================================================

FILE *arquivoinput;
FILE *arquivooutput;

int n, m, G;

float pontos[MAX][2];

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

    srand(311003);

    fscanf(arquivoinput, "%d %d %d", &n, &m, &G);

    fclose(arquivoinput);
    fclose(arquivooutput);

    return 0;
}