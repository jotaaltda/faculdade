// Bibliotecas ==============================================================================================

#include <stdio.h>
#include <stdlib.h>

// Defines ==================================================================================================

#define MAXPONTOS 1000
#define MAXPOPULACAO 1000

// Variáveis globais e protótipos ===========================================================================

FILE *arquivoinput;
FILE *arquivooutput;

int n, m, G;
int melhor, melhor1, melhor2, pior;

float x, y;
float a, b;
float melhorfit1, melhorfit2, piorfit;
float melhorfit, melhorerro;

float pontos[MAXPONTOS][2];
float populacao[MAXPOPULACAO][2];
float fitness[MAXPOPULACAO];

float calcularerro(float a, float b, int n, float pontos[][2]);

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

    if (n > MAXPONTOS)
    {

        fprintf(arquivooutput, "Digite um n menor que 1000!");
        exit(1);
    }
    else if (m > MAXPOPULACAO)
    {

        fprintf(arquivooutput, "Digite um m menor que 1000!");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {

        x = -10 + 20 * ((float)rand() / RAND_MAX);
        y = -10 + 20 * ((float)rand() / RAND_MAX);

        pontos[i][0] = x;
        pontos[i][1] = y;
    }

    for (int j = 0; j < m; j++)
    {

        a = -10 + 20 * ((float)rand() / RAND_MAX);
        b = -10 + 20 * ((float)rand() / RAND_MAX);

        populacao[j][0] = a;
        populacao[j][1] = b;
    }

    for (int i = 0; i < m; i++)
    {
        float erro = calcularerro(populacao[i][0], populacao[i][1], n, pontos);
        fitness[i] = 1.0 / (erro + 0.0001); // transforma MSE em fitness
    }

    for (int gen = 0; gen < G; gen++)
    {

        melhor1 = 0;
        melhor2 = 0;
        pior = 0;
        melhorfit1 = -1.0;
        melhorfit2 = -1.0;
        piorfit = 1e18;

        for (int j = 0; j < m; j++)
        {

            if (fitness[j] > melhorfit1)
            {
                melhorfit2 = melhorfit1;
                melhor2 = melhor1;
                melhorfit1 = fitness[j];
                melhor1 = j;
            }
            else if (fitness[j] > melhorfit2)
            {
                melhorfit2 = fitness[j];
                melhor2 = j;
            }

            if (fitness[j] < piorfit)
            {
                piorfit = fitness[j];
                pior = j;
            }
        }

        float filhoA = populacao[melhor1][0];
        float filhoB = populacao[melhor2][1];

        float delta = -5.0 + 10.0 * ((float)rand() / RAND_MAX);

        if (rand() % 2 == 0)
        {
            filhoA += delta;
        }
        else
        {
            filhoB += delta;
        }

        populacao[pior][0] = filhoA;
        populacao[pior][1] = filhoB;
        fitness[pior] = 1.0 / (calcularerro(filhoA, filhoB, n, pontos) + 0.0001);

        int vencedor = melhor1;
        if (fitness[pior] > fitness[melhor1])
        {
            vencedor = pior;
        }

        float erroVencedor = calcularerro(populacao[vencedor][0], populacao[vencedor][1], n, pontos);

        fprintf(arquivooutput, "Geração %d:\n", gen + 1);
        fprintf(arquivooutput, "Fitness: %f\n", fitness[vencedor]);
        fprintf(arquivooutput, "Erro: %f\n", erroVencedor);
        fprintf(arquivooutput, "a: %f, b: %f\n\n", populacao[vencedor][0], populacao[vencedor][1]);
    }

    fclose(arquivoinput);
    fclose(arquivooutput);

    return 0;
}

// Demais funções ===========================================================================================

float calcularerro(float a, float b, int n, float pontos[][2])
{

    float soma = 0;
    float estimado, erro;

    for (int k = 0; k < n; k++)
    {
        estimado = a * pontos[k][0] + b;
        erro = estimado - pontos[k][1];
        soma += erro * erro;
    }

    return soma / n;
}