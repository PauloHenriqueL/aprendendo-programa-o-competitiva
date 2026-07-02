/*
============================================================================
  OBI 2021 - Fase 1 - Nivel Senior - "Torneio de tenis"
  https://olimpiada.ic.unicamp.br/pratique/ps/2021/f1/torneio/
============================================================================
  Cada participante joga 6 partidas. Classifica-se pelo numero de vitorias:
    5-6 vitorias -> grupo 1 | 3-4 -> grupo 2 | 1-2 -> grupo 3 | 0 -> -1

  ENTRADA: 6 linhas, cada uma 'V' (vitoria) ou 'P' (derrota).
  SAIDA:   o numero do grupo, ou -1.

  Conceito: contagem + if/else encadeado (faixas). Tempo O(1), memoria O(1).
============================================================================
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int vitorias = 0;
    char r;
    for (int i = 0; i < 6; i++) {
        cin >> r;
        if (r == 'V') vitorias++;
    }

    int grupo;
    if      (vitorias == 0) grupo = -1;
    else if (vitorias <= 2) grupo = 3;
    else if (vitorias <= 4) grupo = 2;
    else                    grupo = 1;

    cout << grupo << "\n";
    return 0;
}
