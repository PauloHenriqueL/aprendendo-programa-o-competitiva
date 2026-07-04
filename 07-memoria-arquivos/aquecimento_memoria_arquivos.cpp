/*
============================================================================
  AQUECIMENTO — MEMORIA (vector dinamico) e ARQUIVOS (ifstream/ofstream)
============================================================================
  Antes de resolver, leia a teoria em: teoria_memoria_arquivos.cpp
  Cada exercicio abaixo e um problema separado. Resolva um por vez; me chame
  ("terminei o M1") que eu testo como juiz. Peça dica se precisar.

  REGRA GERAL destes exercicios:
    - Para memoria: quando o tamanho so e conhecido em runtime, use vector.
    - Para arquivos: leia com ifstream e/ou escreva com ofstream, tratando o
      caso do arquivo nao abrir.
============================================================================


  --------------------------------------------------------------------------
  M1 — VETOR DE TAMANHO DINAMICO (memoria)
  --------------------------------------------------------------------------
  Leia um inteiro N e, em seguida, N inteiros. Guarde-os num vetor cujo
  tamanho so e decidido depois de ler N (nao use tamanho fixo). Imprima a
  soma e o maior elemento.

  ENTRADA
    Primeira linha: N.
    Segunda linha:  N inteiros.
  SAIDA
    Duas linhas: a soma e o maior elemento.
  RESTRICOES
    1 <= N <= 100000 ; cada numero cabe em int ; a soma pode NAO caber em int.

  EXEMPLO
    Entrada:            Saida:
      5                   46
      4 8 15 16 3         16
    (4+8+15+16+3 = 46 ; maior = 16)

  Peça dica se precisar;
*/
#include <bits/stdc++.h>
using namespace std;

void m1(){
  int n;
  cin >> n;

  vector <int> vetor(n);

  long long soma = 0;
  int maior = INT_MIN;
  for(int i = 0; i < n; i++) {
    cin >> vetor[i];
    soma += vetor[i];
    if(vetor[i] > maior) maior = vetor[i];
  }

  cout << soma << "\n"<< maior << "\n";

}










/*

  --------------------------------------------------------------------------
  M2 — MATRIZ DINAMICA (memoria em 2 dimensoes)
  --------------------------------------------------------------------------
  Leia dois inteiros L e C (linhas e colunas) e depois L*C inteiros que
  formam uma matriz L x C, lida linha a linha. O tamanho so e conhecido em
  runtime. Imprima a soma de cada linha, uma por linha.

  ENTRADA
    Primeira linha: L e C.
    Depois: L linhas, cada uma com C inteiros.
  SAIDA
    L linhas: a soma dos elementos de cada linha (na ordem).
  RESTRICOES
    1 <= L, C <= 500 ; cada numero cabe em int.

  EXEMPLO
    Entrada:            Saida:
      2 3                 6
      1 2 3               15
      4 5 6

  Peça dica se precisar;

*/

void m2(){
  int l, c;
  cin >> l >> c;

  for(int i = 0; i < l; i++){
    long long soma = 0;
    for(int j = 0; j  < c; j++){
        int x;
        cin >> x;
        soma += x;
    }
    cout << soma << endl;
  }
}





/*
  --------------------------------------------------------------------------
  M3 — ESCREVER RESULTADO NUM ARQUIVO (ofstream)
  --------------------------------------------------------------------------
  Leia N (da entrada padrao) e depois N inteiros. Calcule a soma. Em vez de
  imprimir na tela, ESCREVA a soma no arquivo "resultado.txt" (uma linha, so
  o numero). O programa nao deve imprimir nada na saida padrao.

  ENTRADA (padrao)
    Primeira linha: N. Segunda linha: N inteiros.
  SAIDA
    Nenhuma na tela. Crie o arquivo "resultado.txt" contendo a soma.
  RESTRICOES
    1 <= N <= 100000 ; a soma pode nao caber em int.

  EXEMPLO
    Entrada:            Conteudo de resultado.txt:
      3                   60
      10 20 30

  Peça dica se precisar;

*/

void m3(){
  int n;
  long long soma = 0;
  cin >> n;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    soma += x;
  }
  ofstream fout("resultado.txt");
  fout << soma;
  fout.close();



}





/*
  --------------------------------------------------------------------------
  M4 — LER DE UM ARQUIVO (ifstream) ATE O FIM
  --------------------------------------------------------------------------
  Existe um arquivo "numeros.txt" contendo uma quantidade DESCONHECIDA de
  inteiros (separados por espacos e/ou quebras de linha). Leia TODOS eles do
  arquivo (voce nao sabe quantos sao) e imprima, na saida padrao, quantos
  numeros havia e a soma deles. Se o arquivo nao existir/abrir, imprima
  "ERRO" e encerre.

  ENTRADA
    O arquivo "numeros.txt" (a entrada padrao nao e usada).
  SAIDA (padrao)
    Duas linhas: a quantidade de numeros e a soma deles.
  RESTRICOES
    ate ~1e6 numeros ; a soma pode nao caber em int.

  EXEMPLO
    numeros.txt:        Saida:
      3 1 4              7
      1 5                25
      9 2
    (sao 7 numeros ; 3+1+4+1+5+9+2 = 25)

  Peça dica se precisar;

*/

void m4(){
  ifstream fin("numeros.txt");
  if (!fin) {cout << "ERRO\n"; return;}
  int x, cont = 0;
  long long soma = 0;
  while(fin >> x){
    soma += x;
    cont++;
  }
  cout << cont << endl;
  cout <<  soma << endl;
  fin.close();
}






/*

  --------------------------------------------------------------------------
  M5 — COPIAR E TRANSFORMAR (ler de um arquivo, escrever em outro)
  --------------------------------------------------------------------------
  Leia todas as palavras do arquivo "entrada.txt" e escreva-as, uma por
  linha e EM ORDEM ALFABETICA, no arquivo "ordenado.txt". (Reforca: ler ate
  o fim, guardar num vector, ordenar com sort, escrever em arquivo.)

  ENTRADA
    O arquivo "entrada.txt" com varias palavras (separadas por espaco/linha).
  SAIDA
    O arquivo "ordenado.txt" com as palavras ordenadas, uma por linha.
    Nada na saida padrao.
  RESTRICOES
    ate ~1e5 palavras ; cada palavra so tem letras minusculas.

  EXEMPLO
    entrada.txt:        ordenado.txt:
      banana caju          abacaxi
      abacaxi damasco      banana
                           caju
                           damasco

  Peça dica se precisar;

============================================================================
*/

void m5(){
  ifstream fin ("entrada.txt");
  if(!fin) {cout << "ERRO"; return;}
  string x;
  vector<string> vetor;
  while(fin >> x){
    vetor.push_back(x);
  }
  sort(vetor.begin(), vetor.end());
  fin.close();
  ofstream fout("ordenado.txt");
  if(!fout){cout << "ERRO"; return;}
  for(string s : vetor){
    fout << s << "\n";
  }
  fout.close();
}
