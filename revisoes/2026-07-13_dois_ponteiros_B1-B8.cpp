// ============================================================
// AQUECIMENTO — 2026-07-13 (8 exercícios)
//
// Foco deliberado nos seus 🔴:
//   - ÍNDICE × VALOR  ("isto é POSIÇÃO ou VALOR?")
//   - BORDA INCLUSIVA (`<` vs `<=`)
//   - PASSO DA BUSCA BINÁRIA (meio±1, nunca ++/--)
//   - COMPILAÇÃO LIMPA: **não julgo exercício com warning.**
//
// REGRA DO DIA: antes de me chamar, rode
//   g++ -std=c++17 -Wall -Wextra -Wshadow -O2 arquivo.cpp -o a
// Se aparecer QUALQUER warning, o exercício NÃO terminou.
// Warning é teste falhando.
//
// Escreva uma função por exercício. Pode fazer um main() só,
// chamando a que estiver testando.
// ============================================================

#include <bits/stdc++.h>
using namespace std;





// ------------------------------------------------------------
// B1 — REFAZER: BUSCA BINÁRIA (você errou este no A7)
//
// Leia N e depois N inteiros JÁ ORDENADOS em ordem crescente.
// Em seguida leia um alvo X.
// Imprima a POSIÇÃO (índice, base 0) onde X está no vetor,
// ou -1 se X não estiver lá.
//
// OBRIGATÓRIO: usar BUSCA BINÁRIA de verdade (lo, hi, meio).
// Busca linear = Wrong Answer, mesmo que a saída bata.
//
// Entrada:
//   5
//   2 4 7 9 15
//   9
// Saída:
//   3
//
// Entrada:
//   5
//   2 4 7 9 15
//   8
// Saída:
//   -1
//
// Restrições: 1 <= N <= 100000
// ------------------------------------------------------------


void B1(){
    int n; cin >> n;
    vector<int> vetor(n);
    for(int i = 0; i < n; i++){
        cin >> vetor[i];
    }
    int alvo; cin >> alvo;
    
    bool achei = false;
    int lo = 0, hi = n - 1, meio = 0;
    while(lo <= hi){ // porque tem que ser  <= e não <s?
        meio = lo + (hi - lo)/2;
        if(vetor[meio] == alvo){
            achei = true;
            break;
        } else if (vetor[meio] < alvo){
            lo = meio + 1;
        } else {
            hi = meio - 1;
        }
    }
    if(achei)   cout << meio << endl;
    else        cout << -1   << endl;
}







// ------------------------------------------------------------
// B2 — REFAZER: PREFIX SUM (você errou este no A8)
//
// Leia N, depois N inteiros. Depois leia Q (número de consultas).
// Cada consulta traz dois inteiros L e R (base 0).
// Para cada consulta, imprima a soma de v[L] até v[R], INCLUSIVE
// os dois extremos.
//
// OBRIGATÓRIO: usar prefix sum. Somar com um for por consulta é
// O(N*Q) e leva TLE.
//
// Entrada:
//   5
//   1 2 3 4 5
//   3
//   0 4
//   1 3
//   2 2
// Saída:
//   15
//   9
//   3
//
// Restrições: 1 <= N, Q <= 100000; valores até 10^9 (cuidado!)
// ------------------------------------------------------------



void B2(){
    int n, q; cin >> n;
    vector<int> vetor(n);
    for(int i = 0; i < n; i++){
        cin >> vetor[i];
    }
    vector<long long> pre(n+1);
    pre[0] = 0;
    for(int i = 0; i < n; i++){
        pre[i+1] = pre[i] + vetor[i];
    }
    cin >> q;
    vector<pair<int, int>> pares(q);
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        pares[i] = {l, r};
    }
    for(auto& [l, r] : pares){
        long long soma = pre[r+1] - pre[l];
        cout << soma << "\n";
    }
}




