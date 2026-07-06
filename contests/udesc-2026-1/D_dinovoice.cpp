/*
============================================================================
  CONCEITO — SIMULACAO DE TORNEIO (com vector que encolhe a cada rodada)
============================================================================
  (Explicacao para voce ler. A SOLUCAO e sua — main vazio.)

  O PROBLEMA (D — DinoVoice):
    N dinos numa fila. Em cada RODADA formam-se pares comecando do 1o:
    (1o,2o), (3o,4o), (5o,6o)... Em cada par, o MAIOR fica, o menor sai.
    Repete ate sobrar 1. A resposta NAO e quem ganha — e a MAIOR diferenca
    |maior - menor| entre os dois de um confronto, somando TODOS os
    confrontos de TODAS as rodadas.

  O QUE E "SIMULACAO"?
    Reproduzir o processo passo a passo, exatamente como descrito, guardando
    o estado que evolui (aqui, a fila de dinos que sobra a cada rodada).
    Mesmo espirito do problema "tempo" (OBI) que voce ja fez.

  ESTRUTURA MENTAL (uma forma de pensar — nao e a unica):
    - Tenha a fila atual num vector.
    - ENQUANTO a fila tiver mais de 1 dino:
        * percorra de 2 em 2 (i = 0, 2, 4, ...) formando pares (v[i], v[i+1]);
        * para cada par: atualize a MAIOR diferenca vista; o vencedor
          (o maior dos dois) entra numa NOVA fila;
        * se sobrar UM sem par (fila de tamanho impar -> o ultimo), ele
          passa direto para a nova fila (nao lutou nesta rodada);
        * a nova fila vira a fila atual.
    - No fim, imprima a maior diferenca.

  CUIDADOS (onde esse problema derruba):
    1. FILA IMPAR: o ultimo elemento fica sem par e AVANCA de graca. Se voce
       nao tratar isso, ou acessa v[i+1] fora do vetor (crash!) ou perde o
       ultimo dino. Veja o exemplo 2 (o 7 passa sem lutar na 1a rodada).
    2. DIFERENCA e |maior - menor|. Se voce sempre coloca o maior de um lado,
       a diferenca e (maior - menor) e ja da positivo. Cuidado para nao dar
       negativo.
    3. TIPOS: Ai vai ate 1e9. A DIFERENCA cabe em int (ate ~1e9), mas se
       tiver duvida use long long — nunca custa. (Aqui nao ha SOMA
       acumulando, so um max de diferencas, entao int basta, mas pense.)
    4. Complexidade: cada rodada corta a fila ~pela metade -> total O(N).
       Tranquilo para N ate 2e5.

  EXEMPLOS (rastreie na mao para conferir sua logica):
    N=2:  5 2            -> par (5,2) dif 3                       -> 3
    N=3:  4 5 7          -> (4,5) dif1; 7 passa; depois (5,7) dif2 -> 2
    N=4:  10 6 3 2       -> (10,6) dif4; (3,2) dif1; depois (10,3) dif7 -> 7

----------------------------------------------------------------------------
  ENTRADA: N; depois N inteiros (poderes de canto).
  SAIDA:   a maior diferenca de poder entre os dois de algum confronto.
  RESTRICOES: 2 <= N <= 2e5 ; 1 <= Ai <= 1e9.

  Peça dica se precisar;
============================================================================
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, maior = 0, diferenca = 0, tam = 0;
  cin >> n;
  vector<int> vetor(n);
  for(int i = 0; i < n; i++){
    cin >> vetor[i];
  }
  while(vetor.size() > 1){
    vector<int> vencedores;
    for(int i = 0; i + 1 < (int)vetor.size(); i += 2){
      if(vetor[i]>=vetor[i+1]){
        vencedores.push_back(vetor[i]);
        diferenca = vetor[i] - vetor [i+1];
        if (diferenca > maior){
          maior = diferenca;
        }
      } else {
        vencedores.push_back(vetor[i+1]);
        diferenca = vetor[i+1] - vetor[i];
        if (diferenca > maior){
          maior = diferenca;
        }
      }
    }
    tam = vetor.size();
    if(tam % 2 != 0) {
      vencedores.push_back(vetor[tam - 1]);
    }
    vetor = vencedores;

  }
  cout << maior << "\n";

  return 0;
}
