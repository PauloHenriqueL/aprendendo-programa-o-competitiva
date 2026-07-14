#include <bits/stdc++.h>
using namespace std;



/*
============================================================================
  CONCEITO NOVO — ALGORITMO GULOSO (GREEDY)
============================================================================
  (Explicacao para ler. Os 2 problemas no fim sao seus — resolva-os.)

  O QUE E?
    Guloso = a cada passo, escolher a opcao localmente MELHOR (a que parece
    melhor AGORA), sem voltar atras e sem reconsiderar. Voce ja fez isso hoje:
    - A7: comprar os itens MAIS BARATOS primeiro (para maximizar quantidade).
    - A8: pegar sempre a MAIOR moeda que cabe (para minimizar moedas).
    - No recall, voce DESCREVEU essa estrategia sozinho.

  O FORMATO TIPICO de um guloso (decore este esqueleto):
    1. ORDENAR os elementos por algum criterio (o "melhor primeiro").
    2. VARRER uma vez, pegando/decidindo item a item de forma gulosa.
    -> Custo tipico: O(N log N) do sort + O(N) da varredura = O(N log N).

  ============================================================================
  O PONTO MAIS IMPORTANTE: GULOSO NEM SEMPRE DA O OTIMO!  (cuidado!)
  ============================================================================
  Guloso e RAPIDO, mas so esta CORRETO se a "escolha local melhor" leva, de
  fato, ao melhor resultado global. Isso NEM SEMPRE acontece.

  EXEMPLO REAL (rodado e comprovado):
    Troco de 6 com moedas {1, 3, 4}:
      - GULOSO: pega 4 (o maior que cabe), sobra 2 -> 1 + 1. Total: 4+1+1 = 3 moedas.
      - OTIMO:  3 + 3 = 2 moedas!  O guloso ERROU (deu 3, o certo era 2).
    Com moedas {50,25,10,5,1} o guloso funciona (esse sistema e "canonico").
    Com {1,3,4} ele falha. A MOEDA importa!

  MORAL: antes de confiar num guloso, pergunte-se "a escolha gananciosa SEMPRE
  leva ao otimo, ou existe um caso onde 'guardar para depois' seria melhor?".
  Quando o guloso NAO serve, o caminho costuma ser Programacao Dinamica (DP) —
  que veremos mais a frente.

  COMO SABER SE O GULOSO FUNCIONA (na pratica de competicao):
    - Muitos problemas 800-1200 do Codeforces SAO gulosos e o guloso funciona.
    - Sinais de guloso: "minimo/maximo de X", "o maior numero de...", ordenar
      ajuda, decisao local obvia.
    - Se voce tem duvida, TESTE contra forca bruta em casos pequenos (foi o
      que fizemos para achar o {1,3,4}).

*/


/*
  ============================================================================
  PROBLEMA G1 — ATENDIMENTO NO MENOR TEMPO DE ESPERA TOTAL
  ============================================================================
  Ha N clientes numa fila e voce escolhe a ORDEM de atender. O cliente i leva
  t[i] minutos para ser atendido. O "tempo de espera" de um cliente e quanto
  tempo ele espera ATE o seu atendimento TERMINAR (inclui a espera pelos
  anteriores + o proprio atendimento). Escolha a ordem que MINIMIZA a soma dos
  tempos de espera de todos, e imprima essa soma minima.

  ENTRADA: N (1<=N<=1e5); depois N inteiros t[i] (1<=t[i]<=1e4).
  SAIDA:   a soma minima dos tempos de espera.
  EXEMPLO
    Entrada: 3 / 3 1 2
    Saida:   10
    (Melhor ordem: 1,2,3. Esperas: 1, 1+2=3, 1+2+3=6. Soma = 1+3+6 = 10.
     Se atendesse na ordem dada 3,1,2: 3, 3+1=4, 3+1+2=6 -> 13. Pior!)
  DICA: qual criterio guloso de ORDENACAO minimiza a espera total? Pense:
  atender o mais RAPIDO primeiro faz todo mundo esperar menos por ele.
  CUIDADO: a soma pode estourar int (N grande * tempos) -> long long.

  Peça dica se precisar;

*/



int G1() {
  int n; cin >> n;
  vector<int> vetor;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    vetor.push_back(x);
  }
  sort(vetor.begin(), vetor.end());
  long long soma = 0, acumular = 0;
  for(int i = 0; i < n; i++){
    acumular += vetor[i];
    soma += acumular;
    
  }
  cout << soma << endl;

  return 0;
}




/*

  ============================================================================
  PROBLEMA G2 — MAXIMO DE ATIVIDADES SEM CONFLITO (guloso classico)
  ============================================================================
  Voce tem N atividades, cada uma com horario de INICIO s[i] e FIM f[i]. Voce
  so pode fazer uma atividade por vez (nao podem se sobrepor: uma nova so pode
  comecar quando a anterior ja terminou). Qual o MAIOR numero de atividades
  que voce consegue fazer?

  ENTRADA: N (1<=N<=1e5); depois N linhas com s[i] e f[i] (0<=s[i]<f[i]<=1e9).
  SAIDA:   o numero maximo de atividades sem conflito.
  EXEMPLO
    Entrada:            Saida:
      3                   2
      1 3
      2 5
      4 6
    (Faz [1,3] e depois [4,6] -> 2 atividades. A [2,5] conflita com ambas.)
  DICA (guloso classico!): ordene as atividades pelo horario de TERMINO (f[i])
  crescente. Percorra pegando cada atividade cujo inicio nao conflita com o
  fim da ultima escolhida. Terminar cedo deixa mais espaco para as proximas.
  (Este e um dos gulosos mais famosos: "activity selection".)

  Peça dica se precisar;

============================================================================
*/

int G2() {
  int n; cin >> n;
  vector<pair<long long, long long>> ativ(n);
  for(int i = 0; i < n; i++){
    long long s, f;
    cin >> s >> f;
    ativ[i] = {f, s};
  }
  sort(ativ.begin(), ativ.end());

  int cont =0;
  long long ultimoFim = LLONG_MIN;
  for(auto& [fim, inicio] : ativ){
    if(inicio >= ultimoFim){
      cont++;
      ultimoFim = fim;
    }
  }

  cout << cont << "\n";
  return 0;
}
