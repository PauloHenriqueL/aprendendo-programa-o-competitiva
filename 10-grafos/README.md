# 🕸️ Grafos — Semana 4 (21/07 a 27/07)

**Ainda não iniciado.** É o **único conceito novo de julho** (ver
`PLANO_DE_ESTUDO.md`).

## A ponte já está pronta
`revisoes/2026-07-14_revisao_C1-C8_janela_buscabin_matriz_fila.cpp` (C5–C8)
monta as 4 peças do BFS, uma por exercício:

| Exercício | Peça | Por que importa |
|-----------|------|-----------------|
| **C5** | matriz 2D | *o labirinto **É** uma matriz* |
| **C6** | os 4 vizinhos + limites da grade | *é o **coração** do BFS* |
| **C7** | `queue` (fila) | *o BFS **É** uma fila de células a visitar* |
| **C8** | vetor de visitados | *é o que impede o algoritmo de **girar em círculos para sempre*** |

Ao terminar os quatro, o BFS já está montado — só falta encaixar.

## A lição conceitual (o aluno errou isto no recall)
Num labirinto, **não se ESCOLHE um caminho** — guloso **quebra** (você se enfia
num beco e não sabe voltar). **Espalha-se por todos.**

A pergunta não é *"por onde eu vou?"*, é **"quais células eu ALCANÇO?"**

1. Marque a origem como alcançável.
2. De toda célula alcançável, olhe os 4 vizinhos.
3. Vizinho livre e **ainda não marcado**? Marque.
4. Repita até não marcar mais ninguém.
5. O destino está marcado? **Existe caminho.**

O passo 3 (*"ainda não marcado"*) é o que faz o algoritmo **terminar**.
