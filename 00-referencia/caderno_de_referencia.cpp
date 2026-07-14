/*
=============================================================================
  visto.cpp  —  CADERNO DE REFERENCIA (Paulo / programacao competitiva)
=============================================================================
  Reune TODOS os conceitos, estruturas e "padroes de competicao" que eu vi
  ate agora, com exemplos comentados. Serve para CONSULTA: quando esquecer
  como se cria/usa algo (vector, for-range, array de contagem, sort, pilha...),
  procure aqui a funcao correspondente e leia o comentario.

  Cada demonstracao esta numa funcao propria demo_XXXX(). O main() no fim
  permite rodar uma demo por vez (veja instrucoes la embaixo).

  COMPILAR:  g++ -std=c++17 -Wall -Wextra -Wshadow -O2 -o visto visto.cpp
  DEBUG:     g++ -std=c++17 -Wall -Wextra -fsanitize=address,undefined -g visto.cpp -o visto

  INDICE:
    [0]  I/O basico e flags               demo_io()
    [1]  "\n" vs endl, sync/tie            (comentario em demo_io)
    [2]  getline vs cin>> e cin.ignore     demo_getline()
    [3]  if/else encadeado (faixas)        demo_ifelse()
    [4]  switch/case (break, fall-through) demo_switch()
    [5]  for tradicional vs for-range      demo_fors()
    [6]  blocos SEM chaves {} (pegadinha)  demo_sem_chaves()
    [7]  atribuicoes compostas (+=,/=,++)  demo_compostas()
    [8]  string como vetor de char         demo_string()
    [9]  char <-> int ('0','a')            demo_char_int()
    [10] extrair digitos (% e /)           demo_digitos()
    [11] array normal vs vector            demo_array_vs_vector()
    [12] array de contagem (frequencia)    demo_contagem()
    [13] pair (.first/.second)             demo_pair()
    [14] sort (ordenar) + "ordenar p/ simplificar"  demo_sort()
    [15] stack (pilha, LIFO)               demo_stack()
    [16] funcoes (parametros, retorno)     demo_funcoes / quadrado()
    [17] Big-O (nota teorica)              (comentario ao final)
=============================================================================
*/

#include <bits/stdc++.h>   // inclui tudo (iostream, vector, algorithm, stack...)
using namespace std;


// - Em I/O nao-interativo (entrada vem de arquivo, sem mensagens "Digite..."):
//   as 2 linhas abaixo aceleram MUITO a leitura/escrita:
//       ios_base::sync_with_stdio(false);
//       cin.tie(NULL);
//   ATENCAO: NAO usar cin.tie(NULL) em programa INTERATIVO (com "Digite:"),
//   senao as mensagens so aparecem no fim (o cout nao e mais descarregado
//   antes de cada leitura).
void demo_io(){
    int a, b;
    cin >> a >> b;                 // da para encadear varias leituras
    cout << "soma = " << a + b << "\n";
}

// ---------------------------------------------------------------------------
// [2] getline  vs  cin >>   e   cin.ignore
// ---------------------------------------------------------------------------
// - cin >> x   : para no 1o espaco em branco (le UMA palavra/numero).
// - getline(cin, s) : le a LINHA inteira (ate o '\n'), inclusive espacos.
// - PEGADINHA: ao misturar cin>> e depois getline, o '\n' que o cin>> deixou
//   no buffer faz o getline ler uma linha VAZIA. Solucao: cin.ignore(...)
//   para descartar esse '\n' antes do getline.
void demo_getline(){
    int n;
    cin >> n;                                          // le um numero
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpa o \n que sobrou
    string linha;
    getline(cin, linha);                               // agora le a linha toda
    cout << "n=" << n << " | linha=\"" << linha << "\"\n";
}

// ---------------------------------------------------------------------------
// [3] if / else if ENCADEADO (ideal para FAIXAS de valores)
// ---------------------------------------------------------------------------
// Use if/else para faixas, use switch para valores exatos.
void demo_ifelse(){
    int d; cin >> d;
    if      (d <= 2)  cout << "Fervendo\n";
    else if (d <= 5)  cout << "Quente\n";
    else if (d <= 10) cout << "Morno\n";
    else              cout << "Frio\n";
}

// ---------------------------------------------------------------------------
// [4] switch / case  (para comparar 1 variavel com VALORES FIXOS)
// ---------------------------------------------------------------------------
// - case usa dois-pontos ':' e NAO parenteses:  case 'C':
// - SEMPRE por 'break;' no fim de cada case, senao "vaza" para o proximo (fall-through). 
void demo_switch(){
    char naipe; cin >> naipe;
    switch (naipe) {
        case 'C': cout << "Copas\n";   break;
        case 'E': cout << "Espadas\n"; break;
        case 'U': cout << "Ouros\n";   break;
        case 'P': cout << "Paus\n";    break;
        default:  cout << "invalido\n"; break;
    }
}

