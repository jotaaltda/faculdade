#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

#include "Bibliotecas/fila.h" 
#include "Bibliotecas/pilha.h"

// ==========================================================================================================

// VARIAVEIS GLOBAIS
int opcaomenu;
int contador_PID = 1; // PID inicial.
Fila *fila; // Chamando a fila globalmente.
Fila *finalizados;

// PROTOTIPOS DAS FUNÇÕES
void mostrar_fila_por_prioridade(Fila *f, int prioridade);
void mostrar_processo_atual();
void mostrar_filas_prioridade();
void mostrar_processos_finalizados();

// ==========================================================================================================

int main() {
    finalizados = criar_fila();
    fila = criar_fila();

    printf("\033[2J\033[H");
    for (int i = 0; i < 3; i++) {
        printf("\t\e[1;91mINICIANDO SISTEMA");
        for (int j = 0; j <= 3; j++) {
            printf("\e[1;91m.");
            fflush(stdout);
            usleep(300000); 
        }
        printf("\r\033[K"); 
    }

    printf("\t\e[1;91m=====================================\e[0m\n");
    printf("\t\e[1;91m  _____                ____   _____ \e[0m\n");
    printf("\t\e[1;91m |_   _|              / __ \\ / ____|\e[0m\n");
    printf("\t\e[1;91m   | |  ___ __ _ _ __| |  | | (___  \e[0m\n");
    printf("\t\e[1;91m   | | / __/ _` | '__| |  | |\\___ \\ \e[0m\n");
    printf("\t\e[1;91m  _| || (_| (_| | |  | |__| |____) |\e[0m\n");
    printf("\t\e[1;91m |_____\\___\\__,_|_|   \\____/|_____/\e[0m\n");
    printf("\t\e[1;91m=====================================\e[0m\n");

    sleep(2); 
    printf("\033[2J\033[H");

// ==========================================================================================================

    do {
        sleep(2);
        printf("\t\e[1;91m======== DIGITE A OPCAO DESEJADA! ========\e[0m\n\n");
        printf("\t\e[1;91m1 .................... CRIAR NOVO PROCESSO\e[0m\n");
        printf("\t\e[1;91m2 .................... EXECUTAR PROCESSO\e[0m\n");
        printf("\t\e[1;91m3 .................... IMPRIMIR ESTADO ATUAL DO SISTEMA\e[0m\n");
        printf("\t\e[1;91m4 .................... CANCELAR PROCESSO\e[0m\n\n");
        printf("\t\e[1;91m0 .................... SAIR DO SISTEMA\e[0m\n");
        printf("\t\e[1;91m==========================================\e[0m\n\n");
        printf("\t\e[1;91mOPCAO:\e[0m ");
        scanf("%d", &opcaomenu);
        getchar();

        switch (opcaomenu) {
            case 1: {
                printf("\033[2J\033[H");
                TipoDado processo;
                processo.pid = contador_PID++;
            
                printf("\t\e[1;91mNome do Processo:\x1b[0m ");
                fgets(processo.nome,sizeof(processo.nome),stdin);
                processo.nome[strcspn(processo.nome, "\n")] = '\0';

                do {
                    printf("\t\e[1;91mPrioridade (1: Alta) (2: Media) (3: Baixa):\x1b[0m ");
                    scanf("%d", &processo.prioridade);
                    getchar(); // Limpa o buffer do scanf,
                } while (processo.prioridade < 1 || processo.prioridade > 3);

                printf("\t\e[1;91mNumero de Chamadas desejadas:\x1b[0m ");
                scanf("%d",&processo.num_chamadas);
                getchar(); // Limpador de buffer portátil.

                strcpy(processo.estado, "Pronto");
                criar_pilha(&processo.pilha_funcoes);
                enfileirar(fila,processo);

                printf("\t\e[1;91mProcesso criado com sucesso. \x1b[0m\n\n");
                sleep(2);
                printf("\033[2J\033[H");
                break;
            }

            case 2: {
                printf("\033[2J\033[H");
                if(fila_vazia(fila)) {
                    printf("\t\e[1;91mNenhum processo encontrado.\x1b[0m\n");
                    sleep(2);
                    printf("\033[2J\033[H");
                    break;
                }

                TipoDado processo = desenfileirar(fila);
                strcpy(processo.estado, "Executando");

                for (int i = 1; i <= processo.num_chamadas; i++) {
                    char nomefuncao[50];
                    sprintf(nomefuncao, "Funcao_%d",i);
                    empilhar(&processo.pilha_funcoes, nomefuncao, i);
                }

                printf("\t\e[1;91mExecutando processo PID %d: %s\x1b[0m\n", processo.pid, processo.nome);

                while(!pilha_vazia(&processo.pilha_funcoes)) {
                    int chamada = desempilhar(&processo.pilha_funcoes);
                    printf("\t\e[1;91m-> Executando chamada \e[1;95m%d\e[0m \e[1;91mdo processo\e[0m \e[1;95m%s\e[0m\n", 
                           chamada, processo.nome);
                    sleep(1);
                }

                strcpy(processo.estado, "Finalizado");
                enfileirar(finalizados, processo);
                printf("\t\e[1;91mProcesso \e[1;95m%d\e[0m \e[1;91mfinalizado com sucesso.\e[0m\n\n", processo.pid);
                sleep(2);
                printf("\033[2J\033[H");
                break;
            }

            case 3: {
                printf("\033[2J\033[H");
                
                mostrar_processo_atual();
                
                mostrar_filas_prioridade();
               
                mostrar_processos_finalizados();
                
                printf("\nPressione Enter para continuar...");
                getchar();
                printf("\033[2J\033[H");
                break;
            }

            case 4: {
                printf("\033[2J\033[H");
                
                if (fila_vazia(fila)) {
                    printf("\t\e[1;91mNenhum processo na fila para cancelar.\x1b[0m\n");
                } else {
                    printf("\t\e[1;91mProcessos na fila:\x1b[0m\n");
                    mostrar_fila(fila);
                    
                    printf("\n\t\e[1;91mDigite o PID do processo a cancelar:\x1b[0m ");
                    int pid_cancelar;
                    scanf("%d", &pid_cancelar);
                    getchar();
                    
                   
                    Fila *temp = criar_fila();
                    int encontrado = 0;
                    
                  
                    while (!fila_vazia(fila)) {
                        TipoDado p = desenfileirar(fila);
                        
                        if (p.pid == pid_cancelar) {
                            printf("\n\t\e[1;91mProcesso PID %d (%s) cancelado com sucesso!\x1b[0m\n", 
                                   p.pid, p.nome);
                            liberar_pilha(&p.pilha_funcoes);
                            encontrado = 1;
                        } else {
                            enfileirar(temp, p);
                        }
                    }
                    
                   
                    while (!fila_vazia(temp)) {
                        enfileirar(fila, desenfileirar(temp));
                    }
                    liberar_fila(temp);
                    
                    if (!encontrado) {
                        printf("\n\t\e[1;91mProcesso com PID %d não encontrado!\x1b[0m\n", pid_cancelar);
                    }
                }
                
                printf("\n\t\e[1;91mPressione Enter para continuar...\x1b[0m");
                getchar();
                printf("\033[2J\033[H");
                break;
            }

            case 0: {
                printf("\033[2J\033[H");
                printf("\n\t\e[1;91m==========================================\e[0m\n");
                printf("\t\e[1;91m          FINALIZANDO O SISTEMA          \e[0m\n");
                printf("\t\e[1;91m==========================================\e[0m\n\n");
                
               
                if (!fila_vazia(fila)) {
                    printf("\t\e[1;91mProcessos pendentes: %d\x1b[0m\n", 
                           fila->inicio ? 1 : 0);
                }
                
                if (!fila_vazia(finalizados)) {
                    printf("\t\e[1;91mProcessos finalizados: %d\x1b[0m\n", 
                           finalizados->inicio ? 1 : 0);
                }
                
                printf("\n\t\e[1;91mLiberando recursos...\x1b[0m\n");
                liberar_fila(fila);
                liberar_fila(finalizados);
                
               
                for (int i = 0; i < 3; i++) {
                    printf("\t\e[1;91m.");
                    fflush(stdout);
                    usleep(300000);
                }
                
                printf("\n\t\e[1;91mSistema encerrado com sucesso!\x1b[0m\n");
                sleep(2);
                printf("\033[2J\033[H");
                exit(0);
                break;
            }

            default: {
                printf("\t\e[1;91mOPCAO NAO ENCONTRADA!");
                sleep(2);
                printf("\033[2J\033[H");
                break;
            }
        }
    } while (opcaomenu != 0);

// ==========================================================================================================

    return 0;
}

