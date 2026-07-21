#include <bits/stdc++.h>
using namespace std;
// ============================================================
// AQUECIMENTO — 2026-07-15 (8 exercícios)
// FOCO DA SEMANA: BUSCA BINÁRIA / lower_bound (o 🔴 nº 1)
//
// REGRA (você pediu para eu cobrar):
//   g++ -std=c++17 -Wall -Wextra -Wshadow -O2 arquivo.cpp -o a
//   Warning = teste falhando. E: compilação limpa é o PISO, não
//   a garantia (o -Wall não pega `cout` faltando). Rode os exemplos.
//
// PRÉ-FLIGHT (diga em voz alta antes de codar busca binária):
//   - passo?          lo = meio+1 / hi = meio-1  (NUNCA ++/--)
//   - while?          lo <= hi  (faixa FECHADA)
//   - meio?           lo + (hi-lo)/2
//   - achei o alvo?   se quero a PRIMEIRA ocorrência: guardo e vou
//                     pra ESQUERDA, SEM break
//   - não achei?      sentinela -1 (0 é índice válido!)
//   - long long?      onde a CONTA explode (limites perto de 1e9)
// ============================================================


// ------------------------------------------------------------
// D1 — BUSCA BINÁRIA CLÁSSICA (achou → pode parar)
//
// Leia N e N inteiros ORDENADOS (crescente, SEM repetições).
// Leia Q consultas. Para cada X, imprima o ÍNDICE (base 0) de X,
// ou -1 se não existir.
//
// OBRIGATÓRIO: busca binária. Busca linear = TLE.
//
// Entrada:
//   5
//   2 4 7 9 15
//   3
//   9
//   4
//   10
// Saída:
//   3
//   1
//   -1
//
// Restrições: 1 <= N, Q <= 100000
// ------------------------------------------------------------
void D1(){
    int n; cin >> n;
    vector<long long> catalago(n);
    for(int i = 0; i < n; i++){
        cin >> catalago[i];
    }
    int q; cin >> q;
    vector<long long> consultas(q, -1);
    for(int i = 0; i < q; i++){
        long long x;
        cin >> x;
        long long lo = 0, hi = n - 1, meio = 0;
        while(lo<=hi){
            meio = lo + (hi - lo)/2;
            if(catalago[meio]==x){
                consultas[i] = meio;
                break;
            } else if(catalago[meio] > x){
                hi = meio - 1;
            } else {
                lo = meio + 1;
            }
        }
    }
    for(auto& valor : consultas){
        cout << valor << "\n";
    }
}


// ------------------------------------------------------------
// D2 — lower_bound: PRIMEIRA ocorrência (COM repetições)
//
// Igual ao D1, MAS o vetor pode ter valores REPETIDOS, e você
// deve imprimir o índice da PRIMEIRA ocorrência de X (-1 se não
// existir).
//
// >>> É o C3 de ontem. O bug foi dar `break` ao achar. <<<
// Ao achar X: guarde a posição e continue procurando à ESQUERDA.
//
// Entrada:
//   6
//   1 3 3 3 7 9
//   3
//   3
//   9
//   5
// Saída:
//   1
//   5
//   -1
//
// Restrições: 1 <= N, Q <= 100000
// ------------------------------------------------------------
void D2(){
    int n; cin >> n;
    vector<long long> catalago(n);
    for(int i = 0; i < n; i++){
        cin >> catalago[i];
    }
    int q; cin >> q;
    vector<long long> busca(q, -1);
    for(int i = 0; i < q; i++){
        long long x; cin >> x;
        long long lo = 0, hi = n-1, meio = 0;
        while(lo <= hi){
            meio = lo + (hi - lo)/2;
            if(catalago[meio]==x){
                busca[i] = meio;
                hi = meio - 1;
            } else if (catalago[meio] > x){
                hi = meio - 1;
            } else {
                lo = meio + 1;
            }
        }
    }
    for(auto& valor : busca){
        cout << valor <<  "\n";
    }
}