// ------------------------------------------------------------
//    g++ -std=c++17 -Wall -Wextra -Wshadow -O2 arquivo.cpp -o a


// B3 — ÍNDICE × VALOR (armadilha proposital)
//
// Leia N e N inteiros (NÃO ordenados). Leia um alvo X.
// Imprima o ÍNDICE (base 0) da PRIMEIRA ocorrência de X.
// Se X não existir, imprima -1.
//
// Depois, na MESMA execução, imprima o MAIOR VALOR do vetor e,
// na linha seguinte, o ÍNDICE onde esse maior valor aparece
// pela primeira vez.
//
// Saída: 3 linhas (índice de X, maior valor, índice do maior).
//
// Entrada:
//   6
//   4 9 2 9 1 7
//   2
// Saída:
//   2
//   9
//   1
//
// (Antes de escrever cada comparação, diga em voz alta:
//  "isto é POSIÇÃO ou VALOR?")
// ------------------------------------------------------------



void B3(){
    int n; cin >> n;
    vector<int> vetor(n);
    for(int i = 0; i < n; i++) cin >> vetor[i];
    int alvo; cin >> alvo;
    int maior = vetor[0];
    int posicao = -1, posicao_maior = 0;
    for(int i = 0; i < n; i++){
        if(vetor[i] > maior){
            maior = vetor[i];
            posicao_maior = i;
        }
    }
    for(int i = 0; i < n; i++){
        if(alvo == vetor[i]){
            posicao = i;
            break;
        }
    }
    cout << posicao << "\n" << maior << "\n" << posicao_maior << "\n";
}










// ------------------------------------------------------------
// B4 — BORDA INCLUSIVA (3ª vez que isso te pega)
//
// Leia A e B (com A <= B). Imprima quantos números do intervalo
// fechado [A, B] são PARES, e na linha seguinte a SOMA de todos
// os números de A até B, inclusive.
//
// Entrada:
//   2 2
// Saída:
//   1
//   2
//
// Entrada:
//   3 7
// Saída:
//   2
//   25
//   (o intervalo [3,7] = 3 4 5 6 7; pares: 4 e 6 -> 2 pares.
//    soma = 3+4+5+6+7 = 25)
//
// Restrições: -10^9 <= A <= B <= 10^9  (pense no tipo!)
// ------------------------------------------------------------



void B4(){
    int a, b, p1, p2; cin >> a >> b;
    int pares = 0;
    if(a%2 == 0){
        p1 = a;
    } else {
        p1 = a + 1;
    }
    if(b%2 == 0){
        p2 = b;
    } else {
        p2 = b - 1;
    }
    pares = (p2 - p1)/2 + 1;
    long long soma = (long long)(a + b) * (b - a + 1)/2;
    cout << pares << "\n" << soma << "\n";
}









// ------------------------------------------------------------
// B5 — SWAP CORRETO (o warning do A6)
//
// Leia N e N inteiros. Troque de lugar o menor e o maior
// elemento do vetor (se houver empate, use as PRIMEIRAS
// ocorrências). Imprima o vetor resultante, separado por espaço.
//
// Se o menor e o maior forem o mesmo elemento (N=1, ou todos
// iguais), imprima o vetor sem alteração.
//
// Entrada:
//   5
//   3 8 1 9 4
// Saída:
//   3 8 9 1 4
//
// (O swap tem 3 linhas. A variável temporária PRECISA aparecer
//  à direita de um '=' em algum momento. Se não aparecer, o
//  -Wall vai te avisar.)
// ------------------------------------------------------------
void B5(){
    int n; cin >> n;
    vector<int> vetor(n);
    for(int i = 0; i < n; i++){
        cin >> vetor[i];
    }
    int maior = INT_MIN, menor = INT_MAX, posicao_menor = 0, posicao_maior=0;
    for(int i = 0; i < n; i++){
        if(vetor[i] > maior){
            maior = vetor[i]; 
            posicao_maior = i;
        }
        if(vetor[i] < menor){
            menor = vetor[i]; 
            posicao_menor = i;
        }
    }
    int temp = vetor[posicao_menor];
    vetor[posicao_menor] = vetor[posicao_maior];
    vetor[posicao_maior] = temp;
    for(int i = 0; i < n; i++){
        cout << vetor[i] << " ";
    }

}









