# 🔥 Revisões (repetição espaçada)

Cada arquivo é **uma sessão de estudo**. O nome diz **quando** foi e **o que
treina** — assim dá pra achar rápido o exercício de um conceito específico.

Formato do nome: `AAAA-MM-DD_conceito_FAIXA.cpp`

| Arquivo | Exercícios | O que treina | Resultado |
|---------|-----------|--------------|-----------|
| `2026-06-30_revisao_A-D_contagem_sort_pilha.cpp` | A–D | array de contagem, maior/menor, sort, pilha, dígitos | 4/4 ✅ |
| `2026-07-02_revisao_H-L_map_doisponteiros_sort.cpp` | H–L | `map`, dois ponteiros, sort, mediana, busca linear | 5/5 ✅ |
| `2026-07-03_recursao_R1-R5.cpp` | R1–R5 | recursão (caso base + recursivo), fibonacci | 5/5 ✅ |
| `2026-07-04_memoria_arquivos_M1-M5.cpp` | M1–M5 | `vector` dinâmico, matriz 2D, `ifstream`/`ofstream` | 5/5 ✅ |
| `2026-07-05_guloso_A1-A8.cpp` | A1–A8 | guloso, `vector<pair>`, sort + varrer | 8/8 ✅ |
| `2026-07-06_bits_A1-A8_PAUSADO.cpp` | A1–A8 | binário na mão, `%2`, `/2` | 7/8 ⏸️ pausado |
| `2026-07-08_dois_ponteiros_A1-A8.cpp` | A1–A8 | dois ponteiros, busca binária, prefix sum | 6/8 |
| `2026-07-13_dois_ponteiros_B1-B8.cpp` | B1–B8 | idem + overflow, warnings, borda inclusiva | 8/8 ✅ |
| `2026-07-14_revisao_C1-C8_janela_buscabin_matriz_fila.cpp` | C1–C8 | janela deslizante, `lower_bound`, guloso, matriz, fila | C1–C4 ✅ |

## Regra da casa

1. **Compile com as flags ANTES de pedir correção:**
   ```
   g++ -std=c++17 -Wall -Wextra -Wshadow -O2 arquivo.cpp -o a
   ```
   Warning = teste falhando. Mas ⚠️ **compilação limpa é o PISO, não a
   garantia** — o `-Wall` não pega um `cout` faltando.
2. **Rode os exemplos do enunciado.** Sempre.
3. **A meta não é o AC — é acertar DE PRIMEIRA.** Um conceito só está fixado
   quando sai sem rodada de correção e sem dica, em 2 exercícios diferentes.
