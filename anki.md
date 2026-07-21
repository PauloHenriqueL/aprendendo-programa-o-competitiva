# Flashcards — Programação Competitiva

Formato: pergunta na primeira linha terminando em ponto e vírgula, resposta na segunda linha terminando em ponto.

Qual o passo da busca binária quando o meio é grande demais;
hi igual a meio menos 1, nunca hi menos menos.

Por que hi menos menos quebra a busca binária;
Porque descarta apenas um elemento em vez de metade, virando busca linear O(N) disfarçada, o que dá TLE.

Qual a condição do while da busca binária em faixa fechada;
lo menor ou igual a hi, porque uma faixa de um elemento só, quando lo é igual a hi, ainda é candidata.

Como calcular o meio na busca binária sem estourar;
meio igual a lo mais a diferença hi menos lo dividido por dois.

Qual sentinela usar para dizer que a busca binária não achou nada;
Menos um, porque zero é um índice válido e não daria para distinguir achei na posição zero de não achei.

Na busca binária, o que fazer ao encontrar o alvo se eu quero a PRIMEIRA ocorrência com valores repetidos;
Guardar a posição e continuar procurando para a esquerda com hi igual a meio menos um, sem dar break.

Quando é correto dar break ao achar o alvo na busca binária;
Só quando não há repetições ou quando qualquer ocorrência serve.

O que é lower_bound;
O primeiro elemento maior ou igual a X, ou seja, o primeiro que alcança ou passa X.

Na busca por primeiro valor maior ou igual a X, ao ter v de meio maior ou igual a X, o que faço;
Guardo esse candidato e vou para a esquerda, porque o próprio meio ainda pode ser a resposta.

O que é busca binária na resposta;
Buscar binário no valor da resposta em vez de num vetor, quando a propriedade é monotônica, por exemplo quanto maior o corte menos pedaços saem.

Na janela deslizante, quando eu encolho a janela;
Quando ela ESTOUROU, ou seja, quando a condição foi violada.

Por que a janela deslizante é O(N) mesmo tendo dois laços aninhados;
Porque o ponteiro da esquerda nunca retrocede, então o while interno roda no máximo N vezes somadas em toda a execução.

Por que a janela deslizante funciona no problema dos livros;
Porque os valores são positivos, o que torna a soma monotônica ao crescer a janela. Não é por causa de ordenação.

O que acontece se eu inverter o sinal do while da janela deslizante;
O ponteiro da esquerda passa do direito e estoura o vetor, causando crash.

Na janela deslizante de MENOR trecho com soma maior ou igual a T, onde eu meço o tamanho;
Dentro do while, enquanto a janela ainda é válida, antes de encolher.

Quantos ponteiros eu movo por iteração em dois ponteiros nas pontas;
Apenas UM, dentro do if ou do else, nunca os dois no mesmo passo.

Como inicializar dois ponteiros nas pontas;
esq igual a zero, dir igual a n menos um, e o laço é while esq menor que dir.

O que significa contar em bloco em dois ponteiros;
Somar dir menos esq de uma vez, porque se um par vale então todos os pares daquele elemento com os do intervalo também valem.

Que tipo usar no contador de pares em dois ponteiros;
long long, porque o número de pares chega perto de n ao quadrado dividido por dois, cerca de cinco bilhões.

Qual a relação entre guloso e dois ponteiros;
São a mesma ideia. O guloso DECIDE qual é a escolha forçada e os dois ponteiros EXECUTAM essa decisão em O(N).

O que é o algoritmo guloso;
Ordenar e varrer uma vez, escolhendo o melhor local e nunca voltando atrás.

O guloso é sempre ótimo;
Não. Com moedas de um, três e quatro, para dar sete, o guloso dá quatro mais um mais um mais um, quatro moedas, quando o ótimo é três mais quatro, duas moedas.

Qual o custo do guloso com ordenação;
O de N log N, dominado pelo sort.

O que é activity selection;
O guloso clássico de escolher o máximo de atividades sem sobreposição, ordenando por horário de FIM.

Quando posso parar cedo num guloso de comprar itens ordenados;
Quando o item atual já não cabe, porque os seguintes são ainda mais caros. Usa-se else break.

A pergunta certa sobre overflow não é onde eu guardo, qual é;
Onde a CONTA explode.

Onde colocar o cast para long long numa multiplicação;
Num OPERANDO, por exemplo abre parêntese long long fecha parêntese a vezes b. Nunca no resultado, porque aí a conta já estourou.

Qual a melhor forma de resolver overflow na origem;
Declarar o próprio contêiner como vector de long long, assim não precisa de cast nenhum.

Quando devo usar long long por reflexo;
Sempre que os limites do enunciado chegarem perto de um bilhão, já no cin e no vector, sem analisar caso a caso.

O overflow dá erro de execução;
Não, ele é SILENCIOSO. Compila, roda e devolve número errado.

