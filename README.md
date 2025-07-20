<h1 align="center">🖥️ Simulador de Sistema Operacional</h1>
<p align="center">
  <b>Gerencie processos, filas de prioridade, pilhas de chamadas e mais — tudo em C!</b>
</p>

---

## 🚀 Funcionalidades

✅ Criação de processos com PID, nome, prioridade e estado  
📊 Filas de prioridade (Alta, Média, Baixa) para escalonamento  
🧠 Pilhas de chamadas de função para simular execução  
📁 Lista encadeada de processos finalizados  
🖱️ Interface por menu no terminal

---

## 🧬 Estrutura do Processo

```c
typedef struct Processo {
    int pid;
    char nome[50];
    int prioridade;  // 0: Alta, 1: Média, 2: Baixa
    int estado;      // 0: Pronto, 1: Executando, 2: Finalizado
    int chamadas_pilha;
    struct Processo* prox;
} Processo;
╔════════════════════════════╗
║   Simulador de S.O. - C   ║
╠════════════════════════════╣
║ [1] Criar novo processo    ║
║ [2] Executar processo      ║
║ [3] Listar processos       ║
║ [4] Finalizar processo     ║
║ [0] Sair                   ║
╚════════════════════════════╝
[1] Criar novo processo
Digite o nome do processo: Compilador
Digite a prioridade (0: Alta, 1: Média, 2: Baixa): 0
✅ Processo 'Compilador' criado com PID 1!

[2] Executar processo...
🚀 Processo em execução: Compilador (PID 1)

[4] Finalizar processo...
🛑 Processo finalizado: Compilador (PID 1)

[5] Ver processos:
📦 PID 1 | Nome: Compilador | Estado: Finalizado
```
Autores:
| Nome                 | GitHub                                         |
| -------------------- | ---------------------------------------------- |
| João Paulo           | [@jotaaltda](https://github.com/jotaaltda)     |
| Italo Xavier Fonseca | [@italoxavier](https://github.com/italoxavier) |


