# Plano de Estudo — Programação Competitiva

Objetivo: preparar o Paulo para competições (OBI, maratonas, ICPC), cobrindo
estruturas de dados E **paradigmas de resolução** (guloso, dois ponteiros,
força bruta, backtracking, DP...). Meta prática: resolver Codeforces 800 com
autonomia e subir a partir daí. O aluno resolve; o Claude é juiz.

---

# 🗓️ RITMO: **UM CONCEITO NOVO POR SEMANA** (decidido 2026-07-14)

⚠️ **REGRA Nº 1 PARA O CLAUDE — LER NO INÍCIO DE TODA SESSÃO:**
> **Verifique a DATA DE HOJE e descubra em que SEMANA do calendário abaixo
> estamos. Trabalhe o conceito DAQUELA semana. NÃO introduza conceito novo
> antes do fim da semana.**


Ele estava certo. Entre 08/07 e 14/07 recebeu: dois ponteiros, janela
deslizante, prefix sum, `lower_bound`, grafos... Conceito empilhado em conceito
não vira reflexo, vira confusão. **Menos assunto, mais repetição.**

## Como é uma SEMANA (não um dia)

| Dia | O que acontece |
|-----|----------------|
| **Dia 1** | Recall + 8 aquecimentos de REVISÃO + apresentação do conceito da semana (teoria + 2 exercícios simples) |
| **Dias 2-4** | Recall + 8 aquecimentos (**metade** revisão espaçada, **metade** o conceito da semana) + 2 problemas do conceito, subindo a dificuldade |
| **Dia 5** | **Problema REAL do Codeforces** (rating 800-1000) usando o conceito. Sem dica. |
| **Dia 6** | **Prova de fixação:** refazer, do zero, os exercícios que ele NÃO acertou de primeira na semana. Meta: acertar de primeira agora. |
| **Dia 7** | Fecha a semana. Atualizar painel. Só avança se o conceito estiver 🟢. |

**Só avança de semana se o conceito da semana estiver 🟢** (acertou de
primeira, sem dica, em pelo menos 2 exercícios diferentes). Se não estiver,
**a semana se estende**. Ver a régua em "ACERTAR DE PRIMEIRA" no CLAUDE.md.

## Estrutura de um DIA (mantida — mínimo 10 exercícios)

1. **RECALL (6 perguntas, oral):** conceitos já vistos, priorizando os 🔴.
   Inclui o **pré-flight verbal** dos conceitos em fixação.
2. **AQUECIMENTO — 8 exercícios:** 6 de revisão espaçada (os 🔴!) + 2 que
   preparam/aplicam o conceito da semana.
3. **CONCEITO DA SEMANA — 2 exercícios.**

---

# 📅 CALENDÁRIO DE SEMANAS

## ✅ Semanas passadas (retroativo)
- **Sem. 1** (~30/06–06/07): fundamentos, recursão, memória/arquivos, **GULOSO**
- **Sem. 2** (07/07–13/07): **DOIS PONTEIROS** (pontas + janela deslizante) +
  prefix sum + busca binária. Fechou com CF 279B (rating 900) AC. 🏆

> ## 🎯 A META DE JULHO (nas palavras do aluno, 2026-07-14)
>
> *"Se eu sair de julho sabendo bem tudo que vimos até aqui, principalmente
> **busca binária, guloso e grafos 1**, vou me sentir realizado."*
>
> **São muitos conceitos para ver — por isso o plano é RESTRITO a isto.**
> Nada de conteúdo novo fora deste roteiro até agosto.

## 🔄 **SEMANA 3 — 14/07 a 20/07: REVISITAR TUDO** ⬅️ ESTAMOS AQUI

**ZERO conceito novo.** A semana inteira é revisão do que já foi visto.
*"Essa semana vamos revisitar tudo que vimos até aqui."*

### 📋 INVENTÁRIO — TUDO QUE JÁ VIMOS (a lista da revisão)

**ESTRUTURAS DE DADOS**
- [ ] **vector** — `v(n)` × `push_back` (**exclusivos, não misturar!**),
      `.size()`, `vector<int> v;` vazio + `cin>>v[i]` = **CRASH** (pegou 2x)
