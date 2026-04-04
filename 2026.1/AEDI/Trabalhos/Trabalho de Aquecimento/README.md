# Regressão Linear - Algoritmo Genético Steady-State

Projeto acadêmico para encontrar a reta f(x) = ax + b que minimiza o Erro Quadrático Médio (MSE).

## 🛠️ Compilação e Execução (Linux)
1. `make` - Compila o projeto.
2. `make run` - Executa a simulação.
3. `make clean` - Remove arquivos temporários.

## 🧠 Lógica
- **Fitness**: 1 / (MSE + 0.0001)
- **Crossover**: Parâmetro 'a' do 1º melhor + Parâmetro 'b' do 2º melhor.
- **Mutação**: Variação aleatória em um dos genes do descendente.
- **Substituição**: O novo descendente substitui o pior da população.

## 📝 Créditos
- **Desenvolvedor**: João Paulo de Abreu Duarte
- **Documentação**: README gerado com auxílio do Gemini (Google AI).