/*
============================================================================
  DESAFIO — "Consultas no Catalogo"   (estilo olimpiada/maratona)
  Tema novo: BUSCA BINARIA
============================================================================

CONTEXTO
--------
Uma loja tem N produtos, cada um identificado por um CODIGO (numero inteiro).
Voce recebe a lista de codigos e depois Q consultas. Para cada consulta (um
codigo), diga se aquele produto EXISTE no catalogo.

Como N e Q podem ser grandes, uma busca linear (olhar todos os codigos a cada
consulta) seria O(N*Q) e lenta demais. A ideia e: ORDENAR os codigos uma vez
e usar BUSCA BINARIA em cada consulta -> O((N + Q) log N).

ENTRADA
-------
Primeira linha: dois inteiros N e Q (numero de produtos e de consultas).
Segunda linha: N inteiros, os codigos dos produtos (podem vir desordenados,
               e pode haver codigos repetidos).
Terceira linha: Q inteiros, os codigos consultados.

SAIDA
-----
Q linhas. Para cada consulta, imprima:
  - "SIM" se o codigo existe no catalogo;
  - "NAO" caso contrario.

RESTRICOES
----------
  - 1 <= N, Q <= 100000
  - 0 <= codigo <= 1000000000   (ATENCAO: cabe em int, mas cuidado com overflow
                                 no calculo do meio; use lo + (hi-lo)/2)

EXEMPLO
-------
Entrada:
5 3
30 10 50 20 40
20 25 50
Saida:
SIM
NAO
SIM

  (catalogo ordenado: 10 20 30 40 50.
   consulta 20 -> existe -> SIM
   consulta 25 -> nao existe -> NAO
   consulta 50 -> existe -> SIM)

============================================================================
  DICA: 1) leia os N codigos num vector; 2) sort(...) uma vez;
        3) para cada consulta, faca busca binaria (manual OU binary_search).
        Comece pela versao MANUAL (lo/hi/meio) para fixar a ideia; depois,
        se quiser, refaca com binary_search(v.begin(), v.end(), x).
  Consulte visto.cpp (sort) se precisar.
============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q, codigo;
  cin >> n >> q;
  vector<int> vetor(n);
  // catalago
  for(int i = 0; i < n; i++){
    cin >> vetor[i];
  }
  // ordernar
  sort(vetor.begin(), vetor.end());
  // consultas
  for(int i = 0; i < q; i++){
    cin >> codigo;

    int esquerda = 0, direita = n - 1;
    bool encontrou = false;
    while(esquerda<=direita){
      int meio = esquerda + (direita - esquerda) / 2;
      if(vetor[meio] == codigo){
        encontrou = true;
        break;
      } else if (vetor[meio] < codigo){
        esquerda = meio + 1;
      } else {
        direita = meio -1;
      }
    }
    if (encontrou) cout << "SIM\n";
    else            cout << "NAO\n";
  }
  return 0;
}

// ===========================================================================
// VERSAO OTIMA — busca_otima  (usando binary_search da biblioteca)
// Complexidade: Tempo O((N + Q) log N) | Memoria O(N)
//   sort: O(N log N). Cada consulta: O(log N). Igual a versao manual, mas
//   com muito menos codigo (e sem risco de errar o +1/-1 ou esquecer break).
//
// binary_search(inicio, fim, valor) devolve um bool: true se 'valor' existe
// no intervalo [inicio, fim), false caso contrario.
//   ATENCAO: o intervalo PRECISA estar ORDENADO (mesma regra da versao manual).
//
// Outras buscas prontas uteis (mesma familia, tambem exigem ordenado):
//   lower_bound(b, e, x) -> iterador para o 1o elemento >= x
//   upper_bound(b, e, x) -> iterador para o 1o elemento >  x
//   (uteis para contar ocorrencias, achar posicao de insercao, etc.)
// ===========================================================================
void busca_otima(){
    ios_base::sync_with_stdio(false);  // I/O rapido: bom com N,Q grandes
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> catalogo(n);
    for (int i = 0; i < n; i++) cin >> catalogo[i];

    sort(catalogo.begin(), catalogo.end());     // ORDENA uma vez (obrigatorio)

    while (q--) {                                // repete q vezes
        int codigo;
        cin >> codigo;
        // binary_search faz toda a busca binaria por voce e devolve true/false:
        if (binary_search(catalogo.begin(), catalogo.end(), codigo))
            cout << "SIM\n";
        else
            cout << "NAO\n";
    }
}

