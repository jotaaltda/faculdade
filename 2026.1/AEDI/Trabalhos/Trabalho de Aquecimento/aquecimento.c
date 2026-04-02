// Bibliotecas ==============================================================================================

#include <stdio.h>
#include <stdlib.h>

// Variáveis globais e protótipos ===========================================================================

FILE *arquivoinput;
FILE *arquivooutput;

int caractere;
int x, y, z;

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

    fscanf(arquivoinput, "%d %d %d", &x, &y, &z);
    fprintf(arquivooutput, "O 1° valor é %d, o 2° é %d e o 3° é %d!", x, y, z);

    printf("\nTexto impresso com sucesso em output.dat!\n");

    fclose(arquivoinput);
    fclose(arquivooutput);

    return 0;
}