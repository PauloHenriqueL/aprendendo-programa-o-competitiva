# 🎯 Revisão Final — consolidação antes de grafos (21–24/07)

Pasta criada em **2026-07-21**, a pedido do aluno: *"melhor ter tudo que vimos
até aqui consolidado do que simplesmente pular para grafos sem consolidar tudo."*

**A meta de julho NÃO foi cortada.** Grafos 1 continua sendo 1 dos 3 alvos
(busca binária · guloso · grafos 1). O que mudou: 21–24/07 consolida, e
25–31/07 faz BFS **usando o BFS como prova da consolidação** — ele reusa
matriz + queue + visitados + dl/dc todos ao mesmo tempo.

## Os arquivos (o que ficou ao encerrar)

| Arquivo | O quê | Resultado |
|---------|-------|-----------|
| `2026-07-21_padroes_E1-E10.cpp` | os **padrões de erro** + ternário `?:` | **E1–E9 ✅ AC** (5 de primeira); E10 com solução comentada (`E10_otimo`) |
| `2026-07-21_estruturas_S8_bfs.cpp` | o exercício que monta o **BFS** | **S8 ✅ AC** — grafos parte 1 fechado |

Os exercícios S1–S7 (stack/queue/vector/matriz sem rótulo) foram propostos mas
não resolvidos, e removidos ao encerrar. O cabeçalho didático com a teoria das
estruturas foi preservado no arquivo do S8.

## Por que estes exercícios, e não outros

O diagnóstico de 21/07 (julgamento tardio de D1–D7, escritos em 15/07) deu
**6 AC e 1 WA**, com compilação limpa nos sete. Isso mudou o desenho da revisão:

- **Busca binária saiu do 🔴.** D1, D2, D3 e D7 passaram — e o D7 era *conceito
  novo* (busca binária na resposta), validado contra força bruta em 200 casos.
- **Dois ponteiros** idem (D5, 300 casos, `long long` segurou 4999950000).
- O único WA (D4) **não foi um conceito** — foi mecânica de laço.

Conclusão: o 🔴 real não é um conceito, é um **padrão**:
1. **inicializar acumulador/sentinela** com valor errado (`min` com `melhor=0`)
2. **a linha certa no lugar errado** (dentro × fora do laço)

Esses dois já apareceram em **M1, C2, C4, C5, D8 e D4** — seis vezes, em seis
conceitos diferentes. O arquivo `E` caça o padrão, não o conceito.

## O erro do recall de 21/07 que gerou o arquivo `S`

O aluno **inverteu LIFO e FIFO**: disse *"stack é FIFO"* e trocou as duas
estruturas na aplicação. Os **conceitos** ele acertou (soube dizer que "ordem de
chegada" é FIFO e "desfazer" é LIFO) — só os **nomes** estavam trocados.

É perigoso porque num enunciado de prova está escrito "pilha" e "fila", não
"LIFO". Vocabulário errado faz escolher a estrutura errada mesmo entendendo o
problema. Daí o formato: **8 exercícios sem rótulo**, e o aluno declara em
comentário `// ESCOLHA:` qual estrutura escolheu e **qual palavra do enunciado**
o fez escolher — antes de codar. Julga-se a **escolha** e o **uso**.

Distribuição (não revelada no arquivo): 2 stack · 2 queue · 2 vector · 2 matriz.

## A distinção que o arquivo `S` ensina

`stack`/`queue`/`vector` são **lineares** e se diferenciam pela **política** de
entrada/saída. **Matriz não é irmã delas** — não tem política nenhuma, é um
*arranjo* 2D (um vector de vectors). A pergunta que separa:

- dados com **posição em 2D** (linha × coluna)? → **matriz**
- dados com **ordem** de entrada e saída? → **stack** ou **queue**
- só guardar e acessar por índice? → **vector**

## S8 é o BFS

O último exercício do arquivo `S` **é** o BFS, montado a partir das 4 peças que
o aluno já construiu (C5 matriz, C6 vizinhos, C7 queue, C8 visitados — as duas
últimas AC de primeira). Não é conceito novo: é **encaixe**.

O exemplo do S8 foi escolhido de propósito: duas células **parecem** bloqueadas
mas são alcançáveis **contornando por baixo**. É a demonstração concreta de por
que guloso quebra em labirinto — quem "escolhe o caminho que aponta para o
alvo" nunca faz o desvio.
