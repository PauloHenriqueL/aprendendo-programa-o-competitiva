/*
=============================================================================
  aquecimento2.cpp — 2a rodada de revisao (repeticao espacada)
=============================================================================
  Reforca: map, dois ponteiros, sort, contagem, extrair digitos, e prepara
  o terreno para BUSCA BINARIA (busca linear vs ordenada).

  Resolva cada um na sua funcao. Terminou um? Me chame ("terminei o H").
  Eu compilo e testo como juiz (exemplos + casos de borda).
  Consulte visto.cpp / votacao.cpp se precisar da sintaxe.

  INDICE (conceito reforcado):
    H  Palavras repetidas       -> map (contar strings)
    I  Par que soma ao alvo     -> sort + DOIS PONTEIROS (ponte p/ busca)
    J  Inverter um numero       -> extrair digitos (%,/)
    K  Mediana                  -> sort + acessar posicao do meio
    L  Existe o elemento?       -> busca LINEAR (para comparar com binaria)
=============================================================================
*/

#include <bits/stdc++.h>
using namespace std;


/*
-----------------------------------------------------------------------------
  H - PALAVRAS REPETIDAS            (reforca: map<string,int>)
-----------------------------------------------------------------------------
  Leia N palavras. Imprima, em ordem alfabetica, apenas as palavras que
  aparecem MAIS DE UMA VEZ, com a sua contagem, no formato:  palavra contagem

  ENTRADA: primeira linha N; depois N palavras (uma por linha ou separadas
           por espaco).
  SAIDA:   as palavras repetidas (contagem >= 2), em ordem alfabetica,
           uma por linha: "palavra contagem". Se nenhuma repetir, nao imprime
           nada.
  RESTRICOES: 1 <= N <= 100000.

  EXEMPLO
    Entrada:
      6
      sol lua sol mar lua sol
    Saida:
      lua 2
      sol 3
    (mar aparece 1 vez -> nao entra)
-----------------------------------------------------------------------------
*/
void H(){
  int n;
  string palavra;
  map<string, int> mapa;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> palavra;
    mapa[palavra]++;
  }
  for(auto& par : mapa){
    if(par.second >= 2) cout << par.first << " " << par.second << endl;
  }
}


/*
-----------------------------------------------------------------------------
  I - PAR QUE SOMA AO ALVO         (reforca: sort + dois ponteiros)
-----------------------------------------------------------------------------
  Dado um vetor de N inteiros e um valor ALVO, diga se existem DOIS elementos
  (em posicoes diferentes) cuja soma seja exatamente ALVO.

  Imprima "SIM" se existir tal par, "NAO" caso contrario.

  ENTRADA: primeira linha N e ALVO; segunda linha com N inteiros.
  SAIDA:   "SIM" ou "NAO".
  RESTRICOES: 2 <= N <= 100000.

  EXEMPLO
    Entrada:
      5 9
      2 7 11 4 5
    Saida:
      SIM
    (4 + 5 = 9)

  DICA: ordene o vetor. Use dois ponteiros: um no inicio (i) e um no fim (j).
  - se v[i]+v[j] == alvo -> achou (SIM)
  - se a soma < alvo -> precisa somar mais -> i++
  - se a soma > alvo -> precisa somar menos -> j--
  Pare quando i >= j.
-----------------------------------------------------------------------------
*/
void I(){
  int n, alvo;
  cin >> n;
  cin >> alvo;
  bool existe = false;
  vector<int> vetor(n,0);
  for(int i = 0; i < n; i++) cin >> vetor[i];
  sort(vetor.begin(), vetor.end());
  int esquerda = 0, direita = vetor.size() - 1;
  while(esquerda < direita){
    int soma = vetor[esquerda] + vetor[direita];
    if(soma == alvo) {existe = true; break;}
    else if(soma < alvo) esquerda++;
    else if(soma > alvo) direita--;
  }
  if(existe)  cout << "SIM";
  else        cout << "NAO";
}



/*
-----------------------------------------------------------------------------
  J - INVERTER UM NUMERO           (reforca: extrair digitos %,/)
-----------------------------------------------------------------------------
  Dado um inteiro nao-negativo X, imprima o numero com os digitos invertidos.
  Zeros a esquerda no resultado simplesmente desaparecem (ex.: 1200 -> 21).

  ENTRADA: um inteiro X (0 <= X <= 1000000000).
  SAIDA:   o numero invertido.

  EXEMPLOS
    Entrada: 123     Saida: 321
    Entrada: 1200    Saida: 21
    Entrada: 0       Saida: 0
123
3
  DICA: pegue o ultimo digito (x % 10) e va construindo o resultado:
  resultado = resultado * 10 + digito;  depois x /= 10.
-----------------------------------------------------------------------------
*/
void J(){
  int n, resposta = 0;
  cin >> n;
  while(n > 0){
    resposta = resposta * 10 + n % 10;
    n /= 10;
  }
  cout << resposta << endl;
}


/*
-----------------------------------------------------------------------------
  K - MEDIANA                      (reforca: sort + posicao do meio)
-----------------------------------------------------------------------------
  Leia N inteiros (N e sempre IMPAR). Imprima a MEDIANA: o valor que fica no
  MEIO quando os numeros estao ordenados.

  ENTRADA: primeira linha N (impar); segunda linha com N inteiros.
  SAIDA:   a mediana.
  RESTRICOES: 1 <= N <= 99999 (N impar).

  EXEMPLO
    Entrada:
      5
      7 1 3 9 5
    Saida:
      5
    (ordenado: 1 3 5 7 9 -> o do meio e o 5, posicao N/2 = 2)

  DICA: ordene e pegue o elemento da posicao N/2 (divisao inteira).
-----------------------------------------------------------------------------
*/
void K(){
  int n, posicao;
  cin >> n;
  vector<int> vetor(n);
  for(int i = 0; i < n; i++){
    cin >> vetor[i];
  }
  sort(vetor.begin(), vetor.end());


  cout << vetor[n/2] << endl;
}


/*
-----------------------------------------------------------------------------
  L - EXISTE O ELEMENTO? (busca LINEAR)   (ponte para BUSCA BINARIA)
-----------------------------------------------------------------------------
  Leia N inteiros e depois um valor ALVO. Diga se o ALVO aparece entre os N
  numeros. Aqui use BUSCA LINEAR (percorrer todos) — no busca.cpp voce fara
  a versao BINARIA e vera a diferenca de eficiencia.

  Imprima "achei" se o alvo existe, "nao achei" caso contrario.

  ENTRADA: primeira linha N; segunda linha com N inteiros; terceira linha ALVO.
  SAIDA:   "achei" ou "nao achei".
  RESTRICOES: 1 <= N <= 100000.

  EXEMPLO
    Entrada:
      5
      4 8 15 16 23
      15
    Saida:
      achei

  DICA: um for percorrendo os N; se algum == alvo, marque uma flag.
  (Guarde na cabeca: isto e O(N) por consulta. A busca binaria fara O(log N).)
-----------------------------------------------------------------------------
*/
void L(){
  int n, alvo;
  bool existe = false;

  cin >> n;
  vector <int> vetor(n);
  for(int i = 0; i < n; i++){
    cin >> vetor[i];
  }
  cin >> alvo;
  for(int i = 0; i < n; i++){
    if(vetor[i] == alvo){
      existe = true;
    }
  }
  if(existe == true){
    cout << "achei\n"; 
  } else {
    cout << "nao achei\n";
  }
}


// Para testar: renomeie a funcao desejada para main(), ou chame-a de um main().
int main(){
    L();
    return 0;
}
