#include <bits/stdc++.h>
using namespace std;




/*
=============================================================================
  AQUECIMENTO — 2026-07-08 — rumo a DOIS PONTEIROS
=============================================================================
  8 exercícios. Escreva UMA FUNÇÃO por exercício (ou um main separado por vez).
  Compile sempre com:
      g++ -std=c++17 -Wall -Wextra -Wshadow -O2 arquivo.cpp -o prog

  BLOCO 1 (A1-A4) — REVISÃO dirigida dos seus 🟡 do recall de hoje.
  BLOCO 2 (A5-A8) — PREPARAÇÃO para dois ponteiros.

  Faça um de cada vez e me avise. Eu sou o juiz.
=============================================================================


-----------------------------------------------------------------------------
  A1 — Leitura segura (o bug que te pegou 2x)
-----------------------------------------------------------------------------
  Leia um inteiro N (1 <= N <= 100000) e depois N inteiros.
  Imprima a SOMA deles.

  RESTRIÇÃO EXTRA (importante): cada valor cabe em int, mas pode ser até
  1000000000 (1e9) em módulo.

  Entrada:
    3
    1000000000 1000000000 1000000000
  Saída:
    3000000000

  (Sim, isso é uma armadilha. Duas, na verdade.)

*/

void A1(){
  int n; cin >> n;
  long long soma = 0;
  for(int i = 0;  i < n; i++){
    long long x; cin >> x;
    soma += x;
  }
  cout << soma << "\n";
}








/*
-----------------------------------------------------------------------------
  A2 — Vizinhos (o limite correto do laço)
-----------------------------------------------------------------------------
  Leia N e N inteiros. Imprima QUANTOS pares de posições VIZINHAS (i, i+1)
  têm valores iguais.

  Entrada:
    6
    1 1 2 3 3 3
  Saída:
    3
  (pares: (0,1), (3,4), (4,5))

  Casos de borda que eu VOU testar: N = 1.
*/

void A2(){
  int n, cont = 0; cin >> n;
  vector<int> vetor(n);
  for(int i = 0; i < n; i++){
    cin >> vetor[i];
  }
  for(int i = 0; i < n - 1; i++){
    if(vetor[i] == vetor[i+1]){
      cont++;
    }
  }
  cout << cont << "\n";
}





/*
-----------------------------------------------------------------------------
  A3 — Overflow silencioso (a multiplicação estoura ANTES)
-----------------------------------------------------------------------------
  Leia dois inteiros A e B (1 <= A, B <= 1000000000).
  Imprima o produto A*B.

  Entrada:
    100000 100000
  Saída:
    10000000000

  Depois de resolver, me diga: se você escrever
      long long r = a * b;
  o que sai? Por quê?
  sai um valor mais sai errado.
*/

void A3(){
  int a, b; cin >> a >> b;
  long long soma = (long long) a * b;
  cout << soma << "\n";
}



/*
-----------------------------------------------------------------------------
  A4 — map vs vector<pair> (escolha a estrutura certa)
-----------------------------------------------------------------------------
  Leia N (1 <= N <= 100000) linhas, cada uma com o NOME de um produto (string
  sem espaços) e a QUANTIDADE vendida (int).
  Um mesmo produto pode aparecer várias vezes — some as quantidades.

  Imprima os produtos ORDENADOS POR QUANTIDADE TOTAL, do MAIOR para o MENOR.
  Em caso de empate, ordem alfabética do nome.

  Entrada:
    5
    banana 3
    maca 10
    banana 4
    uva 7
    maca 1

  Saída:
    maca 11
    uva 7
    banana 7

  ATENÇÃO: você vai precisar das DUAS estruturas. Pense: qual serve para
  ACUMULAR por chave? Qual serve para ORDENAR por valor?
*/


void A4(){
  int n; cin >> n;
  map<string, int> total;
  for(int i =0; i < n; i++){
    int x;
    string nome;
    cin >> nome >> x;
    total[nome] += x;
  }
  vector<pair<int, string>> lista;

  for(auto& [nome, qtd] : total){
    lista.push_back({-qtd, nome});
  }

  sort(lista.begin(), lista.end());
  for(auto& [negQt, nome] : lista){
    cout << nome << " " << -negQt << "\n";
  }
  
}



/*
-----------------------------------------------------------------------------
  A5 — Um ponteiro em cada ponta (palíndromo, de novo)
-----------------------------------------------------------------------------
  Leia uma string S (só letras minúsculas, 1 <= |S| <= 100000).
  Imprima "SIM" se for palíndromo, "NAO" caso contrário.

  Entrada:  arara      Saída: SIM
  Entrada:  arroz      Saída: NAO

  Você já fez isso. Agora faça de propósito com DOIS ÍNDICES: um em 0, outro
  em |S|-1, andando um em direção ao outro. Repare no formato do laço.
*/


