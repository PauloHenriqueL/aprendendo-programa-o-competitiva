/*
============================================================================
  TEORIA (leia com calma) + 1 ATIVIDADE para praticar pair + guloso
============================================================================

  ==========================================================================
  1) O QUE E "GULOSO" (greedy) — relembrando
  ==========================================================================
  Guloso = a cada passo, escolher a opcao localmente MELHOR, sem voltar
  atras. Esqueleto tipico: ORDENAR por um criterio + VARRER uma vez pegando
  o que puder. Custo: O(N log N) do sort + O(N) da varredura = O(N log N).
  ATENCAO: guloso nem sempre da o otimo (lembra do troco {1,3,4}). So use
  quando a escolha gananciosa comprovadamente leva ao melhor global.


  ==========================================================================
  2) O QUE E   vector<pair<long long, long long>> ativ(n);
  ==========================================================================
  Vamos por partes:

  pair<A, B>  -> um "PAR": uma caixinha que guarda DOIS valores JUNTOS.
                 O primeiro acessa-se com .first, o segundo com .second.
                 Ex.: pair<int,int> p = {3, 7};  p.first==3 ; p.second==7
                 Serve para manter dois dados que pertencem a MESMA coisa
                 grudados (ex.: inicio E fim da MESMA atividade).

  pair<long long, long long> -> um par onde os dois valores sao long long
                 (numeros grandes, ate ~9e18). Se os valores fossem pequenos
                 poderia ser pair<int,int>. Aqui usamos long long por seguranca.

  vector<pair<long long,long long>>  -> um VETOR (lista) onde CADA elemento e
                 um par. Ou seja: uma lista de caixinhas-de-dois-valores.
                 Perfeito para uma lista de atividades (cada uma tem 2 numeros).

  ativ(n)  -> cria esse vetor JA com n posicoes (dimensionado em runtime),
              igual voce faz com vector<int> v(n). Cada posicao comeca como
              um par {0,0} que voce vai preencher.

  Como usar na pratica:
      vector<pair<long long,long long>> ativ(n);
      ativ[i] = {fim, inicio};        // guarda os dois JUNTOS numa posicao
      ativ[i].first                   // pega o primeiro (aqui, o fim)
      ativ[i].second                  // pega o segundo (aqui, o inicio)
      sort(ativ.begin(), ativ.end()); // ordena a lista pelo .first (o fim!)

  Por que colocar {fim, inicio} e nao {inicio, fim}?
      Porque sort(pair) ordena pelo .first. Como o guloso de atividades ordena
      pelo horario de TERMINO, poe-se o fim como .first para o sort ordenar
      por ele automaticamente.

  Percorrer os pares (duas formas equivalentes):
      // forma A (structured binding, C++17 — da nomes aos dois campos):
      for(auto& [fim, inicio] : ativ){ ... usa fim e inicio ... }
      // forma B (classica):
      for(auto& p : ativ){ ... usa p.first e p.second ... }


  ==========================================================================
  3) DIFERENCA entre pair (vector<pair>) e MAP — quando usar cada um
  ==========================================================================
  map<Chave, Valor>:
    - Associa UMA chave a UM valor e permite BUSCAR pela chave rapidamente.
    - As chaves sao UNICAS (nao repete) e ficam ordenadas PELA CHAVE.
    - Use quando voce precisa perguntar "qual o valor da chave X?" (ex.:
      nome -> quantidade de votos; palavra -> quantas vezes apareceu).

  vector<pair>:
    - E so uma LISTA de pares. Pode ter pares repetidos, e voce ORDENA por
      qualquer criterio (com sort).
    - Use quando voce tem uma COLECAO de itens (cada um com 2+ campos) e
      precisa ORDENAR/percorrer essa colecao (ex.: atividades por horario de
      fim; alunos por nota).

  REGRA PRATICA:
    - Preciso BUSCAR por chave / contar ocorrencias   -> map
    - Preciso ORDENAR uma lista de itens por um campo  -> vector<pair> + sort
    Neste problema queremos ORDENAR atividades pelo fim -> vector<pair>, NAO map.
    (map ordenaria pela chave e nao aceitaria dois inicios iguais.)


  ==========================================================================
  4) O QUE E   long long ultimoFim = LLONG_MIN;
  ==========================================================================
  long long ultimoFim -> uma variavel que vai guardar o horario de TERMINO da
       ULTIMA atividade que voce ESCOLHEU. Serve para checar se a proxima
       atividade conflita (comeca antes desse fim) ou nao.

  = LLONG_MIN -> LLONG_MIN e o MENOR valor possivel de um long long (algo como
       -9e18). Iniciar com ele significa "ainda NAO escolhi nenhuma atividade".
       Assim, a PRIMEIRA atividade sempre passa no teste (inicio >= -infinito),
       ou seja, e sempre escolhida. E o mesmo espirito de iniciar o "maior" com
       INT_MIN (nunca iniciar com 0, que poderia dar bug). Precisa de <climits>
       (ja incluso no bits/stdc++.h).

  Uso no loop guloso:
      long long ultimoFim = LLONG_MIN;   // nada escolhido ainda
      for(auto& [fim, inicio] : ativ)    // em ordem de fim crescente
          if(inicio >= ultimoFim){       // nao conflita com a ultima escolhida?
              cont++;                     // escolhe esta
              ultimoFim = fim;            // agora a ultima escolhida termina aqui
          }


  ============================================================================
  ATIVIDADE H1 — MAXIMO DE PALESTRAS NUMA SALA (activity selection)
  ============================================================================
  Uma sala de eventos recebe pedidos para N palestras. A palestra i comeca no
  minuto s[i] e termina no minuto f[i]. A sala so comporta UMA palestra por
  vez (duas palestras nao podem se sobrepor; uma nova so pode comecar quando a
  anterior ja terminou). Escolhendo bem quais aceitar, qual o MAIOR numero de
  palestras que a sala consegue realizar?

  ENTRADA: N (1<=N<=1e5); depois N linhas, cada uma com s[i] e f[i]
           (0 <= s[i] < f[i] <= 1e9).
  SAIDA:   o numero maximo de palestras sem sobreposicao.

  EXEMPLOS
    Entrada:            Saida:
      4                   2
      1 4
      3 5
      0 6
      5 7
    (Aceita [1,4] e depois [5,7] -> 2. As outras conflitam.)

    Entrada:            Saida:
      3                   3
      1 2
      3 4
      5 6
    (Todas disjuntas -> aceita as 3.)

  DICA: e o mesmo guloso do G2 (activity selection). Guarde cada palestra como
  pair {fim, inicio}, ordene pelo fim, e percorra escolhendo toda palestra cujo
  inicio nao conflita com o fim da ultima escolhida. Use ultimoFim como acima.
  (Uma palestra que comeca exatamente quando a outra termina NAO conflita:
   inicio >= ultimoFim conta.)

  Peça dica se precisar;
============================================================================
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<pair<long long, long long>> ativ(n);
  for(int i =0; i < n; i++){
    long long s, f;
    cin >> s >> f;
    ativ[i] = {f , s};
  }
  sort(ativ.begin(), ativ.end());
  int cont = 0;
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
