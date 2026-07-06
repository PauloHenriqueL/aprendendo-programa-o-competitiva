# Plano de Estudo — Programação Competitiva

Objetivo: preparar o Paulo para competições (OBI, maratonas, ICPC), cobrindo
estruturas de dados E **paradigmas de resolução** (guloso, dois ponteiros,
força bruta, backtracking, DP...). Meta prática: resolver Codeforces 800 com
autonomia e subir a partir daí. O aluno resolve; o Claude é juiz.

## MÉTODO DIÁRIO (decidido 2026-07-04) — mínimo 10 exercícios/dia

O estudo raso (poucas perguntas + 4 aquecimentos + 1 novo) acabou. Todo dia
segue este fluxo, com NO MÍNIMO 10 exercícios:

1. **DISCUSSÃO INICIAL (recall ativo, estilo prova):** o Claude faz perguntas
   sobre conceitos já vistos — o aluno responde de cabeça, sem código. Serve
   para reativar a memória e diagnosticar o que enferrujou.
2. **AQUECIMENTO — 8 exercícios:**
   - **4 exercícios** que cobram conceitos JÁ VISTOS (reforço espaçado dirigido
     — priorizar os que o aluno mais ERRA; ver painel abaixo).
   - **4 exercícios variados** que relembram o que será necessário para o
     problema principal do dia (preparam o terreno para o conceito novo).
3. **CONCEITO NOVO — 2 exercícios:** um arquivo com o conceito explicado em
   COMENTÁRIO + 2 problemas para o aluno aplicar/implementar o conceito novo.

Total: 8 + 2 = 10 exercícios mínimos por dia (fora a discussão inicial).

## CONTROLE DE DESEMPENHO (o plano é um PAINEL)

Este arquivo controla 4 coisas, não só "o que estudar":
- **O que o aluno JÁ VIU** (introduzido) × **NÃO VIU** (⬜).
- **O que ele vai BEM** (acerta de primeira/poucas tentativas) × **vai MAL**
  (erra muito, precisa refazer).

Regra de avanço/trava (repetição espaçada dirigida por desempenho):
- Conceito que o aluno **mais ACERTA** → AVANÇA (🔁→🏆); para de repetir tanto,
  liberando espaço para o que ele erra.
- Conceito que o aluno **mais ERRA** → FICA PARADO (não avança); é
  deliberadamente reintroduzido nos próximos aquecimentos até firmar.
- A contagem fina de repetições e o histórico de bugs ficam no CLAUDE.md
  (tabela "Conceitos praticados" + painel de erros recorrentes).

Legenda: ✅ introduzido (≥1x) · 🔁 em reforço · 🏆 consolidado (~10x) · ⬜ a fazer
Desempenho: 🟢 vai bem (acerta) · 🟡 instável · 🔴 erra muito (REFORÇAR!)

## PAINEL DE DESEMPENHO (atualizar a cada sessão)

🔴 ERRA MUITO (reforçar de propósito, NÃO avançar):
- **`vector<int> v;` VAZIO + `cin >> v[i]`** → crash! Precisa `vector<int> v(n)`
  antes de indexar (ou push_back). Pegou 2x no mesmo dia (A3 e A5, 2026-07-05).
  NOVO bug recorrente — reforçar até fixar.
- **Índice fora do vetor** (`v[i+1]` no último, `v[1]` com n=1) — recorrente.
  (No recall 2026-07-05 acertou a REGRA; manter reforçando na prática.)
- **`<` vs `<=` (borda inclusiva)** — acertou no A2 mas errou no A7 no MESMO dia.
  Ainda instável em contexto. Reforçar.
- **Ler o enunciado com atenção** (A7: pediu CONTAGEM, ele deu SOMA).
- **Variável não-inicializada** (`int cont;` → lixo).

🟡 INSTÁVEL (melhorando — confirmar na prática):
- **Overflow → `long long`**: acertou de cabeça no recall (2026-07-05),
  incluindo o limite ~2,1e9 do int. Melhorou de 🔴 para 🟡. Confirmar em
  código nas próximas sessões antes de dar 🟢.
- **Comparação encadeada `a<b<c`**: explicou perfeitamente no recall
  (vira `(a<b)<c`, usar `&&`). Subiu de 🔴 para 🟡. Confirmar em código.
