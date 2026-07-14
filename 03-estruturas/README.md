# 🗺️ Estruturas de dados

| Arquivo | Estrutura | O que faz |
|---------|-----------|-----------|
| `map_votacao.cpp` | `map<string,int>` | Apura votos por nome; lista em ordem alfabética (o `map` já vem ordenado por chave) e acha o vencedor com desempate alfabético. |

## Notas
- **`map` × `vector`:** o `vector` acessa por **índice** (posição), o `map`
  acessa por **CHAVE** (qualquer tipo). Se a chave é um inteiro pequeno,
  um **array de contagem** é mais rápido.
- Iterar um `map` devolve os pares **já ordenados por chave** — de graça.
- `m[k]++` cria a chave com valor 0 se ela não existir, e então incrementa.

## A ver nesta pasta (Semana 3)
`set` (dedup / "já vi isso?"), `stack` (LIFO), `queue` (FIFO — base do BFS),
`pair`, matriz 2D.
