/*
============================================================================
  OBI 2021 - Fase 1 - Nivel Senior - "Zero para cancelar"
  https://olimpiada.ic.unicamp.br/pratique/ps/2021/f1/zero/
============================================================================
  Soma numeros ditados; o valor 0 CANCELA (desfaz) o ultimo numero valido
  ainda nao cancelado (comportamento de PILHA / LIFO).

  ENTRADA: N; depois N inteiros Xi.
  SAIDA:   a soma correta apos as correcoes.
  Ex.: [1 3 5 4 0 0 7 0 0 6] -> 7

  Conceito: pilha (stack). Tempo O(N), memoria O(N).
============================================================================
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    long long soma = 0;
    cin >> n;
    stack<int> p;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 0) {
            if (!p.empty()) { soma -= p.top(); p.pop(); }  // cancela o ultimo
        } else {
            p.push(x);
            soma += x;
        }
    }
    cout << soma << "\n";
    return 0;
}
