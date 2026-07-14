#include <bits/stdc++.h>
using namespace std;


/*
============================================================================
  CONCEITO NOVO — BITS e OPERADORES BIT A BIT
============================================================================
  (Explicacao para ler. Os 2 problemas no fim sao seus.)

  Voce ja fez a base na mao no aquecimento (par/impar com %2, dividir por 2,
  converter para binario). Agora vem as FERRAMENTAS DIRETAS para mexer em bits.

  ==========================================================================
  1) RELEMBRANDO O BINARIO
  ==========================================================================
  Todo numero e uma soma de POTENCIAS DE 2. Cada posicao (bit) vale o dobro
  da anterior: ..., 32, 16, 8, 4, 2, 1.
      13 = 8 + 4 + 1 = binario 1101
           bit3=1, bit2=1, bit1=0, bit0=1  (contamos da DIREITA, comecando em 0)
  "bit ligado" = 1 ; "bit desligado" = 0.


  ==========================================================================
  2) OS 5 OPERADORES (todos rodados e comprovados)
  ==========================================================================
  Sejam a=12 (1100) e b=10 (1010).

  &  (AND)  -> bit 1 SO onde AMBOS tem 1.   12 & 10 = 8  (1000)
  |  (OR)   -> bit 1 onde PELO MENOS UM tem 1. 12 | 10 = 14 (1110)
  ^  (XOR)  -> bit 1 onde os bits sao DIFERENTES. 12 ^ 10 = 6 (0110)
  ~  (NOT)  -> inverte todos os bits (cuidado: mexe no sinal; use com mascara).

  <<  (shift left)  -> "empurra" os bits para a ESQUERDA, enchendo com 0 a
                       direita. Equivale a MULTIPLICAR por potencia de 2:
                          5 << 1 = 10   (5 * 2)
                          5 << 3 = 40   (5 * 2^3 = 5*8)
  >>  (shift right) -> empurra para a DIREITA, jogando fora bits. Equivale a
                       DIVIDIR (inteiro) por potencia de 2:
                          20 >> 1 = 10  (20 / 2)
                          20 >> 2 = 5   (20 / 4)


  ==========================================================================
  3) O TRUQUE MAIS USADO:  1 << k   E   (x >> k) & 1
  ==========================================================================
  1 << k  -> vale 2^k. E uma "MASCARA" com um unico bit 1, na posicao k:
      1<<0 = 1     1<<1 = 2     1<<2 = 4     1<<3 = 8   ...  1<<10 = 1024

  Testar se o bit k de x esta LIGADO:
      (x >> k) & 1   -> empurra o bit k ate a posicao 0, e isola com &1.
                        Vale 1 se ligado, 0 se desligado.
      Ex.: x = 22 = 10110.  (x>>2)&1 = 1 (bit 2 ligado). (x>>3)&1 = 0.

  x & 1  -> o ULTIMO bit de x. E o mesmo que x % 2 (par/impar), mas com bits.


  ==========================================================================
  4) POPCOUNT (contar bits 1) e um truque elegante
  ==========================================================================
  popcount(x) = quantos bits 1 tem x.  popcount(13)=popcount(1101)=3.
    - Na mao:  cont=0; while(x>0){ cont += x&1; x >>= 1; }
    - Pronto (C++):  __builtin_popcount(x)   (para long long: __builtin_popcountll)

  Truque:  x & (x-1)  -> apaga o ULTIMO bit 1 de x.
      Ex.: x=22=10110 ; x-1=10101 ; x&(x-1)=10100=20 (sumiu o bit 1 mais baixo).
      Consequencia: x e POTENCIA DE 2  <=>  (x & (x-1)) == 0  (tem so 1 bit).
      (Compare com o seu A7, que dividia por 2 ate sobrar 1 — mesma ideia!)


  ==========================================================================
  5) POR QUE BITS IMPORTAM EM COMPETICAO
  ==========================================================================
  - Testar/ligar/desligar opcoes (flags) de forma compacta.
  - Percorrer todos os SUBCONJUNTOS de um conjunto (mascaras de 0 a 2^n-1).
  - Operacoes O(1) que substituem loops (multiplicar/dividir por 2, paridade).
  - Base de varios problemas 800-1400 do Codeforces (inclusive o popcount que
    ficou pendente — agora voce tera a ferramenta).

*/









/*
  ============================================================================
  PROBLEMA B1 — CONTAR OS BITS 1 (popcount na mao)
  ============================================================================
  Leia um inteiro X (0 <= X <= 1e9). Imprima quantos bits 1 ha na
  representacao binaria de X. NAO use __builtin_popcount — faca com o loop
  (x & 1) e (x >>= 1), para praticar.

  ENTRADA: X.
  SAIDA:   o numero de bits 1.
  EXEMPLOS
    5   -> 2     (101 tem dois 1)
    7   -> 3     (111)
    8   -> 1     (1000)
    0   -> 0
    255 -> 8     (11111111)

  Peça dica se precisar;
*/

void b1(){
  long long x; cin >> x;
  int cont = 0;
  while(x>0){
    cont += x&1;
    x>>=1;
  }
  cout << cont << endl;

}









/*
  ============================================================================
  PROBLEMA B2 — O K-ESIMO BIT ESTA LIGADO?
  ============================================================================
  Leia um inteiro X (0 <= X <= 1e9) e um inteiro K (0 <= K <= 30). Imprima
  "LIGADO" se o bit de posicao K de X for 1, ou "DESLIGADO" se for 0.
  (As posicoes contam da DIREITA, comecando em 0.)

  ENTRADA: dois inteiros X e K.
  SAIDA:   "LIGADO" ou "DESLIGADO".
  EXEMPLOS
    13 0 -> LIGADO      (13 = 1101 ; bit 0 = 1)
    13 1 -> DESLIGADO   (bit 1 = 0)
    13 2 -> LIGADO      (bit 2 = 1)
    13 3 -> LIGADO      (bit 3 = 1)
    13 4 -> DESLIGADO   (bit 4 = 0)
  DICA: use  (X >> K) & 1  para isolar o bit K.

  Peça dica se precisar;

============================================================================
*/

int main() {

    return 0;
}
