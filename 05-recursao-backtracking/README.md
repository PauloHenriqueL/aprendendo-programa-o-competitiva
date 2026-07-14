# 🔁 Recursão e Backtracking

| Arquivo | Conteúdo |
|---------|----------|
| `backtracking_subconjuntos_decidir.cpp` | Subset-sum **SIM/NÃO** — existe subconjunto que soma o alvo? (material de leitura) |
| `backtracking_subconjuntos_contar.cpp` | **CONTAR** quantos subconjuntos somam o alvo. ✅ AC |

## A lição-chave (bug real, 3 tentativas)

| A recursão... | Combina os ramos com |
|---------------|----------------------|
| **DECIDE** (existe? sim/não) | `\|\|` → `ramoA \|\| ramoB` |
| **CONTA** (quantos?) | **SOMA** → `ramoA + ramoB` (igual ao fibonacci!) |

Ele reaproveitou o padrão `if (...) return 1` (de *decidir*) num problema de
*contar*. Não é o mesmo molde.

## Backtracking = árvore incluir / não-incluir
Para cada elemento, **duas chamadas**: uma que o inclui, outra que o pula.

## Cuidados
- **Caso base ALCANÇÁVEL** (senão: recursão infinita → stack overflow).
- Caso base `void` **não imprime**, só **para**.
- Imprimir **antes** × **depois** da chamada muda a ordem (descida × volta).
- Fibonacci ingênuo é **exponencial** (2ⁿ) → é a semente da DP/memoização.
