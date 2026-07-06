/*
============================================================================
  Codeforces — "Another Popcount Problem"
  (confira o enunciado oficial no Codeforces; este e um resumo em pt-BR)
============================================================================
  Dados n e k, construa k inteiros nao-negativos a1..ak com soma <= n,
  maximizando o total de bits 1 (soma dos popcount). Imprima esse maximo.

  popcount(x) = numero de bits 1 na representacao binaria de x.
    popcount(6) = popcount(110) = 2 ; popcount(0) = 0.

  ENTRADA
    Primeira linha: t (numero de casos de teste, 1 <= t <= 1e3).
    Cada caso: uma linha com n e k (1 <= n,k <= 1e6).
  SAIDA
    Para cada caso, uma linha com o maximo de sum(popcount(ai)).

  EXEMPLO
    Entrada:              Saida:
      6                      1
      2 1                    2
      3 1                    4
      6 2                    14142
      14142 137205           1322
      1000000 100            1000000
      1000000 1000000

----------------------------------------------------------------------------
  ESTRATEGIA (greedy por CAMADAS de bits):
    Um bit na posicao b (valor 2^b) custa 2^b e da 1 de popcount. Cada um dos
    k numeros tem no maximo 1 bit por posicao -> em cada posicao cabem ate k
    bits. Compre bits BARATOS primeiro:
      camada custo 1 (2^0): ate k bits ; camada custo 2 (2^1): ate k bits ; ...
    Em cada camada pegue min(k, n/custo) bits, gaste-os, e suba a camada
    (custo *= 2) ate n acabar.

  CUIDADOS:
    - t CASOS DE TESTE: leia t e repita a leitura de (n,k) t vezes.
    - OVERFLOW: pego * custo pode passar de 1e6 (ate ~1e12). Use long long
      para n, custo e o produto.
    - custo *= 2: quando custo > n, n/custo vira 0 e o laco para (~20 voltas).

  Peça dica se precisar;
============================================================================
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

    return 0;
}
