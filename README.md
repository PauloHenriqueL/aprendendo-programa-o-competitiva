# 🏆 Programação Competitiva — Jornada de Estudos

Repositório de estudos de **programação competitiva** em C++ (OBI, maratonas,
ICPC), partindo do zero. Cada arquivo tem o **enunciado em comentário** no topo
e a **solução comentada**, com a análise de complexidade (Big-O).

> Estudante: Paulo (UFMG). Método: resolvo os problemas sozinho e valido cada
> um contra os casos de teste; foco em **entender o "porquê"**, não decorar.

---

## 📂 Como o repositório está organizado

Os **módulos de assunto** (a trilha de estudo, em ordem) são numerados. As
pastas de **apoio** (aquecimentos, referência, contests, codeforces) não têm
número.

### Módulos de assunto (trilha de estudo)
| Pasta | Tema | Conteúdo |
|-------|------|----------|
| [`01-simulacao/`](01-simulacao/) | 🎯 Simulação (OBI 2021) | `zero`, `torneio`, `baralho`, `tempo` |
| [`02-estruturas-associativas/`](02-estruturas-associativas/) | 🗺️ Map | `votacao.cpp` — apuração de votos |
| [`03-busca/`](03-busca/) | 🔍 Busca | `busca.cpp` — busca binária (manual + `binary_search`) |
| [`04-recursao/`](04-recursao/) | 🔁 Recursão/Backtracking | `subconjuntos`, `contar_subconjuntos` |
| [`05-memoria-arquivos/`](05-memoria-arquivos/) | 💾 Memória e arquivos | `teoria_memoria_arquivos.cpp` |
| [`06-guloso/`](06-guloso/) | 🍰 Algoritmo guloso | `conceito_guloso`, `pratica_pair_guloso` |

### Pastas de apoio
| Pasta | Conteúdo |
|-------|----------|
| [`aquecimentos/`](aquecimentos/) | 🔥 Todos os aquecimentos, por tema (geral, recursão, memória, guloso) |
| [`referencia/`](referencia/) | 📖 `visto.cpp` — caderno de conceitos vistos (consulta rápida) |
| [`contests/`](contests/) | 🏆 Provas reais resolvidas (upsolving). Ex.: `udesc-2026-1` |
| [`codeforces/`](codeforces/) | 💻 Problemas avulsos do Codeforces (com link/ID) |

Roteiro de estudos completo: [`PLANO_DE_ESTUDO.md`](PLANO_DE_ESTUDO.md)

---

## ✅ O que já aprendi

### Fundamentos & I/O
- [x] Compilação com flags (`-Wall -Wextra -Wshadow -O2`), sanitizers para debug
- [x] `cin`/`cout`, `getline` vs `cin >>`, `cin.ignore`, `"\n"` vs `endl`
- [x] `sync_with_stdio(false)` + `cin.tie(NULL)` para I/O rápido

### Lógica & Controle
- [x] `if/else` encadeado (faixas), `switch/case` (break, fall-through)
- [x] Laços `for` / `while` / `do-while`; blocos com/sem chaves `{}`
- [x] `for-range` (`for(x : col)`) vs `for` tradicional (por índice)
- [x] Flag booleana; "processar tudo, depois decidir"

### Strings & Números
- [x] String como vetor de char (`s[i]`, `s.size()`)
- [x] Conversão char↔int (`c - '0'`, `c - 'a'`, `char('a'+i)`)
- [x] Extrair dígitos (`% 10`, `/= 10`), paridade

### Estruturas de Dados
- [x] **Array de contagem** (tabela de frequência)
- [x] **Pilha** (`stack`) — LIFO, "desfazer"
- [x] **`vector`** (array dinâmico), **`pair`** (`.first`/`.second`)
- [x] **`map`** (dicionário chave→valor, mantém ordem)

### Algoritmos & Técnicas
- [x] **Ordenação** (`sort`) e "ordenar para simplificar"
- [x] **Dois ponteiros** (esquerda/direita)
- [x] **Busca binária** (manual e `binary_search`) — O(log n)
- [x] Simulação com estado que evolve
- [x] Noções de **Big-O** (tempo e memória)

---

## 🚧 O que ainda falta aprender

### Próximos passos
- [ ] `lower_bound` / `upper_bound` (busca da posição, contar ocorrências)
- [ ] `set` / `unordered_set` (conjuntos), `unordered_map`
- [ ] Ordenação com comparador custom (lambda), ordenar structs

### Matemática
- [ ] Aritmética modular, MDC/MMC (Euclides)
- [ ] Crivo de Eratóstenes, primalidade
- [ ] Exponenciação rápida; overflow (`long long`)

### Recursão & além
- [ ] Recursão e backtracking (permutações, N-rainhas)
- [ ] **Grafos**: BFS, DFS, caminhos em grade
- [ ] **Programação Dinâmica**: mochila, LIS, moedas
- [ ] Grafos avançados: Dijkstra, DSU, árvore geradora mínima

---

## 📊 Progresso por tópico

| Tópico | Status |
|--------|--------|
| Fundamentos / I/O | ✅ Praticado |
| Lógica e simulação | ✅ OBI 2021 completa |
| Estruturas lineares (pilha, vector, pair) | 🔁 Em reforço |
| Ordenação e busca (sort, dois ponteiros, busca binária) | 🔁 Em reforço |
| Estruturas associativas (map) | ✅ Iniciado |
| Matemática | 🔁 Iniciado (dígitos, paridade) |
| Recursão / Grafos / DP | ⬜ A fazer |

**Legenda:** ✅ praticado · 🔁 em reforço (repetição espaçada) · ⬜ a fazer

> 💡 Nenhum tópico é "concluído" após um uso — cada conceito é revisitado
> várias vezes em problemas diferentes, para fixar na memória de longo prazo.

---

## 🛠️ Como compilar e rodar

```bash
# Compilar (flags de competição)
g++ -std=c++17 -Wall -Wextra -Wshadow -O2 -o solucao arquivo.cpp

# Rodar
./solucao < entrada.txt

# Debug (detecta acesso inválido de memória, overflow)
g++ -std=c++17 -Wall -Wextra -fsanitize=address,undefined -g -o solucao arquivo.cpp
```

---

## 📚 Fontes dos problemas

- [OBI — Olimpíada Brasileira de Informática](https://olimpiada.ic.unicamp.br/pratique/)
- Beecrowd, Codeforces, AtCoder, neps.academy