// ------------------------------------------------------------
// D3 — lower_bound de VERDADE: primeiro valor >= X
//
// Leia N e N inteiros ORDENADOS (crescente, pode repetir).
// Leia Q consultas. Para cada X, imprima o MENOR VALOR do vetor
// que seja >= X (o primeiro que "alcança ou passa" X).
// Se NENHUM valor for >= X, imprima "-".
//
// >>> É a pergunta 10 do recall. Ao ter v[meio] >= X, o meio
//     AINDA pode ser a resposta: guarde e vá pra esquerda. <<<
//
// Entrada:
//   6
//   2 5 5 8 13 20
//   4
//   5
//   6
//   1
//   100
// Saída:
//   5
//   8
//   2
//   -
//
// Restrições: 1 <= N, Q <= 100000; valores até 1e9.
// ------------------------------------------------------------
void D3(){
    int n; cin >> n;
    vector<long long> catalago(n);
    for(int i = 0; i < n; i++){
        cin >> catalago[i];
    }
    int q; cin >> q;
    vector<long long> busca(q, -1);
    for(int i =0; i < q; i++){
        long long x; cin >> x;
        long long lo = 0, hi = n-1, meio =0;
        while(lo<=hi){
            meio = lo + (hi - lo)/2;
            if(catalago[meio] >= x){
                busca[i] = catalago[meio];
                hi = meio -1;
            } else {
                lo = meio + 1;
            }
        }
    }
    for(auto& valor : busca){
        if(valor != -1){
            cout << valor << "\n";
        } else {
            cout << "-" << "\n";
        }
        
    }
}


// ------------------------------------------------------------
// D4 — JANELA DESLIZANTE (o 🔴: sinal do while)
//
// Leia N e T, depois N inteiros POSITIVOS.
// Imprima o comprimento do MENOR trecho contíguo cuja soma seja
// >= T. Se nenhum trecho alcança T, imprima 0.
//
// >>> ATENÇÃO: agora é MENOR trecho com soma >= T (o C1 era o
//     MAIOR com soma <= T). Pense em quando encolher. <<<
//
// Entrada:
//   6 8
//   2 1 5 1 3 2
// Saída:
//   3
//   (o menor trecho contíguo com soma >= 8 é "5 1 3" = 9, com 3
//    elementos. Nenhum trecho de 2 elementos alcança 8.)
//
// Restrições: 1 <= N <= 100000; T, a[i] até 1e9 (long long!).
// ------------------------------------------------------------
void D4(){
    int n, t; cin >> n >> t;
    vector<long long> vetor(n);
    for(int i = 0; i < n; i++){
        cin >> vetor[i];
    }
    long long esq = 0, melhor = 0, soma = 0;
    for(int i = 0; i < n; i++){
        soma += vetor[i];
        while(soma >= t){
            soma -= vetor[esq];
            esq++;
        }
        melhor = min(melhor, i - esq + 1);
    }
    cout << melhor << endl;

}

void D4_otimo(){
    int n; long long t;              // t até 1e9 -> long long
    cin >> n >> t;
    vector<long long> v(n);          // soma até 1e14 -> long long na ORIGEM
    for(int i = 0; i < n; i++) cin >> v[i];

    long long esq = 0, soma = 0;
    long long melhor = n + 1;        // "impossível": marca "nada achado ainda"

    for(int i = 0; i < n; i++){      // i = borda direita, SEMPRE avança
        soma += v[i];

        while(soma >= t){                        // janela [esq..i] AINDA alcança T = válida
            melhor = min(melhor, i - esq + 1);   // <-- MEDE AQUI, enquanto é válida
            soma -= v[esq];                      // tenta encolher pela esquerda...
            esq++;                               // ...talvez uma MENOR também alcance T
        }
    }

    // A linha abaixo, mas escrita como if/else para ficar claro:
    //
    //   cout << (melhor == n + 1 ? 0 : melhor) << "\n";
    //
    // Se 'melhor' NUNCA foi atualizado, ele continua com o valor
    // inicial (n+1). Isso significa: nenhum trecho alcançou T.
    // Nesse caso o enunciado pede 0. Caso contrário, imprime o
    // menor tamanho que encontramos.
    if(melhor == n + 1){        // nunca achei uma janela válida
        cout << 0 << "\n";
    } else {                    // achei -> 'melhor' guarda o menor tamanho
        cout << melhor << "\n";
    }
}


// ------------------------------------------------------------
// D5 — DOIS PONTEIROS: contar pares (o 🔴: UM ponteiro por vez)
//
// Leia N e N inteiros ORDENADOS crescente. Leia X.
// Conte quantos pares (i, j) com i < j têm v[i] + v[j] >= X.
//
// >>> Agora é >= (antes era <=). Repense a direção do descarte. <<<
// O(N). UM ponteiro por iteração.
//
// Entrada:
//   5 7
//   1 2 3 4 5
// Saída:
//   4
//   (pares com soma >= 7: 2+5, 3+4, 3+5, 4+5. São 4.)
//
// Restrições: 1 <= N <= 100000; valores até 1e9. Contador long long!
// ------------------------------------------------------------
void D5(){
    int n, x; cin >> n >> x;
    vector<long long> vetor(n);
    for(int i = 0; i < n; i++){
        cin >> vetor[i];
    }
    long long esq = 0, dir = n -1, cont = 0;

    while(esq < dir){
        long long soma = vetor[esq] + vetor[dir];
        if(soma>=x){
            cont += dir - esq;
            dir--;
        } else {
            esq++;
        }
    }
    
    cout << cont << endl;

    
}


