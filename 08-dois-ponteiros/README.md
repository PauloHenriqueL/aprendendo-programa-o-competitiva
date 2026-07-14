# 👉👈 Dois ponteiros

| Arquivo | Conteúdo |
|---------|----------|
| `teoria_dois_ponteiros_e_janela.cpp` | Teoria + **D1** (Codeforces 279B "Books", rating **900** — ✅ AC) + **D2** (botes de resgate: guloso + dois ponteiros). |

## As duas variantes

| Variante | Ponteiros | O que a estrutura deixa descartar |
|----------|-----------|-----------------------------------|
| **Nas PONTAS** | `esq=0`, `dir=n-1`, vindo ao encontro | ordenação → um elemento **e todos os pares dele** |
| **JANELA DESLIZANTE** | juntos, mesma direção | valores positivos → um ponto de partida **e todos os trechos dele** |

## As regras que mais pegam
- **UM ponteiro se move por iteração.** Nunca os dois no mesmo passo.
- Janela: encolhe **quando ESTOUROU** (`while (soma > T)`), não antes.
  E é `>`, não `>=` — se bater exatamente T, **cabe**.
- É **O(N)** mesmo com dois laços aninhados: `esq` **nunca retrocede**, então o
  laço interno roda ≤ N vezes **somadas** em toda a execução.
- ⚠️ `v[esq] + v[dir]` com valores até 1e9 **estoura `int`** → `long long`.

## O fio condutor
Busca binária (descarta metade) · dois ponteiros (descarta um elemento e todos
os pares dele) · prefix sum (pré-calcula) · guloso (não volta atrás) são **a
mesma ideia**: usar a **ESTRUTURA** do problema para **descartar em BLOCO**.

> A pergunta: *"o que a estrutura me deixa jogar fora SEM TESTAR?"*
