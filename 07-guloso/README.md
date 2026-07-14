# 🤑 Guloso (greedy)

| Arquivo | Conteúdo |
|---------|----------|
| `teoria_guloso.cpp` | Teoria + G1 (menor tempo de espera) + G2 (activity selection). ⚠️ Guloso **nem sempre** é ótimo: com moedas {1,3,4} e alvo 6, o guloso dá 3 moedas (4+1+1), mas o ótimo são 2 (3+3). |
| `teoria_pair_e_activity_selection.cpp` | Teoria de `pair`/`vector<pair>`/`map` + H1 (activity selection resolvido sozinho ✅). |

## A ideia
A cada passo, escolher a opção **localmente melhor** e **nunca voltar atrás**.
Padrão típico: **ordenar + varrer uma vez** → O(N log N).

## Cuidados
- **Provar** que a escolha gulosa é ótima (ou testar contra força bruta!).
- **Parar cedo:** se está ordenado e o item atual não cabe, nenhum dos
  seguintes cabe → `else break`.
- **Borda inclusiva:** `preco <= dinheiro`, não `<`. Se você tem R$10 e o item
  custa R$10, **dá pra comprar**.