O que significa um warning do compilador;
É um teste falhando. Se compilou com warning, o exercício não terminou.

Compilação limpa garante que o código está certo;
Não, é o PISO e não a garantia. O menos Wall não pega cout faltando, por exemplo.

Quais flags usar para compilar em competitiva;
g mais mais, menos std igual a c mais mais dezessete, menos Wall, menos Wextra, menos Wshadow, menos O2.

Quais flags usar para debugar um crash;
menos fsanitize igual a address e undefined, mais o menos g.

Como testar meu programa sem digitar a entrada;
Com printf da entrada, barra vertical, e o executável. Digitar mistura o eco do terminal com a saída do programa.

O que é ÍNDICE versus VALOR;
Índice é a POSIÇÃO e valor é o CONTEÚDO. Antes de escrever uma comparação, dizer em voz alta se aquilo é posição ou valor.

Como declarar uma matriz 2D em C mais mais;
vector de vector de long long, com nome abre parêntese l, vector de long long abre parêntese c vírgula zero.

Como ler a declaração da matriz 2D;
Da direita para a esquerda. O vector de dentro é UMA linha e o de fora faz l cópias dela.

O que devolve ponto size de uma matriz;
O número de LINHAS. Para colunas usa-se colchete zero ponto size.

Qual a ordem dos índices numa matriz;
Primeiro linha, depois coluna.

Qual o erro de escrever vector com dois parâmetros de tipo;
O segundo parâmetro do vector é o ALOCADOR, não o tipo interno. O tipo interno vai aninhado.

O que são os vetores dl e dc;
Dois vetores de quatro posições com os deslocamentos dos quatro vizinhos, casados pelo índice k, sendo dl a variação da linha e dc a variação da coluna.

Quais os valores de dl e dc para os quatro vizinhos ortogonais;
dl igual a menos um, um, zero, zero, e dc igual a zero, zero, menos um, um.

Qual a diferença entre dl de k e ni;
dl de k é o DESLOCAMENTO, o quanto anda. ni é a POSIÇÃO, o onde chega. Só a posição pode indexar a matriz.

Como testar se um vizinho existe numa grade;
ni maior ou igual a zero e ni menor que l e nj maior ou igual a zero e nj menor que c. O teste ABRAÇA o acesso.

Um vizinho que não existe conta contra a célula;
Não, ele é simplesmente ignorado. Por isso uma matriz um por um, sem nenhum vizinho, é um pico local.

Onde perguntar se uma flag sobreviveu a TODOS os testes;
DEPOIS que o laço fecha, nunca dentro dele, senão a pergunta é feita antes de todos votarem.

Como usar uma flag booleana para verificar uma propriedade universal;
Começar com verdadeira antes do laço, derrubar para falsa se algum caso desmentir, e conferir depois do laço.

Por que usar menor ou igual ao derrubar a flag de pico local;
Porque estritamente maior falha também no EMPATE, não só quando o vizinho é maior.

O que é prefix sum;
Um vetor onde a posição i guarda a soma dos i primeiros elementos, ou seja, tudo que vem ANTES da posição i.

Qual o tamanho do vetor de prefix sum e o valor inicial;
Tem n mais um posições e a posição zero vale zero.

Como consultar a soma de L até R com prefix sum;
pre de R mais um menos pre de L, em tempo constante.

Por que o prefix sum usa R mais um;
Porque resolve o intervalo inclusivo de graça, incluindo o próprio elemento R.

Qual o tipo do vetor de prefix sum;
vector de long long, sempre.

Qual a complexidade de responder Q consultas com prefix sum;
O de N mais Q, em vez de O de N vezes Q da versão ingênua.

O que é uma queue;
Uma fila FIFO, o primeiro que entra é o primeiro que sai. É a base do BFS.

Quais as operações da queue;
push para inserir, front para olhar, pop para remover e empty para testar se está vazia.

Qual a diferença entre front e pop;
front OLHA e pop REMOVE. São separados, então int x igual a fila ponto pop não compila.

Quando posso chamar front ou pop numa fila;
Só quando a fila não está vazia, mesma regra da pilha.

O que é uma stack;
Uma pilha LIFO, o último que entra é o primeiro que sai. Serve para casamento de parênteses.

Para que serve o vetor de visitados;
Para saber em tempo constante se já passei por uma célula. É o que impede o algoritmo de girar em círculos para sempre.

O que acontece num BFS sem vetor de visitados;
Ele NÃO TERMINA, fica em loop infinito.

Devo varrer o vetor de flags no final para imprimir os resultados;
Não. É lento e ainda dá a ordem errada, crescente em vez de ordem de aparição. Imprimir na hora resolve os dois problemas.

Por que o guloso quebra num labirinto;
Porque ele escolhe um caminho e se enfia num beco sem saber voltar.

