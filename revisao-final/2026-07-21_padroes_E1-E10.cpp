#include <bits/stdc++.h>
using namespace std;
// ============================================================
// REVISÃO FINAL — 2026-07-21 (10 exercícios)
// FOCO: os PADRÕES DE ERRO que se repetem, não os conceitos.
//
// POR QUE ESTE ARQUIVO EXISTE:
// O diagnóstico de hoje (D1-D7 de 15/07) deu 6 AC e 1 WA.
// Busca binária SAIU do vermelho: D1, D2, D3 e D7 passaram, e o
// D7 era conceito NOVO (busca binária na resposta). Dois ponteiros
// idem (D5). Compilação limpa nos sete.
//
// O que falhou NÃO foi um conceito — foi MECÂNICA DE LAÇO:
//   (a) inicializar acumulador/sentinela com valor errado
//   (b) a linha certa NO LUGAR ERRADO (dentro x fora do laço)
// Esses dois erros já te pegaram em: M1, C2, C4, C5, D8 e agora D4.
// É o mesmo erro vestindo roupas diferentes. Este arquivo caça ELE.
//
// REGRA (você pediu para eu cobrar):
//   g++ -std=c++17 -Wall -Wextra -Wshadow -O2 arquivo.cpp -o a
//   Warning = teste falhando. E: compilação limpa é o PISO, não a
//   garantia (o -Wall não pega `cout` faltando). Rode os exemplos.
//
// PRÉ-FLIGHT (diga em voz alta antes de codar):
//   - meu acumulador começa com quanto? é IMPOSSÍVEL de verdade?
//   - esta linha mede algo VÁLIDO no ponto onde ela está?
//   - quando encolho a janela? (estourou -> conserta | já serve -> mede)
//   - long long? onde a CONTA explode (limites perto de 1e9)
//   - sentinela: -1 (0 é índice válido!) ou n+1 (nenhuma janela é maior)
// ============================================================


// ------------------------------------------------------------
// E1 — OPERADOR TERNÁRIO (a lacuna que você pediu)
//
// Leia N inteiros. Para cada um, imprima "PAR" ou "IMPAR".
// Depois imprima, em uma linha, o MAIOR dos N valores.
//
// OBRIGATÓRIO: use o operador ternário `?:` nas DUAS saídas.
// Nenhum `if` neste exercício.
//
// >>> POR QUE o ternário existe (você perguntou no recall):
//     `if` é um COMANDO — ele FAZ algo, não VALE nada.
//     `?:` é uma EXPRESSÃO — ela TEM um valor.
//     Por isso `cout << (a > b ? a : b)` funciona e
//     `cout << if(...)` nem compila. Um valor cabe dentro de um
//     cout, de um `=`, de um argumento de função. Um comando não.
//
//     Forma:  condicao ? valor_se_verdadeiro : valor_se_falso
// <<<
//
// Entrada:
//   5
//   3 8 1 10 7
// Saída:
//   IMPAR
//   PAR
//   IMPAR
//   PAR
//   IMPAR
//   10
//
// Restrições: 1 <= N <= 100000; valores até 1e9.
// ------------------------------------------------------------

void E1(){
    int n; cin >> n;
    vector<long long> vetor(n);
    for(int i = 0; i < n; i++){
        cin >> vetor[i];
    }
    long long maior = vetor[0];
    for(auto& valor : vetor){
        maior = (valor > maior ? valor : maior);
        cout << (valor % 2 == 0 ? "PAR" : "IMPAR") << "\n";
    }
    cout << maior << "\n";
}




