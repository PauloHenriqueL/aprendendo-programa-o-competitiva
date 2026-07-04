/*
============================================================================
  TEORIA — ALOCACAO DE MEMORIA e ARQUIVOS  (o que voce viu em C, agora em C++)
============================================================================
  Este arquivo e SO PARA LER. Ele mostra, lado a lado, o jeito C (que voce ja
  viu) e o jeito C++ (que voce vai usar). Compile e rode se quiser ver
  funcionando:  g++ -std=c++17 -Wall -Wextra -Wshadow -O2 teoria_memoria_arquivos.cpp -o teoria && ./teoria
============================================================================


  ==========================================================================
  PARTE 1 — ALOCACAO DE MEMORIA
  ==========================================================================

  O QUE E "ALOCAR MEMORIA"?
  -------------------------
  Quando voce escreve  int v[100];  o tamanho e FIXO e decidido na hora de
  compilar. Mas e se voce so descobre o tamanho durante a execucao (ex.: o
  usuario digita N e voce precisa de um vetor de N posicoes)? Ai voce precisa
  ALOCAR memoria "na hora". Essa memoria vem de uma area chamada HEAP.

  Existem 3 jeitos. Do "pior para competicao" ao "melhor":

  --------------------------------------------------------------------------
  (1) JEITO C — malloc / free   (EVITE em C++)
  --------------------------------------------------------------------------
      #include <cstdlib>
      int* a = (int*) malloc(n * sizeof(int));  // aloca espaco para n ints
      if (a == NULL) { ... }   // malloc devolve NULL se falhar
      ... usa a[0]..a[n-1] ...
      free(a);                 // VOCE tem que liberar. Esqueceu = VAZAMENTO.

    Problemas do malloc em C++:
      - Nao "sabe" o tipo: voce escreve n * sizeof(int) na mao (erro facil).
      - Nao chama construtor (irrelevante para int, mas quebra objetos).
      - Se esquecer o free, a memoria vaza. Se der free 2x, crash.
      - Precisa do cast (int*) e do #include <cstdlib>.

  --------------------------------------------------------------------------
  (2) JEITO C++ "cru" — new / delete   (raro em competicao)
  --------------------------------------------------------------------------
      int* b = new int[n];     // aloca n ints (sabe o tipo, sem sizeof)
      ... usa b[0]..b[n-1] ...
      delete[] b;              // libera. Note o [] porque e ARRAY.
                               // (para 1 objeto so: new int; ... delete b;)

    Melhor que malloc (sabe o tipo, chama construtor), mas voce AINDA precisa
    lembrar do delete[]. Se esquecer, vaza igual.

  --------------------------------------------------------------------------
  (3) JEITO C++ RECOMENDADO — vector   (use SEMPRE isto)
  --------------------------------------------------------------------------
      #include <vector>
      vector<int> v(n);        // aloca n ints (inicializados com 0)
      ... usa v[0]..v[n-1] ...
      // PRONTO. Nao precisa liberar nada: o vector se limpa SOZINHO quando
      // sai de escopo. Zero vazamento, zero free/delete.

    Por que e o melhor:
      - Libera a memoria automaticamente (RAII) -> impossivel esquecer.
      - Sabe o proprio tamanho: v.size().
      - Pode crescer: v.push_back(x); v.resize(m);
      - E o que TODO mundo usa em competicao. malloc/new quase nunca aparecem.

    REGRA PRATICA PARA COMPETICAO:
      - Tamanho conhecido e pequeno/fixo?  ->  array normal:  int v[100005];
      - Tamanho so descoberto em runtime?   ->  vector<int> v(n);
      - malloc/new?  ->  praticamente NUNCA. Esqueca que existem.


  ==========================================================================
  PARTE 2 — ARQUIVOS (ler/escrever de um arquivo, nao do teclado)
  ==========================================================================

  POR QUE ARQUIVOS?
  -----------------
  Ate agora voce leu com cin (do teclado/entrada padrao) e escreveu com cout
  (na tela/saida padrao). As vezes o problema pede ler de um ARQUIVO
  (ex.: "entrada.txt") e escrever em outro ("saida.txt"). A boa noticia:
  em C++ isso e QUASE IGUAL a cin/cout.

  --------------------------------------------------------------------------
  JEITO C — FILE* / fopen / fscanf / fprintf / fclose   (EVITE)
  --------------------------------------------------------------------------
      #include <cstdio>
      FILE* f = fopen("dados.txt", "r");   // "r"=ler, "w"=escrever, "a"=anexar
      if (f == NULL) { ... }               // NULL se o arquivo nao abriu
      int x;
      fscanf(f, "%d", &x);                 // como scanf, mas do arquivo
      fprintf(f, "%d\n", x);               // como printf, mas no arquivo
      fclose(f);                           // FECHE sempre.

    Mesmos problemas do printf/scanf: formato "%d" na mao, & nos enderecos,
    e o compilador ate reclama se voce ignora o retorno do fscanf.

  --------------------------------------------------------------------------
  JEITO C++ — ifstream / ofstream   (use isto: e o cin/cout de arquivo)
  --------------------------------------------------------------------------
      #include <fstream>

      // ESCREVER: ofstream ("output file stream") funciona como cout
      ofstream fout("saida.txt");   // abre (cria/sobrescreve) para escrita
      fout << 42 << " " << "ola" << "\n";   // usa <<  IGUAL ao cout
      fout.close();                          // fecha (opcional: fecha no fim)

      // LER: ifstream ("input file stream") funciona como cin
      ifstream fin("entrada.txt");  // abre para leitura
      if (!fin) { ... }             // '!fin' e true se nao abriu
      int a, b;
      fin >> a >> b;                // usa >>  IGUAL ao cin
      string s;  fin >> s;          // le uma palavra
      getline(fin, s);              // le uma linha inteira (igual cin)
      fin.close();

    Ler ate o fim do arquivo (nao sabe quantos numeros tem):
      int x;
      while (fin >> x) {            // para sozinho quando o arquivo acaba
          // processa x
      }

    RESUMO: troque cin -> ifstream e cout -> ofstream. Todo o resto (>>, <<,
    getline, while(fin>>x)) e IGUAL ao que voce ja sabe. Por isso o jeito C++
    e melhor: voce nao aprende nada novo, so troca a "fonte" da stream.

  NOTA de competicao: a maioria dos juizes online (OBI, Codeforces...) usa
  entrada/saida PADRAO (cin/cout), nao arquivos. Arquivos aparecem em provas
  locais, geracao de casos de teste, e alguns problemas especificos. Mesmo
  assim, saber fstream e util e trivial (e so cin/cout com outro nome).

============================================================================
  A seguir, o mesmo codigo dos comentarios acima, RODANDO de verdade.
  Leia, rode, e brinque a vontade.
============================================================================
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;

    // ---------- MEMORIA: os 3 jeitos, mesmo resultado ----------
    int* a = (int*) malloc(n * sizeof(int));     // (1) malloc
    for (int i = 0; i < n; i++) a[i] = i * 10;
    cout << "malloc: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
    free(a);

    int* b = new int[n];                          // (2) new
    for (int i = 0; i < n; i++) b[i] = i * 10;
    cout << "new:    ";
    for (int i = 0; i < n; i++) cout << b[i] << " ";
    cout << "\n";
    delete[] b;

    vector<int> v(n);                             // (3) vector (RECOMENDADO)
    for (int i = 0; i < n; i++) v[i] = i * 10;
    cout << "vector: ";
    for (int x : v) cout << x << " ";
    cout << "\n";
    // sem free/delete: o vector se limpa sozinho.

    // ---------- ARQUIVOS: escrever e ler de volta (jeito C++) ----------
    ofstream fout("demo.txt");                    // como cout, mas no arquivo
    fout << 7 << " " << 8 << " " << 9 << "\n";
    fout.close();

    ifstream fin("demo.txt");                     // como cin, mas do arquivo
    int soma = 0, x;
    while (fin >> x) soma += x;                    // le ate o fim
    fin.close();
    cout << "li de demo.txt e somei: " << soma << " (esperado 24)\n";

    return 0;
}
