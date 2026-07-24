#include <bits/stdc++.h>
using namespace std;
// ============================================================
// CONTEST 1 — PROBLEMAS REAIS DA SELETIVA UnB 2025
// Prova original: 19/07/2025 · Caderno com 14 problemas
// https://danielsaad.com/maratona/assets/seletiva-unb-2025/caderno-seletiva-unb-2025.pdf
//
// ⚠️ POR QUE UnB E NÃO UFMG: a UFMG NÃO publica os problemas das
// suas seletivas internas (só notícias e recursos no site oficial).
// Estes são problemas REAIS de uma seletiva brasileira do mesmo
// formato e da mesma comunidade (ICPC Brasil). Ver o README.
//
// SÃO 4 DOS 14. Os outros 10 são mais difíceis e ficaram de fora
// DE PROPÓSITO — não porque você não deva tentar, mas porque estes
// 4 são os que cabem no seu nível HOJE, a 14 dias da prova.
//
// REGRA DA CASA:
//   g++ -std=c++17 -Wall -Wextra -Wshadow -O2 arquivo.cpp -o a
//
// ⚠️ ESTES SÃO PROBLEMAS DE PROVA REAL. Isso muda 3 coisas:
//   1. O enunciado tem HISTÓRIA. A tarefa real está escondida no
//      meio da piada. Leia até o fim ANTES de codar.
//      (é o seu 🔴: o molde dispara antes da leitura terminar)
//   2. A SAÍDA é exata — texto, acentuação, pontuação. Um "cafe"
//      escrito "café" é Wrong Answer. Copie do enunciado.
//   3. Tem PENALIDADE por submissão errada. Rode o exemplo ANTES.
//
// ORDEM SUGERIDA: A2 → E → J → C  (do mais direto ao mais difícil)
// (o problema A original foi QUEIMADO por um erro meu de transcrição;
//  o substituto A2 treina os mesmos pontos — ver o comentário lá.)
// ============================================================


// ------------------------------------------------------------
// PROBLEMA A — Athleta Alemão          (Seletiva UnB 2025)
// Limite de tempo: 1s · Limite de memória: 256MB
// Autor: Guilherme Ramos
//
// Vin Borgen é um alemão radicado em Brasília, que abandonou seu
// cotidiano de weißwurst und weißbier para forjar um glorioso
// histórico de athleta no interior de Minas Gerais. Multicampeão
// de corridas, ele treina intensamente para manter o ritmo (e as
// vitórias).
//
// Herr Borgen sabe que o segredo do sucesso alemão é a
// laufschrittfrequenz, a cadência da volta do athleta. Cada volta
// no circuito deve ser feita dentro de um intervalo de tempo
// razoável para a sua cadência, de modo a manter um desempenho
// ótimo e constante. Ajude-o a acompanhar e ajustar seu treino!
//
// ENTRADA
// A primeira linha fornece a meta do athleta alemão — o tempo de
// uma volta na cadência adequada para o circuito, em minutos.
// A seguir é dada uma quantidade INDETERMINADA de linhas, cada uma
// indicando o tempo, em minutos, de uma volta dada por Herr Borgen
// (nenhuma volta demora menos de 1 minuto ou mais de 12 horas).
// Ele corre até não conseguir manter o ritmo.
//
// SAÍDA
// Para cada volta, apresente uma mensagem de apoio ao treino:
//   - se desviar MAIS QUE 5% da meta:
//       "Athelera, fera!"                     (se for LENTO)
//       "Calma que ainda tem o returno."      (se for RÁPIDO)
//   - caso contrário:
//       "Boa! Merece cafe e pao de queijo."
//
// ⚠️⚠️ ENUNCIADO CORRIGIDO EM 2026-07-24 — ERRO DE TRANSCRIÇÃO MEU.
// A primeira versão que eu escrevi aqui juntou os DOIS casos de
// teste do exemplo num só (o `pdftotext` achatou as duas caixas do
// PDF numa coluna só de números: 50 50 60 62 63 64).
// Eu li como "meta 50, cinco voltas" e ainda inventei uma armadilha
// que NÃO EXISTE. O código do aluno estava CERTO e eu julguei errado.
// >>> O PDF ORIGINAL está em `seletiva/caderno_seletiva_unb_2025.pdf`,
//     problema A na PÁGINA 4. Confira sempre a fonte. <<<
//
// EXEMPLO (são DOIS casos de teste independentes!)
//
//   CASO 1                     CASO 2
//   Entrada:  Saída:           Entrada:  Saída:
//   50        Boa! ...         60        Boa! Merece cafe e pao de queijo.
//   50                         62        Boa! Merece cafe e pao de queijo.
//                              63        Athelera, fera!
//                              64
//
//   Caso 1: meta=50, volta 50  -> desvio 0%   -> Boa!
//   Caso 2: meta=60
//           volta 62 -> 3,3%   -> Boa!
//           volta 63 -> 5,0%   -> Boa!   <<< EXATAMENTE 5% ainda é BOA
//           volta 64 -> 6,7%   -> Athelera, fera!
//
// >>> ⚠️ ESTE PROBLEMA É 90% SAÍDA — e saída é o seu 🔴 nº1
//     (6 ocorrências: B7, D1, C7, E3, E6, E8).
//     As strings são EXATAMENTE como estão acima. Sem acento em
//     "cafe" e "pao". Ponto final em "returno." e não em "fera!".
//     COPIE E COLE do enunciado. Não digite de memória.
//
//     ⚠️ ARMADILHA 1 — "quantidade INDETERMINADA de linhas":
//     você não sabe quantas voltas são. Precisa ler ATÉ ACABAR.
//     Você já fez isso no M4: `while(cin >> x){ ... }`
//
//     ⚠️ ARMADILHA 2 — A META É FIXA. Ela é lida UMA VEZ, na
//     primeira linha, e vale para TODAS as voltas. Não atualize a
//     meta a cada volta — o caso 2 prova isso: 62, 63 e 64 são
//     todos comparados contra 60, nunca contra a volta anterior.
//     (se a meta virasse a volta anterior, 64 vs 63 = 1,6% -> Boa,
//      e o gabarito diz Athelera.)
//
//     ⚠️ ARMADILHA 3 — "desviar mais que 5%": ESTRITAMENTE maior.
//     O caso 2 é a prova: 63 vs 60 é exatamente 5% e a resposta é
//     "Boa!". É o `<` vs `<=` que já te pegou 5 vezes.
//     ⚠️ E NÃO USE `double`: `60 * 1.05` pode dar 63.000000000000007
//     e a comparação de borda vira loteria. Multiplique por 100 e
//     compare INTEIROS:
//         x * 100 < meta * 95   (rápido)
//         x * 100 > meta * 105  (lento)
//     Zero imprecisão. É assim que se faz em prova.
// ------------------------------------------------------------

