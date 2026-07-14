# 🔍 Ordenação e Busca

| Arquivo | Conteúdo |
|---------|----------|
| `busca_binaria_catalogo.cpp` | "Consultas no Catálogo" — busca binária em O(log n). Duas versões: **manual** (`lo`/`hi`/`meio`) e com `binary_search` da STL. Passou N=Q=100k em ~117ms. |

## Busca binária — o que mais pega (🔴 recorrente!)

| Detalhe | Certo | Errado |
|---------|-------|--------|
| Condição do laço | `while (lo <= hi)` | `while (lo < hi)` — a faixa é **FECHADA**; com 1 candidato (`lo==hi`) ele ainda precisa ser testado |
| O passo | `lo = meio + 1` / `hi = meio - 1` | `lo++` / `hi--` — descarta **1** elemento em vez de **metade** → vira O(N) disfarçado! |
| O meio | `lo + (hi - lo)/2` | `(lo + hi)/2` — pode estourar `int` |
| A comparação | `v[meio] < alvo` | `meio < alvo` — `meio` é **POSIÇÃO**, não valor! |
| Não achou | sentinela **`-1`** | `0` — que é um índice **VÁLIDO**! |

## `lower_bound` (primeira ocorrência com valores repetidos)
Ao achar o alvo, **não dê `break`**: guarde a posição como candidata e
**continue procurando à esquerda** (`hi = meio - 1`). A última atualização é
necessariamente a ocorrência mais à esquerda.