// ------------------------------------------------------------
// E2 — JANELA DESLIZANTE (o D4 em roupa nova — vale como "de primeira")
//
// Leia N e T, depois N inteiros POSITIVOS.
// Imprima o comprimento do MENOR trecho contíguo cuja soma seja
// >= T. Se nenhum trecho alcança T, imprima 0.
//
// >>> É O MESMO PROBLEMA DO D4, que deu Wrong Answer. Os dois bugs:
//       1. `melhor = 0` + `min(...)` -> min com 0 é SEMPRE 0.
//          A resposta nunca sai do lugar.
//       2. a linha que MEDE estava DEPOIS do while que encolhe ->
//          mediu uma janela que já não valia mais.
//
//     Agora, sem olhar o D4_otimo, responda ANTES de codar:
//       - com quanto `melhor` deve começar? (dica: qual tamanho é
//         IMPOSSÍVEL para uma janela? não precisa ser LLONG_MAX)
//       - a medição vai DENTRO ou FORA do while? por quê?
//
//     A regra dos dois casos:
//       MAIOR com soma <= T -> while(soma > T): ESTOUROU, conserta
//                              e mede DEPOIS (fora do while)
//       MENOR com soma >= T -> while(soma >= T): JÁ SERVE, mede
//                              DENTRO e depois tenta encolher mais
// <<<
//
// Entrada:
//   6 8
//   2 1 5 1 3 2
// Saída:
//   3
//   (o menor trecho com soma >= 8 é "5 1 3" = 9, com 3 elementos)
//
// Restrições: 1 <= N <= 100000; T e a[i] até 1e9 (long long!).
// ------------------------------------------------------------

void E2(){
    int n; cin >> n;
    long long t; cin >> t;
    vector<long long> vetor(n);
    for(int i = 0; i < n; i++){
        cin >> vetor[i];
    }
    long long esq = 0, soma = 0, melhor = n + 1;
    for(int i = 0; i < n; i++){
        soma += vetor[i];
        while(soma >= t){
            melhor = min(melhor, i - esq + 1);
            soma -= vetor[esq];
            esq++;
        }
    }
    cout << (melhor != n+1 ? melhor : 0) << "\n";
}




// ------------------------------------------------------------
// E3 — ACUMULADOR: o mínimo que NÃO pode começar em zero
//
// Leia N inteiros (podem ser negativos). Imprima:
//   - o MENOR valor
//   - a POSIÇÃO (base 0) da PRIMEIRA ocorrência desse menor valor
// nessa ordem, separados por espaço.
//
// >>> DOIS 🔴 SEUS NA MESMA LINHA:
//     1. mínimo começando em 0 -> se todos os valores forem
//        positivos, a resposta sai 0 e está ERRADA (M1: você usou
//        v[1] e crashou com N=1).
//     2. VALOR e POSIÇÃO têm que andar JUNTAS, no MESMO if. Se você
//        atualizar o valor num if e a posição noutro, elas se
//        DESCOLAM (foi o C5, duas rodadas).
//
//     Pense: se SEMPRE existe resposta, qual o melhor chute inicial?
//     (dica: o primeiro elemento — e a posição dele!)
//     E: `<` estrito já te dá a PRIMEIRA ocorrência de graça. Por quê?
// <<<
//
// Entrada:
//   6
//   4 -2 7 -2 9 1
// Saída:
//   -2 1
//
// Restrições: 1 <= N <= 100000; valores de -1e9 a 1e9.
// ------------------------------------------------------------

void E3(){
    int n; cin >> n;
    vector<long long> vetor(n);
    for(int i =0; i < n; i++){
        cin >> vetor[i];
    }
    long long menor = vetor[0], posicao = 0;
    for(int i = 0; i < n; i++){
        if(vetor[i]<menor){
            menor = vetor[i];
            posicao = i;
        }
    }
    cout << menor << " " << posicao << "\n";
}




// ------------------------------------------------------------
// E4 — A LINHA NO LUGAR ERRADO (flag depois do laço fechar)
//
// Leia N e N inteiros. Diga quantos elementos são ESTRITAMENTE
// MAIORES que todos os elementos que vêm ANTES deles.
// (O primeiro elemento conta: não há nada antes dele.)
//
// >>> É o bug do D8: você pôs `pico++` DENTRO do laço dos vizinhos,
//     então uma matriz 1x1 imprimiu 4 em vez de 1.
//     A pergunta "sobreviveu a TODOS?" só pode ser feita DEPOIS que
//     o laço FECHOU. Dentro do laço você só pode DERRUBAR a flag,
//     nunca contar.
//
//     Existe uma solução O(N) sem laço interno nenhum. Ache ela.
//     (dica: o que você precisa lembrar do passado? só UM número.)
// <<<
//
// Entrada:
//   6
//   3 1 5 5 9 2
// Saída:
//   3
//   (o 3 conta - nada antes; o 5 conta - maior que 3 e 1;
//    o 9 conta. O segundo 5 NÃO conta: não é ESTRITAMENTE maior
//    que o primeiro 5.)
//
// Restrições: 1 <= N <= 100000; valores até 1e9.
// ------------------------------------------------------------