void A(){
    long long meta; cin >> meta;
    long long x;
    while(cin >> x){
        if(x < (meta * 0.95)){
            cout << "Calma que ainda tem o returno." << "\n";
        } else if(x > (meta * 1.05)){
            cout << "Athelera, fera!" << "\n";
        } else {
            cout << "Boa! Merece cafe e pao de queijo." << "\n";
        }
        meta = x;
    }
}
// ↑ ESTA VERSÃO ESTÁ ERRADA por causa do `meta = x;` (a meta é FIXA).
//   Sem essa linha, ela passa nos dois casos e em todas as bordas.
//   O `meta = x` foi adicionado por causa do MEU gabarito quebrado.


// ------------------------------------------------------------
// PROBLEMA A2 — Fornada de Pão de Queijo        (SUBSTITUTO)
// Limite de tempo: 1s · Limite de memória: 256MB
//
// >>> POR QUE ESTE PROBLEMA EXISTE: eu estraguei o problema A ao
//     transcrever o exemplo errado do PDF. Depois da discussão,
//     você já sabe a resposta dele (meta fixa, 5% exato é "Boa",
//     as três strings) — não sobrou nada para descobrir.
//     Este treina EXATAMENTE os mesmos pontos, com roupa nova:
//       1. ler quantidade INDETERMINADA de valores (até EOF)
//       2. classificar em 3 faixas com borda ESTRITA
//       3. saída com texto EXATO (o seu 🔴 nº1)
//       4. aritmética INTEIRA em vez de ponto flutuante
//     + 1 ponto novo: acumular durante o laço e RESUMIR no fim
//       (o padrão "acumula dentro, decide fora" do E2/E4/E10)
//
//     ⚠️ ESTE GABARITO EU VALIDEI antes de te entregar. Se algum
//     exemplo não fechar, desconfie de mim primeiro — foi o que
//     aconteceu no A. Confira e me cobre.
//
// A padaria de dona Ruth assa pão de queijo o dia inteiro. Cada
// fornada tem um tempo ideal de forno, em segundos, que depende do
// dia (umidade, tamanho da bolinha, humor do forno).
//
// Dona Ruth anota o tempo de cada fornada e quer saber quais
// saíram no ponto. Uma fornada está PERFEITA se o seu tempo não
// desviar MAIS QUE 8% do tempo ideal. Se passar disso, ou queimou
// (demorou demais) ou está crua (rápido demais).
//
// ENTRADA
// A primeira linha contém um inteiro T, o tempo ideal de forno em
// segundos (3 <= T <= 1e9).
// As linhas seguintes contêm, cada uma, um inteiro x: o tempo da
// fornada em segundos (1 <= x <= 1e9). A quantidade de fornadas é
// INDETERMINADA — leia até o fim da entrada. Há pelo menos uma.
//
// SAÍDA
// Para cada fornada, imprima UMA linha:
//   - "CRU: volta pro forno."      se desviou mais que 8% para MENOS
//   - "QUEIMOU: fora!"             se desviou mais que 8% para MAIS
//   - "PERFEITO: pode servir."     caso contrário
// Ao final, imprima uma última linha:
//   "<N> fornada(s) perfeita(s)."
// onde <N> é quantas fornadas ficaram perfeitas.
//
// EXEMPLO 1
//   Entrada:      Saída:
//   25            PERFEITO: pode servir.
//   25            PERFEITO: pode servir.
//   27            PERFEITO: pode servir.
//   23            QUEIMOU: fora!
//   30            CRU: volta pro forno.
//   21            3 fornada(s) perfeita(s).
//
//   (8% de 25 = 2, então a faixa perfeita é [23, 27] INCLUSIVE.
//    25 -> 0%     -> PERFEITO
//    27 -> +8,0%  -> PERFEITO  <<< exatamente 8% AINDA É PERFEITO
//    23 -> -8,0%  -> PERFEITO  <<< idem, do outro lado
//    30 -> +20%   -> QUEIMOU
//    21 -> -16%   -> CRU)
//
// EXEMPLO 2
//   Entrada:      Saída:
//   50            PERFEITO: pode servir.
//   54            1 fornada(s) perfeita(s).
//
//   (8% de 50 = 4; 54 é exatamente +8% -> PERFEITO)
//
// >>> ⚠️ AS ARMADILHAS (leia antes de codar):
//
//     1. QUANTIDADE INDETERMINADA -> `while(cin >> x){ ... }`
//        (o padrão do M4). Você não sabe quantas fornadas são.
//
//     2. A REFERÊNCIA É FIXA. T é lido UMA VEZ e vale para todas
//        as fornadas. Não atualize T a cada linha.
//
//     3. "MAIS QUE 8%" É ESTRITO. Exatamente 8% ainda é PERFEITO.
//        Os dois exemplos testam essa borda de propósito.
//
//     4. ⚠️⚠️ NÃO USE `double`. Com T = 1000000007:
//              1080000007 é exatamente +8%  -> PERFEITO
//              1080000008 é um a mais       -> QUEIMOU
//        Um `T * 1.08` em double não distingue esses dois com
//        segurança. Faça em INTEIROS:
//              x * 100 < T * 92    -> CRU
//              x * 100 > T * 108   -> QUEIMOU
//              caso contrário      -> PERFEITO
//
//     5. ⚠️ OVERFLOW (seu 🔴 histórico, 7 reps): T até 1e9, e
//        `T * 108` = 1,08e11. NÃO CABE EM INT (máx ~2,1e9).
//        `long long` desde a declaração — resolve na ORIGEM,
//        sem cast (a lição do B6/B8).
//
//     6. O CONTADOR e o RESUMO: você conta DENTRO do laço e
//        imprime o total FORA, depois que o laço fechou. É o
//        "acumula dentro, decide fora" do E2, E4 e E10.
//        ⚠️ E o formato da última linha é EXATO — com o "(s)" nos
//        dois lugares e o ponto final. Copie do enunciado.
// ------------------------------------------------------------

void A2(){
    long long meta, x, cont = 0; cin >> meta;
    while(cin>>x){
        if(x > (meta * 1.08)){
            cout << "QUEIMOU: fora!" << "\n";
        } else if (x < (meta * 0.92)){
            cout << "CRU: volta pro forno." << "\n";
        } else {
            cout << "PERFEITO: pode servir." << "\n";
            cont++;
        }
    }
    cout << cont << " fornada(s) perfeita(s)."<< "\n";
}
         


int main(){
    // Descomente o que for testar:
    // A();    // versão original (com bug do meta=x; ver comentário)
    // A2();   // ✅ AC
    return 0;
}
