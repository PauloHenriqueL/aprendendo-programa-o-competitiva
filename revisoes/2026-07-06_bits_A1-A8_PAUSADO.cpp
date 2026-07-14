/*
============================================================================
  AQUECIMENTO DO DIA — 8 exercicios (4 reforco + 4 preparatorios p/ BITS)
============================================================================
  Resolva um por vez; me chame ("terminei o A1"). Sou juiz. Peça dica se
  precisar. Formato: so enunciado, o codigo e seu.

  Estes 8 preparam o conceito novo de hoje: BITS / representacao BINARIA.
============================================================================


  ==========================================================================
  PARTE 1 — REFORCO (conceitos ja vistos; foco nos seus 🔴)
  ==========================================================================

  --------------------------------------------------------------------------
  A1 — PRODUTO QUE ESTOURA (overflow / long long)   [reforco 🔴]
  --------------------------------------------------------------------------
  Leia dois inteiros A e B (cada um ate 1e9) e imprima o produto A*B.

  ENTRADA: A B (1 <= A,B <= 1e9).
  SAIDA:   o produto.
  EXEMPLO
    1000000 1000000 -> 1000000000000
  (Cuidado: A*B cabe em int? E se voce escrever  int p = A*B  vs  long long?)

  Peça dica se precisar;

*/
#include <bits/stdc++.h>
using namespace std;




void A1(){
  int a, b; cin >> a >> b;
  long long mult = (long long) a * b; cout << mult << endl;
}


/*
  --------------------------------------------------------------------------
  A2 — VETOR DINAMICO E MEDIA (vetor com tamanho em runtime)   [reforco 🔴]
  --------------------------------------------------------------------------
  Leia N e N inteiros. Imprima quantos deles sao MAIORES que a media (a soma
  dividida por N, em divisao real). Use um vetor dimensionado em runtime.

  ENTRADA: N; depois N inteiros (ate 1e6).
  SAIDA:   quantos elementos sao > media.
  EXEMPLO
    5 / 1 2 3 4 10   -> 1     (media=4.0; so o 10 e maior)
  (Cuidado: soma em long long; media em double; NAO use vetor sem tamanho!)

  Peça dica se precisar;

*/
void A2(){
  int n, cont = 0; cin >> n;
  vector<int> vetor(n);
  long long soma = 0;
  double media;
  for(int i = 0; i < n; i++){
    cin >> vetor[i];
  }
  for(int valor : vetor){
    soma += valor;
  }
  media = (double)soma / n;
  for(int valor : vetor){
    if(valor > media) cont++;
  }
  cout << cont << "\n";
}



/*
  --------------------------------------------------------------------------
  A3 — TROCO GULOSO (guloso: maior primeiro)   [reforco 🔴/🟢]
  --------------------------------------------------------------------------
  Dar troco de V com moedas {25, 10, 5, 1} (ilimitadas). Imprima o numero
  MINIMO de moedas. (Para ESTAS moedas o guloso funciona.)

  ENTRADA: V (0 <= V <= 1e9).
  SAIDA:   numero minimo de moedas.
  EXEMPLO
    41 -> 4      (25 + 10 + 5 + 1 = 41 -> 4 moedas)
  (Dica: pegue a maior que cabe. Use / e % em vez de subtrair de 1 em 1!)

  Peça dica se precisar;
*/
void A3(){
  int n, cont = 0; cin >> n;
  while(n >= 25){
    n -= 25;
    cont++;
  }
  while(n>=10){
    n -= 10;
    cont++;
  }
  while(n>=5){
    n-= 5;
    cont++;
  }
  while(n >= 1){
    n -= 1;
    cont++;
  }
  cout << cont << endl;
}



/*
  --------------------------------------------------------------------------
  A4 — MAXIMO DE ATIVIDADES (activity selection, pair + sort)   [reforco 🟢]
  --------------------------------------------------------------------------
  N atividades com inicio s[i] e fim f[i]. So uma por vez (sem sobrepor).
  Imprima o MAIOR numero de atividades possiveis.

  ENTRADA: N; depois N linhas com s[i] f[i] (0 <= s < f <= 1e9).
  SAIDA:   numero maximo de atividades sem conflito.
  EXEMPLO
    3 / (1 3)(2 5)(4 6)  -> 2
  (Dica: vector<pair> guardando {fim, inicio}, ordena pelo fim, ultimoFim.)

  Peça dica se precisar;
*/

