// Bibliotecas ==============================================================================================

#include <stdio.h>
#include <stdlib.h>

// Variáveis globais e protótipos ===========================================================================

FILE *arquivo;
int caractere;

// Função main ==============================================================================================

int main()
{

    arquivo = fopen("input.dat", "r");

    if (arquivo == NULL)
    {

        printf("Arquivo não encontrado!");
        exit(1);
    }

    do
    {

        caractere = fgetc(arquivo);

        if (caractere != EOF)
        {

            printf("%c", caractere);
        }

    } while (caractere != EOF);

    fclose(arquivo);

    return 0;
}