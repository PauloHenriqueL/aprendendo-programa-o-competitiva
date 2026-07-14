#include <bits/stdc++.h>
using namespace std;


// ============================================================
// CONCEITO: DOIS PONTEIROS  (two pointers)
// ============================================================
//
// ---------- O PROBLEMA ----------
// Vetor ORDENADO, alvo X. Existem dois elementos que somam X?
//
// Força bruta: testar todo par -> O(N^2).
// N = 100.000  ->  10.000.000.000 operações. Morre.
//
//
// ---------- A IDEIA ----------
//   esq = 0        aponta pro MENOR
//   dir = n-1      aponta pro MAIOR
//
//   soma = v[esq] + v[dir]
//
//   soma == X  ->  achou
//   soma <  X  ->  preciso AUMENTAR  ->  esq++
//   soma >  X  ->  preciso DIMINUIR  ->  dir--
//
//   Para quando esq >= dir (a faixa esvaziou).
//
//
// ---------- POR QUE ISSO É CORRETO (o que importa) ----------
// Suponha v[esq] + v[dir] < X. Quero aumentar. Duas opções:
//
//   (a) aumentar v[dir]? IMPOSSÍVEL. v[dir] já é o MAIOR
//       elemento disponível na faixa. Não existe nada maior.
//   (b) logo, só resta esq++.
//
// E aqui está a joia: se v[esq] somado com o MAIOR de todos
// já ficou abaixo de X, então v[esq] somado com QUALQUER outro
// também fica abaixo de X. Ou seja:
//
//       v[esq] NUNCA formará par com ninguém.
//
// Descarto ele INTEIRO -- e com ele, N-1 pares de uma vez só,
// num único passo. Cada iteração mata um elemento em definitivo.
//
//   Total: O(N).
//
//
// ---------- EXEMPLO ----------
// v = [1, 3, 5, 8, 11],  X = 13
//
//   esq=0 dir=4 -> 1 + 11 = 12 < 13 -> o 1 não serve nem com o
//                                      maior de todos -> esq=1
//   esq=1 dir=4 -> 3 + 11 = 14 > 13 -> o 11 é grande demais nem
//                                      com o menor da faixa -> dir=3
//   esq=1 dir=3 -> 3 +  8 = 11 < 13 -> esq=2
//   esq=2 dir=3 -> 5 +  8 = 13 == X -> SIM
//
// 4 passos, em vez de 10 pares.
//
//
// ---------- O FIO CONDUTOR (a lição de verdade) ----------
// Olhe pro que você já sabe fazer:
//
//   BUSCA BINÁRIA  -> descarta METADE do vetor por passo
//   DOIS PONTEIROS -> descarta UM elemento e TODOS os pares dele
//   PREFIX SUM     -> pré-calcula pra não recalcular nada
//   GULOSO         -> ordena e nunca volta atrás
//
// SÃO A MESMA IDEIA:
//   usar a ESTRUTURA do problema (ordenação, monotonicidade)
//   para DESCARTAR EM BLOCO, em vez de testar tudo.
//
// Sempre que um enunciado disser "ordenado" / "crescente",
// a pergunta a fazer é:
//   "o que essa ordem me deixa jogar fora SEM TESTAR?"
//
//
// ---------- CUIDADOS ----------
//  - v[esq] + v[dir] com valores até 1e9 ESTOURA int. long long.
//  - "posições diferentes" -> a condição é while (esq < dir),
//    não <=. Com <= você somaria o elemento com ele mesmo.
//  - Se o vetor NÃO vier ordenado, você ordena antes. O custo
//    vira O(N log N) -- ainda muito melhor que O(N^2).
//
// ============================================================