Qual a pergunta certa em problemas de grade;
Não é por onde eu vou, é quais células eu ALCANÇO. Não se escolhe um caminho, se espalha por todos.

Quais as quatro peças que formam um BFS em grade;
A matriz que é o labirinto, os quatro vizinhos que dizem para onde posso andar, a fila que guarda as células a visitar e o vetor de visitados que impede o loop infinito.

O que é recursão;
Uma função que chama a si mesma, com um caso base que para e um caso recursivo que reduz o problema.

O que precisa ser verdade sobre o caso base;
Ele precisa ser ALCANÇÁVEL, senão a recursão é infinita e estoura a pilha.

Qual a diferença entre imprimir antes e depois da chamada recursiva;
Antes imprime na descida e depois imprime na volta, o que inverte a ordem.

Por que o fibonacci recursivo ingênuo é lento;
Porque é exponencial, dois elevado a n, já que recalcula os mesmos valores. É a semente da programação dinâmica.

Como funciona o backtracking de subconjuntos;
Para cada elemento há duas chamadas, uma incluindo e outra não incluindo, formando uma árvore binária de decisões.

Qual a diferença entre uma recursão que DECIDE e uma que CONTA;
A que decide combina os ramos com ou lógico e a que conta SOMA os ramos.

O que é o algoritmo de Euclides;
O máximo divisor comum, em que mdc de a e b é igual a mdc de b e o resto de a por b.

Quando usar map e quando usar vector de pair;
Map quando preciso buscar por chave e vector de pair quando preciso ORDENAR a lista de itens.

Como o sort ordena um vector de pair;
Pelo primeiro campo e, em caso de empate, pelo segundo.

Como ordenar em ordem decrescente;
Com o truque do sinal, guardando o valor negativo, que só funciona para números, ou com um comparador lambda, que funciona para qualquer tipo.

O que é structured binding;
A sintaxe for de auto e colchetes com dois nomes, que separa o par em duas variáveis com nome.

Por que não misturar push_back com vector de tamanho n;
Porque são exclusivos. Declarar com tamanho n já cria n posições e o push_back adiciona depois delas.

O que acontece com vector vazio recebendo cin no colchete i;
Crash, porque a posição não existe. É preciso declarar com o tamanho.

Para que serve o for de intervalo;
Para percorrer a coleção inteira dando o VALOR de cada elemento, não o índice.

O for de intervalo pode ser aninhado com um for de índice;
Não, porque a técnica JÁ é o laço. Aninhar faz o trabalho ser repetido n vezes.

Posso modificar a variável do for de intervalo declarada por referência;
Não, porque isso altera o próprio contêiner sem querer.

Qual a pergunta que salva antes de aplicar uma técnica conhecida;
O que este problema me PROÍBE de fazer. Por exemplo, ler em sequência proíbe usar sort.

Por que ter repertório é perigoso;
Porque o padrão dispara antes de a leitura do enunciado terminar, e aí resolve-se outro problema.

O que é o erro de menor versus menor ou igual;
Errar a borda inclusiva. Se um item custa exatamente o dinheiro que sobra, dá para comprar, então é menor ou igual.

Por que usar aspas barra n em vez de endl;
Porque o endl força um flush do buffer, o que é lento em competitiva.

O switch aceita string;
Não, só tipos inteiros e char. Para string usa-se if e else if.

Qual a armadilha de acessar uma string na posição do próprio tamanho;
Ela devolve o caractere nulo e NÃO crasha, nem o sanitizer acusa. É um erro silencioso, diferente do vector que crasha.

O que faz uma variável não inicializada;
Guarda lixo de memória, valor imprevisível. O menos Wall costuma avisar.

Como escrever um swap de três linhas corretamente;
temp recebe a, a recebe b, b recebe temp. A variável temporária PRECISA aparecer do lado direito.

Como comparar três valores em cadeia em C mais mais;
Não existe a menor que b menor que c. É preciso escrever a menor que b e lógico b menor que c.

Como avançar de dois em dois num laço;
i mais igual a dois. Escrever i mais dois não tem efeito e o menos Wall avisa.

Qual a diferença entre igual e mais igual;
Igual ATRIBUI, substituindo o valor, e mais igual ACUMULA, somando ao que já havia. O menos Wall não pega essa troca.

Ao percorrer uma coleção que encolhe, qual tamanho usar no laço;
O tamanho ATUAL da coleção, chamando ponto size a cada volta, e não o n original, senão o laço nunca termina ou estoura.

Como inicializar uma variável de máximo;
Com o primeiro elemento da coleção, ou com INT_MIN, nunca com zero, porque todos os valores podem ser negativos.

Quando devo inicializar com o primeiro elemento em vez de sentinela;
Quando o problema garante que SEMPRE existe resposta. E aí é preciso inicializar também a POSIÇÃO correspondente.