// ---------------------------------------------------------------------------
// [5] FOR tradicional  vs  FOR-RANGE
// ---------------------------------------------------------------------------
// - for tradicional: use quando precisa do INDICE i (ex.: comparar v[i] com
//   v[i-1], andar de 2 em 2, ir de tras pra frente).
// - for-range  "for (tipo x : colecao)": visita CADA elemento sem indice.
//   Use quando so quer passar por todos os elementos.
void demo_fors(){
    vector<int> v = {10, 20, 30};

    // tradicional (tenho o indice i)
    for (int i = 0; i < (int)v.size(); i++)
        cout << "v[" << i << "] = " << v[i] << "\n";

    // for-range (nao preciso do indice)
    int soma = 0;
    for (int x : v)          // x recebe cada elemento de v
        soma += x;
    cout << "soma = " << soma << "\n";
}

// ---------------------------------------------------------------------------
// [6] BLOCOS SEM CHAVES {}  (regra + PEGADINHA)
// ---------------------------------------------------------------------------
// Um for/if/while/else SEM {} governa APENAS o proximo comando (1 linha).
// As chaves servem para agrupar VARIOS comandos. Pegadinha classica:
//     for (int i = 0; i < 3; i++)
//         cout << "A";     // <- SO isto esta no for
//         cout << "B";     // <- FORA do for! (roda 1 vez) -> imprime "AAAB"
// O -Wall avisa: "misleading indentation". RECOMENDACAO enquanto aprende:
// use {} sempre, mesmo com 1 comando. (Ler codigo sem {} tudo bem.)
void demo_sem_chaves(){
    // versao segura, com chaves:
    for (int i = 0; i < 3; i++) {
        cout << "A";
        cout << "B";        // dentro do for -> "ABABAB"
    }
    cout << "\n";
}

// ---------------------------------------------------------------------------
// [7] ATRIBUICOES COMPOSTAS  (+=, -=, *=, /=, ++)
// ---------------------------------------------------------------------------
// Abreviacoes: x /= 10  e  x = x / 10 ;  x *= 10 e  x = x * 10.
void demo_compostas(){
    int x = 100;
    x += 5;   // 105
    x -= 20;  // 85
    x *= 2;   // 170
    x /= 10;  // 17  (divisao INTEIRA: descarta a parte decimal)
    x++;      // 18
    cout << "x = " << x << "\n";
}

// ---------------------------------------------------------------------------
// [8] STRING como vetor de char
// ---------------------------------------------------------------------------
// - s[i] acessa o caractere na posicao i (0-based).
// - s.size() (ou s.length()) da o tamanho. CUIDADO: retorna tipo sem sinal;
//   ao comparar com int use (int)s.size() para nao gerar warning.
// - Ler string com cin >> s le UMA palavra (para no espaco).
void demo_string(){
    string s = "abc";
    cout << "s[0]=" << s[0] << " s[2]=" << s[2] << " tam=" << s.size() << "\n";
    for (int i = 0; i < (int)s.size(); i++)
        cout << s[i] << " ";
    cout << "\n";
}

// ---------------------------------------------------------------------------
// [9] CHAR <-> INT  (o truque '0' e 'a')
// ---------------------------------------------------------------------------
// Caracteres sao numeros na tabela ASCII, e os digitos '0'..'9' e as letras
// 'a'..'z' ficam em sequencia. Logo:
//   - digito:  c - '0'   converte '7' -> 7   ('0'->0 ... '9'->9)
//   - letra:   c - 'a'   converte 'c' -> 2   ('a'->0 ... 'z'->25)
// Muito usado para indexar array de contagem por caractere.
void demo_char_int(){
    char d = '7', L = 'c';
    cout << "'7'-'0' = " << (d - '0') << "\n";   // 7
    cout << "'c'-'a' = " << (L - 'a') << "\n";   // 2
    // montar numero de 2 digitos a partir de chars: dezena*10 + unidade
    char c1 = '1', c2 = '3';
    int valor = (c1 - '0') * 10 + (c2 - '0');    // 13
    cout << "valor = " << valor << "\n";
}