void E4(){
    int n; cin >> n;
    vector<long long> vetor(n);
    for(int i =0; i < n; i++){
        cin >> vetor[i];
    }
    int resposta = 0;
    long long maior = vetor[0];
    for(int i = 0; i < n; i++){
        if(i == 0){
            resposta++;
        } else{
            if(vetor[i] > maior){
                resposta++;
                maior = vetor[i];
            }
        }
    }
    cout << resposta << "\n";
}

// ------------------------------------------------------------
// E5 — `=` vs `+=` (atribuir x acumular) + soma corrente
//
// Uma loja registra N vendas ao longo do dia. Leia N e os N valores.
// Imprima:
//   - o FATURAMENTO TOTAL do dia
//   - o MAIOR saldo acumulado atingido em algum momento
// nessa ordem, em duas linhas.
//
// O "saldo acumulado no momento i" = soma das vendas de 0 até i.
//
// >>> O bug do C4: você escreveu `soma = pre[i]` onde precisava de
//     `soma += pre[i]`. ATRIBUIR joga fora o passado; ACUMULAR
//     soma a ele. O -Wall NÃO pega esse erro — os dois compilam.
//
//     E o 🔴 mais antigo seu: onde a CONTA explode? N=1e5 vendas de
//     1e9 = 1e14. Não cabe em int. Declare o CONTÊINER como
//     long long e resolva na ORIGEM, sem cast nenhum.
// <<<
//
// Entrada:
//   5
//   10 -3 8 -20 5
// Saída:
//   0
//   15
//   (acumulados: 10, 7, 15, -5, 0. O total é 0; o maior pico foi 15.)
//
// Restrições: 1 <= N <= 100000; valores de -1e9 a 1e9.
// ------------------------------------------------------------

void E5(){
    int n; cin >> n;
    vector<long long> totais(n);
    long long soma = 0;
    for(int i =0; i < n; i++){
        long long valor;
        cin >> valor;
        soma += valor;
        totais[i] = soma;
    }
    cout << totais[n-1] << "\n";
    sort(totais.begin(), totais.end());
    cout << totais[n-1] << "\n";

}


// ------------------------------------------------------------
// E6 — SENTINELA IMPOSSÍVEL (-1 x 0) + busca binária
//
// Leia N inteiros ORDENADOS crescente (pode repetir) e Q consultas.
// Para cada X, imprima o índice (base 0) da ÚLTIMA ocorrência de X,
// ou -1 se X não existir.
//
// >>> ATENÇÃO: é a ÚLTIMA ocorrência. O D2 era a PRIMEIRA.
//     Ao achar X, para que lado você continua procurando agora?
//
//     E o 🔴 do sentinela: por que a resposta "não achei" tem que
//     ser -1 e NÃO 0? (dica: 0 é uma resposta VÁLIDA — é o índice
//     do primeiro elemento. Um sentinela que colide com uma resposta
//     real é indistinguível dela.)
//
//     Busca binária OBRIGATÓRIA. Busca linear = TLE.
// <<<
//
// Entrada:
//   7
//   1 3 3 3 7 9 9
//   4
//   3
//   9
//   1
//   5
// Saída:
//   3
//   6
//   0
//   -1
//
// Restrições: 1 <= N, Q <= 100000; valores até 1e9.
// ------------------------------------------------------------

void E6(){
    int n; cin >> n;
    vector<long long> vetor(n);
    for(int i =0; i<n; i++){
        cin >> vetor[i];
    }
    int q; cin >> q;
    vector<long long> resposta(q, -1);
    for(int i = 0; i < q; i++){
        long long lo = 0, hi = n -1, meio = 0, x;
        cin >> x;
        
        while(lo<=hi){
            meio = lo + (hi - lo)/2;
            if(vetor[meio] == x){
                resposta[i] = meio;
                lo = meio + 1;
            } else if(vetor[meio] > x){
                hi = meio - 1;
            } else {
                lo = meio + 1;
            }
        }
    }
    for(auto& valor : resposta) cout << valor << "\n";
}