Como manter valor e posição sincronizados ao buscar um máximo;
Atualizar os dois dentro do MESMO if, sem condição extra separando um do outro.

Como achar a primeira ocorrência de um máximo numa varredura;
Usando menor estrito na comparação, porque assim o empate não dispara a atualização.

Como converter um caractere de dígito para número;
Subtraindo o caractere zero dele.

Como extrair os dígitos de um número;
Com resto por dez para pegar o último dígito e divisão por dez para descartá-lo, repetindo enquanto o número for maior que zero.

Como testar se um número é par;
Verificando se o resto da divisão por dois é zero.

O que acontece num for ou if sem chaves;
Só o PRIMEIRO comando obedece ao laço ou à condição. O segundo executa sempre.

Qual a diferença entre igual e igual igual;
Um igual ATRIBUI e dois iguais COMPARAM. Usar um igual dentro de um if é um bug clássico que o menos Wall avisa.

O que é um array de contagem;
Um vetor em que o próprio VALOR é usado como ÍNDICE para contar ocorrências. É o map dos pobres quando as chaves são pequenas.

Quando usar ifstream e ofstream;
ifstream é o cin de arquivo, para ler, e ofstream é o cout de arquivo, para escrever.

Como ler um arquivo até o fim;
Com while do fin recebendo a variável, que para sozinho quando a leitura falha.

O que significa processar em fluxo;
Ler e já processar sem guardar tudo, o que usa memória constante em vez de memória proporcional a N.

Qual o C mais mais idiomático para memória e arquivos;
Vector em vez de new e de malloc, e fstream em vez de FILE ponteiro.

Qual a régua para considerar um conceito aprendido;
Acertar de PRIMEIRA, sem dica e sem rodada de correção, em três sessões seguidas. Chegar no AC depois de três correções é resolvido, não aprendido.

# ACHE O BUG — cards com código

Formato igual: a pergunta mostra o código errado e termina em ponto e vírgula, a resposta mostra a correção e termina em ponto.

Onde está o erro: meio = hi + (hi + lo) / 2;
meio = lo + (hi - lo) / 2. Parte-se do lo e anda METADE da distância até o hi. A versão errada aponta para fora da faixa.

Onde está o erro: while (lo < hi) { meio = lo + (hi - lo) / 2; ... };
while (lo <= hi). A faixa é FECHADA, e uma faixa de um elemento só, quando lo é igual a hi, ainda é candidata. Com menor estrito ela nunca é testada.

Onde está o erro: if (v[meio] > x) hi--; else lo++;
if (v[meio] > x) hi = meio - 1; else lo = meio + 1. Com hi-- descarta-se um elemento em vez de metade, virando O(N) e dando TLE.

Onde está o erro: int resposta = 0; ... if (v[meio] == x) resposta = meio;;
int resposta = -1. O zero é um índice VÁLIDO, então não dá para distinguir achei na posição zero de não achei. O sentinela precisa ser impossível.

Onde está o erro: if (v[meio] == x) { resposta = meio; break; } quando o vetor tem repetidos e quero a primeira ocorrência;
if (v[meio] == x) { resposta = meio; hi = meio - 1; }. Sem break, guarda-se o candidato e continua para a ESQUERDA procurando uma ocorrência anterior.

Onde está o erro: if (meio < alvo) lo = meio + 1;
if (v[meio] < alvo). O meio é uma POSIÇÃO e o alvo é um VALOR. Só se compara valor com valor.

Onde está o erro: while (soma < t) { soma -= v[esq]; esq++; } numa janela que não pode passar de T;
while (soma > t). Encolhe-se quando ESTOUROU. Com o sinal invertido o esq passa do direito e estoura o vetor.

Onde está o erro: for (int i = 0; i < n; i++) { soma += v[i]; while (soma >= t) { soma -= v[esq]; esq++; } melhor = min(melhor, i - esq + 1); } no menor trecho com soma maior ou igual a T;
A medição precisa ficar DENTRO do while, antes de encolher, porque só ali a janela ainda é válida. Fora dele a janela já deixou de alcançar T.

Onde está o erro: long long melhor = 0; ... melhor = min(melhor, tamanho);
long long melhor = n + 1. Começando em zero o min nunca sobe e a resposta é sempre zero. O valor inicial precisa ser IMPOSSÍVEL, maior que qualquer tamanho real.

Onde está o erro: if (soma >= x) { cont += dir - esq; dir--; } dir--;
O segundo dir-- sobra. Move-se UM ponteiro por iteração, dentro do if ou do else, nunca os dois no mesmo passo, senão pulam-se pares.

Onde está o erro: int cont = 0; while (esq < dir) { ... cont += dir - esq; };
long long cont. O número de pares chega perto de n ao quadrado sobre dois, cerca de cinco bilhões, o que estoura o int silenciosamente.