- [ ] **string** — é um vetor de char; `s[i]`, `s.size()`.
      ⚠️ `s[s.size()]` devolve `'\0'` e **não crasha** (erro silencioso!)
- [ ] **pair** — `.first`/`.second`; `vector<pair>` + `sort` (ordena pelo
      `.first`, desempata pelo `.second`); structured binding `auto&[a,b]`
- [ ] **matriz 2D** — `vector<vector<T>>(l, vector<T>(c))`; `[i][j]`;
      `.size()` (linhas) × `[0].size()` (colunas); os 4 vizinhos;
      matriz de char / `vector<string>`
- [ ] **map** — chave→valor; `m[k]++`; iterar (vem **ORDENADO** por chave);
      `count`/`find`. **`map` × `vector`: chave × índice — quando usar cada um**
- [ ] **set** — dedup, "já vi isso?", ordenado. `set` × `map` × `vector`
- [ ] **stack** — LIFO; `push`/`top`/`pop`/`empty`; só mexer com `!empty()`;
      casamento de parênteses
- [ ] **queue** (fila) — FIFO; `push`/`front`/`pop`. **É a base do BFS!**
- [ ] **array de contagem** — o "map dos pobres" quando a chave é pequena

**PARADIGMAS / TÉCNICAS** (o que mais importa)
- [ ] 🎯 **BUSCA BINÁRIA** — `lo <= hi` (faixa **fechada**!); `meio = lo+(hi-lo)/2`;
      passo `lo=meio+1` / `hi=meio-1` (**metade, nunca `++`/`--`**);
      `lower_bound` na mão (primeira ocorrência com repetidos)
- [ ] 🎯 **GULOSO** — ordenar + varrer 1x, nunca voltar atrás; **nem sempre é
      ótimo!**; activity selection; parar cedo (`else break`)
- [ ] **DOIS PONTEIROS (pontas)** — `esq=0`, `dir=n-1`, `while(esq<dir)`;
      **UM ponteiro por vez**; contar em BLOCO (`cont += dir-esq`)
- [ ] **JANELA DESLIZANTE** — ponteiros na mesma direção; cresce `dir`, encolhe
      `esq` **quando ESTOUROU**; é O(N) porque `esq` nunca retrocede
- [ ] **PREFIX SUM** — `pre[R+1] - pre[L]`; `pre` tem **n+1** posições;
      `pre[0]=0`; **`vector<long long>`!**
- [ ] **RECURSÃO** — caso base ALCANÇÁVEL + caso recursivo; pilha de chamadas
- [ ] **BACKTRACKING** — árvore incluir/não-incluir; DECIDE→`||`, CONTA→soma
- [ ] **SIMULAÇÃO** — estado que evolui; usar `size()` ATUAL, não `n` fixo
- [ ] **ORDENAÇÃO** — `sort`; decrescente (sinal ou lambda); comparador lambda

**FUNDAMENTOS QUE AINDA ERRA (os 🔴)**
- [ ] ⚠️ **OVERFLOW → `long long`** — a pergunta é **"ONDE A CONTA EXPLODE?"**,
      não "onde eu guardo". Cast num **OPERANDO** (`(long long)(a+b)*c`), nunca
      no resultado. Melhor: `vector<long long>` **na origem**
- [ ] ⚠️ **LER OS WARNINGS** (`-Wall` aponta o bug exato — ignorou 6x!).
      Mas: compilação limpa é o **PISO**, não a garantia (não pega `cout` faltando)
- [ ] ⚠️ **`<` vs `<=`** (borda inclusiva) — errou 5x
- [ ] ⚠️ **ÍNDICE × VALOR** (`v[meio]`, não `meio`)
- [ ] **sentinela impossível** (`-1`, `INT_MIN`) — `0` é índice VÁLIDO!
- [ ] **`=` vs `==`** e **`=` vs `+=`** (o `-Wall` não pega o segundo)
- [ ] **a TÉCNICA já é o laço** — não aninhar num `for` externo
- [ ] **"o que este problema me PROÍBE de fazer?"** (o `sort` que matou o D1)

