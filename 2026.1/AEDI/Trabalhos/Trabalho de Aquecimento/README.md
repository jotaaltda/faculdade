# Ajuste de Função Linear via Algoritmo Genético

Este projeto implementa um **Algoritmo Genético (AG)** simplificado para resolver o problema de regressão linear. O objetivo é encontrar os coeficientes _a_ (angular) e _b_ (linear) de uma reta *f(x) = ax + b* que minimizem o erro quadrático médio em relação a um conjunto de dados.

---

## 🛠️ Estrutura e Lógica de Programação

O algoritmo utiliza o modelo **Steady-State**, focado em eficiência computacional e evolução incremental.

---

### 1. Estruturas de Dados
* **Dados:** Armazenados em matriz `float pontos[1000][2]` para acesso rápido.
* **População:** Representada por uma matriz `float populacao[1000][2]`, onde cada linha é um indivíduo _[a, b]_.
* **Fitness:** Vetor independente `float fitness[1000]` que mapeia a qualidade de cada solução.

---

### 2. Ciclo Evolutivo
* **Avaliação:** O fitness é calculado como o inverso do Erro Quadrático Médio (MSE):  
  $$Fitness = \frac{1}{MSE + 0.0001}$$
* **Seleção:** Implementada via **busca linear (_O(m)_)** para identificar os dois melhores indivíduos (pais) e o pior (substituição), evitando o custo de ordenação total.
* **Crossover:** O descendente herda o gene _a_ do primeiro pai e o gene _b_ do segundo pai.
* **Mutação:** Aplicação de uma variação aleatória _\delta \in [-5, 5]_ em um dos genes escolhido via `rand()`.
* **Substituição:** O novo filho mutado substitui diretamente o pior indivíduo da geração.

---

### 3. Análise de Complexidade
O algoritmo foi projetado para ser altamente escalável:
* **Por Geração:** _O(n + m)_
* **Algoritmo Completo:** $O(G \cdot (n + m))$  
*(Onde _G_ = gerações, _n_ = pontos, _m_ = população)*

---

## 🚀 Como Compilar e Executar

O projeto foi desenvolvido para ambiente **Linux** (Ubuntu/Zorin OS).

1. **Compilar o programa:**
   make
   
2. **Executar a simulação:**
   make run

3. **Limpar arquivos binários:**
   make clean

## ⚠️ Configuração do `input.dat`

O arquivo de entrada deve conter apenas **uma linha** com três valores inteiros separados por espaço:
`n m G`

* **n**: Número de pontos a serem gerados.
* **m**: Tamanho da população (indivíduos).
* **G**: Quantidade de gerações (iterações).

**Nota importante sobre os pontos:** Para este trabalho de aquecimento, as coordenadas _(x, y)_ dos pontos são geradas **aleatoriamente** pelo próprio software logo após a leitura dos parâmetros. Por esse motivo, **não insira coordenadas manuais** no arquivo `input.dat`; o programa cuidará de criar o ambiente de teste automaticamente com base no valor de `n` informado.

---

## 📂 Organização do Repositório

├── src/
│   └── aquecimento.c   # Código-fonte principal em C
├── build/              # Binários e objetos (gerado pelo Makefile)
├── Makefile            # Script de automação de compilação
├── input.dat           # Parâmetros e dados de entrada
├── output.dat          # Log de evolução gerado pelo programa
└── README.md           # Documentação técnica (esta página)

---

## 🛠️ Créditos e Autoria

* **Desenvolvimento:** João Paulo de Abreu Duarte
* **Documentação Técnica:** Estruturação e análise algorítmica realizadas com auxílio da inteligência artificial **Gemini (Google)** para padronização acadêmica.