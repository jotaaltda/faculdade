// Bibliotecas ==============================================================================================

#include <stdio.h>
#include <stdlib.h>

// Defines ==================================================================================================

#define MAX 1000

// Variáveis globais e protótipos ===========================================================================

FILE *arquivoinput;
FILE *arquivooutput;

int n, m, G;
float x, y;

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

    if (n > MAX)
    {

        fprintf(arquivooutput, "Digite um n menor que 1000!");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {

        x = (float)rand() / RAND_MAX;
        y = (float)rand() / RAND_MAX;

        pontos[i][0] = x;
        pontos[i][1] = y;

        printf("%f %f\n", pontos[i][0], pontos[i][1]);
    }

    fclose(arquivoinput);
    fclose(arquivooutput);

    return 0;
}