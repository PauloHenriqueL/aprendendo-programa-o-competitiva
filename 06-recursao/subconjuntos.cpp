/*
============================================================================
  "Somando Subconjuntos"  — RESOLVIDO (solucao de referencia)
  Tema: RECURSAO que EXPLORA POSSIBILIDADES (semente do backtracking)
============================================================================
  Existe um SUBCONJUNTO dos N numeros cuja soma seja exatamente ALVO?
  Para cada numero ha duas escolhas: INCLUIR ou NAO incluir -> arvore de
  decisoes que a recursao percorre.

  ENTRADA:  N e ALVO; depois N inteiros.
  SAIDA:    "SIM" ou "NAO".
  RESTRICOES: 1 <= N <= 20; cabe em int. Tempo O(2^N).

  NOTA: esta atividade foi encerrada como referencia (o esqueleto original
  vinha cheio demais). Fica como material de leitura. Novos desafios de
  recursao em outros arquivos, com main minimo para o aluno resolver.
============================================================================
*/
#include <bits/stdc++.h>
using namespace std;

int n, alvo;
vector<int> v;

// i = qual numero decidimos agora; faltam = quanto ainda falta ate o alvo
bool existe(int i, int faltam) {
    if (faltam == 0) return true;    // achamos um subconjunto que soma o alvo
    if (i == n)      return false;   // acabaram os numeros e ainda faltava algo

    // duas escolhas para o numero v[i]:
    if (existe(i + 1, faltam))         return true;  // NAO incluir v[i]
    if (existe(i + 1, faltam - v[i]))  return true;  // INCLUIR   v[i]
    return false;
}

int main() {
    cin >> n >> alvo;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    if (existe(0, alvo)) cout << "SIM\n";
    else                 cout << "NAO\n";
    return 0;
}
