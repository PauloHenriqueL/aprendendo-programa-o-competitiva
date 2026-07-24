#include <bits/stdc++.h>
using namespace std;
// ============================================================
// REVISÃO FINAL — ESTRUTURAS — 2026-07-21 (8 exercícios)
// FOCO: ESCOLHER a ferramenta certa + USAR a ferramenta certa.
//
// >>> OS EXERCÍCIOS NÃO DIZEM QUAL ESTRUTURA USAR. <<<
// São 2 de cada: stack, queue, vector, matriz — embaralhados.
//
// ANTES DE CODAR CADA UM, escreva no comentário // ESCOLHA:
//   (a) qual estrutura você escolheu
//   (b) QUAL PALAVRA do enunciado te fez escolher ela
// Eu vou julgar as DUAS coisas: a escolha e o uso.
//
// ------------------------------------------------------------
// PRIMEIRO: O ERRO DO RECALL DE HOJE (você inverteu os nomes)
// ------------------------------------------------------------
// Você disse "stack é FIFO" e trocou as duas estruturas.
// Os CONCEITOS você acertou — só os NOMES estavam trocados. Isso é
// perigoso: numa prova o enunciado diz "pilha" e "fila", não "LIFO".
//
//   stack = PILHA = LIFO (Last In, First Out)
//       -> PILHA DE PRATOS: empilha por cima, tira por cima.
//          O ÚLTIMO que entrou é o PRIMEIRO que sai.
//
//   queue = FILA  = FIFO (First In, First Out)
//       -> FILA DO BANCO: quem chegou primeiro é atendido primeiro.
//          Ninguém fura fila.
//
// ------------------------------------------------------------
// A TABELA (decore esta, não a sigla)
// ------------------------------------------------------------
//   estrutura | OLHAR    | REMOVER | INSERIR     | sai quem
//   ----------|----------|---------|-------------|-------------
//   stack     | top()    | pop()   | push(x)     | entrou por ÚLTIMO
//   queue     | front()  | pop()   | push(x)     | entrou PRIMEIRO
//   vector    | v[i]     | -       | push_back(x)| você escolhe (v[i])
//
//   NAS DUAS: pop()/top()/front() só depois de checar !empty().
//   NAS DUAS: pop() é void — REMOVE e não devolve nada.
//             `int x = fila.pop();` NÃO COMPILA.
//             O certo são DOIS passos:
//                 int x = fila.front();   // OLHA
//                 fila.pop();             // REMOVE
//
// ------------------------------------------------------------
// E A MATRIZ? (ela não é irmã das outras três)
// ------------------------------------------------------------
// stack/queue/vector são LINEARES e se diferenciam pela POLÍTICA
// de quem entra e quem sai. A matriz não tem política nenhuma —
// ela é um ARRANJO 2D: um vector de vectors.
//
//   vector<vector<long long>> m(L, vector<long long>(C, 0));
//
//   Leia da DIREITA para a ESQUERDA:
//     vector<long long>(C, 0)  ->  É UMA LINHA de C zeros
//     m(L, <linha>)            ->  faz L cópias dessa linha
//
//   m.size()     = LINHAS
//   m[0].size()  = COLUNAS
//   m[i][j]      = [linha][coluna]
//
//   ⚠️ vector<A,B> NÃO é matriz! O 2º parâmetro é o ALOCADOR.
//   ⚠️ os tipos têm que CASAR: vector<vector<long long>> pede
//      vector<long long> dentro (não vector<long>).
//
// A pergunta que separa matriz das outras:
//   "os dados têm POSIÇÃO em 2D (linha x coluna)?" -> matriz
//   "os dados têm ORDEM de entrada e saída?"       -> stack/queue
//   "eu só preciso guardar e acessar por índice?"  -> vector
//
// REGRA: g++ -std=c++17 -Wall -Wextra -Wshadow -O2 arquivo.cpp -o a
// ============================================================


