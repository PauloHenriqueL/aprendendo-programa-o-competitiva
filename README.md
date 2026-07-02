# 🏆 Programação Competitiva — Jornada de Estudos

Repositório de estudos de **programação competitiva** em C++ (OBI, maratonas,
ICPC), partindo do zero. Cada arquivo tem o **enunciado em comentário** no topo
e a **solução comentada**, com a análise de complexidade (Big-O).

> Estudante: Paulo (UFMG). Método: resolvo os problemas sozinho e valido cada
> um contra os casos de teste; foco em **entender o "porquê"**, não decorar.

---

## 📂 Como o repositório está organizado

| Pasta | Tema | Conteúdo |
|-------|------|----------|
| [`00-referencia/`](00-referencia/) | 📖 Caderno de conceitos | `visto.cpp` — todos os conceitos vistos, com exemplos comentados (consulta rápida) |
| [`02-simulacao-obi2021/`](02-simulacao-obi2021/) | 🎯 OBI 2021 (Fase 1, Sênior) | Prova completa: `zero`, `torneio`, `baralho`, `tempo` |
| [`03-aquecimentos/`](03-aquecimentos/) | 🔥 Revisão | `aquecimento.cpp` (7 problemas) e `aquecimento2.cpp` (5 problemas) |
| [`04-estruturas-associativas/`](04-estruturas-associativas/) | 🗺️ Map | `votacao.cpp` — apuração de votos com `map` |
| [`05-busca/`](05-busca/) | 🔍 Busca | `busca.cpp` — busca binária (manual + `binary_search`) |

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