void A4(){
  int n; cin >> n;
  vector<pair<long long, long long>> vetor(n);
  for(int i = 0; i < n; i++){
    long long inicio, fim;

    cin >> inicio >> fim;
    vetor[i] = {fim, inicio};
  }
  sort(vetor.begin(), vetor.end());
  int cont = 0;
  long long ultimoFim = LLONG_MIN;
  for(auto& [fim, inicio] : vetor){
    if(inicio>=ultimoFim){
      cont++;
      ultimoFim = fim;
    }
  }
  cout << cont << "\n";

}




/*

  ==========================================================================
  PARTE 2 — PREPARATORIOS (ferramentas que BITS usa: % 2, / 2, potencias de 2)
  ==========================================================================

  --------------------------------------------------------------------------
  A5 — PAR OU IMPAR (o ultimo bit!)
  --------------------------------------------------------------------------
  Leia N inteiros e, para cada um, imprima "PAR" ou "IMPAR".

  ENTRADA: N; depois N inteiros.
  SAIDA:   N linhas, "PAR" ou "IMPAR" para cada.
  EXEMPLO
    3 / 4 7 10   ->   PAR / IMPAR / PAR
  (Dica: x % 2. Curiosidade: x % 2 e o ULTIMO BIT de x em binario! Guarde.)

  Peça dica se precisar;
*/

void A5(){
  int n; cin >> n;
  vector<int> vetor(n);
  for(int i = 0; i < n; i++){
    cin >> vetor[i];
  }
  for(int valor : vetor){
    if(valor % 2 == 0){
      cout << "PAR" << endl;
    } else {
      cout << "IMPAR" << endl;
    }
  }
}





/*--------------------------------------------------------------------------
  A6 — QUANTAS VEZES DIVIDE POR 2 (ate ficar impar)
  --------------------------------------------------------------------------
  Leia um inteiro X (X >= 1). Imprima quantas vezes voce consegue dividir X
  por 2 (divisao inteira) ATE ele ficar impar (ou seja, quantos fatores 2).

  ENTRADA: X (1 <= X <= 1e9).
  SAIDA:   o numero de divisoes por 2.
  EXEMPLO
    40 -> 3      (40/2=20, 20/2=10, 10/2=5 impar -> 3 vezes)
    7  -> 0      (ja e impar)
  (Dica: enquanto X for par (X%2==0), divide X por 2 e conta. Isto e "quantos
   zeros no final do binario de X".)

  Peça dica se precisar;
*/

void A6(){
  int x, div = 0; cin >> x;
  while(x % 2 == 0){
    div++;
    x = x / 2;
  }
  cout << div << endl;
}







/*
  --------------------------------------------------------------------------
  A7 — POTENCIA DE 2? (numero com um so bit 1)
  --------------------------------------------------------------------------
  Leia um inteiro X (X >= 1). Imprima "SIM" se X for uma potencia de 2
  (1, 2, 4, 8, 16, ...), senao "NAO".

  ENTRADA: X (1 <= X <= 1e9).
  SAIDA:   "SIM" ou "NAO".
  EXEMPLOS
    8 -> SIM ;  16 -> SIM ;  1 -> SIM ;  6 -> NAO ;  12 -> NAO
  (Dica: uma potencia de 2 e um numero que voce consegue dividir por 2
   repetidamente ate chegar EXATAMENTE em 1, sem nunca sobrar resto.
   Em binario, potencia de 2 tem UM UNICO bit 1. Voce vera isso hoje.)

  Peça dica se precisar;
*/

void A7(){
  long long x; cin >> x;
  while(x % 2 == 0){
    x /= 2;
  }
  if(x == 1){
    cout << "SIM" << endl;
  } else {
    cout << "NAO" << endl;
  }
}









/*
  --------------------------------------------------------------------------
  A8 — CONVERTER DECIMAL -> BINARIO (na mao, com % 2 e / 2)
  --------------------------------------------------------------------------
  Leia um inteiro X (0 <= X <= 1e9). Imprima X em BINARIO (sem zeros a
  esquerda; para X=0, imprima "0").

  ENTRADA: X.
  SAIDA:   a representacao binaria de X.
  EXEMPLOS
    5  -> 101      (4+1)
    8  -> 1000
    0  -> 0
    6  -> 110      (4+2)
  (Dica: os bits saem de tras para frente com  X % 2  e depois  X /= 2,
   ate X virar 0. Voce precisa INVERTER a ordem no final -- pense em como.
   Isto e EXATAMENTE o conceito novo de hoje, feito na mao!)

  Peça dica se precisar;

============================================================================
*/

void A8(){
  long long x; cin >> x;

  if(x == 0) {cout << 0 << "\n";}
  string bin = "";
  while(x > 0){
    int bit = x%2;
    bin = char('0' + bit) + bin;
    x /= 2;
  }

  cout << bin << "\n";
}


