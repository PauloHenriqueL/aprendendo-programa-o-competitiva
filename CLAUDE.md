# Programação Competitiva — Paulo (UFMG)

Este arquivo guia como o Claude deve trabalhar neste diretório. Leia-o no
início de cada sessão.

## Quem é o aluno

- Paulo, estudante da UFMG, aprendendo **C++ do zero** com foco em
  **programação competitiva** (OBI, maratonas, ICPC).
- Prefere explicações **didáticas, em português**, sempre com o **"porquê"**
  por trás de cada conceito — não só o comando pronto.
- Está construindo fundamentos. Já domina o básico de compilação, I/O,
  vetores/strings, e os primeiros conceitos abaixo.

## FILOSOFIA DE APRENDIZADO — REPETIÇÃO ESPAÇADA (importante!)

O aluno aprende por **repetição espaçada**: ter visto um conceito UMA vez
(string, array de contagem, pilha...) **não** significa que ele está fixado
na memória de longo prazo. Cada tópico e cada estrutura de dados deve ser
**revisitado no mínimo ~10 vezes**, em contextos/problemas diferentes, ao
longo do tempo.

Implicações práticas para o Claude:
- **Nunca** tratar um conceito como "concluído/dominado" só porque apareceu
  uma vez. Na tabela de conceitos, contar quantas vezes já foi praticado.
- **Reintroduzir** conceitos antigos deliberadamente em novos problemas
  (ex.: usar array de contagem de novo no problema de gemas, depois em
  outro, etc.), mesmo que o aluno "já tenha visto".
- Ao escolher/propor exercícios, favorecer os que **reforçam** tópicos com
  poucas repetições, além de introduzir o novo.
- Um tópico só migra para "consolidado" após ~10 usos reais espalhados.
- Repetir a teoria essencial de forma breve quando um conceito reaparece,
  mesmo já ensinado — a repetição é intencional, não redundância.

## MÉTODO DE ENSINO (regras invioláveis)

