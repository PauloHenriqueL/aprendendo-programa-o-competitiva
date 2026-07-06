#include <bits/stdc++.h>
using namespace std;

/*
============================================================================
  AQUECIMENTO DO DIA — 8 exercicios (4 reforco + 4 preparatorios p/ GULOSO)
============================================================================
  Resolva um por vez; me chame ("terminei o A1"). Sou juiz. Peça dica se
  precisar. Formato: so enunciado, o codigo e seu.

  Estes 8 preparam o conceito novo de hoje: ALGORITMO GULOSO.
============================================================================


  ==========================================================================
  PARTE 1 — REFORCO (conceitos ja vistos; foco no que voce mais erra)
  ==========================================================================

  --------------------------------------------------------------------------
  A1 — SOMA QUE ESTOURA (overflow / long long)   [reforco 🔴]
  --------------------------------------------------------------------------
  Leia N e depois N inteiros (cada um ate 1e9). Imprima a soma de todos.

  ENTRADA: N (1<=N<=1e5); depois N inteiros (1<=Ai<=1e9).
  SAIDA:   a soma.
  EXEMPLO
    Entrada: 3 / 1000000000 1000000000 1000000000     Saida: 3000000000
  (Pense: a soma cabe em int?)

  Peça dica se precisar;

*/

void A1(){
  long long soma = 0;
  int n; cin >> n;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    soma += x;
  }
  cout << soma;

}



/*


  --------------------------------------------------------------------------
  A2 — ESTA NO INTERVALO? (comparacao / && / borda inclusiva)   [reforco 🔴]
  --------------------------------------------------------------------------
  Leia tres inteiros X, A, B. Imprima "DENTRO" se A <= X <= B (inclusive as
  pontas), senao "FORA".

  ENTRADA: tres inteiros X A B.
  SAIDA:   "DENTRO" ou "FORA".
  EXEMPLOS
    5 2 8 -> DENTRO ;  2 2 2 -> DENTRO ;  1 2 8 -> FORA ;  8 2 8 -> DENTRO
  (Cuidado: NAO escreva a<x<b encadeado! E as pontas contam.)

  Peça dica se precisar;
*/

void A2(){
  int x, a, b;
  cin >> x >> a >> b;
  if(a <= x && x <= b){
    cout << "DENTRO";
  } else {
    cout << "FORA";
  }
}






/*
  --------------------------------------------------------------------------
  A3 — MAIOR E POSICAO (indice do vetor / max sem iniciar em 0)   [reforco 🔴]
  --------------------------------------------------------------------------
  Leia N e N inteiros. Imprima o MAIOR valor e a POSICAO (base 1) da primeira
  ocorrencia dele.

  ENTRADA: N; depois N inteiros (podem ser negativos).
  SAIDA:   duas informacoes numa linha: maior valor e a posicao (1..N).
  EXEMPLO
    5 / -3 -1 -7 -1 -9   ->   -1 2
  (Nao inicie o maior em 0! Cuidado com indices 0..N-1.)

  Peça dica se precisar;

*/

void A3(){
  int n; cin >>n;
  vector<int> vetor(n);
  for(int i = 0; i < n; i++){
    cin >> vetor[i];
  }
  int maior = vetor[0], posi = 1;
  for(int i = 0; i < n; i++){
    if(vetor[i] > maior){
      maior = vetor[i];
      posi = i + 1;
    }
  }
  cout << maior << " " << posi << "\n";
}





/*
  --------------------------------------------------------------------------
  A4 — MDC DE DOIS NUMEROS (Euclides recursivo)   [reforco 🟢]
  --------------------------------------------------------------------------
  Leia dois inteiros A e B e imprima MDC(A, B) usando o Algoritmo de Euclides.

  ENTRADA: dois inteiros A B (1<=A,B<=1e9).
  SAIDA:   o MDC.
  EXEMPLOS
    12 18 -> 6 ;   100 100 -> 100 ;   17 5 -> 1
  (Escreva sua funcao mdc recursiva.)

  Peça dica se precisar;
*/

int A4(int a, int b){
  if(b == 0) return a;
  return A4(b, a % b);
}






