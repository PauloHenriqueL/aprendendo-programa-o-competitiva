#include <bits/stdc++.h>
using namespace std;



// ============================================================
// AQUECIMENTO — 2026-07-14 (8 exercícios)  |  rumo a GRAFOS
//
// C1-C4: REFORÇO do que você já viu (foco nos 🔴/🟡 do painel).
// C5-C8: PREPARAM as ferramentas que BFS/DFS exige.
//
// REGRA (você pediu para eu cobrar):
//   g++ -std=c++17 -Wall -Wextra -Wshadow -O2 arquivo.cpp -o a
//   Warning = teste falhando. Não julgo exercício com warning.
//   E: compilação limpa é o PISO, não a garantia. Rode os exemplos.
//
// REGRA 2 (você pediu): limites perto de 1e9 -> long long JÁ no
//   cin/no vector. Não fique analisando se "sobrevive" em int.
// ============================================================


// ------------------------------------------------------------
// C1 — JANELA DESLIZANTE (reforço do D1; 1ª rep, precisa de ~9)
//
// Leia N e T, depois N inteiros POSITIVOS.
// Encontre a MAIOR quantidade de elementos CONSECUTIVOS (um
// trecho contíguo) cuja soma seja <= T.
//
// (É o D1 de novo, com outra roupa. Faça SEM olhar o D1.)
//
// Entrada:
//   6 8
//   2 1 5 1 3 2
// Saída:
//   3
//   (o trecho 1 3 2 no fim soma 6 <= 8, três elementos.
//    O trecho 2 1 5 soma 8 <= 8, também três. Não há quatro.)
//
// Restrições: 1 <= N <= 100000; 1 <= T <= 1e9; 1 <= a[i] <= 1e9
// ------------------------------------------------------------
void C1(){
    int n; cin >> n;
    long long t; cin >> t;
    vector<long long> vetor(n);
    for(int i =0; i < n; i++){
        cin >> vetor[i];
    }
    long long esq = 0, soma = 0, melhor = 0;
    for(long long i = 0; i < n; i++){
        soma += vetor[i];
        while(soma>t){
            soma -= vetor[esq];
            esq++;
        }
        melhor = max(melhor, i - esq + 1);
    }
    cout << melhor << endl;
}
// ------------------------------------------------------------
// C2 — DOIS PONTEIROS NAS PONTAS + borda inclusiva (🟡 do painel)
//
// Leia N e N inteiros JÁ ORDENADOS em ordem crescente. Leia X.
// Imprima QUANTOS PARES (i, j) com i < j têm v[i] + v[j] <= X.
//
// ATENÇÃO: é <= (inclusive!), e é CONTAR (não "existe?").
// O(N). Nada de for dentro de for.
//
// Entrada:
//   5 7
//   1 2 3 4 5
// Saída:
//   8
//   (os pares: 1+2, 1+3, 1+4, 1+5, 2+3, 2+4, 2+5, 3+4.
//    Confira você mesmo — eu já errei enunciado duas vezes,
//    e você me pegou nas duas.)
//
// Restrições: 1 <= N <= 100000; valores e X até 1e9.
//
// DICA de raciocínio: se v[esq] + v[dir] <= X, então v[esq] forma
// par válido com TODOS entre esq e dir. Quantos são? Conte em
// BLOCO, não um a um.
// ------------------------------------------------------------
void C2(){
    int n; cin >> n;
    long long x, cont = 0; cin >> x;
    vector<long long> vetor(n);

    for(int i = 0; i < n; i++){
        cin >> vetor[i];
    }

    int esq = 0, dir = n -1; 
    while(esq<dir){
        if(vetor[esq] + vetor[dir] <= x){
            cont += dir - esq;
            esq++;
        }else{
            dir--;
        }
    }
    cout << cont << endl;

}
// ------------------------------------------------------------
// C3 — BUSCA BINÁRIA (🟢, manter aquecido) + sentinela
//
// Leia N e N inteiros ORDENADOS (podem repetir!). Leia Q consultas.
// Para cada consulta X, imprima o ÍNDICE da PRIMEIRA ocorrência
// de X (base 0), ou -1 se X não existir.
//
// OBRIGATÓRIO: busca binária. Busca linear = TLE.
// Cuidado: com valores REPETIDOS, achar "um" X não basta —
// tem que ser o PRIMEIRO. Pense em como continuar a busca.
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
void C3(){
    int n, q; cin >> n;
    vector<long long> catalago(n);
    for(int i =0; i < n; i++){
        cin >> catalago[i];
    }
    cin >> q;
    vector<long long> busca(q, -1);
    for(int i = 0; i < q; i++){
        long long x; cin >> x;
        int esq = 0, dir = n -1, meio =0;
        while(esq <= dir){
            meio = esq + (dir - esq)/2;
            if(catalago[meio] == x){
                busca[i] = meio;
                dir = meio - 1;
            } else if(catalago[meio]>x){
                dir = meio - 1;
            } else {
                esq = meio + 1;
            }
        }
    }
    for(auto& valor : busca){
        cout << valor << endl;
    }
}
// ------------------------------------------------------------
// C4 — GULOSO (🟢, manter aquecido)
//
// N tarefas. A tarefa i leva t[i] minutos. Você faz UMA de cada
// vez, na ordem que quiser. O "tempo de espera" de uma tarefa é
// quanto tempo passou desde o início até ela TERMINAR.
//
// Imprima a MENOR soma possível dos tempos de espera.
//
// Entrada:
//   3
//   3 1 2
// Saída:
//   10
//   (ordem 1,2,3: espera 1, depois 1+2=3, depois 1+2+3=6.
//    Soma = 1 + 3 + 6 = 10. Nenhuma outra ordem dá menos.)
//
// Restrições: 1 <= N <= 100000; 1 <= t[i] <= 1e9  (pense no tipo!)
// ------------------------------------------------------------
void C4(){
    int n; cin >> n;
    vector<long long> vetor(n);
    for(int i = 0; i < n; i++){
        cin >> vetor[i];
    }
    sort(vetor.begin(), vetor.end());
    vector<long long> pre(n + 1);
    pre[0] = 0;
    for(int i = 0; i < n; i++){
        pre[i + 1] = pre[i] + vetor[i];
    }
    long long soma = 0;
    for(int i = 1; i <= n; i++){
        soma += pre[i];
    }
    cout << soma << "\n";
}
// ------------------------------------------------------------
// C5 — MATRIZ 2D: ler e percorrer   [PREPARA GRAFOS]
//
// Leia L e C (linhas e colunas), depois uma matriz L x C de
// inteiros. Imprima:
//   linha 1: a SOMA de todos os elementos
//   linha 2: o MAIOR elemento e, separados por espaço, a LINHA e
//            a COLUNA onde ele aparece pela primeira vez
//            (varrendo linha por linha, da esquerda p/ a direita)
//
// Entrada:
//   2 3
//   1 9 3
//   4 5 9
// Saída:
//   31
//   9 0 1
//
// Restrições: 1 <= L, C <= 1000; valores até 1e9.
//
// (Use vector<vector<int>>. Você fez isso no M2 — relembre.
//  Uma grade de labirinto É uma matriz 2D. É a estrutura de hoje.)
// ------------------------------------------------------------
void C5(){
    int l, c; cin >> l >> c;
    long long soma = 0;
    vector<vector<long long>> matriz(l, vector<long long>(c, 0));
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            cin >> matriz[i][j];
            soma += matriz[i][j];
        }
    }
    long long maior = matriz[0][0];
    int linha = 0, coluna = 0;
    for(int i =0; i < l; i++){
        for(int j = 0; j < c; j++){
            if(maior<matriz[i][j]){
                maior = matriz[i][j];
                linha = i;
                coluna = j;
            }
        }
    }
    cout << soma << "\n" << maior << " " << linha << " " << coluna << endl;
}
// ------------------------------------------------------------
// C6 — OS 4 VIZINHOS + limites da grade   [PREPARA GRAFOS]
//
// Leia L e C, depois uma matriz L x C de inteiros.
// Depois leia duas coordenadas: l e c (uma célula da matriz).
//
// Imprima a SOMA dos VIZINHOS ORTOGONAIS da célula (l, c) —
// isto é: cima, baixo, esquerda e direita.
// ATENÇÃO: vizinhos que caem FORA da matriz não existem e não
// entram na soma. NÃO leia fora do vetor (o sanitizer vai pegar).
//
// Na linha seguinte, imprima QUANTOS vizinhos válidos existiam.
//
// Entrada:
//   3 3
//   1 2 3
//   4 5 6
//   7 8 9
//   0 0
// Saída:
//   6
//   2
//   (a célula (0,0) vale 1. Vizinhos: direita=2, baixo=4.
//    Cima e esquerda caem fora. Soma 2+4=6, são 2 vizinhos.)
//
// Restrições: 1 <= L, C <= 1000; 0 <= l < L; 0 <= c < C.
//
// >>> ESTE É O CORAÇÃO DO BFS/DFS EM GRADE. <<<
// Dica de estilo competitivo: em vez de 4 ifs, use dois vetores
//   int dl[4] = {-1, 1, 0, 0};
//   int dc[4] = { 0, 0,-1, 1};
// e um for de 0 a 3. Pense no porquê isso funciona.
// ------------------------------------------------------------
void C6(){
    int l, c; cin >> l >> c;
    vector<vector<long long>> matriz(l, vector<long long>(c, 0));
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            cin >> matriz[i][j];
        }
    }
    int linha, coluna; cin >> linha >> coluna;
    long long soma = 0, cont = 0;
    if(linha - 1 >= 0){
        soma += matriz[linha - 1][coluna];
        cont++;
    }
    if(coluna -1 >= 0){
        soma += matriz[linha][coluna-1];
        cont++;
    }
    if(coluna + 1 <= c-1){
        soma += matriz[linha][coluna+1];
        cont++;
    }
    if(linha + 1 <= l-1){
        soma +=matriz[linha+1][coluna];
        cont++;
    }
    cout << soma << "\n" << cont << endl;
}