// ------------------------------------------------------------
// //  — DOIS PONTEIROS: contar em BLOCO (um ponteiro por vez!)
//
// Leia N e N inteiros ORDENADOS crescente. Leia X.
// Conte quantos pares (i, j) com i < j têm v[i] + v[j] <= X.
//
// >>> Agora é <= (o D5 era >=). A direção do descarte INVERTE.
//
//     OS DOIS 🔴 DESTE EXERCÍCIO:
//     1. UM ponteiro por iteração. No C2 você pôs `dir--` fora do
//        `else`, moveu os dois, e matou pares que deviam contar.
//     2. contar em BLOCO: quando um par (esq,dir) vale, TODOS os
//        pares entre esq e dir também valem — some `dir - esq` de
//        uma vez, não um por um. Senão vira O(N²).
//     3. o contador estoura int: n²/2 com n=1e5 é ~5e9. long long.
//
//     O(N). Sem laço aninhado — a TÉCNICA já é o laço.
// <<<
//
// Entrada:
//   5 6
//   1 2 3 4 5
// Saída:
//   6
//   (pares com soma <= 6: 1+2, 1+3, 1+4, 1+5, 2+3, 2+4. São 6.)
//
// Restrições: 1 <= N <= 100000; valores até 1e9.
// ------------------------------------------------------------

void E7 (){
    int n; cin >> n;
    long long x; cin >> x;
    vector<long long> vetor(n);
    for(int i =0; i < n; i++){
        cin >> vetor[i];
    }
    long long esq = 0, dir = n -1, soma = 0, resposta = 0;
    while(esq < dir){
        soma = vetor[esq] + vetor[dir];
        if(soma <= x){
            resposta += (dir - esq);
            esq++;
        } else {
            dir--;
        }
    }
    cout << resposta << "\n";
}

// ------------------------------------------------------------
// E8 — BUSCA BINÁRIA NA RESPOSTA (o D7 numa roupa nova)
//
// N pessoas querem atravessar um rio. Há N mochilas com pesos a[i].
// Um barco aguenta no máximo P quilos por viagem e leva NO MÁXIMO
// 2 mochilas por vez. Qual o MENOR número de viagens para levar
// todas as mochilas? Se alguma mochila sozinha pesa mais que P,
// imprima -1.
//
// >>> Este NÃO é busca binária na resposta — é guloso + dois
//     ponteiros (é o problema dos "Botes" que você já fez, D2 de
//     13/07). Coloquei junto DE PROPÓSITO, misturado com o E9, para
//     você treinar a pergunta que salva:
//
//        "o que este problema me PROÍBE de fazer?"
//        "esta técnica que me veio à cabeça é MESMO a certa?"
//
//     Foi assim que o D1 (CF 279B) te pegou: você aplicou `sort` num
//     problema que proibia reordenar, porque reconheceu o padrão
//     rápido DEMAIS. Ter repertório é bom E perigoso.
// <<<
//
// Entrada:
//   5 10
//   9 2 3 8 1
// Saída:
//   3
//   (ordenado: 1 2 3 8 9. Viagens: (1,9), (2,8), (3) = 3 viagens.)
//
// Restrições: 1 <= N <= 100000; pesos e P até 1e9.
// ------------------------------------------------------------

void E8(){
    int n; cin >> n;
    long long max; cin >> max;
    vector<long long> vetor(n);
    for(int i = 0; i < n; i++){
        cin >> vetor[i];
    }
    sort(vetor.begin(), vetor.end());
    if(vetor[n-1]>max){
        cout << -1 << "\n";
    } else{    
        long long esq = 0, dir = n -1, peso = 0, resposta = 0;
        while(esq<=dir){
            peso = vetor[esq] + vetor[dir];
            if(peso <= max){
                resposta++;
                esq++;
                dir--;
            } else {
                resposta++;
                dir--;
            }
        }
        cout << resposta << "\n";
    }
}