Onde está o erro: for (int i = 0; i < n; i++) { esq = 0; dir = n - 1; while (esq < dir) { ... } };
O for externo sobra. A TÉCNICA já é o laço. Aninhar faz contar tudo n vezes.

Onde está o erro: long long produto = (long long)(a * b);
long long produto = (long long)a * b. O cast precisa tocar um OPERANDO. Envolvendo a conta inteira ela já estourou dentro do parêntese antes da conversão.

Onde está o erro: vector<int> pre(n + 1); ... pre[i + 1] = pre[i] + v[i];
vector<long long> pre. A soma acumulada estoura ao ENCHER o vetor, antes de qualquer consulta. Resolve-se na ORIGEM, no tipo do contêiner.

Onde está o erro: int soma = v[esq] + v[dir]; com valores até um bilhão;
long long soma, ou melhor, declarar o próprio vector como vector de long long. A conta explode na soma, não no destino.

Onde está o erro: cout << soma(l, r) << endl; dentro de um laço de cem mil consultas;
cout com aspas barra n. O endl força um flush do buffer a cada linha, o que é lento o bastante para causar TLE.

Onde está o erro: pre[r] - pre[l] para somar de L até R inclusive;
pre[r + 1] - pre[l]. O mais um inclui o próprio elemento R, resolvendo o intervalo inclusivo de graça.

Onde está o erro: if (produto < dinheiro) { comprar(); } quando um item que custa exatamente o que sobra pode ser comprado;
if (produto <= dinheiro). Borda INCLUSIVA. Com dez reais e um item de dez reais, dá para comprar.

Onde está o erro: soma = pre[i]; dentro de um laço que deveria acumular;
soma += pre[i]. Um igual ATRIBUI e substitui o valor, mais igual ACUMULA. O menos Wall não pega essa troca.

Onde está o erro: if (a < b < c) picos++;
if (a < b && b < c). Comparação encadeada não existe em C mais mais. A expressão vira um booleano comparado com c, o que quase sempre é verdadeiro. O menos Wall avisa.

Onde está o erro: for (int i = 0; i < n; i + 2) processar(v[i]);
i += 2. Escrever i mais dois não muda o i, o laço fica infinito, e o menos Wall diz que a expressão não tem efeito.

Onde está o erro: for (int i = 0; i < n; i++) if (v[i] > maior) maior = v[i]; posicao = i;
Faltam as chaves. Sem elas só o primeiro comando obedece ao if, então a posicao é atualizada SEMPRE e se descola do valor.

Onde está o erro: if (v[i] > maior) { maior = v[i]; } if (v[i] >= maior) { posicao = i; };
Valor e POSIÇÃO precisam ser atualizados dentro do MESMO if, sem condição extra separando um do outro, senão eles se descolam.

Onde está o erro: int maior = 0; para achar o máximo de um vetor que pode ter negativos;
int maior = v[0], ou INT_MIN. Começando em zero, um vetor todo negativo devolve zero, que nem está no vetor.

Onde está o erro: int temp = v[i]; v[i] = v[f]; v[f] = v[i];
A última linha deve ser v[f] = temp. A variável temporária PRECISA aparecer do lado direito, senão as duas posições ficam com o mesmo valor. O menos Wall avisa que temp não é usada.

Onde está o erro: vector<int> v; for (int i = 0; i < n; i++) cin >> v[i];
vector<int> v(n). Um vector vazio não tem posições, então o acesso crasha. Declarar com o tamanho ou usar push_back, que são exclusivos entre si.

Onde está o erro: vector<int> lista(v.size()); for (auto x : v) lista.push_back(x);
Declarar com tamanho e usar push_back são EXCLUSIVOS. Ou se declara vazio e usa push_back, ou se declara com tamanho e atribui por índice.

Onde está o erro: for (auto& [l, r] : v) { l++; };
Não se modifica a variável do for de intervalo declarada por referência, porque isso altera o próprio contêiner sem querer.

Onde está o erro: for (int i = 0; i < n; i++) { for (auto& p : m) { ... } };
O for de intervalo JÁ é o laço completo. Aninhá-lo num for de índice repete o trabalho n vezes.

Onde está o erro: vector<vector<long, long>> m(l, vector<long long>(c));
vector<vector<long long>>. O segundo parâmetro do vector é o ALOCADOR, não o tipo interno. E os tipos de fora e de dentro precisam CASAR.

Onde está o erro: int linha, coluna; if (i - 1 >= 0) soma += m[linha - 1][coluna];
Usar i e j, que são a posição atual. As variáveis linha e coluna nunca receberam valor, então guardam lixo e o acesso crasha.

Onde está o erro: for (int k = 0; k < 4; k++) { if (existe) soma += m[dl[k]][dc[k]]; };
soma += m[ni][nj], com ni igual a i mais dl[k] e nj igual a j mais dc[k]. O dl[k] é o DESLOCAMENTO, o quanto anda. Só a POSIÇÃO pode indexar a matriz.