// ---------------------------------------------------------------------------
// [10] EXTRAIR DIGITOS de um numero  (operadores % e /)
// ---------------------------------------------------------------------------
// - x % 10  da o ULTIMO digito de x   (253 % 10 = 3).
// - x / 10  REMOVE o ultimo digito    (253 / 10 = 25, divisao inteira).
// Padrao classico (soma dos digitos), versao compacta com for:
//     for (int y = x; y > 0; y /= 10) soma += y % 10;
void demo_digitos(){
    int x; cin >> x;
    int soma = 0;
    for (int y = x; y > 0; y /= 10)   // varre os digitos de x
        soma += y % 10;               // acumula o ultimo digito
    cout << "soma dos digitos de " << x << " = " << soma << "\n";
}

// ---------------------------------------------------------------------------
// [11] ARRAY NORMAL  vs  VECTOR
// ---------------------------------------------------------------------------
// ARRAY normal (tipo nome[N]):
//   - tamanho FIXO, conhecido na hora de escrever o codigo.
//   - inicializar zerado com  = {}
//   - NAO sabe o proprio tamanho; nao cresce.
//   - Use quando o tamanho e fixo/conhecido (ex.: contagem[26], soma[101]).
//
// VECTOR (vector<tipo>):
//   - tamanho DINAMICO: pode ser definido em runtime ou crescer com push_back.
//   - sabe o tamanho: v.size()
//   - Use quando NAO sabe o tamanho antes, ou vai adicionando aos poucos.
//   - EVITAR "int arr[n];" com n variavel (VLA, nao e C++ padrao) -> use vector.
void demo_array_vs_vector(){
    // array fixo, zerado:
    int fixo[5] = {};                 // 5 posicoes, todas 0
    fixo[2] = 42;

    // vector com tamanho definido em runtime:
    int n; cin >> n;
    vector<int> v(n, 0);              // n posicoes, todas 0
    // vector que cresce dinamicamente:
    vector<int> cresce;
    for (int i = 0; i < 3; i++)
        cresce.push_back(i * 10);    // adiciona no fim: 0, 10, 20

    cout << "fixo[2]=" << fixo[2] << " | v.size()=" << v.size()
         << " | cresce.size()=" << cresce.size() << "\n";
}

// ---------------------------------------------------------------------------
// [12] ARRAY DE CONTAGEM (tabela de frequencia)
// ---------------------------------------------------------------------------
// Ideia: o INDICE representa "o que" e o VALOR guardado representa "quantas
// vezes aquilo apareceu". Substitui varios if/else. Sempre ZERAR (= {}).
// Ex.: contar quantas vezes cada letra minuscula aparece numa string.
void demo_contagem(){
    string s; cin >> s;
    int freq[26] = {};                 // 26 gavetas (uma por letra), zeradas
    for (char c : s)
        freq[c - 'a']++;               // usa a letra como indice
    for (int i = 0; i < 26; i++)
        if (freq[i] > 0)
            cout << char('a' + i) << ": " << freq[i] << "\n";
}

// ---------------------------------------------------------------------------
// [13] PAIR  (guardar DOIS valores juntos)
// ---------------------------------------------------------------------------
// pair<A,B> guarda dois valores: .first e .second. Otimo para intervalos
// (inicio, fim), coordenadas, etc. Criar com {a, b}.
void demo_pair(){
    pair<int,int> p = {10, 20};
    cout << "first=" << p.first << " second=" << p.second << "\n";

    vector<pair<int,int>> v;           // vector de pares
    v.push_back({3, 4});
    v.push_back({1, 2});
    for (auto& par : v)                // 'auto' descobre o tipo; '&' evita copia
        cout << "(" << par.first << "," << par.second << ") ";
    cout << "\n";
}

// ---------------------------------------------------------------------------
// [14] SORT  (ordenar) + tecnica "ORDENAR PARA SIMPLIFICAR"
// ---------------------------------------------------------------------------
// - sort(v.begin(), v.end())  ordena um vector em ordem crescente. O(N log N).
// - sort(a, a + n)            ordena um array normal.
// - pares/tuplas: ordena pelo .first, empata pelo .second (automatico).
// TECNICA: em muitos problemas, ORDENAR os dados primeiro deixa a solucao
// obvia. Ex.: para achar sobreposicao de intervalos, ordene por inicio e
// compare cada um com o VIZINHO (em vez de comparar todos com todos O(N^2)).
void demo_sort(){
    vector<int> v = {5, 2, 8, 1};
    sort(v.begin(), v.end());          // 1 2 5 8
    for (int x : v) cout << x << " ";
    cout << "\n";

    vector<pair<int,int>> iv = {{30,40},{10,20},{15,25}};
    sort(iv.begin(), iv.end());        // ordena por inicio
    // exemplo da tecnica: existe sobreposicao entre intervalos vizinhos?
    bool sobrepoe = false;
    for (int i = 1; i < (int)iv.size(); i++)
        if (iv[i].first <= iv[i-1].second)   // comeca antes do anterior acabar
            sobrepoe = true;
    cout << (sobrepoe ? "tem sobreposicao\n" : "sem sobreposicao\n");
}