// ------------------------------------------------------------
// E9 — BUSCA BINÁRIA NA RESPOSTA de verdade (o conceito do D7)
//
// Você tem N pilhas de moedas, com a[i] moedas cada.
// Você quer dar a mesma quantidade M de moedas para cada um dos K
// amigos. De uma pilha de a[i] moedas você consegue tirar a[i]/M
// porções de M moedas (divisão inteira; o resto se perde).
// Qual o MAIOR M possível para atender os K amigos?
// Se nem M=1 atende K amigos, imprima 0.
//
// >>> É a MESMA técnica do D7 (que você acertou e passou em 200
//     casos de força bruta). A pergunta 9 do recall era esta:
//
//     O QUE PRECISA SER VERDADE para buscar binário na RESPOSTA?
//     A resposta é MONOTONICIDADE: quanto MAIOR o M, MENOS porções
//     saem — nunca o contrário. Então o "dá pra atender K?" é
//     sim-sim-sim-NÃO-NÃO-NÃO, sem alternar:
//
//        M:      1    2    3    4  |  5    6    7
//        dá K?   sim  sim  sim  sim|  não  não  não
//                                  ^ a resposta é a FRONTEIRA
//
//     Se M=5 falha, NENHUM M maior funciona -> joga metade fora.
//     A monotonicidade faz o papel da ordenação.
//
//     GATILHO no enunciado: "o MAIOR X tal que ainda dá" ou "o MENOR
//     X tal que já dá", e testar um X específico é fácil.
//     Você não busca NUM VETOR — busca NO ESPAÇO DE RESPOSTAS.
//
//     CUIDADO: a soma de porções estoura int. E o limite superior
//     do seu `hi` — qual é? (dica: nenhum M maior que a maior pilha
//     produz porção alguma.)
// <<<
//
// Entrada:
//   4 7
//   5 9 12 6
// Saída:
//   4
//   (com M=4: 5/4=1, 9/4=2, 12/4=3, 6/4=1 -> 7 porções >= 7 ok.
//    com M=5: 1+1+2+1 = 5 < 7 não. Logo o maior M é 4.)
//
// Restrições: 1 <= N <= 100000; 1 <= a[i] <= 1e9; 1 <= K <= 1e9.
// ------------------------------------------------------------
void E9(){
    int n, k; cin >> n >> k;
    vector<long long> vetor(n);
    for(int i = 0; i < n; i++){
        cin >> vetor[i];
    }
    long long  esq = 1, dir = *max_element(vetor.begin(), vetor.end()), meio = 0, melhor = 0;
    while(esq<=dir){
        long long porcoes = 0;
        meio = esq + (dir - esq)/2;
        for(int i = 0; i < n; i++){
            porcoes += vetor[i]/meio;
        }
        if(porcoes<k){
            dir = meio - 1;
        } else{
            melhor = meio;
            esq = meio + 1;
        }
    }
    cout << melhor << "\n";
}


// ------------------------------------------------------------
// E10 — MATRIZ + os 4 vizinhos (a PONTE para o BFS)
//
// Leia L e C, depois uma matriz L x C só com 0 e 1, onde 1 é
// PAREDE e 0 é livre.
// Uma célula livre é uma "SAÍDA POTENCIAL" se ela está livre E
// está na BORDA da matriz (primeira/última linha ou coluna).
// Imprima quantas saídas potenciais existem, e depois, em outra
// linha, quantas células livres têm PELO MENOS 2 vizinhos
// ortogonais livres.
//
// >>> ESTE EXERCÍCIO É A PONTE PARA GRAFOS (semana 25-31/07).
//     Você vai varrer uma grade, olhar os 4 vizinhos, tratar
//     limites e contar — que é EXATAMENTE o corpo do BFS.
//     Só falta a fila e o vetor de visitados (arquivo S).
//
//     O padrão dl/dc, que você aprendeu no D8:
//        dl[4] = {-1, 1, 0, 0};   dc[4] = {0, 0, -1, 1};
//        ni = i + dl[k];  nj = j + dc[k];
//     `dl[k]` é DESLOCAMENTO, `ni` é POSIÇÃO — só POSIÇÃO indexa a
//     matriz (o bug da 2ª rodada do D8: matriz[dl[k]][dc[k]]).
//     O teste de existência ABRAÇA o acesso: if(existe){ acessa }.
//
//     E lembre do E4: contar DEPOIS do laço k fechar, nunca dentro.
// <<<
//
// Entrada:
//   3 4
//   0 1 0 0
//   0 0 0 1
//   1 0 1 0
// Saída:
//   6
//   4
//
// Restrições: 1 <= L, C <= 1000.
// ------------------------------------------------------------
// E10: não resolvido pelo aluno (ele reconheceu a modelagem mas travou
// ao encaixar). Solução comentada e explicada em E10_otimo, abaixo.



