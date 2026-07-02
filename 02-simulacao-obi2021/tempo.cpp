/*
============================================================================
  OBI 2021 - Fase 1 - Nivel Senior - "Tempo de resposta"
  https://olimpiada.ic.unicamp.br/pratique/ps/2021/f1/tempo/
============================================================================
  Registros: "R X" (recebeu de X), "E X" (respondeu a X), "T X" (X segundos).
  REGRA DO TEMPO: entre dois registros consecutivos passa 1 segundo por
  padrao; um "T X" redefine esse intervalo para X. O 1o evento e no instante 0.
  Tempo de resposta = instante do E menos instante do R. Se um R nunca foi
  respondido, o total daquele amigo e -1.

  ENTRADA: N; depois N registros "tipo valor".
  SAIDA:   uma linha por amigo (ordem crescente): "amigo total".

  Conceito: SIMULACAO com estado (relogio + "gap"). Tempo O(N+A), memoria O(A).
============================================================================
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int MAXA = 101;              // amigos vao de 1 a 100
    vector<long long> soma(MAXA, 0);   // soma dos tempos de resposta
    vector<int> rPendente(MAXA, -1);   // instante do R pendente (-1 = nenhum)
    vector<bool> existe(MAXA, false);  // amigo apareceu?

    int n;
    cin >> n;

    int relogio = 0;
    int gap = 1;                       // intervalo ate o proximo evento real
    bool primeiro = true;

    for (int i = 0; i < n; i++) {
        char tipo;
        int x;
        cin >> tipo >> x;

        if (tipo == 'T') { gap = x; continue; }  // T so ajusta o proximo gap

        if (primeiro) primeiro = false;          // 1o evento fica em t=0
        else          relogio += gap;
        gap = 1;                                 // volta ao padrao

        if (tipo == 'R') {
            existe[x] = true;
            rPendente[x] = relogio;
        } else { // 'E'
            soma[x] += relogio - rPendente[x];
            rPendente[x] = -1;
        }
    }

    for (int a = 1; a < MAXA; a++) {
        if (!existe[a]) continue;
        if (rPendente[a] == -1) cout << a << " " << soma[a] << "\n";
        else                    cout << a << " -1\n";
    }
    return 0;
}