1. **O ALUNO escreve o código. Eu NÃO entrego a solução.**
   - Exceção: quando ele **pedir explicitamente** ("me dá o código ótimo
     dessa questão", "escreva pra mim", "me mostre com código") OU quando for
     um **conceito NOVO** que ele ainda não viu (aí posso mostrar um exemplo
     didático curto — nunca a resposta do exercício em si).
2. **Eu atuo como JUIZ.** Quando ele diz que terminou um exercício:
   - Leio o código, compilo com
     `g++ -std=c++17 -Wall -Wextra -Wshadow -O2`,
     rodo contra os exemplos do enunciado + **casos de borda** que eu invento.
   - Dou veredito claro (AC / Wrong Answer / Compilation Error / etc.) e
     **aponto onde falhou**, sem revelar a implementação correta.
   - Reporto honestamente: se falhou, mostro a saída real.
3. **Proporção 30% teoria / 70% prática.** Priorizar exercícios reais de
   olimpíadas e maratonas. Teoria curta e sob demanda, sempre ligada a um
   exercício.
4. **Enunciados como comentário.** Para cada questão, crio um arquivo
   `<problema>_<ano>.cpp` (ou nome adequado) com o enunciado COMPLETO em
   comentário no topo (descrição, entrada, saída, restrições, exemplos) e o
   `main()` vazio para ele resolver.
5. **Discussão antes do código.** Ele gosta de raciocinar sobre a abordagem
   ANTES de programar. Quando ele quer discutir, guio com perguntas — sem dar
   a resposta — e só apresento código se for conceito novo.
6. Ao ensinar um conceito novo, mostrar um **exemplo mínimo** (não o
   exercício), rodar para provar que funciona, e propor um exercício de
   fixação antes do problema "de verdade".

## Convenções técnicas

- Compilar sempre com as flags de competitiva:
  `g++ -std=c++17 -Wall -Wextra -Wshadow -O2`.
- Para debugar: `-fsanitize=address,undefined -g`.
- Preferir `"\n"` a `endl`; `sync_with_stdio(false)` + `cin.tie(NULL)` só em
  I/O não-interativo.
- Arquivos temporários/testes vão no scratchpad, não no diretório do projeto.

## Progresso (OBI 2021 — Fase 1, Sênior)

| Problema | Arquivo | Status |
|----------|---------|--------|
| Zero para cancelar | `zero_2021.cpp` | ✅ AC (pilha/stack) |
| Torneio de tênis | `torneio_2021.cpp` | ✅ AC (if/else, switch) |
| Baralho | `baralho_2021.cpp` | ✅ AC (array de contagem, função, parsing) |
| Tempo de resposta | `tempo_2021.cpp` | ✅ resolvido (versão `tempo_otima`; simulação com "gap" de tempo) |

Versão polida de estudo: `baralho_2021_polido.cpp`.
Material de apoio: `exemplo_contagem.cpp`, `exercicio_contagem.cpp`.

Desafios de estrutura nova:
- `votacao.cpp` — ✅ AC (map: contar strings, achar vencedor)
- `busca.cpp` — ✅ AC (BUSCA BINÁRIA; passou N=Q=100k em ~117ms)

Aquecimento 2 (`aquecimento2.cpp`) — CONCLUÍDO ✅ (5/5):
| Problema | Conceito | Status |
|----------|----------|--------|
| H Palavras repetidas | map<string,int> | ✅ (de primeira) |
| I Par que soma ao alvo | sort + dois ponteiros | ✅ |
| J Inverter número | extrair dígitos | ✅ |
| K Mediana | sort + v[n/2] | ✅ |
| L Existe elemento? | busca linear (ponte p/ binária) | ✅ |

Aquecimento (`aquecimento.cpp`) — CONCLUÍDO ✅ (4/4):
| Problema | Função | `_otima` | Big-O ótimo |
|----------|--------|----------|-------------|
| A Quente ou Frio | `quente` | `quente_otima` | O(1) / O(1) |
| B Gemas | `gemas` | `gemas_otima` | O(N) / O(1) |
| C Confronto de Horários | `horarios` | `horarios_otima` | O(N log N) / O(N) |
| D Promoção | `promocao` | `promocao_otima` | O(N·d) / O(1) |

## Conceitos praticados (contagem de repetições — meta: ~10 cada)

Um conceito só é "consolidado" após ~10 usos reais espalhados no tempo.
Atualizar o contador a cada vez que o aluno usa o conceito num problema.

| Conceito | Repetições | Onde |
|----------|-----------|------|
| Compilação/flags, I/O básico | ~vários | todas as sessões |
| `"\n"` vs `endl`, sync/tie | 2 | teoria + uso |
| Strings como vetor de char (`s[i]`, `s.size()`) | 3 | baralho, gemas, aquec-F |
| **Dois ponteiros** (esquerda/direita) | 2 | aquec-F(palindromo), aquec2-I(par soma) |
| **`map`** (dicionário chave→valor) | 2 | votacao, aquec2-H |
| **for/if sem `{}`** (2 comandos → só 1 obedece) | 2 | _otima, votacao(bug real!) |
| `switch/case` (break, fall-through) | 2 | torneio, baralho |
| if/else encadeado (faixas) | 4 | torneio, quente, promocao... |
| **Pilha (`stack`)** | 2 | zero, aquec-D(parenteses) |
| **Array de contagem** | 5 | notas, baralho, gemas, aquec-A, aquec-G |
| achar máximo/índice do máximo | 2 | aquec-B, aquec-G |
| `=` vs `==` (bug clássico) | 2 | baralho, aquec-G |
| for-range dá VALOR, não índice | 1 | aquec-G (quando precisa do índice, usar for tradicional) |
| char→int (`c-'0'`, `c-'a'`) + char('a'+i) | 3 | baralho, gemas, aquecimento-A |
| Flag booleana | 4 | baralho, gemas, horarios, aquec-D |
| `'c'` (char) vs `"c"` (string) | 1 | aquec-D |
| pop/top só com `!empty()` | 2 | zero, aquec-D |
| Funções (params, retorno, locais) | 2 | baralho, gemas |
| `=` vs `==` | 1 | baralho |
| Big-O (tempo/memória) | 4 | zero, torneio, baralho, gemas |
| Simulação com estado (relógio) | 0 | (tempo — em andamento) |
| **Ordenação (`sort`)** | 5 | horarios, aquec-C, C_array, aquec2-I/K |
| **`vector`** | 6 | horarios, aquec-B/C, aquec2-H?/I/K/L |
| máx/mín (não iniciar com 0!) | 1 | aquec-B |
| **Busca binária** (O(log n), meio anti-overflow) | 1 | busca.cpp |
| busca linear (contraste com binária) | 1 | aquec2-L |
| mediana = elemento em v[n/2] (ordenado) | 1 | aquec2-K |
| **break ao "achar" num while** (evita loop∞) | 3 | aquec2-I, busca.cpp, (recall) |
| **`pair` (.first/.second)** | 1 | horarios(C) |
| Índice fora do vetor (bug clássico) + sanitizer | 2 | baralho, horarios |
| **`%` e `/` (extrair dígitos)** | 3 | promocao, aquec-E, aquec2-J(inverter) |
| **`do/while`** | 2 | promocao, aquec-E |
| Paridade (`% 2`) | 2 | promocao, aquec-E |
| **for/if sem chaves `{}`** (regra + pegadinha) | 2 | _otima, recall ativo |
| **for-range** `for(x : col)` | 2 | _otima, recall ativo |
| **atribuições compostas** (`/=`, `+=`, `++`) | 3 | promocao, _otima, recall |
| **loop de dígitos compacto** `for(x=i;x>0;x/=10)` | 2 | promocao_otima, recall |
| **getline / cin.ignore** (misturar com `cin >>`) | 1 | revisão + exemplo rodado |

⚠️ ATENÇÃO ESPECIAL (pedido do aluno em 2026-06-30): ele quer FIXAR por
repetição espaçada os "modelos de for" — blocos sem chaves, for-range, e o
loop de extração de dígitos. Ele avisou que não lembrará amanhã. Nas próximas
sessões: reintroduzir esses padrões de propósito, e ANTES de seguir, pedir
que ele diga o que a linha faz (recall ativo). Ver Módulo 1.5 no plano.

Nenhum conceito acima atingiu ~10 repetições ainda — TODOS precisam ser
revisitados muitas vezes. Não tratar nada como "dominado".

Padrão de referência: para cada problema resolvido no `aquecimento.cpp`,
existe uma versão `<nome>_otima` com o algoritmo de nível competição
(elegante/legível) e Big-O comentado. Bom material de revisão de estilo.

## Plano de estudo

Ver arquivo `PLANO_DE_ESTUDO.md`. Atualizar o progresso lá conforme avança.