void A5(){
  string palavra; cin >> palavra;
  int direita = palavra.size() -1, esquerda = 0;
  bool palindrome = true;
  while(esquerda < direita){
    if(palavra[esquerda] != palavra[direita]){
      palindrome = false;
      break;
    } else {
      esquerda++;
      direita--;
    }
  }
  if(palindrome)  cout << "SIM\n";
  else            cout << "NAO\n";
}







/*
-----------------------------------------------------------------------------
  A6 — Inverter um vetor no lugar (dois ponteiros que trocam)
-----------------------------------------------------------------------------
  Leia N e N inteiros. Imprima os N inteiros na ORDEM INVERSA — mas sem criar
  um segundo vetor e sem usar reverse(). Troque os elementos das pontas.

  Entrada:
    5
    1 2 3 4 5
  Saída:
    5 4 3 2 1

  Pergunta que eu vou te fazer: quantas trocas acontecem? E quando o laço para?
*/

void A6(){
  int n; cin >> n;
  vector<int> vetor(n);
  for(int i = 0; i < n; i++){
    cin >> vetor[i];
  }
  int i = 0, f = n-1;
  while(i < f){
    int temp = vetor[i];
    vetor[i] = vetor[f];
    vetor[f] = temp;
    i++;
    f--;
  }
  for(int valor : vetor){
    cout << valor << " ";
  }
  cout << "\n";
}



/*
-----------------------------------------------------------------------------
  A7 — Ordenado: existe o valor X? (contraste linear x binária)
-----------------------------------------------------------------------------
  Leia N e N inteiros JÁ ORDENADOS em ordem crescente. Depois leia X.
  Imprima "SIM" se X está no vetor, "NAO" caso contrário.

  Entrada:
    5
    2 4 6 8 10
    8
  Saída:
    SIM

  Resolva com BUSCA BINÁRIA na mão (lo, hi, meio). Não use binary_search().
  Cuidado com o cálculo do meio (você já viu o truque anti-overflow).
*/


void A7(){
  int n; cin >> n;
  bool achei = false;
  vector<int> vetor(n);
  for(int i = 0; i < n; i++){
    cin >> vetor[i];
  }
  int alvo; cin >> alvo;
  int lo = 0;
  int hi = n - 1, meio = 0;

  while(lo <= hi){
    meio = lo + (hi - lo)/2;
    if(vetor[meio] < alvo){
      hi = meio -1;
    } else if (vetor[meio] > alvo){
      lo = meio + 1;
    } else if(vetor[meio] == alvo){
      achei = true;
      break;
    }
  }
  if(achei) cout << "SIM";
  else      cout << "NAO";
}




/*
-----------------------------------------------------------------------------
  A8 — Soma corrente / prefixos (prepara a intuição de "descartar em bloco")
-----------------------------------------------------------------------------
  Leia N (1 <= N <= 100000) e N inteiros POSITIVOS.
  Depois leia Q consultas (1 <= Q <= 100000). Cada consulta é um par L R
  (0 <= L <= R < N). Para cada consulta, imprima a soma de v[L..R] (inclusive
  nas duas pontas!).

  Entrada:
    5
    1 2 3 4 5
    2
    0 4
    1 3
  Saída:
    15
    9

  ATENÇÃO: N e Q são grandes. Somar do L até o R em cada consulta é O(N*Q)
  = 10^10 operações -> TLE. Pense em PRÉ-CALCULAR alguma coisa uma única vez.
  Dica de conceito (não de código): "soma acumulada" / "prefix sum".

  E sim: cuidado com o tipo da soma.

=============================================================================
*/


void A8(){
  int n; cin >> n;

  vector<int> vetor(n);
  for(int i = 0; i < n; i++){
    cin >> vetor[i];
  }
  int q; cin >> q;
  vector<pair<int, int>> pares(n);
  for(int i = 0; i < q; i++){
    int l, r; cin >> l >> r;
    pares[i] = {l, r};
  }
  for(auto& [l, r] : pares){
    long long soma = 0;
    for(int i = l; i <= r; l++){
      soma += vetor[l];
    }
    cout << soma << "\n";
  }

}


void A8_otima(){
    int n; cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    // 1) PRE-CALCULA UMA UNICA VEZ.  pre tem n+1 posicoes.
    vector<long long> pre(n + 1);
    pre[0] = 0;                                 // soma de zero elementos
    for (int i = 0; i < n; i++)
        pre[i + 1] = pre[i] + v[i];             // acumula o proximo

    // 2) CADA CONSULTA RESPONDE EM O(1) — uma subtracao.
    int q; cin >> q;
    while (q--) {                               // idioma: "repita q vezes"
        int l, r; cin >> l >> r;
        cout << pre[r + 1] - pre[l] << "\n";
    }
}
















