/*
============================================================================
  OBI 2021 - Fase 1 - Nivel Senior - "Baralho"
  https://olimpiada.ic.unicamp.br/pratique/ps/2021/f1/baralho/
============================================================================
  Cada carta e "ddN": dd = valor 01..13, N = naipe (C,E,U,P = Copas, Espadas,
  Ouros, Paus). Para cada naipe (nesta ordem C,E,U,P), imprima:
    0     se completo (13 cartas, sem repetir)
    erro  se ha carta duplicada
    k     quantidade de cartas faltando, caso contrario.

  ENTRADA: uma string com as cartas concatenadas (3 chars por carta).
  SAIDA:   4 linhas (Copas, Espadas, Ouros, Paus).

  Conceitos: array de contagem, parsing de string (de 3 em 3), char->int,
  funcao, flag. Tempo O(N), memoria O(1).
============================================================================
*/
#include <bits/stdc++.h>
using namespace std;

// Analisa um naipe (contagem[1..13]) e imprime a linha de resultado.
void imprimeNaipe(int naipe[]) {
    int qt = 0;
    bool temErro = false;
    for (int i = 1; i <= 13; i++) {
        if (naipe[i] >= 2) { temErro = true; break; }  // duplicata
        if (naipe[i] == 1) qt++;                        // presente
    }
    if (temErro)       cout << "erro\n";
    else if (qt == 13) cout << "0\n";
    else               cout << (13 - qt) << "\n";
}

int main() {
    int C[14] = {}, E[14] = {}, U[14] = {}, P[14] = {};
    string s;
    cin >> s;

    for (int i = 0; i < (int)s.size(); i += 3) {
        int valor = (s[i] - '0') * 10 + (s[i + 1] - '0');
        char naipe = s[i + 2];
        switch (naipe) {
            case 'C': C[valor]++; break;
            case 'E': E[valor]++; break;
            case 'U': U[valor]++; break;
            case 'P': P[valor]++; break;
        }
    }

    imprimeNaipe(C);
    imprimeNaipe(E);
    imprimeNaipe(U);
    imprimeNaipe(P);
    return 0;
}