// ------------------------------------------------------------
// S8 — O EXERCÍCIO QUE MONTA O BFS
//
// Leia L e C e uma matriz L x C só com 0 e 1 (1 = parede).
// A entrada é a célula (0,0) e ela é sempre livre.
// Imprima quantas células livres são ALCANÇÁVEIS a partir de (0,0)
// andando apenas na horizontal e vertical (nunca na diagonal),
// sem atravessar paredes. Conte a própria (0,0).
//
// >>> ESTE É O BFS. Você já construiu TODAS as peças:
//       C5/S3 = a matriz é o labirinto
//       C6/S7 = os 4 vizinhos + limites (você acertou de PRIMEIRA)
//       C7/S2 = a fila de células a visitar
//       C8    = o vetor de visitados (acertou de PRIMEIRA)
//     Aqui elas se ENCAIXAM. Não é conceito novo — é montagem.
//
//     A LIÇÃO QUE VOCÊ ERROU NO RECALL (14/07 e hoje):
//     num labirinto você NÃO ESCOLHE um caminho. Guloso QUEBRA:
//     você entra num corredor que aponta para o alvo, ele termina
//     em beco, e você não sabe voltar nem quais bifurcações deixou
//     para trás.
//
//        A pergunta não é "POR ONDE EU VOU?"
//        A pergunta é  "QUAIS CÉLULAS EU ALCANÇO?"
//
//     Você não escolhe um caminho — você se ESPALHA por todos.
//
//     O algoritmo:
//       1. marque (0,0) como visitada e ponha na fila
//       2. enquanto a fila não estiver vazia:
//            tire a célula da frente (front() OLHA, pop() REMOVE!)
//            para cada um dos 4 vizinhos:
//               existe? é livre? AINDA NÃO VISITADO?
//                  -> marque como visitado E ponha na fila
//       3. a resposta é quantas você marcou
//
//     ⚠️ O passo "AINDA NÃO VISITADO" é o coração: sem ele o
//     algoritmo gira em círculos PARA SEMPRE e nunca termina.
//     ⚠️ Marque como visitado NA HORA DE ENFILEIRAR, não na hora de
//     desenfileirar — senão a mesma célula entra na fila várias vezes.
//     ⚠️ Visitados de matriz: vector<vector<bool>> visto(L, vector<bool>(C,false));
//
//     Se você fizer este exercício, você já sabe BFS. <<<
//
// // ESCOLHA:
// // (a)
// // (b)
//
// Entrada:
//   3 4
//   0 0 1 0
//   1 0 1 0
//   0 0 0 0
// Saída:
//   9
//   (TODAS as 9 células livres são alcançáveis.
//    Cuidado com a armadilha: (0,3) e (1,3) PARECEM bloqueados
//    pela parede da coluna 2 — mas dá para CONTORNAR por baixo,
//    descendo até (2,1), indo até (2,3) e subindo.
//    É exatamente por isso que guloso quebra: quem "escolhe o
//    caminho que aponta para o alvo" nunca faz esse desvio.
//    Trace no papel antes de codar.)
//
// Restrições: 1 <= L, C <= 1000.
// ------------------------------------------------------------

void S8(){
    int l, c; cin >> l >> c;
    vector<vector<int>> m(l, vector<int>(c, 0)); // Crio a matriz.
    for(int i =0; i < l; i++){
        for(int j = 0; j < c; j++){// Depois preencho a matriz com o labirito
            cin >> m[i][j];
        }
    }
    int dl[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1}; // Defino um dois array para poder olhar ao redor
    vector<vector<bool>> visto(l, vector<bool>(c, false)); // Quem eu já marquei
    queue<pair<int,int>> fila; // lista de pendências

    int livre = 1; 
    visto[0][0] = true;
    fila.push({0,0});
    
    while(!fila.empty()){
        pair<int, int> atual = fila.front(); // Pego o primeiro da fila e olho e guardo
        fila.pop(); // retiro o primeiro da fila
        int i = atual.first, j = atual.second; 

        for(int k =0; k < 4; k++){
            int ni = i + dl[k]; // declaro a linha do vizinho
            int nj = j + dc[k]; // declaro a coluna do vizinho
            if(ni >= 0 && ni < l && nj >= 0 && nj < c){ // Verifico se existe
                if(visto[ni][nj] == false && m[ni][nj] == 0){ // verifico se já foi visto
                    livre++;   
                    fila.push({ni,nj});
                    visto[ni][nj] = true;
                }  
            }
        }
    }
    cout << livre << "\n";
    
}




int main(){
    // Descomente o que for testar:
    // S1();
    // S2();
    // S3();
    // S4();
    // S5();
    // S6();
    // S7();
     S8();
    return 0;
}
