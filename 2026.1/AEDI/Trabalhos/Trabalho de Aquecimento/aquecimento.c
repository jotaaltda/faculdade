// Bibliotecas ==============================================================================================

#include <stdio.h>
#include <stdlib.h>

// Variáveis globais e protótipos ===========================================================================

FILE *arquivoinput;
FILE *arquivooutput;

int n, m, G;

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

    fscanf(arquivoinput, "%d %d %d", &n, &m, &G);

    fclose(arquivoinput);
    fclose(arquivooutput);

    return 0;
}