### 🔥 PRIORIDADE MÁXIMA DA SEMANA
Os **3 que ele fechou em 2-3 rodadas** (não de primeira) em 14/07 — martelar
até saírem **DE PRIMEIRA**:
1. **busca binária / `lower_bound`** (os 4 bugs voltaram 1 dia depois!)
2. **janela deslizante** (sinal do `while` invertido → crash)
3. **dois ponteiros contando em bloco** (moveu os 2 ponteiros no mesmo passo)

## ⬜ SEMANA 4 — 21/07 a 27/07: **GRAFOS parte 1 — BFS/DFS**

O ÚNICO conceito novo do mês. (Adiado de propósito: ele precisa de matriz e
fila firmes ANTES. O `revisoes/2026-07-14_revisao_C1-C8_janela_buscabin_matriz_fila.cpp` (C5-C8) já está
pronto e serve de ponte: matriz 2D → 4 vizinhos → fila → visitados.)

- [ ] Representação: **grade 2D** (labirinto) e **lista de adjacência**
- [ ] **BFS** (fila) — menor caminho em grade, número de passos
- [ ] **DFS** (recursão/pilha) — componentes conexas, contar ilhas
- [ ] **Vetor de VISITADOS** — é o que impede o algoritmo de girar em círculos
      para sempre. Sem ele, o algoritmo NÃO TERMINA.
- [ ] ⚠️ A lição conceitual: em labirinto **não se ESCOLHE um caminho** (guloso
      quebra!) — **se ESPALHA** por todos. "Quais células eu ALCANÇO?"
- [ ] Problema real: contar ilhas / menor caminho em labirinto

## ⬜ SEMANA 5 — 28/07 a 31/07 (última de julho): **GRAFOS FORTE + REVISÃO**

**Fecha o mês.** Sem conceito novo — aprofundar grafos e revisitar TUDO.

- [ ] **Grafos mais forte**: mais problemas de BFS/DFS, variações
      (grade com pesos? múltiplas origens? contar componentes?)
- [ ] **Revisitar tudo do inventário acima**, com ênfase nos 3 da meta:
      **busca binária · guloso · grafos 1**
- [ ] **Prova de fixação:** refazer do zero o que ele não acertou de primeira
      ao longo do mês
- [ ] Fechar julho com a meta batida: *"saber bem tudo que vimos até aqui"*


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

## 🔁 PEDIDO EXPLÍCITO DO ALUNO (2026-07-14) — REFAZER ATÉ ACERTAR DE PRIMEIRA


**A meta dele NÃO é "chegar no AC". É "acertar de PRIMEIRA, sem dica."**
Enquanto precisar de 2-3 rodadas, o conceito NÃO está fixado — mesmo que o
veredito final seja AC. Respeitar isso: é autoconhecimento correto.

### 🎯 OS 3 CONCEITOS A MARTELAR (incluir em TODO aquecimento até virar reflexo)

| Conceito | Reps | Erro recorrente dele |
|----------|------|----------------------|
| **1. Janela deslizante** (ponteiros na mesma direção) | 2 | sinal do `while` INVERTIDO (`soma < t` em vez de `> t`) → o `esq` estoura o vetor e CRASHA. Verbalizar antes: *"quando eu preciso encolher?" → "quando ESTOUROU"* |
| **2. Dois ponteiros nas pontas (CONTAR em bloco)** | 7 | mover os DOIS ponteiros no mesmo passo (`dir--` fora do `else`) → mata rápido demais e perde pares. Regra: **UM ponteiro por vez, sempre** |
| **3. Busca binária / `lower_bound`** | 4 | REGREDIU nos 4 detalhes que ele acertara 1 dia antes: `dir--` em vez de `dir=meio-1` (vira O(N), 7,2s → TLE!); `while(esq<dir)` em vez de `<=`; sentinela `0` em vez de `-1`; `break` ao achar (perde a PRIMEIRA ocorrência) |

⚠️ **O C3 é o alerta mais importante do dia:** os 4 bugs dele foram os MESMOS
que o aluno resolveu em 2026-07-13 (B1 e B3) — e que ele EXPLICOU CORRETAMENTE
no recall verbal de hoje. Um dia depois, sem revisar, os 4 voltaram.
→ Prova viva de que **acertar 1x não fixa**. É a repetição espaçada dando o
  recado. NÃO tratar nada como "dominado" (regra do CLAUDE.md).

