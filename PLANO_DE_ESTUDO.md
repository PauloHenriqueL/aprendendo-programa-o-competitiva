# Plano de Estudo — Programação Competitiva

Objetivo: preparar o Paulo para competições (OBI, maratonas, ICPC),
cobrindo os pontos mais importantes e **todas as estruturas de dados**
essenciais. Método: **30% teoria / 70% prática** com problemas reais de
olimpíadas e maratonas. O aluno resolve; o Claude é juiz.

## Princípio central: REPETIÇÃO ESPAÇADA

Ver um tópico uma vez ≠ aprendê-lo. Cada conceito e estrutura de dados deve
ser **revisitado no mínimo ~10 vezes**, em problemas diferentes, ao longo do
tempo, para fixar na memória de longo prazo. Por isso:

- Os módulos NÃO são "faça uma vez e siga". Conceitos antigos reaparecem de
  propósito em problemas novos (ex.: array de contagem volta em vários
  módulos).
- Um `[x]` aqui significa "já foi introduzido/praticado ao menos uma vez",
  **não** "dominado". O domínio vem da contagem de repetições (ver CLAUDE.md).
- Sessões devem misturar: ~1 conceito novo + reforço de 1-2 antigos.

Legenda: ✅ introduzido (≥1x) · 🔁 em reforço · 🏆 consolidado (~10x) · ⬜ a fazer

---

## MÓDULO 0 — Fundamentos de C++ e ambiente ✅ (essencialmente feito)

Teoria: compilação e flags, I/O, `"\n"` vs `endl`.
- [x] Compilar/rodar, flags de competitiva
- [x] `cin`/`cout`, `getline` vs `cin >>`, `cin.ignore`
- [x] Strings como vetor de char; conversão char↔int
Prática já feita: `torneio_2021` (if/else, switch).

---

## MÓDULO 1 — Lógica, laços e simulação 🔄

Muitos problemas de fase 1 são "simulação": seguir regras passo a passo.
Teoria (curta): laços, condicionais, acumuladores, flags, "processar tudo
depois decidir".
- [x] Flag booleana, acumulador
- [x] Array de contagem (tabela de frequência)
- [ ] **Simulação com estado que evolui** (relógio, filas de eventos)
Prática:
- [x] `zero_2021` (pilha), `baralho_2021` (contagem+parsing)
- [ ] 🔄 `tempo_2021` — simulação com relógio (EM ANDAMENTO)
- [ ] Problemas extras de simulação (OBI fase 1 de outros anos)

---

## MÓDULO 1.5 — Sintaxe de laços (REVISAR MUITO — repetição espaçada) 🔁

⚠️ CONCEITOS QUE O ALUNO PRECISA FIXAR POR REPETIÇÃO — vistos 2026-06-30,
provavelmente esquecidos amanhã. O Claude deve reintroduzi-los DE PROPÓSITO
nos próximos exercícios até ~10 usos, e checar se o aluno lembra.

- [ ] **for/if/while/else SEM chaves `{}`** — governa só o PRÓXIMO comando.
      Pegadinha da indentação enganosa (o `-Wall` avisa). Repetições: 1.
      (Recomendação: aluno usa `{}` sempre por ora; só reconhecer ao ler.)
- [ ] **for-range** `for (tipo x : colecao)` — visita cada elemento sem
      índice. Bom quando não precisa da posição. Usar for tradicional quando
      precisa do índice (ex.: comparar `v[i]` com `v[i-1]`). Repetições: 1.
- [ ] **`x /= 10`** e amigos (`+=`, `*=`, `++`) — abreviações de atribuição.
      Repetições: ~2.
- [ ] **Loop de extração de dígitos compacto** `for(x=i; x>0; x/=10)
      soma+=x%10;` — equivalente ao do/while. Repetições: 1.

Como revisitar: em cada exercício novo onde couber, preferir/expor um desses
padrões e perguntar ao aluno o que a linha faz antes de seguir.

Material: exemplos rodados na sessão (blocos sem chave, for-range em
string/vector/array, tabela de rastreio de dígitos).

---

## MÓDULO 2 — Estruturas lineares 🔁

Teoria: quando cada estrutura brilha e seu custo (Big-O das operações).
- [x] **Pilha** (`stack`) — LIFO, "desfazer" (feito no `zero`) — 1x, revisitar
- [ ] **Fila** (`queue`) — FIFO; **deque** (fila dupla)
- [x] **Vetor dinâmico** (`vector`) — `push_back`, `size` (feito no `horarios`)
      — 1x, revisitar
- [x] **Par** (`pair`) — `.first`/`.second` (feito no `horarios`) — 1x, revisitar
- [ ] **Tupla** (`tuple`)
Prática: problemas de fila de atendimento, buffers, janelas.

---

## MÓDULO 3 — Ordenação e busca 🔁

Teoria: ordenar (`sort`), comparadores custom, **busca binária**.
- [x] `sort` (horarios, aquec-C, C_array) — 3x
- [x] Técnica **dois ponteiros** (aquec-F palindromo) — 1x
- [ ] Ordenar por comparador custom (lambda), ordenar structs
- [x] Busca linear (aquec2-L) vs **busca binária** (busca.cpp) — 1x cada
      Busca binária manual (lo/hi/meio, meio anti-overflow, break ao achar),
      validada com N=Q=100k em ~117ms. ✅