/*

  ==========================================================================
  PARTE 2 — PREPARATORIOS (ferramentas que o GULOSO usa: ordenar + varrer)
  ==========================================================================

  --------------------------------------------------------------------------
  A5 — ORDENAR E IMPRIMIR (sort crescente)
  --------------------------------------------------------------------------
  Leia N inteiros, ordene em ordem CRESCENTE e imprima-os separados por espaco.

  ENTRADA: N; depois N inteiros.
  SAIDA:   os N inteiros ordenados.
  EXEMPLO
    5 / 4 1 5 2 3   ->   1 2 3 4 5
  (Reforca sort — ferramenta central do guloso.)

  Peça dica se precisar;
*/


void A5(){
  int n; cin >> n;
  vector<int> vetor(n);
  for(int i =0; i < n; i++){
    cin >> vetor[i];
  }
  sort(vetor.begin(), vetor.end());
  for(int valor : vetor){
    cout << valor << " ";
  }
}












/*

  --------------------------------------------------------------------------
  A6 — ORDENAR DECRESCENTE E SOMAR OS K MAIORES
  --------------------------------------------------------------------------
  Leia N e K, depois N inteiros. Imprima a soma dos K MAIORES valores.

  ENTRADA: N K (1<=K<=N); depois N inteiros (ate 1e9).
  SAIDA:   a soma dos K maiores.
  EXEMPLO
    5 2 / 4 1 5 2 3   ->   9      (os 2 maiores: 5 e 4)
  (Dica: ordene e pegue do maior para o menor. Soma pode estourar int!)
  (Esta e a ESSENCIA do guloso: "pegar os melhores primeiro".)

  Peça dica se precisar;

*/



void A6(){
  int n, k; cin >> n >> k;
  vector<int> vetor(n);
  long long soma = 0;
  for(int i = 0; i < n; i++){
    cin >> vetor[i];
  }
  sort(vetor.begin(), vetor.end());
  for(int i = n-k; i < n; i++){
    soma += vetor[i];
  }
  cout << soma << "\n";
}





/*
  --------------------------------------------------------------------------
  A7 — MAXIMO DE ITENS NA MOCHILA POR CONTAGEM (pegar os mais baratos)
  --------------------------------------------------------------------------
  Voce tem um orcamento M e N itens com precos dados. Comprando cada item no
  maximo uma vez, qual o MAIOR numero de itens que voce consegue comprar sem
  passar do orcamento?

  ENTRADA: N M; depois N precos (1<=preco<=1e9).
  SAIDA:   o numero maximo de itens compraveis.
  EXEMPLO
    5 10 / 3 1 4 1 5   ->   4     (compra 1,1,3,4 = 9 <= 10 ; o 5 nao cabe)
  (Dica: para MAXIMIZAR a quantidade, compre os MAIS BARATOS primeiro.
   Ordene crescente e vá somando ate estourar o orcamento. ISSO E GULOSO!)

  Peça dica se precisar;

*/


void A7(){
  int n, salario; cin >> n >> salario;
  vector<int> produtos;
  int cont = 0;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    produtos.push_back(x);
  }
  sort(produtos.begin(), produtos.end());
  for(int valor : produtos){
    if(valor <= salario){
      cont++;
      salario -= valor;
    }
  }
  cout << cont << "\n";
}



/*
  --------------------------------------------------------------------------
  A8 — TROCO COM MENOS MOEDAS (guloso classico do recall)
  --------------------------------------------------------------------------
  Voce precisa dar um troco de valor V usando moedas de 50, 25, 10, 5 e 1
  (quantidade ilimitada de cada). Imprima o MENOR numero de moedas necessario.

  ENTRADA: um inteiro V (0<=V<=1e9).
  SAIDA:   o numero minimo de moedas.
  EXEMPLO
    87 -> 5      (50 + 25 + 10 + 1 + 1 = 87 -> 5 moedas)
  (Dica: pegue sempre a MAIOR moeda que ainda cabe, repita. E o guloso que
   voce descreveu no recall. Para ESTAS moedas o guloso da o otimo.)

  Peça dica se precisar;

============================================================================
*/


void A8(){
  int valor, cont = 0; cin >> valor;
// 50, 25, 10, 5 e 1
  while(valor >= 50){
    valor -= 50;
    cont++;
  }
  while(valor >= 25){
    valor -= 25;
    cont++;
  }
  while(valor >= 10){
    valor -= 10;
    cont++;
  }
  while(valor >= 5){
    valor -= 5;
    cont++;
  }
  while(valor >= 1){
    valor -= 1;
    cont++;
  }
  cout << cont << "\n";

}