// ------------------------------------------------------------
// D6 — GULOSO (o 🔴: borda inclusiva <=)
//
// Você tem M reais. N itens com preços. Compre a MAIOR
// quantidade possível de itens.
//
// >>> Item que custa EXATAMENTE o que sobra: DÁ pra comprar. <<<
//
// Entrada:
//   5 10
//   3 1 8 2 5
// Saída:
//   3
//
// Restrições: 1 <= N <= 100000; preços e M até 1e9.
// ------------------------------------------------------------
void D6(){
    int n, cont = 0; cin >> n;
    long long m; cin >> m;
    vector<long long> catalago(n);
    for(int i =0; i < n; i++){
        cin >> catalago[i];
    }
    sort(catalago.begin(), catalago.end());
    for(auto& valor : catalago){
        if(valor <= m){
            m -= valor;
            cont++;
        }
    }
    cout << cont << endl;
}


// ------------------------------------------------------------
// D7 — BUSCA BINÁRIA NA RESPOSTA (conceito poderoso!)
//
// Você tem N tábuas de madeira, cada uma de comprimento a[i].
// Você quer cortar K pedaços, TODOS do MESMO comprimento L
// (inteiro). De uma tábua de comprimento a[i] saem a[i]/L pedaços
// (divisão inteira). Qual o MAIOR L possível para conseguir pelo
// menos K pedaços? Se nem L=1 dá K pedaços, imprima 0.
//
// >>> A resposta (L) é um número entre 1 e max(a). Testar todo L
//     é O(max*N). Mas "quanto MAIOR o L, MENOS pedaços saem" —
//     isso é MONOTÔNICO. Dá pra BUSCAR BINÁRIO no valor de L! <<<
//
// Entrada:
//   4 7
//   5 9 12 6
// Saída:
//   4
//   (com L=4: 5/4=1, 9/4=2, 12/4=3, 6/4=1 -> 1+2+3+1 = 7 >= 7 ok.
//    com L=5: 1+1+2+1 = 5 < 7 nao.
//    Então o MAIOR L que ainda dá >= 7 pedaços é 4.)
//
// Restrições: 1 <= N <= 100000; 1 <= a[i] <= 1e9; 1 <= K <= 1e9.
// (long long na SOMA de pedaços!)
// ------------------------------------------------------------
void D7(){
    int n, k; cin >> n >> k;
    vector<long long> vetor(n);
    for(int i =0; i < n; i++) cin >> vetor[i];
    
    sort(vetor.begin(), vetor.end());
    long long lo = 1, hi = vetor[n - 1];
    long long melhor = 0;
    while(lo<=hi){
        long long l = lo + (hi-lo)/2;
        long long pedacos = 0;
        for(int i = 0; i < n; i++){
            pedacos += vetor[i]/l;
        }  
        if(pedacos >= k){
            melhor = l;
            lo = l + 1;
        } else{
            hi = l - 1;
        }
    }
    cout << melhor << endl;
}


// ------------------------------------------------------------
// D8 — MATRIZ + os 4 vizinhos (revisão de ontem, C5/C6)
//
// Leia L e C, depois uma matriz L x C. Uma célula é um "PICO
// LOCAL" se seu valor é ESTRITAMENTE MAIOR que TODOS os seus
// vizinhos ortogonais (cima/baixo/esq/dir) que existem.
// Imprima quantos picos locais há na matriz.
//
// Entrada:
//   3 3
//   1 2 1
//   2 9 2
//   1 2 1
// Saída:
//   1
//   (só o 9 no centro é maior que todos os 4 vizinhos)
//
// Restrições: 1 <= L, C <= 1000; valores até 1e9.
// (Dica de estilo: dl[4]={-1,1,0,0}, dc[4]={0,0,-1,1}.)
// ------------------------------------------------------------
void D8(){
    int l, c; cin >> l >> c;
    vector<vector<long long>> matriz(l, vector<long long>(c, 0));
    for(int i = 0; i < l; i++){
        for(int j = 0; j< c; j++){
            cin >> matriz[i][j];
        }
    }
    int pico = 0;
    int dl[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            bool ehpico = true;
            for(int k = 0; k < 4; k++){
                int ni = i + dl[k];
                int nj = j + dc[k];
                if(ni >= 0 && ni < l && nj >= 0 && nj < c){
                    if(matriz[i][j] <= matriz[ni][nj]){
                        ehpico = false;
                    }
                }
            }
            if(ehpico){
                pico++;
            }
        }
    }
    cout << pico << "\n";
}


int main(){
    // Descomente o que for testar:
    //D1();
    // D2();
    // D3();
    // D4();
    // D5();
    // D6();
    // D7();
     D8();
    return 0;
}
