/*
=============================================================================
  aquecimento_recursao.cpp — primeiros passos com RECURSAO
=============================================================================
  Cada funcao DEVE ser recursiva (chamar a si mesma). Regras de toda
  recursao: (1) um CASO BASE (quando parar) e (2) um CASO RECURSIVO que
  chama a si mesmo com um problema MENOR, caminhando ate o caso base.

  Resolva cada uma. Terminou? Me chame ("terminei o R1"). Eu testo como juiz.

  INDICE:
    R1  Soma de 1 a N          (recursao numerica simples)
    R2  Potencia (base^exp)    (reduzir o expoente)
    R3  Somar digitos          (recursao + % e /)
    R4  Contar para baixo      (imprimir na descida)
    R5  Fibonacci              (dois ramos recursivos)
=============================================================================
*/

#include <bits/stdc++.h>
using namespace std;


/*
-----------------------------------------------------------------------------
  R1 - SOMA DE 1 A N
-----------------------------------------------------------------------------
  Escreva uma funcao RECURSIVA que calcule 1 + 2 + 3 + ... + N.
  Leia N e imprima a soma.

  Ideia: soma(N) = N + soma(N-1);  caso base: soma(0) = 0.

  ENTRADA: um inteiro N.
  SAIDA:   a soma de 1 ate N.
  RESTRICOES: 0 <= N <= 10000.

  EXEMPLO
    Entrada: 5
    Saida:   15
    (1+2+3+4+5 = 15)
-----------------------------------------------------------------------------
*/
long long soma(int n){
  long long total;
  if(n==0)  return 0;
  else{
    total = (n + soma(n-1));
    return total;
  }
}

long long gauss(int n){
  long long total;
  return (n * (n+1))/2;
}


/*
-----------------------------------------------------------------------------
  R2 - POTENCIA (base elevado a expoente)
-----------------------------------------------------------------------------
  Escreva uma funcao RECURSIVA que calcule base^exp (base elevado a exp),
  com exp >= 0. Leia base e exp e imprima o resultado.

  Ideia: potencia(b, e) = b * potencia(b, e-1);  caso base: potencia(b, 0) = 1.

  ENTRADA: dois inteiros na mesma linha: base e exp.
  SAIDA:   base elevado a exp.
  RESTRICOES: exp >= 0; resultado cabe em long long.

  EXEMPLO
    Entrada: 2 10
    Saida:   1024

    Entrada: 5 0
    Saida:   1     (qualquer base elevado a 0 e 1)
-----------------------------------------------------------------------------
*/
long long potencia(long long base, int exp){
    if(exp == 0) return 1;
    else         return base * potencia(base, exp -1);
}


/*
-----------------------------------------------------------------------------
  R3 - SOMA DOS DIGITOS (recursiva)
-----------------------------------------------------------------------------
  Escreva uma funcao RECURSIVA que some os digitos de um inteiro X >= 0.
  Leia X e imprima a soma dos digitos.

  Ideia: somaDig(X) = (X % 10) + somaDig(X / 10);  caso base: somaDig(0) = 0.

  ENTRADA: um inteiro X (X >= 0).
  SAIDA:   a soma dos digitos de X.

  EXEMPLO
    Entrada: 1234
    Saida:   10    (1+2+3+4)

    Entrada: 0
    Saida:   0
-----------------------------------------------------------------------------
*/
int somaDig(int x){
    if(x == 0) return 0;
    else       return (x % 10 + somaDig(x/10));
    return 0;
}


/*
-----------------------------------------------------------------------------
  R4 - CONTAR PARA BAIXO
-----------------------------------------------------------------------------
  Escreva uma funcao RECURSIVA que imprima os numeros de N ate 1, um por
  linha (em ordem decrescente). Leia N.

  Ideia: imprime N, depois chama para N-1; caso base: se N < 1, nao faz nada.

  ENTRADA: um inteiro N (N >= 0).
  SAIDA:   os numeros de N ate 1, um por linha. Se N = 0, nao imprime nada.

  EXEMPLO
    Entrada: 3
    Saida:
      3
      2
      1
-----------------------------------------------------------------------------
*/
void contarParaBaixo(int n){
  if(n == 0) return;
  else{
    cout << (n) << endl;
    contarParaBaixo(n-1);
  }
}


/*
-----------------------------------------------------------------------------
  R5 - FIBONACCI (recursivo classico)
-----------------------------------------------------------------------------
  A sequencia de Fibonacci: fib(0)=0, fib(1)=1, e fib(n)=fib(n-1)+fib(n-2).
  Escreva uma funcao RECURSIVA que retorne fib(n). Leia n e imprima fib(n).

  Ideia: DOIS casos base (n==0 e n==1) e a soma de DUAS chamadas recursivas.

  ENTRADA: um inteiro n.
  SAIDA:   fib(n).
  RESTRICOES: 0 <= n <= 40 (recursao simples fica lenta acima disso).

  EXEMPLO
    Entrada: 7
    Saida:   13
    (sequencia: 0 1 1 2 3 5 8 13 -> o de indice 7 e 13)

    Entrada: 0
    Saida:   0
-----------------------------------------------------------------------------
*/
long long fib(int n){
    if(n == 0) return 0;
    else if(n == 1) return 1;
    else return (fib(n-1) + fib(n-2));

}


// Para testar: chame a funcao desejada a partir do main.
int main(){
    // Exemplos de como testar (descomente um):
    // int n; cin >> n; cout << soma(n) << "\n";
    // cout << potencia(2, 10) << "\n";
    // cout << somaDig(1234) << "\n";
    // contarParaBaixo(3);
    // cout << fib(7) << "\n";
    return 0;
}