### 📋 COMO CONDUZIR OS PRÓXIMOS AQUECIMENTOS

1. **Todo aquecimento deve conter os 3 acima**, em roupagens diferentes, até
   ele acertar CADA UM **de primeira, sem dica, 3 sessões seguidas**.
2. Só então marcar 🟢 e reduzir a frequência.
3. Variar o disfarce (é o ponto da repetição espaçada): a janela pode ser
   "maior trecho com soma <= T", "menor trecho com soma >= T", "trecho com no
   máximo K distintos"; a busca binária pode ser `lower_bound`, `upper_bound`,
   "primeiro elemento >= X", "binary search na RESPOSTA".
4. **Pré-flight verbal** (30 segundos, antes de codar): fazer ele responder
   - "quando eu encolho a janela?" → *quando ESTOUROU*
   - "quantos ponteiros eu movo por iteração?" → *UM*
   - "qual o passo da busca binária?" → *meio ± 1, nunca ++/--*
   - "o intervalo é fechado? então o while é..." → *`<=`*
   - "meu sentinela pode colidir com uma resposta válida?" → *0 é índice válido!*

---

## PAINEL DE DESEMPENHO (atualizado 2026-07-13)

### 🏆 SESSÃO 2026-07-13 — **10/10 AC** (leia ANTES de montar o próximo dia)

Arquivos: `revisoes/2026-07-13_dois_ponteiros_B1-B8.cpp` (B1-B8) e
`08-dois-ponteiros/teoria_dois_ponteiros_e_janela.cpp` (D1-D2).

**MARCO: resolveu o Codeforces 279B "Books" (rating 900).** Em 2026-07-04 ele
se assustou achando que não resolveria um 800. Stress-testado contra força
bruta (500 casos, 0 falhas; 25ms com N=1e5). O D2 (botes) foi validado contra
força bruta ÓTIMA (400 casos, 0 falhas) — o guloso dele **É** ótimo.
Refez e fechou B1 (busca binária) e B2 (prefix sum), que falharam em 07-08.

**O FIO CONDUTOR FECHOU** (era o objetivo pedagógico). Ele fez as 3 variantes:
- **B8** — ponteiros nas PONTAS, vindo ao encontro (ordenação descarta pares).
- **D1** — JANELA DESLIZANTE, ponteiros na MESMA direção (valores positivos ⇒
  soma monotônica ⇒ o `dir` nunca volta). É O(N) apesar dos 2 laços aninhados:
  `esq` nunca retrocede, então o `while` interno roda ≤N vezes SOMADAS.
