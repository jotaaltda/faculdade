#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main()
{

    srand(time(NULL));

    int n = 50;
    int vetor[n];

    for (int i = 0; i < n; i++)
    {

        vetor[i] = rand() % (10 - (-10) + 1) + (-10);
    }

    for (int j = 0; j < n; j++)
    {

        int indice = rand() % (n - 0 + 1) + 0;
        int subvetor[indice];

        printf("Vetor %d: ", j);

        for (int k = 0; k < indice; k++)
        {

            subvetor[k] = vetor[k];

            printf("%d ", subvetor[k]);
        }

        printf("\n");
        Sleep(100);
    }

    return 0;
}