- [ ] `lower_bound` / `upper_bound` / `binary_search` prontos
- [ ] Janela deslizante
Prática: `busca.cpp` ✅ (consultas no catalogo).
NOTA: reforçar sempre — nada chegou a ~10x.

---

## MÓDULO 4 — Estruturas associativas 🔁

Teoria: mapear chaves a valores; conjuntos.
- [x] **`map`** (dicionário) — feito no `votacao.cpp` — 1x
- [x] Contagem/agrupamento com map (evolução do array de contagem) — votacao
- [x] `for(auto& par : m)` com `.first`/`.second`; map já vem ordenado — votacao
- [ ] **`unordered_map`** (map rápido, sem ordem)
- [ ] **`set` / `unordered_set`** (conjunto, elementos únicos)
Prática: `votacao.cpp` (apuração de votos). Reforçar (só 1x).

---

## MÓDULO 5 — Matemática para competição 🔁

Teoria: o essencial que cai muito.
- [x] Operadores `%` (resto) e `/` (divisão inteira) — feito no `promocao`
- [x] Extração de dígitos (`x%10`, `x/=10`) — feito no `promocao` — 1x
- [x] Paridade (`% 2`) — feito no `promocao` — 1x
- [ ] Aritmética modular, MDC/MMC (Euclides)
- [ ] Crivo de Eratóstenes, primalidade
- [ ] Exponenciação rápida; noções de combinatória
- [ ] Overflow: quando usar `long long`
Prática: problemas de teoria dos números de olimpíadas.
NOTA: extração de dígitos/paridade vistos 1x — revisitar bastante.

---

## MÓDULO 6 — Recursão e Backtracking ⬜

Teoria: pensar recursivamente; explorar todas as possibilidades.
- [ ] Recursão (fatorial, Fibonacci, torre de Hanói)
- [ ] Backtracking (permutações, subconjuntos, N-rainhas)
Prática: gerar combinações, resolver labirintos simples.

---

## MÓDULO 7 — Grafos (parte 1) ⬜

Teoria: a estrutura mais importante de competição avançada.
- [ ] Representação: lista/matriz de adjacência
- [ ] **BFS** (busca em largura) e **DFS** (busca em profundidade)
- [ ] Componentes conexas, caminho em grade (mapa/labirinto)
Prática: contar ilhas, menor número de passos em grade.

---

## MÓDULO 8 — Programação Dinâmica (DP) ⬜

Teoria: o "chefão" da maioria das maratonas.
- [ ] Memoização vs tabulação
- [ ] Clássicos: mochila, subsequência, moedas, LIS
Prática: problemas de DP de dificuldade crescente.

---

## MÓDULO 9 — Grafos (parte 2) e tópicos avançados ⬜

- [ ] Dijkstra (menor caminho com peso), união-busca (DSU)
- [ ] Árvore geradora mínima; ordenação topológica
- [ ] Árvores, intervalos (segment tree) — introdução

---

## MÓDULO 10 — Treino de prova ⬜

- [ ] Resolver **provas completas** cronometradas (OBI, seletivas)
- [ ] Revisar erros; construir "caderno de truques" pessoal

---

## Progresso geral

- Módulo 0: ✅ (revisitar sempre)
- Módulo 1: 🔄 (falta `tempo` — simulação; extras)
- Módulo 2: 🔁 iniciado (pilha, vector, pair — cada 1x, muito a reforçar)
- Módulo 3: 🔁 iniciado (sort — 1x, muito a reforçar)
- Módulo 5: 🔁 iniciado (dígitos, paridade — 1x)
- Demais: ⬜

Lembrete: NENHUM conceito atingiu ~10 repetições. "Iniciado" ≠ "aprendido".
As próximas sessões devem reforçar deliberadamente o que foi visto (array de
contagem, vector, pair, sort, extração de dígitos, funções, flags).

## Aquecimento (NEPS) — CONCLUÍDO ✅

Arquivo `aquecimento.cpp`, 4 problemas resolvidos pelo aluno + versão `_otima`
de cada (padrão de competição + Big-O comentado):
- A `quente` (if/else faixas) — ótima: O(1)/O(1)
- B `gemas` (array de contagem + ordem de aparição) — ótima: O(N)/O(1)
- C `horarios` (vector+pair+sort, ordenar-para-simplificar) — ótima: O(N log N)/O(N)
- D `promocao` (extração de dígitos, paridade) — ótima: O(N·d)/O(1)

## Fontes de exercícios

- OBI (Unicamp): olimpiada.ic.unicamp.br/pratique
- Beecrowd (ex-URI), Codeforces (divs iniciantes), AtCoder (ABC),
  neps.academy, SPOJ Brasil.

## Como cada tópico será conduzido

1. Teoria curta com exemplo mínimo (Claude mostra e roda).
2. Exercício de fixação simples (aluno resolve; Claude é juiz).
3. Problema real de olimpíada/maratona (aluno resolve; Claude é juiz).
4. Ao final, se o aluno pedir, Claude mostra a solução ótima + Big-O.