// ------------------------------------------------------------
// B6 — OVERFLOW (7 reps, mas nunca relaxe)
//
// Leia N e N inteiros (cada um até 10^9). Imprima:
//   linha 1: a SOMA de todos
//   linha 2: o maior PRODUTO possível de dois elementos
//            DISTINTOS (posições diferentes) do vetor
//
// Entrada:
//   4
//   1000000000 999999999 2 3
// Saída:
//   2000000004
//   999999999000000000
//
// Restrições: 2 <= N <= 100000; valores POSITIVOS até 10^9.
// (Dica: são DUAS naturezas diferentes de overflow.)
// ------------------------------------------------------------


void B6(){
    int n; cin >> n;
    vector<long long> vetor(n);
    long long soma = 0;
    for(int i = 0; i < n; i++){
        cin >> vetor[i];
        soma += vetor[i];
    }
    sort(vetor.begin(), vetor.end());
    long long produto = vetor[n - 1] * vetor[n - 2];

    cout << soma << "\n" << produto << "\n";


    
}










// ------------------------------------------------------------
// B7 — GULOSO + sort (reforço; 🟢, mantendo aquecido)
//
// Você tem M reais e uma lista de N preços. Quer comprar a MAIOR
// QUANTIDADE possível de itens (não importa quais).
// Imprima quantos itens consegue comprar.
//
// Entrada:
//   5 10
//   3 1 8 2 5
// Saída:
//   3
//   (compra 1 + 2 + 3 = 6; o próximo custaria 5 -> 11 > 10)
//
// Restrições: 1 <= N <= 100000; preços e M até 10^9.
// ------------------------------------------------------------


void B7(){
    int n, dinheiro, cont = 0; cin >> n >> dinheiro;
    vector<int> vetor;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        vetor.push_back(x);
    }
    sort(vetor.begin(), vetor.end());
    for(auto& produto : vetor){
        if(produto <= dinheiro){
            dinheiro -= produto;
            cont++;
        } else {
            break;
        }
    }
    cout << cont << endl;
}














// ------------------------------------------------------------
// B8 — PONTE PARA O CONCEITO NOVO
//
// Leia N e N inteiros JÁ ORDENADOS em ordem crescente.
// Leia um alvo X.
// Imprima "SIM" se existirem DOIS elementos em POSIÇÕES
// DIFERENTES cuja soma seja exatamente X; senão "NAO".
//
// OBRIGATÓRIO: O(N). Nada de for dentro de for.
// Use dois ponteiros (esq=0, dir=n-1).
//
// Entrada:
//   5
//   1 3 5 8 11
//   13
// Saída:
//   SIM
//
// Entrada:
//   5
//   1 3 5 8 11
//   2
// Saída:
//   NAO
//
// Restrições: 1 <= N <= 100000; valores até 10^9 (soma estoura int!)
// ------------------------------------------------------------


void B8(){
    int n; cin >> n;
    long long alvo;
    vector<long long> vetor(n);
    bool achei = false;

    for(int i = 0; i < n; i++){
        cin >> vetor[i];
    }
    cin >> alvo;
    long long esq = 0, dir = n-1;
    while(esq < dir){
        long long soma = vetor[esq] + vetor[dir];
        if(soma == alvo){
            achei = true;
            break;
        } else if(soma>alvo){
            dir--;
        } else if(soma<alvo){
            esq++;
        }
    }
    if(achei)   cout << "SIM";
    else        cout << "NAO";
}










int main(){
//    B1();
//    B2();
//    B3();
//    B4();
//    B5();
//    B6();
//    B7();
   B8();





    return 0;
}