// ------------------------------------------------------------
// C7 — FILA (queue): processar em ordem de chegada  [PREPARA BFS]
//
// Você tem uma fila de atendimento. Leia N comandos, um por linha.
// Cada comando é um destes:
//   "CHEGA x"   -> a pessoa de número x entra no FIM da fila
//   "ATENDE"    -> a primeira pessoa da fila é atendida e SAI
//   "QUANTOS"   -> imprima quantas pessoas estão na fila agora
//
// Se vier "ATENDE" com a fila VAZIA, imprima "VAZIA" e siga.
// Toda vez que alguém for atendido, imprima o número da pessoa.
//
// Entrada:
//   6
//   CHEGA 10
//   CHEGA 20
//   ATENDE
//   QUANTOS
//   ATENDE
//   ATENDE
// Saída:
//   10
//   1
//   20
//   VAZIA
//
// (Use std::queue<int>. Métodos: push(x), front(), pop(), empty(),
//  size(). Você já usou stack — a fila é a prima: FIFO em vez de
//  LIFO. Cuidado: front() e pop() só com !empty()!)
//
// >>> BFS É EXATAMENTE ISSO: uma fila de células a visitar. <<<
// ------------------------------------------------------------
void C7(){
    int n; cin >> n;
    std::queue<int> fila;
    for(int i = 0; i<n; i++){
        string comando;
        cin >> comando;
        if(comando == "CHEGA"){
            int x; cin >> x;
            fila.push(x);
        } else if(comando == "ATENDE"){
            if(!fila.empty()){
                long long x = fila.front();
                cout << x << endl;
                fila.pop();
            } else {
                cout << "VAZIA" << endl;
            }
        } else if(comando == "QUANTOS"){
            cout << fila.size() << "\n"; 
        }
    }
}
// ------------------------------------------------------------
// C8 — MARCAR VISITADOS: não repetir trabalho   [PREPARA BFS/DFS]
//
// Leia N e depois N inteiros (0 <= v[i] <= 1000000), possivelmente
// com repetições.
//
// Imprima, em UMA linha separada por espaço, os elementos na ORDEM
// EM QUE APARECERAM, mas SEM REPETIR: cada valor só sai na sua
// PRIMEIRA aparição.
//
// Na linha seguinte, imprima quantos valores DISTINTOS havia.
//
// Entrada:
//   7
//   4 7 4 1 7 9 1
// Saída:
//   4 7 1 9
//   4
//
// Restrições: 1 <= N <= 100000; 0 <= v[i] <= 1000000.
//
// >>> A IDEIA CENTRAL: um vetor `visitado[]` de bool/int que
//     responde "eu já vi isso antes?" em O(1).
//     É EXATAMENTE o que impede o BFS/DFS de girar em círculos
//     para sempre. Sem ele, o algoritmo de hoje NÃO TERMINA. <<<
//
// (Dá para fazer com `set`, mas faça com um VETOR de flags —
//  é O(1) por consulta e é o que se usa em grafos.)
// ------------------------------------------------------------
void C8(){
    int n, distintos = 0; cin >> n;
    vector<bool> vetor(1000001, false);
    for(int i =0; i < n; i++){
        int x; cin >> x;
        if(!vetor[x]){
            cout << x << " ";
            vetor[x] = true;
            distintos++;
        }
    }
    
    cout << "\n" << distintos << "\n";
    


}



int main(){
//    C1();
//    C2();
//    C3();
//    C4();
//    C5();
//    C6();
//    C7();
    C8();


    return 1;
}