- **D2** — PONTAS + GULOSO juntos. Fecha o círculo: **guloso e dois ponteiros
  são a mesma coisa** — o guloso DECIDE ("o par da mais pesada só pode ser a
  mais leve"), os dois ponteiros EXECUTAM em O(N).

### 🔴 O ERRO MAIS VALIOSO DO DIA: "a ferramenta veio antes da leitura"

- **D1 (1ª tentativa):** aplicou `sort` + guloso — o molde do B7, que ele
  acabara de resolver — e ATROPELOU a restrição *"lê em SEQUÊNCIA, sem pular"*.
  `sort` embaralha a pilha de livros → resolve OUTRO problema.
- **D2 (1ª tentativa):** pôs um `for(i)` externo EM VOLTA dos dois ponteiros
  (a técnica JÁ é o laço) → contou os botes N vezes.

Causa comum: ele **reconheceu o padrão rápido demais** e o padrão disparou
antes de a leitura terminar. Ter repertório é bom E perigoso.
→ **A PERGUNTA QUE SALVA: "o que este problema me PROÍBE de fazer?"**
→ Quando ele lê para CONFERIR, acerta (caçou 2 erros MEUS nos enunciados hoje).
  Quando lê para RECONHECER UM PADRÃO, atropela.

### 🔴 OVERFLOW TEM UMA RAIZ SÓ (pegou 3x hoje: B2, B4, B8)

Ele põe `long long` no **DESTINO** e deixa `int` **ONDE A CONTA ACONTECE**:
- B2: `long long soma = pre[r+1]-pre[l]` — mas `pre` era `vector<int>`; estourou
  ao ENCHER o `pre`, antes de qualquer consulta.
- B4: `(long long)((a+b)*(b-a+1)/2)` — o cast engloba o RESULTADO. A conta já
  estourou dentro do parêntese. Certo: `(long long)(a+b) * (b-a+1) / 2`
  (**o cast tem que tocar um OPERANDO**).
- B8: `int soma = vetor[esq] + vetor[dir]` com `vector<int>`.

→ **A pergunta certa NÃO é "onde eu guardo?", é "ONDE A CONTA EXPLODE?"**
→ Em B6 e na correção do B8 ele achou sozinho a solução certa: declarar o
  **contêiner** como `vector<long long>` — resolve na ORIGEM, sem cast nenhum.
→ **PEDIDO EXPLÍCITO DELE (2026-07-13): "tenho o hábito de usar int, me cobre
  mais disso."** Regra a martelar: **limites perto de 1e9 → `long long` já no
  `cin`/no `vector`.** Não analisar caso a caso se sobrevive.

### 🚨 WARNINGS — ELE PEDIU PARA SER CRITICADO (2026-07-13)

Palavras dele: *"tenho o mau hábito de te pedir para verificar sem rodar o
`-Wall`; se isso acontecer e você pegar um warning, me avise e me critique,
porque preciso quebrar esse hábito."*
→ **CUMPRIR:** se ele pedir "verifique" e o `-Wall` acusar, **NÃO JULGAR** o
  exercício — parar e cobrar. Aconteceu 2x no B5 (5ª e 6ª vez no total).
→ FUNCIONOU: depois disso, B6/B7/B8/D1/D2 vieram TODOS com compilação limpa.
⚠️ MAS ensinar também: **compilação limpa é o PISO, não a garantia.** B7 e D1
  compilaram limpos e não tinham `cout` — o `-Wall` não pega isso (a variável
  É usada, no `++`). Sempre rodar os exemplos do enunciado.

### 🟢 SUBIRAM PARA 🟢 EM 2026-07-13

- **ÍNDICE × VALOR** — era o 🔴 nº1 do painel. AC em B1, B3 e B5. **MORTO.**
- **Busca binária** — `lo=meio+1`/`hi=meio-1`, `lo+(hi-lo)/2`, `break` ao achar.
  B1 saiu **de primeira, zero warnings**. Ele também explicou POR QUE o while é
  `lo <= hi` e não `<`: a faixa é FECHADA, e uma faixa de 1 elemento
  (`lo==hi`) ainda é candidata — toda busca binária termina nela.
- **PREFIX SUM** — no recall verbal deu a melhor resposta do dia (tamanho n+1,
  `pre[0]=0`, a construção e o PORQUÊ da posição extra). AC no B2.
- **Swap de 3 linhas**, **guloso com parada antecipada** (`else break`).

### 🟡 AINDA INSTÁVEL

- **`<` vs `<=` (borda inclusiva)** — errou no B7 (`produto < dinheiro`; com
  R$10 e item de R$10, dá pra comprar!), mas ACERTOU de primeira no B4 e no D1
  (`soma > t`, não `>=`). Melhorou, não firmou. 5ª aparição.
- **Esquecer o `cout`** — 2x hoje (B7, D1). Calcula certo e não imprime.

---

### 🎯 DIAGNÓSTICO DA SESSÃO 2026-07-08 (histórico)

Placar do aquecimento: **6 AC / 2 erros** (A7 e A8).

**A DESCOBERTA MAIS IMPORTANTE DO DIA:** o aluno **acerta a MODELAGEM e erra a
MECÂNICA DO LAÇO**. Dos 5 erros do dia, **4 foram "o laço"**, nenhum foi "não
sei o que fazer". Isso é BOA notícia: mecânica se conserta com repetição;
modelagem é o difícil e ele TEM. Nunca deixar ele achar que "não sabe pensar".

Os erros, agrupados pela CAUSA REAL (não pelo sintoma):

1. **Não checou o SIGNIFICADO da variável antes de usar.**
   - A7: comparou `meio` (POSIÇÃO) com `alvo` (VALOR). Faltou `vetor[meio]`.
   - A8: usou `pares(n)` quando eram `q` consultas (n=tamanho, q=nº consultas).
   → EXERCÍCIO PRESCRITO: antes de escrever qualquer comparação, dizer em voz
     alta "isto é uma POSIÇÃO ou um VALOR?".

2. **IGNOROU OS WARNINGS DO COMPILADOR — 3x no mesmo dia.**
   - A5: `warning: 'palindrome' set but not used` → esqueceu o `cout`.
   - A6: `warning: unused variable 'temp'` → o swap estava quebrado.
   - A8: `warning: statement has no effect` em `for(l; l<r; l++)`.
   Nos TRÊS casos o `-Wall` apontou o bug exato e ele não leu.
   → REGRA NOVA A MARTELAR: **"warning é teste falhando"**. Se compilou com
     warning, o exercício NÃO terminou. Cobrar isso ANTES de julgar.

### 🔴 ERRA MUITO (reforçar de propósito, NÃO avançar)

- **⚠️ IGNORAR WARNING DO COMPILADOR** — 3x em 2026-07-08 (A5, A6, A8), e nos
  3 o warning apontava o bug exato. É o 🔴 mais barato de matar e o de maior
  retorno. Exigir compilação limpa como pré-requisito para ser julgado.
- **ÍNDICE × VALOR (confundir posição com conteúdo)** — NOVO, 2026-07-08.
  A7: `if(meio < alvo)` em vez de `if(vetor[meio] < alvo)`. Parente do
  "for-range dá VALOR, não índice". Reintroduzir SEMPRE.
- **`<` vs `<=` (borda inclusiva)** — 3ª vez! (B Braquiossauro, A7 do guloso,
  A8 de 2026-07-08: pediu `v[L..R]` inclusive, ele fez `l < r`). NÃO avança.
- **Ler o enunciado com atenção** — A7 de 2026-07-08: enunciado dizia
  "BUSCA BINÁRIA na mão", ele entregou busca linear (saída certa, algoritmo
  errado → TLE num juiz real). Antes: A7 do guloso (pediu contagem, deu soma).
- **Busca binária: o passo é `lo=meio+1`/`hi=meio-1`, NÃO `lo++`/`hi--`**
  (descartar METADE, não um elemento). NOVO, 2026-07-08 — ele fez `hi--`,
  virou busca linear disfarçada em O(N). Também esqueceu o `break` ao achar.
- **`vector<int> v;` VAZIO + `cin >> v[i]`** → crash. (Pegou 2x em 2026-07-05.)
  NÃO reapareceu em 2026-07-08 — mas manter em observação (não confirmado).
- **`push_back` × `v(n)`: caminhos EXCLUSIVOS, não misturar** — NOVO,
  2026-07-08 (A4: `lista(produtos.size())` + `push_back`). Ou dimensiona e
  escreve por índice, ou começa vazio e cresce.
- **`for-range` JÁ é o laço; não aninhar com índice** — NOVO, 2026-07-08 (A4:
  `for(i...){ for(auto& par : m) lista[i]=... }` → O(N²) e errado).
- **Variável não-inicializada** (`int cont;` → lixo).

### 🟡 INSTÁVEL (melhorando — confirmar na prática)

- **Índice fora do vetor** — em 2026-07-08 acertou o A2 (limite `n-1` no laço
  certo) mas errou o A5 na 1ª tentativa (`s = size()` em vez de `size()-1`).
  Subiu de 🔴 para 🟡. Cuidado: em `string`, ler `s[size()]` devolve `'\0'` e
  NÃO crasha (o sanitizer não acusa!) — erro silencioso. Em `vector`, crasha.
- **`i + 1 < n` é mais seguro que `i < n-1`** — se `n` for `size_t` (ex.:
  `v.size()`), `n-1` com `n==0` vira número GIGANTE (não -1). Ensinado
  2026-07-08, ainda não praticado.
- **Comparação encadeada `a<b<c`** — explicou no recall; confirmar em código.
- Recursão que DECIDE (`||`) × CONTA (`+`) — confundiu 1x.
- Tratar tamanho ímpar / usar `size()` atual, não `n` fixo.
- **NÃO modificar a variável do `for-range` por referência** (`for(auto&[l,r]`
  + `l++` corrompe o vetor). NOVO 2026-07-08 (A8), bomba-relógio.
- **`map` × `vector<pair>`**: no recall verbal de 2026-07-08 REGREDIU
  ("map é para usar índice" — errado; `vector` usa índice, `map` usa CHAVE).
  Mas ACERTOU a arquitetura no A4 (map acumula por chave → vector<pair>
  ordena por valor). Sabe fazer, não sabe VERBALIZAR. Cobrar a definição.

### 🟢 VAI BEM (pode avançar, repetir menos)

- **OVERFLOW → `long long`** — SUBIU de 🟡 para 🟢 em 2026-07-08. Acertou as
  DUAS naturezas sem eu avisar: (a) A1, soma acumulada; (b) A3, multiplicação
  `(long long)a * b` (o cast ANTES da conta). Vocabulário ainda a polir: é
  **overflow SILENCIOSO** (compila, roda, número errado), não "dá erro". 7ª rep.
- **Limite de laço com vizinhos** (`i < n-1` para comparar `v[i]` e `v[i+1]`)
  — A2 AC com todas as bordas (N=1). Subiu de 🔴 para 🟢.
- **DOIS PONTEIROS (mecânica)** — A5 (palíndromo) e A6 (inverter no lugar):
  AC de primeira, **zero warnings**, bordas certas (n=1, n par).
  `esq=0`, `dir=size()-1`, `while(esq<dir)`, ambos se movem. Sabe o esqueleto!
  ⚠️ MAS: ainda não vê que é UMA IDEIA SÓ (ver "conceito novo" abaixo).
- Leitura/IO, vector dinâmico, laços básicos, sort, MDC/Euclides, simulação
  (DinoVoice ~1000), recursão (caso base + recursivo).
- **GULOSO** (activity selection sozinho, H1 AC de primeira). 🟢
- **`vector<pair>` + `sort` + structured binding** `for(auto&[a,b]:v)`. 🟢
- **`break` ao achar** — usa por reflexo em laço de varredura. (Esqueceu na
  busca binária, onde a estrutura muda.)

### ✅ INTRODUZIDO EM 2026-07-08 (1ª vez — precisa de MUITA repetição)

- **`sort` decrescente**: `sort` só sabe SUBIR. Para descer: (a) truque do
  SINAL — guardar `-qtd` (só funciona com NÚMEROS); ou (b) COMPARADOR lambda
  (ferramenta geral, funciona com string). Preenche o item "ordenar por
  comparador custom (lambda)" do Módulo 3.
- **Lambda como comparador** — `sort(v.begin(), v.end(), [](const T& a, const
  T& b){ ... });`
- **PREFIX SUM (soma de prefixos)** — `pre[i]` = soma dos `i` PRIMEIROS =
  soma de `v[0..i-1]` ("tudo ANTES da posição i"). `pre` tem **n+1** posições,
  `pre[0]=0`. Consulta: **`soma(L..R) = pre[R+1] - pre[L]`** em O(1).
  O `R+1` resolve o intervalo inclusivo de graça. `vector<long long>`!
  Custo O(N+Q) em vez de O(N·Q). Aluno NÃO entendeu sozinho; pediu o algoritmo
  ótimo — está em `revisoes/2026-07-08_dois_ponteiros_A1-A8.cpp` (`A8_otima`),
  validado: 0,17s vs 1,40s da ingênua com N=Q=1e5, respostas idênticas.

### 🎓 CONCEITO NOVO — DOIS PONTEIROS (a fazer em 2026-07-09)

O aluno tem a MECÂNICA (A5, A6 AC) mas não o CONCEITO. No recall de
2026-07-08, perguntado "vetor ORDENADO, existem dois elementos que somam X?",
ele descreveu **força bruta O(N²)** — jogou fora a informação de que o vetor
está ordenado. É EXATAMENTE o buraco a preencher.

A ideia a ensinar (o "porquê", não o código):
  esq=0, dir=n-1. soma = v[esq]+v[dir].
  soma < X → precisa AUMENTAR → esq++   (v[dir] já é o maior disponível)
  soma > X → precisa DIMINUIR → dir--
  Prova do descarte: se v[esq]+v[dir] < X, então v[esq] + (qualquer coisa
  entre esq e dir) também é < X. Logo v[esq] NUNCA formará par → descarto ele
  inteiro, **N-1 pares de uma vez**. Cada passo mata um elemento → O(N).

⚠️ FIO CONDUTOR A EXPLICITAR (o aluno ainda NÃO vê): A6 (ponteiros nas pontas),
A7 (busca binária = descartar metade), A8 (prefix sum = pré-calcular) e o
GULOSO são **A MESMA IDEIA**: *usar a ESTRUTURA do problema (ordenação,
monotonicidade) para descartar em BLOCO, em vez de testar tudo*. Amarrar isso
explicitamente é o objetivo pedagógico de amanhã.

### ✅ PLANO DE 2026-07-09 — **CUMPRIDO EM 2026-07-13, 10/10 AC**

Tudo o que estava planejado foi feito: recall de 6 perguntas, refazer A7/A8
(viraram B1/B2, ambos AC), 8 aquecimentos com ênfase nos 🔴, e o conceito novo
(dois ponteiros) com 2 problemas — incluindo o **CF 279B, rating 900**.
O FIO CONDUTOR foi amarrado explicitamente e o aluno o VIU (ver o painel no
topo deste arquivo). Detalhes completos em CLAUDE.md.

⏸️ PAUSADO por decisão do aluno (2026-07-06):
- **BITS / binário** (Módulo 5.5). Ele vai estudar por fora com um livro; sentiu
  falta de base fundamental nos OPERADORES bit a bit. Não retomar por conta
  própria — esperar ele avisar. Já domina a base intuitiva (%2, /2, converter
  na mão). Ver Módulo 5.5.

⬜ NÃO VIU AINDA (buracos a preencher — vários são cobrados em CF 800!):
- **`set` / `map` como ferramenta consciente** (dedup, "já vi isso?", ordenado).
- **Força bruta inteligente** (quando N é pequeno, testar tudo É a solução).
- **GRAFOS: BFS/DFS** (Módulo 7) — o maior buraco restante. ⭐ PRÓXIMO.
- **DP** (Módulo 8) — depois de grafos.
- ✅ FEITOS: guloso (5.6, 🟢), dois ponteiros nas PONTAS (🟢, 6 reps),
  JANELA DESLIZANTE (D1, 1 rep — precisa de mais), busca binária (🟢),
  prefix sum (2 reps).

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

## MÓDULO 5.5 — Representação BINÁRIA e BITS ⏸️ PAUSADO (aluno estuda por fora)

⏸️ STATUS (2026-07-06): o aluno PEDIU PARA PULAR este módulo por ora. Ao chegar
nos OPERADORES de bits (`&`, `|`, `^`, `<<`, `>>`, `x&1`, `x>>1`), sentiu que
faltava BASE fundamental de binário ("está grego") e decidiu estudar por conta
própria, com um LIVRO, no ritmo dele. Decisão madura — respeitar. NÃO retomar
por iniciativa própria; ESPERAR ele sinalizar que estudou e quer voltar.
O que ele JÁ fez sozinho antes de pausar (base intuitiva, tudo AC): par/ímpar
(`%2`), dividir por 2 até ímpar, testar potência de 2, e CONVERTER decimal→
binário na mão (A8). Travou foi nos OPERADORES bit a bit — é aí que ele retoma.
Arquivos: `09-bits-PAUSADO/teoria_bits.cpp` (teoria + B1/B2) ficam prontos para quando
voltar. `codeforces/CF_popcount_PENDENTE_precisa_bits.cpp` segue pendente (depende deste módulo).

⚠️ Aluno pediu (2026-07-04) para colocar "entender bits" no plano. Ensinar do
ZERO, bem devagar, com muitos exemplos, QUANDO ele retomar.
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
PENDENTE por causa disso: `codeforces/CF_popcount_PENDENTE_precisa_bits.cpp` (guloso por camadas de
bits) — retomar DEPOIS de bits + guloso.

---

## MÓDULO 6 — Recursão e Backtracking 🔁

Teoria: pensar recursivamente; explorar todas as possibilidades.
- [x] Recursão (caso base + caso recursivo, pilha de chamadas) — 5x
      Aquecimento `revisoes/2026-07-03_recursao_R1-R5.cpp` (R1-R5), todos AC:
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
Pasta `06-memoria-arquivos/` (aquecimento em `revisoes/2026-07-04_memoria_arquivos_M1-M5.cpp`).
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
