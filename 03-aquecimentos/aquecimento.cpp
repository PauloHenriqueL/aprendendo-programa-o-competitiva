/*
=============================================================================
  aquecimento.cpp — problemas curtos para REVISAR (repeticao espacada)
=============================================================================
  Cada problema reforca um conceito que voce JA viu. Resolva cada um na sua
  funcao. Quando terminar UM, me chame ("terminei o A") que eu compilo e
  testo como juiz (exemplos + casos de borda), sem entregar a resposta.

  Consulte visto.cpp se esquecer a sintaxe de algo.

  Para testar uma funcao, renomeie-a para main() (ou chame-a de um main()).

  INDICE (conceito reforcado):
    A  Contar letras            -> array de contagem + char->indice
    B  Maior e menor            -> vetor/vector + laco
    C  Ordena e imprime         -> sort
    D  Parenteses balanceados   -> pilha (stack)
    E  Soma dos digitos pares   -> extrair digitos (%,/) + paridade
    F  Palindromo               -> string (s[i]) + dois indices
    G  Top por frequencia       -> array de contagem + achar maximo
=============================================================================
*/

#include <bits/stdc++.h>
using namespace std;


/*
-----------------------------------------------------------------------------
  A - CONTAGEM DE LETRAS            (reforca: array de contagem, c-'a')
-----------------------------------------------------------------------------
  Dada uma palavra de letras minusculas, imprima quantas vezes cada letra
  DISTINTA aparece, em ordem alfabetica, uma por linha, no formato:
      letra quantidade
  Imprima apenas as letras que aparecem ao menos 1 vez.

  ENTRADA: uma linha com uma palavra (so letras minusculas), tamanho 1..1000.
  SAIDA:   uma linha "letra quantidade" por letra distinta, em ordem alfabetica.

  EXEMPLO
    Entrada: banana
    Saida:
      a 3
      b 1
      n 2
-----------------------------------------------------------------------------
*/
void A(){
    vector<int> indice(26, 0);
    string entrada;
    cin >> entrada;
    for(char c: entrada) {
      indice[(c - 'a')]++;
    }
    for(int i = 0; i < 26; i++) if(indice[i] > 0) cout << char('a' + i) << " " << indice[i] << endl;
}


/*
-----------------------------------------------------------------------------
  B - MAIOR E MENOR                 (reforca: vetor/leitura, laco, comparacao)
-----------------------------------------------------------------------------
  Leia N inteiros e imprima, numa unica linha, o MAIOR e o MENOR deles,
  separados por espaco (nesta ordem: maior menor).

  ENTRADA: primeira linha N; segunda linha com N inteiros separados por espaco.
  SAIDA:   "maior menor"
  RESTRICOES: 1 <= N <= 100000 ; valores cabem em int.

  EXEMPLO
    Entrada:
      5
      3 7 2 9 4
    Saida:
      9 2
-----------------------------------------------------------------------------
*/
void B(){
  int primeiro, n;
  cin >> n;
  cin >> primeiro;
  int menor = primeiro, maior = primeiro;
  for(int i = 1; i < n; i++){
    int x;
    cin >> x;
    if (x > maior) maior = x;
    if (x < menor) menor = x;
  }
  cout << maior << " " << menor;
}


/*
-----------------------------------------------------------------------------
  C - ORDENA E IMPRIME              (reforca: sort)
-----------------------------------------------------------------------------
  Leia N inteiros e imprima-os em ordem CRESCENTE, separados por espaco.

  ENTRADA: primeira linha N; segunda linha com N inteiros.
  SAIDA:   os N inteiros ordenados, separados por espaco.
  RESTRICOES: 1 <= N <= 100000.

  EXEMPLO
    Entrada:
      5
      3 7 2 9 4
    Saida:
      2 3 4 7 9
-----------------------------------------------------------------------------
*/
void C(){
  int n;
  cin >> n;
  vector<int> numeros(n);
  for(int i = 0; i < n; i++) cin >> numeros[i];
  sort(numeros.begin(), numeros.end());
  for(int i: numeros) cout << i << " ";
}

void C_array(){
  int n;
  cin >> n;
  int numeros[n];
  for(int i = 0; i < n; i++) cin >> numeros[i];
  sort(numeros, numeros + n);
  for(int i: numeros) cout << i << " ";
}

