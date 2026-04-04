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
int metade, melhor, melhorfit, escolhido;

float x, y;
float a, b;

float pontos[MAXPONTOS][2];
float populacao[MAXPOPULACAO][2];

float fitness[MAXPOPULACAO];

int melhores[MAXPOPULACAO];

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

    metade = m / 2;

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

    printf("\nPontos ================================\n\n");

    for (int i = 0; i < n; i++)
    {

        x = -10 + 20 * ((float)rand() / RAND_MAX);
        y = -10 + 20 * ((float)rand() / RAND_MAX);

        pontos[i][0] = x;
        pontos[i][1] = y;

        printf("%.03f %.03f\n", pontos[i][0], pontos[i][1]);
    }

    printf("\nPopulacao ================================\n\n");

    for (int j = 0; j < m; j++)
    {

        a = -10 + 20 * ((float)rand() / RAND_MAX);
        b = -10 + 20 * ((float)rand() / RAND_MAX);

        populacao[j][0] = a;
        populacao[j][1] = b;

        printf("Individuo %d: (%.03f, %.03f)\n", j + 1, populacao[j][0], populacao[j][1]);
    }

    printf("\nFitness ================================\n\n");

    for (int i = 0; i < m; i++)
    {
        float erro = calcularerro(populacao[i][0], populacao[i][1], n, pontos);
        fitness[i] = 1.0 / (erro + 0.0001); // transforma MSE em fitness
        printf("Individuo %d: Fitness = %.4f\n", i + 1, fitness[i]);
    }

    printf("\nEvolução ================================\n\n");

    for (int gen = 0; gen < G; gen++)
    {

        for (int i = 0; i < metade; i++)
        {
            melhor = -1;
            melhorfit = -1;

            for (int j = 0; j < m; j++)
            {
                escolhido = 0;
                for (int l = 0; l < i; l++)
                {
                    if (melhores[l] == j)
                    {
                        escolhido = 1;
                        break;
                    }
                }
                if (!escolhido && fitness[j] > melhorfit)
                {
                    melhorfit = fitness[j];
                    melhor = j;
                }
            }
            melhores[i] = melhor;
        }

        printf("\nMelhores da geração %d:\n", gen + 1);

        for (int i = 0; i < metade; i++)
        {
            int idx = melhores[i];
            printf("Individuo %d: Fitness = %.4f\n", idx + 1, fitness[idx]);
        }
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