// ==========================================================================================================

// CRIANDO AS FUNÇÕES AUXILIARES
void mostrar_processo_atual() {
    printf("\n=== PROCESSO ATUAL ===\n");
    int encontrado = 0;
    
    No *atual = fila->inicio;
    while (atual != NULL) {
        if (strcmp(atual->dado.estado, "Executando") == 0) {
            printf("| \x1b[35mPID: \x1b[0m \x1b[34m%d\x1b[0m | \x1b[35mNome:\x1b[0m \x1b[34m%s\x1b[0m | \x1b[35mEstado:\x1b[0m \x1b[34m%s\x1b[0m |\n",
                   atual->dado.pid, atual->dado.nome, atual->dado.estado);
            printf("Chamadas restantes: ");
            mostrar_pilha(&atual->dado.pilha_funcoes);
            encontrado = 1;
            break;
        }
        atual = atual->prox;
    }
    
    if (!encontrado) {
        printf("Nenhum processo em execucao no momento.\n");
    }
}

void mostrar_filas_prioridade() {
    printf("=== PROCESSOS NAS FILAS POR PRIORIDADE ===\n");
    
    int count_alta = 0, count_media = 0, count_baixa = 0;
    No *atual = fila->inicio;
    
    while (atual != NULL) {
        if (strcmp(atual->dado.estado, "Executando") != 0) {
            if (atual->dado.prioridade == 1) count_alta++;
            else if (atual->dado.prioridade == 2) count_media++;
            else count_baixa++;
        }
        atual = atual->prox;
    }
    
    printf("ALTA PRIORIDADE (%d processos):\n", count_alta);
    mostrar_fila_por_prioridade(fila, 1);
    
    printf("MEDIA PRIORIDADE (%d processos):\n", count_media);
    mostrar_fila_por_prioridade(fila, 2);
    
    printf("BAIXA PRIORIDADE (%d processos):\n", count_baixa);
    mostrar_fila_por_prioridade(fila, 3);
}

void mostrar_processos_finalizados() {
    printf("=== PROCESSOS FINALIZADOS ===\n");
    if (!fila_vazia(finalizados)) {
        No *atual = finalizados->inicio;
        while (atual != NULL) {
            printf("| PID: %d | Nome: %s | Chamadas: %d |\n",
                   atual->dado.pid, atual->dado.nome, atual->dado.num_chamadas);
            atual = atual->prox;
        }
    } else {
        printf("Nenhum processo finalizado ainda.\n");
    }
}

void mostrar_fila_por_prioridade(Fila *f, int prioridade) {
    No *atual = f->inicio;
    int encontrados = 0;
    
    while (atual != NULL) {
        if (atual->dado.prioridade == prioridade && 
            strcmp(atual->dado.estado, "Executando") != 0) {
            printf("| PID: %d | Nome: %s | Estado: %s |\n",
                   atual->dado.pid, atual->dado.nome, atual->dado.estado);
            encontrados++;
        }
        atual = atual->prox;
    }
    
    if (!encontrados) {
        printf("Nenhum processo nesta fila.\n");
    }
}