/*
-----------------------------------------------------------------------------
  D - PARENTESES BALANCEADOS        (reforca: pilha / stack)
-----------------------------------------------------------------------------
  Dada uma linha contendo apenas os caracteres '(' e ')', diga se os
  parenteses estao BALANCEADOS. Estao balanceados quando cada '(' tem um ')'
  correspondente e nenhum ')' aparece sem um '(' aberto antes.

  Imprima "sim" se balanceado, "nao" caso contrario.

  ENTRADA: uma linha com a sequencia de parenteses (tamanho 1..100000).
  SAIDA:   "sim" ou "nao".

  EXEMPLOS
    Entrada: (())()     Saida: sim
    Entrada: (()        Saida: nao
    Entrada: )(         Saida: nao

  DICA: pilha. '(' empilha; ')' desempilha (se a pilha estiver vazia ao ver
  um ')', ja e "nao"). No fim, tem que sobrar a pilha VAZIA.
-----------------------------------------------------------------------------
*/
void D(){
  stack<int> abertos;
  string entrada;
  bool ok = true;
  cin >> entrada;
  for(char c: entrada) {
    if(c == '(') abertos.push(c);
    else {
      if(abertos.empty()){
        ok = false;
        break;
      } else abertos.pop();
    }
  }
  if(ok && abertos.empty()) cout << "sim";
  else                                  cout << "nao";
}


/*
-----------------------------------------------------------------------------
  E - SOMA DOS DIGITOS PARES        (reforca: extrair digitos %,/ ; paridade)
-----------------------------------------------------------------------------
  Dado um inteiro nao-negativo X, imprima a soma apenas dos digitos PARES
  de X (0, 2, 4, 6, 8).

  ENTRADA: um inteiro X (0 <= X <= 1000000000).
  SAIDA:   a soma dos digitos pares de X.

  EXEMPLO
    Entrada: 123456
    Saida:   12
    (digitos pares: 2, 4, 6 -> 2+4+6 = 12)

  Obs: se X = 0, a soma e 0.
-----------------------------------------------------------------------------
*/
void E(){
  int div, resto, soma = 0;
  cin >> div;
  do {
    resto = div % 10;
    div /= 10;
    if(resto % 2 == 0) soma += resto;
  }
  while(div != 0);
  cout << soma;
}


/*
-----------------------------------------------------------------------------
  F - PALINDROMO                    (reforca: string, indices, s.size())
-----------------------------------------------------------------------------
  Uma palavra e palindromo se e igual lida de tras para frente (ex.: "arara").
  Dada uma palavra, imprima "sim" se for palindromo, "nao" caso contrario.

  ENTRADA: uma linha com uma palavra (so letras minusculas), tamanho 1..1000.
  SAIDA:   "sim" ou "nao".

  EXEMPLOS
    Entrada: arara    Saida: sim
    Entrada: casa     Saida: nao

  DICA: compare o caractere da esquerda com o da direita, andando para o meio.
  (dois indices: um comeca em 0, o outro em size()-1)
-----------------------------------------------------------------------------
*/
void F(){
  string entrada;
  cin >> entrada;
  bool palindromo = true;
  int esquerda = 0, direita = entrada.size() - 1;
  while(esquerda < direita){
    if(entrada[esquerda] != entrada[direita]){
      palindromo = false;
      break;
    }
    esquerda++;
    direita--;
  }
  if(palindromo) cout << "sim\n";
  else           cout << "nao\n";
}


/*
-----------------------------------------------------------------------------
  G - LETRA MAIS FREQUENTE          (reforca: array de contagem + achar maximo)
-----------------------------------------------------------------------------
  Dada uma palavra de letras minusculas, imprima a letra que MAIS aparece.
  Em caso de empate, imprima a que vem PRIMEIRO em ordem alfabetica.

  ENTRADA: uma linha com uma palavra (so letras minusculas), tamanho 1..100000.
  SAIDA:   uma unica letra.

  EXEMPLOS
    Entrada: banana   Saida: a      (a=3, n=2, b=1)
    Entrada: abba     Saida: a      (empate a=2, b=2 -> vence 'a')

  DICA: conte com array de contagem; depois percorra de 'a' a 'z' guardando a
  letra com maior contagem (use > estrito para o desempate alfabetico).
-----------------------------------------------------------------------------
*/
void G(){
  string entrada; cin >> entrada;
  int ind[26] = {};
  int maior = 0;
  for(char c: entrada) ind[c - 'a']++;
  for(int i = 0; i < 26; i++) if(ind[i] > maior) maior = ind[i];
  for(int i = 0; i < 26; i++) if(ind[i] == maior) {
    cout << char(i + 'a');
    break;
  }


}


// Para testar: renomeie a funcao desejada para main(), ou chame-a aqui.
int main(){
    // Ex.: para testar A, deixe apenas:  A();
    return 0;
}
