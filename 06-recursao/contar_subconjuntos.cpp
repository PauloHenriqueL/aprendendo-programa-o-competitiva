/*
============================================================================
  DESAFIO DE RECURSAO — "Quantos subconjuntos somam o alvo?"
============================================================================

  Voce tem N numeros inteiros positivos e um valor ALVO. Em vez de dizer
  apenas SE existe um subconjunto que soma o alvo, agora conte QUANTOS
  subconjuntos diferentes somam exatamente ALVO.

  (O subconjunto vazio soma 0. Cada numero pode ser escolhido ou nao.)

  IDEIA: e a mesma "arvore de decisoes" da recursao incluir / nao-incluir.
  A diferenca e que, em vez de parar no primeiro que der certo, voce SOMA
  as contagens dos dois ramos. Pense: para cada numero, o total de jeitos =
  (jeitos SEM esse numero) + (jeitos COM esse numero).

  ----------------------------------------------------------------------------
  ENTRADA
    Primeira linha: N e ALVO.
    Segunda linha:  N inteiros positivos.
  SAIDA
    Um unico inteiro: quantos subconjuntos somam exatamente ALVO.
  RESTRICOES
    1 <= N <= 20        (2^20 ~ 1 milhao de subconjuntos; recursao aguenta)
    numeros e alvo cabem em int; a RESPOSTA cabe em int tambem.

  EXEMPLOS
    Entrada:              Saida:
      3 3                   2
      1 2 3
    (subconjuntos que somam 3:  {3}  e  {1,2}  -> 2 jeitos)

    Entrada:              Saida:
      4 5                   2
      1 2 3 4
    (que somam 5:  {1,4}  e  {2,3}  -> 2 jeitos)

    Entrada:              Saida:
      3 0                   1
      1 2 3
    (so o subconjunto vazio soma 0 -> 1 jeito)

  ----------------------------------------------------------------------------
  Peça dica se precisar;
*/
#include <bits/stdc++.h>
using namespace std;

int n, alvo;
vector<int> vetor;

int contar(int j, int faltam){
  int valor = 0;
  if (faltam == 0)  return 1;
  if (j == n)     return 0;

  int semEle = (contar(j + 1, faltam));
  int comEle = (contar(j + 1, faltam - vetor[j]));
  return semEle + comEle;
}

int main(){
  cin >> n >> alvo;
  vetor.resize(n); 
  for(int i = 0; i < n; i++) cin >> vetor[i];
  
  cout << contar(0, alvo) << "\n";


  return 0;
}