// ---------------------------------------------------------------------------
// [15] STACK (pilha) — LIFO: ultimo a entrar, primeiro a sair
// ---------------------------------------------------------------------------
// Operacoes: push (empilha), top (le o topo), pop (remove o topo, NAO retorna),
// empty (vazia?), size. Otima para "desfazer o ultimo" (ex.: "0 cancela o
// ultimo numero"). CUIDADO: nunca top()/pop() com a pilha vazia (checar empty).
void demo_stack(){
    stack<int> p;
    p.push(10);
    p.push(20);
    p.push(30);                        // topo = 30
    cout << "topo=" << p.top() << " size=" << p.size() << "\n";
    while (!p.empty()) {               // esvazia removendo do topo
        cout << p.top() << " ";        // 30 20 10  (ordem inversa da insercao)
        p.pop();
    }
    cout << "\n";
}

// ---------------------------------------------------------------------------
// [16] FUNCOES  (parametros, retorno, variaveis locais)
// ---------------------------------------------------------------------------
// - Assinatura: tipo_de_retorno nome(parametros) { ... return valor; }
// - void = nao retorna nada.
// - Variaveis declaradas DENTRO da funcao nascem "novas" a cada chamada
//   (nao vazam entre chamadas) — util para resetar acumuladores.
// - Passar array: parametro "int v[]"; chamar passando so o nome (sem []).
int quadrado(int x){          // recebe int, devolve int
    return x * x;
}
long long somaVetor(int v[], int n){   // array como parametro + tamanho
    long long s = 0;
    for (int i = 0; i < n; i++)
        s += v[i];
    return s;
}
void demo_funcoes(){
    cout << "quadrado(5) = " << quadrado(5) << "\n";      // 25
    int a[4] = {1, 2, 3, 4};
    cout << "somaVetor = " << somaVetor(a, 4) << "\n";    // 10
}

/*
-----------------------------------------------------------------------------
 [17] BIG-O  (nota teorica — complexidade de TEMPO e MEMORIA)
-----------------------------------------------------------------------------
  Big-O descreve como o custo CRESCE com o tamanho da entrada (N).
   - O(1)       constante (nao depende de N)         ex.: acessar v[i]
   - O(log N)   logaritmico                          ex.: busca binaria
   - O(N)       linear (percorre a entrada 1 vez)    ex.: somar um vetor
   - O(N log N) ex.: sort
   - O(N^2)     dois lacos aninhados (cuidado com N grande -> TLE)

  DICAS:
   - "Ler a entrada" ja custa O(N): logo O(N) costuma ser o minimo em tempo.
   - Dois algoritmos podem ter o MESMO tempo e MEMORIA diferente.
   - Em competicao: primeiro faca PASSAR dentro dos limites; otimize so se
     precisar. Nao ha "bonus por codigo curto" — pontua acertar os casos.
   - Memoria: arrays pequenos de tipos primitivos raramente sao o gargalo;
     preocupe-se com estruturas GRANDES (matrizes, muitos elementos).
-----------------------------------------------------------------------------
*/

// ===========================================================================
// main() — descomente UMA demo por vez para experimentar, recompile e rode.
//   Ex.:  ./visto   e digite a entrada que aquela demo pede (veja o codigo).
// Algumas demos leem da entrada (cin); outras nao precisam de entrada.
// ===========================================================================
int main(){
    // --- demos que NAO leem entrada (pode rodar direto): ---
    // demo_sem_chaves();
    // demo_compostas();
    // demo_string();
    // demo_char_int();
    // demo_fors();
    // demo_pair();
    // demo_sort();
    // demo_stack();
    // demo_funcoes();

    // --- demos que LEEM entrada (digite o que o comentario da funcao pede): ---
    // demo_io();               // 2 numeros
    // demo_getline();          // 1 numero, depois 1 linha de texto
    // demo_ifelse();           // 1 numero
    // demo_switch();           // 1 char: C/E/U/P
    // demo_digitos();          // 1 numero
    // demo_array_vs_vector();  // 1 numero (tamanho do vector)
    // demo_contagem();         // 1 palavra (letras minusculas)

    cout << "visto.cpp — descomente uma demo no main() para experimentar.\n";
    return 0;
}