- Recursão que DECIDE (`||`) × CONTA (`+`) — confundiu 1x.
- Tratar tamanho ímpar / usar `size()` atual, não `n` fixo.
- Casos de borda inclusivos (`<=` vs `<`).

🟢 VAI BEM (pode avançar, repetir menos):
- Leitura/IO, vector dinâmico, laços básicos, sort, MDC/Euclides (acertou
  implementando na mão E de cabeça no recall), simulação (resolveu o
  DinoVoice ~1000!). Definição de recursão (caso base + recursivo) — recall OK.
- **GULOSO**: descreveu a ideia no recall, resolveu A7/A8/G1 e implementou o
  ACTIVITY SELECTION sozinho (H1, AC de primeira após estudar a teoria!).
  Paradigma que faltava — AGORA ele tem. Subiu de ⬜ para 🟢.
- **`vector<pair>` + `sort` + structured binding** `for(auto&[a,b]:v)`:
  implementou o H1 corretamente. Sabe a distinção pair×map (ordenar lista ×
  buscar por chave). Era 🔴 no G2, virou 🟢 no H1.

⬜ NÃO VIU AINDA (buracos a preencher — vários são cobrados em CF 800!):
- **Algoritmo GULOSO** (crítico! cobrado em muitos 800 — ver Módulo 5.6).
- **BITS / binário** (pedido do aluno — Módulo 5.5).
- Dois ponteiros como técnica consciente, força bruta inteligente, `set`,
  grafos, DP.

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
- [x] **MDC (Euclides)** — feito no `contests/udesc-2026-1` G/Gondwana (AC). Aluno
      implementou `mdc(a,b)=mdc(b,a%b)` recursivo na mão; usou para simplificar
      fração `P/100` → denominador irredutível. 1x.
- [ ] MMC; aritmética modular
- [ ] Crivo de Eratóstenes, primalidade
- [ ] Exponenciação rápida; noções de combinatória
- [x] **Overflow: quando usar `long long`** — reforçado MUITO (M1,M3,M4 pegaram
      3x: soma acumulada; popcount: multiplicação `pego*custo`). Ainda não é
      reflexo — CONTINUAR reforçando.
Prática: problemas de teoria dos números de olimpíadas.
NOTA: extração de dígitos/paridade vistos 1x — revisitar bastante.

---

## MÓDULO 5.5 — Representação BINÁRIA e BITS ⬜ (PEDIDO DO ALUNO — prioritário)

⚠️ Aluno pediu explicitamente (2026-07-04) para colocar "entender bits" no
plano. Ele NÃO domina binário ainda — travou no problema popcount (Codeforces)
justamente por isso. Ensinar do ZERO, bem devagar, com muitos exemplos.
- [ ] O que é base 2: como um número vira 0s e 1s (contar em binário)
- [ ] Converter decimal↔binário na mão; peso de cada posição (1,2,4,8,...)
- [ ] Bit "ligado/desligado"; `popcount` (quantos bits 1)
- [ ] Operadores bit a bit: `&` (E), `|` (OU), `^` (XOR), `~`, `<<`, `>>`
- [ ] Truques comuns: `x & 1` (par/ímpar), `x << 1` (dobrar), `x >> 1` (metade),
      testar/ligar/desligar um bit, `x & (x-1)` (tira o último bit 1)
- [ ] `__builtin_popcount`, `__builtin_clz` (ferramentas prontas)
Prática: exercícios pequenos SÓ de manipular bits, antes de qualquer problema
que dependa disso. Depois, revisitar o popcount (Codeforces) que ficou pendente.
Material: criar um `teoria_bits.cpp` com exemplos rodados.

---

## MÓDULO 5.6 — Algoritmo GULOSO (Greedy) 🔁 INTRODUZIDO 2026-07-05

STATUS: introduzido com sucesso! Aquecimento (8 AC) + conceito formal +
2 problemas. O aluno JÁ tinha a intuição (descreveu no recall). Fixado:
- Esqueleto do guloso: ORDENAR + VARRER uma vez = O(N log N).
- Guloso NEM SEMPRE da o otimo (provado com moedas {1,3,4}, troco 6:
  guloso=3, otimo=2). Desconfiar; na duvida testar vs forca bruta.