Onde está o erro: for (int k = 0; k < 4; k++) { int ni = i + dl[k]; soma += m[ni][nj]; if (ni >= 0 && ni < l) ... };
O teste de existência precisa ABRAÇAR o acesso, vindo ANTES dele. Checar o limite depois de já ter acessado não impede o crash.

Onde está o erro: for (int k = 0; k < 4; k++) { if (m[i][j] <= m[ni][nj]) ehpico = false; if (ehpico) picos++; };
O if (ehpico) picos++ vai DEPOIS que o laço k fecha. Dentro dele a pergunta é feita quatro vezes por célula, antes de todos os vizinhos votarem.

Onde está o erro: if (m[i][j] < m[ni][nj]) ehpico = false; quando o pico precisa ser estritamente maior;
if (m[i][j] <= m[ni][nj]). Estritamente maior falha também no EMPATE, não só quando o vizinho é maior.

Onde está o erro: while (fila.size() > 0) { int x = fila.pop(); };
int x = fila.front(); fila.pop();. O front OLHA e o pop REMOVE, são separados, e o pop não devolve valor.

Onde está o erro: int x = fila.front(); fila.pop(); sem nenhuma verificação;
Verificar antes com se a fila não está vazia. Chamar front ou pop numa fila vazia é comportamento indefinido.

Onde está o erro: for (int i = 0; i < 1000001; i++) if (visto[i]) cout << i << " "; para imprimir na ordem em que apareceram;
Imprimir NA HORA, dentro do laço de leitura, na primeira vez que o elemento aparece. Varrer as flags é lento e ainda entrega a ordem crescente em vez da ordem de aparição.

Onde está o erro: switch (comando) { case "ENTRA": ... } com comando sendo uma string;
Trocar por if e else if. O switch só aceita tipos inteiros e char, nunca string.

Onde está o erro: int cont; for (...) cont++;
int cont = 0. Uma variável não inicializada guarda lixo de memória e o resultado é imprevisível. O menos Wall avisa.

Onde está o erro: if (x = 5) { ... };
if (x == 5). Um igual ATRIBUI e dois iguais COMPARAM. O menos Wall avisa dessa troca.

Onde está o erro: while (v.size() > 1) { for (int i = 0; i < n; i += 2) ... } com n fixo numa fila que encolhe;
Usar v.size() atual em vez do n original. Com o n fixo o laço acessa posições que já foram removidas.

Onde está o erro: sort(v.begin(), v.end()); num problema que diz que os livros são lidos em sequência, sem pular;
O sort não pode ser usado. Ele embaralha a ordem e passa a resolver OUTRO problema. Antes de aplicar uma técnica, perguntar o que o enunciado me PROÍBE.

Onde está o erro: contarSubconjuntos devolve if (soma == alvo) return 1; com os ramos combinados por ou lógico;
Os ramos precisam ser SOMADOS, semEle mais comEle. Recursão que DECIDE combina com ou lógico, recursão que CONTA soma os ramos.

Onde está o erro: int potencia(int b, int e) { if (e == 1) return b; return b * potencia(b, e - 1); };
O caso base precisa ser e igual a zero devolvendo um. Com o caso base em um, a chamada com expoente zero nunca para e estoura a pilha.

Onde está o erro: um programa que calcula tudo certo mas o menos Wall não reclama e a saída fica vazia;
Falta o cout. A compilação limpa é o PISO e não a garantia, porque o menos Wall não pega saída faltando quando a variável é usada em outro lugar.