// ------------------------------------------------------------
// D1 — Codeforces 279B "Books" (rating 900)
//     https://codeforces.com/problemset/problem/279/B
//
// Valera tem T minutos livres e uma pilha de N livros, na ordem
// em que estão empilhados. O livro i leva a[i] minutos para ser
// lido.
//
// Ele escolhe UM livro para começar (o de índice i) e a partir
// dali lê os livros em SEQUÊNCIA (i, i+1, i+2, ...), sem pular
// nenhum. Ele para quando o próximo livro não couber inteiro no
// tempo que sobrou (ele nunca lê um livro pela metade).
//
// Determine o NÚMERO MÁXIMO de livros que Valera consegue ler,
// escolhendo o melhor ponto de partida.
//
// Entrada:
//   Linha 1: dois inteiros N e T (1 <= N <= 100000; 1 <= T <= 10^9)
//   Linha 2: N inteiros a[1..N] (1 <= a[i] <= 10^4)
//
// Saída:
//   Um único inteiro: o número máximo de livros.
//
// Exemplo 1:
//   Entrada:
//     4 5
//     3 1 2 1
//   Saída:
//     3
//   (começando no livro 2: 1 + 2 + 1 = 4 <= 5, três livros)
//
// Exemplo 2:
//   Entrada:
//     3 3
//     2 2 3
//   Saída:
//     1
//
// ---
// PENSE ANTES DE CODAR (não me peça o código):
//   Aqui os dois ponteiros NÃO estão nas pontas. Eles delimitam
//   um TRECHO CONTÍNUO (uma "janela") que anda pra direita.
//   Chame-os de `esq` e `dir`.
//   Pergunta-guia: quando a soma da janela passa de T, o que
//   você faz -- e por que NUNCA precisa voltar o `dir` atrás?
// ------------------------------------------------------------


void D1(){
    int t, n; cin >> n >> t;
    vector<long long> vetor(n);
    for(int i = 0; i < n; i++){
        cin >> vetor[i];
    }
    long long esq = 0, soma = 0, melhor = 0;
    for(long long i = 0; i < n; i++){
        soma += vetor[i];
        while(soma>t){
            soma -= vetor[esq];
            esq++;
        }
        melhor = max(melhor, i - esq +1);
    } 
    cout << melhor << endl;
}






// ------------------------------------------------------------
// D2 — "Botes de resgate" (clássico: guloso + dois ponteiros
//      nas PONTAS; conhecido como Boat Problem / LeetCode 881)
//
// Você precisa evacuar N pessoas em botes. A pessoa i pesa w[i].
// Cada bote suporta no máximo LIMITE quilos e leva NO MÁXIMO
// DUAS pessoas (podendo levar só uma).
//
// Determine o NÚMERO MÍNIMO de botes necessários para levar
// todas as pessoas.
//
// Garantia: w[i] <= LIMITE para todo i (sempre dá pra levar
// alguém sozinho).
//
// Entrada:
//   Linha 1: dois inteiros N e LIMITE
//            (1 <= N <= 100000; 1 <= LIMITE <= 10^9)
//   Linha 2: N inteiros w[1..N] (1 <= w[i] <= LIMITE)
//
// Saída:
//   Um único inteiro: o número mínimo de botes.
//
// Exemplo 1:
//   Entrada:
//     4 3
//     3 2 2 1
//   Saída:
//     3
//   (botes: [3], [2,1], [2])
//
// Exemplo 2:
//   Entrada:
//     3 3
//     1 2 2
//   Saída:
//     2
//   (botes: [1,2], [2])
//
// Exemplo 3:
//   Entrada:
//     5 5
//     3 5 3 4 5
//   Saída:
//     5
//   (ordenado: 3 3 4 5 5. O 5 vai sozinho (5+3=8>5). O outro 5,
//    sozinho. O 4, sozinho (4+3=7>5). Os dois 3 nem juntos cabem
//    (3+3=6>5) -> um bote cada. Total: 5 botes.)
//
// Exemplo 4:
//   Entrada:
//     4 6
//     3 5 3 1
//   Saída:
//     2
//   (ordenado: 1 3 3 5. O 5 com o 1 = 6 <= 6 ✓. Os dois 3 = 6 ✓.)
//
// ---
// PENSE ANTES DE CODAR:
//   O vetor não vem ordenado. Ordene.
//   Agora: qual é a escolha GULOSA para a pessoa MAIS PESADA?
//   Com quem vale a pena tentar embarcá-la -- e por quê?
//   (Este problema junta GULOSO + DOIS PONTEIROS. É o fio
//    condutor em ação.)
// ------------------------------------------------------------



void D2(){
    int n, cont = 0; cin >> n;
    vector<long long> vetor(n);
    long long limite, soma = 0; cin >> limite;
    for(int i = 0; i < n; i++){
        cin >> vetor[i];
    }
    sort(vetor.begin(), vetor.end());

    int esq = 0, dir = n -1;
    while(esq<=dir){
        if(esq != dir) soma = vetor[esq] + vetor[dir];
        else    soma = vetor[esq];
        if(soma > limite){
            dir--;
            cont++;
        } else if(soma <= limite){
            cont++;
            dir--;
            esq++;
        }
    }
    
    cout << cont << endl;
}