// ============================================================
// E10_otimo — a SOLUÇÃO (pedida pelo aluno em 2026-07-21)
// ============================================================
// Validado: exemplo (6 e 4) + bordas (1x1 livre, tudo parede)
// + 1000x1000 em 0,144s.
//
// >>> POR QUE VOCÊ TRAVOU (e NÃO foi por não saber):
//     Você já tinha escrito 80% disto: a matriz, o dl/dc, o
//     ni/nj, e o teste de limites — TUDO CERTO.
//     O que travou foi ter colado o MIOLO DO D8 (pico local) num
//     problema que faz OUTRA pergunta. O molde veio antes da
//     leitura do enunciado — mesmo mecanismo do `sort` no CF 279B.
//
// >>> AS 3 LIÇÕES DESTE EXERCÍCIO:
//
//  1. FLAG x CONTADOR — a natureza da pergunta decide a ferramenta:
//       D8:  "é maior que TODOS os vizinhos?"  -> FLAG booleana
//            (só pode ser DERRUBADA dentro do laço)
//       E10: "QUANTOS vizinhos são livres?"    -> CONTADOR
//            (ACUMULA dentro do laço)
//     Foi por isso que o `ehpico` não encaixou. Antes de codar,
//     pergunte: é "todos/nenhum" (flag) ou "quantos" (contador)?
//
//  2. ACUMULA DENTRO, DECIDE FORA — o padrão deste arquivo inteiro:
//       `livres++`      fica DENTRO do laço k
//       `corredores++`  fica FORA (depois que o laço k FECHOU)
//     Mesmo princípio do E2 (medir dentro do while) e do E4.
//
//  3. BORDA NÃO PRECISA DE VIZINHO: `i==0 || i==l-1 || j==0 || j==c-1`
//     responde sozinho, olhando só a própria posição.
//
//     E o `continue`: se é parede, pula tudo. É o EARLY RETURN do
//     E8 na versão "pula esta iteração".
// ============================================================
void E10_otimo(){
    int l, c; cin >> l >> c;
    vector<vector<int>> m(l, vector<int>(c, 0));
    for(int i = 0; i < l; i++)
        for(int j = 0; j < c; j++)
            cin >> m[i][j];

    int dl[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int saidas = 0;      // pergunta 1: livre E na borda
    int corredores = 0;  // pergunta 2: livre COM >= 2 vizinhos livres

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            if(m[i][j] == 1) continue;   // parede: nenhuma pergunta se aplica

            // --- pergunta 1: está na borda? não olha vizinho nenhum ---
            if(i == 0 || i == l-1 || j == 0 || j == c-1) saidas++;

            // --- pergunta 2: CONTA quantos vizinhos são livres ---
            int livres = 0;
            for(int k = 0; k < 4; k++){
                int ni = i + dl[k], nj = j + dc[k];
                // o teste de existência ABRAÇA o acesso:
                if(ni >= 0 && ni < l && nj >= 0 && nj < c && m[ni][nj] == 0)
                    livres++;            // DENTRO do laço: só ACUMULA
            }
            if(livres >= 2) corredores++;  // FORA do laço k: aqui DECIDE
        }
    }
    cout << saidas << "\n" << corredores << "\n";
}


int main(){
    // Descomente o que for testar:
    // E1();
    // E2();
    // E3();
    // E4();
    // E5();
    // E6();
    // E7();
    // E8();
     E9();
    // E10();
    return 0;
}