- G1 (menor tempo espera): AC — soma corrente com 2 acumuladores empilhados
  (acumular+=t; total+=acumular). Aluno travou na LOGICA do acumulado,
  destravou. Overflow pegou de novo (→ long long).
- G2 (activity selection): estudado como referencia. Licoes: map ≠ vector+sort
  (map=buscar por chave; ordenar lista=vector+sort); manter dados da mesma
  entidade JUNTOS num pair (nao ordenar campos separados!); ordenar pelo FIM;
  comparar com ultima ESCOLHIDA, nao vizinho. Retomar G2 para ele implementar.
Continuar com mais gulosos (Codeforces 800-1000). PENDENTE ainda: popcount
(guloso+bits) — falta o modulo de BITS (5.5).

⭐ COMEÇAR POR AQUI na próxima sessão. Motivo: guloso é cobrado em MUITOS
problemas Codeforces 800 (o piso!), e a ausência dele fez o aluno travar num
800 e se desmotivar (achou que estava "muito atrás" — não está; faltava ESTE
paradigma). Falha de planejamento minha (Claude) não ter posto antes. É o
maior "buraco" que separa o aluno de resolver 800 sozinho.

⚠️ Aluno pediu (2026-07-04) para adicionar. É um paradigma novo — ensinar a
IDEIA antes de aplicar. O popcount é guloso (pegar bits baratos primeiro), por
isso ficou difícil sem essa base.
- [ ] Ideia: a cada passo, escolher a opção localmente melhor (sem voltar atrás)
- [ ] Quando funciona e quando NÃO funciona (guloso nem sempre dá o ótimo!)
- [ ] Clássicos didáticos: troco com moedas, atividades que não conflitam,
      "pegar o mais barato/valioso primeiro" (ordenar + varrer)
- [ ] Contraste guloso × backtracking × DP (quando cada um serve)
Prática: problemas gulosos simples com prova de que a escolha gulosa é ótima.
PENDENTE por causa disso: `codeforces/popcount.cpp` (guloso por camadas de
bits) — retomar DEPOIS de bits + guloso.

---

## MÓDULO 6 — Recursão e Backtracking 🔁

Teoria: pensar recursivamente; explorar todas as possibilidades.
- [x] Recursão (caso base + caso recursivo, pilha de chamadas) — 5x
      Aquecimento `aquecimentos/aquecimento_recursao.cpp` (R1-R5), todos AC:
      R1 soma, R2 potencia, R3 somaDig, R4 contarParaBaixo, R5 fibonacci.
      Lições fixadas: caso base ALCANÇÁVEL (= menor valor válido, senão
      recursão infinita → stack overflow); caso base `void` NÃO imprime, só
      para; imprimir antes×depois da chamada muda a ordem (descida×volta);
      fib ingênuo é exponencial (2ⁿ) → semente da DP/memoização.
- [x] Backtracking (árvore incluir/não-incluir) — subconjuntos.cpp (SIM/NÃO),
      contar_subconjuntos.cpp (contagem, AC). Lição: DECIDE→`||`, CONTA→soma.
Prática: gerar combinações, resolver labirintos simples.

---

## MÓDULO 6.5 — Memória dinâmica e Arquivos ✅ (feito, revisitar)

Temas que o aluno viu em C e reaprendeu do jeito C++ idiomático.
Pasta `05-memoria-arquivos/` (aquecimento em `aquecimentos/aquecimento_memoria.cpp`).
- [x] Alocação de memória: malloc/free (C) vs new/delete vs **vector** (use!)
- [x] `vector<int> v(n)` (1D) e `vector<vector<int>> m(l, vector<int>(c))` (2D)
- [x] Arquivos: `ofstream` (=cout de arquivo), `ifstream` (=cin de arquivo)
- [x] `while(fin>>x)` (ler até o fim), `if(!fin){...return;}` (tratar falha)
- [x] Processar "em fluxo" (ler e já somar) → memória O(1) em vez de O(N)
Aquecimento M1-M5, todos AC. REFORÇO CRÍTICO: overflow pegou o aluno 3x
seguidas (soma acumulada precisa `long long`) — ainda não é reflexo.

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
- Módulo 6: 🔁 recursão introduzida (5 aquecimentos AC); falta backtracking
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