Onde está o erro: long long lo = 0, hi = n; while (lo <= hi) { meio = lo + (hi - lo) / 2; if (v[meio] ... };
hi = n - 1. O último índice válido é n menos um, então começar o hi em n faz a primeira comparação acessar uma posição inexistente.

Onde está o erro: while (lo <= hi) { meio = lo + (hi - lo) / 2; if (v[meio] < x) lo = meio; else hi = meio - 1; };
lo = meio + 1. Atribuir o próprio meio ao lo não encolhe a faixa quando lo e hi são vizinhos, e o laço nunca termina.

Onde está o erro: numa busca binária na resposta, if (pedacos >= k) hi = meio - 1; else lo = meio + 1; quando quero o MAIOR corte possível;
As direções estão trocadas. Se o corte ainda dá pedaços suficientes, ele é candidato e quero um MAIOR, então guarda-se a resposta e faz-se lo = meio + 1.

Onde está o erro: numa busca binária na resposta, long long lo = 0;
lo = 1. Um corte de tamanho zero é impossível, e a divisão por ele causa erro de execução.

Onde está o erro: for (int i = 0; i < n; i++) pedacos += v[i] / meio; com pedacos declarado como int;
long long pedacos. Com cem mil tábuas de um bilhão cada, a soma de pedaços passa muito do limite do int e estoura silenciosamente.

Onde está o erro: int esq = 0; for (int dir = 0; dir < n; dir++) { soma += v[dir]; if (soma > t) { soma -= v[esq]; esq++; } };
O if precisa ser um while. Um único elemento novo pode exigir várias remoções pela esquerda até a janela voltar a ser válida.

Onde está o erro: while (soma > t) { esq++; soma -= v[esq]; };
As duas linhas estão trocadas. Descontar depois de avançar remove o elemento errado e deixa o antigo esq dentro da soma para sempre.

Onde está o erro: while (esq <= dir) { soma = v[esq] + v[dir]; ... } em dois ponteiros nas pontas;
while (esq < dir). Com menor ou igual o elemento se emparelha consigo mesmo quando os ponteiros se encontram, criando um par que não existe.

Onde está o erro: if (soma >= x) { cont++; dir--; } quando conto todos os pares com soma maior ou igual a X;
cont += dir - esq. Se o par das pontas serve, então TODOS os pares do dir com os elementos entre esq e dir também servem. Contar de um em um vira O(N ao quadrado).

Onde está o erro: sort(v.begin(), v.end()); e em seguida dois ponteiros nas pontas num problema que pede pares de ÍNDICES i menor que j;
O sort destrói os índices originais. Se a resposta depende da posição, é preciso guardar o par de valor e índice antes de ordenar.

Onde está o erro: sort(inicio.begin(), inicio.end()); sort(fim.begin(), fim.end()); com as atividades em dois vetores separados;
Usar um vector de pair e ordenar uma vez só. Ordenar campos separados descola os dados da MESMA entidade e mistura o início de uma atividade com o fim de outra.

Onde está o erro: sort(v.begin(), v.end()); num activity selection, ordenando pelo horário de início;
Ordenar pelo horário de FIM. O guloso do activity selection escolhe sempre a atividade que termina mais cedo, para sobrar o máximo de tempo.

Onde está o erro: for (auto& preco : catalogo) { if (preco <= m) { m -= preco; cont++; } } sem nada antes;
Falta o sort. O guloso só funciona com os preços em ordem crescente, senão gasta-se o dinheiro num item caro e perdem-se vários baratos.

Onde está o erro: cout << pico << endl; no fim de uma função que declarou int pico e nunca somou nada;
Falta o pico++ dentro do laço. O menos Wall não avisa, porque a variável é usada no cout.

Onde está o erro: bool ehpico = true; declarado antes dos dois laços que varrem a matriz;
A flag precisa ser reiniciada DENTRO do laço, uma vez por célula. Declarada fora, a primeira célula que falhar derruba a flag para todas as seguintes.

Onde está o erro: int dl[4] = {-1, 1, 0, 0}; int dc[4] = {-1, 1, 0, 0};
dc[4] = {0, 0, -1, 1}. Os dois vetores são casados pelo índice k, e com valores iguais os deslocamentos apontam para as diagonais em vez dos quatro vizinhos ortogonais.

Onde está o erro: if (ni >= 0 && ni <= l && nj >= 0 && nj <= c) acessar m[ni][nj];
ni < l e nj < c. O último índice válido é l menos um, então o menor ou igual deixa passar uma posição inexistente.

Onde está o erro: if (ni >= 0 && ni < c && nj >= 0 && nj < l);
As dimensões estão trocadas. O ni é uma LINHA e se compara com l, o nj é uma COLUNA e se compara com c. Só se nota quando a matriz não é quadrada.

Onde está o erro: for (int i = 0; i < c; i++) for (int j = 0; j < l; j++) cin >> m[i][j];
Os limites estão trocados. O laço externo percorre as LINHAS e vai até l, o interno percorre as colunas e vai até c.

Onde está o erro: vector<vector<int>> m(c, vector<int>(l));
m(l, vector<int>(c)). Lê-se da direita para a esquerda: o vector de dentro é UMA linha e tem c colunas, e o de fora faz l cópias dela.

Onde está o erro: num BFS, marcar visto[ni][nj] = true apenas quando a célula sai da fila;
Marcar no momento em que ela ENTRA na fila. Marcando na saída, a mesma célula é empilhada várias vezes antes de ser processada e a fila explode.

Onde está o erro: num BFS, fila.push(vizinho) sem consultar o vetor de visitados;
Só empilhar se a célula ainda não foi vista. Sem essa checagem o algoritmo volta por onde veio e NÃO TERMINA.

Onde está o erro: num BFS em grade de mil por mil, vector<bool> visto(1000);
O visitados precisa ter uma posição por CÉLULA, não por linha. São um milhão de células, e o correto é uma matriz de booleanos com as mesmas dimensões da grade.

Onde está o erro: num labirinto, escolher a cada passo o vizinho que mais se aproxima do alvo;
Isso é busca gulosa e QUEBRA em labirinto, porque se enfia num beco e não sabe voltar. Em grade não se escolhe um caminho, se ESPALHA por todos.

Onde está o erro: stack<int> p; while (i < s.size()) { if (s[i] == ')') p.pop(); ... } sem mais nada;
Falta verificar se a pilha não está vazia antes do pop. Uma string que começa com fecha parênteses causa comportamento indefinido.

Onde está o erro: if (c == "a") quando c é declarado como char;
if (c == 'a'). Aspas simples são char e aspas duplas são string. Comparar char com string nem compila.

Onde está o erro: for (char letra : palavra) contagem[letra]++; com contagem sendo um vetor de vinte e seis posições;
contagem[letra - 'a']++. O char precisa ser convertido em índice de zero a vinte e cinco, senão o valor da tabela é usado como posição e estoura o vetor.

Onde está o erro: int n = s.size(); for (int i = 0; i <= n; i++) cout << s[i];
i < n. Com menor ou igual acessa-se a posição do tamanho, que devolve o caractere nulo e NÃO crasha, sendo um erro silencioso que nem o sanitizer acusa.

Onde está o erro: for (int i = 0; i < n; i++) if (v[i] == v[i + 1]) iguais++;
i < n - 1, ou melhor, i + 1 < n. Comparando com o vizinho da direita, a última posição não tem com quem comparar e o acesso sai do vetor.

Onde está o erro: for (int i = 0; i < n; i++) if (v[i - 1] < v[i] && v[i] > v[i + 1]) picos++;
O laço precisa ir de um até n menos dois. As pontas não têm os dois vizinhos, então o acesso sai do vetor nas duas extremidades.

Onde está o erro: cin >> n; getline(cin, nome);
Falta um cin.ignore entre os dois. O cin deixa o enter no buffer e o getline lê uma linha vazia imediatamente.

Onde está o erro: while (fin >> x) soma += x; sem nada antes;
Falta verificar se o arquivo abriu, testando se o fin falhou logo após a abertura. Se o arquivo não existe, o laço simplesmente não roda e o resultado é zero silencioso.

Onde está o erro: for (int i = 1; i <= n; i++) cin >> v[i]; com v declarado como vector de tamanho n;
Os índices vão de zero a n menos um. Começar em um estoura a última posição e ainda deixa a posição zero com lixo.

Onde está o erro: int soma = 0; for (int i = 0; i < 100000; i++) soma += 100000;
long long soma. Cem mil vezes cem mil é dez bilhões, muito acima do limite do int, que é cerca de dois bilhões. O estouro é silencioso.

Onde está o erro: double media = soma / n; com soma e n inteiros;
Converter um dos operandos para double antes da divisão. Entre dois inteiros a divisão é INTEIRA e a parte fracionária é descartada antes da atribuição.

Onde está o erro: if (a / b == 2) quando quero saber se a é o dobro de b;
if (a == 2 * b). A divisão inteira arredonda para baixo, então cinco dividido por dois também dá dois e a condição aceita valores errados.

Onde está o erro: mdc(int a, int b) { if (b == 0) return a; return mdc(a, a % b); };
return mdc(b, a % b). O primeiro argumento vira o b anterior, senão o valor de b nunca muda e a recursão não termina.

Onde está o erro: int fib(int n) { if (n == 0) return 0; return fib(n - 1) + fib(n - 2); };
Falta o segundo caso base, com n igual a um devolvendo um. Sem ele a chamada com n igual a um desce para n igual a menos um e a recursão não termina.

Onde está o erro: void contar(int n) { cout << n; if (n = 0) return; contar(n - 1); };
if (n == 0). Um igual ATRIBUI, então a condição vira falsa para qualquer n diferente de zero e verdadeira zerando o n, quebrando a parada.

Onde está o erro: map<string, int> m; for (auto& p : m) if (p.second > maior) vencedor = p.first; sem atualizar o maior;
Falta a linha maior = p.second dentro do mesmo if. Sem ela o vencedor é sobrescrito por qualquer valor acima do maior inicial e o resultado é o último, não o máximo.

Onde está o erro: sort(v.begin(), v.end(), [](int a, int b) { return a < b; }); quando eu quero ordem DECRESCENTE;
return a > b. O comparador responde se o primeiro vem ANTES do segundo, então para descer a resposta é o maior primeiro.

Onde está o erro: cin >> n; while (t--) { resolver(); } num problema com múltiplos casos de teste;
Falta ler o t antes, com cin recebendo t. Usar o n no lugar do número de casos faz o laço rodar a quantidade errada de vezes.

Onde está o erro: chamar o juiz com o código escrito mas sem ter rodado o compilador;
Compilar sempre antes com todas as flags de aviso e rodar os exemplos do enunciado. Warning é teste falhando, e pedir verificação sem compilar desperdiça uma rodada.
