/*
============================================================================
  DESAFIO — "Apuracao da Votacao"  (estilo olimpiada/maratona)
  Tema novo: MAP (dicionario / tabela associativa)
============================================================================

CONTEXTO
--------
Uma eleicao para representante de turma foi feita por escrito: cada aluno
escreveu o NOME do candidato em quem votou. Voce recebeu todos os votos e
precisa apurar o resultado.

O vencedor e o candidato com MAIS votos. Em caso de EMPATE no numero de
votos, vence quem vier PRIMEIRO em ordem alfabetica.

ENTRADA
-------
A primeira linha contem um inteiro N: a quantidade de votos.
As N linhas seguintes contem, cada uma, o nome de um candidato (uma unica
palavra, sem espacos, apenas letras).

SAIDA
-----
Duas informacoes, em duas linhas:
  - Linha 1: a lista de TODOS os candidatos que receberam ao menos 1 voto,
    em ORDEM ALFABETICA, um por linha, no formato:  nome numero_de_votos
    (Obs: para caber em "duas informacoes", imprima cada candidato numa
     linha propria — veja o exemplo.)
  - Ultima linha: a palavra "VENCEDOR:" seguida do nome do vencedor.

Formato exato da saida (veja exemplo):
    <nome1> <votos1>
    <nome2> <votos2>
    ...
    VENCEDOR: <nome_do_vencedor>

RESTRICOES
----------
  - 1 <= N <= 100000
  - cada nome tem de 1 a 20 letras minusculas
  - pode haver muitos candidatos diferentes

EXEMPLO
-------
Entrada:
6
ana
bruno
ana
carla
bruno
ana
Saida:
ana 3
bruno 2
carla 1
VENCEDOR: ana

  (ana=3, bruno=2, carla=1 -> vencedor ana; a lista sai em ordem alfabetica)

Outro exemplo (empate):
Entrada:
4
zeca
ana
zeca
ana
Saida:
ana 2
zeca 2
VENCEDOR: ana

  (empate 2 a 2 -> vence "ana", que vem antes alfabeticamente)

============================================================================
  DICA DE CONCEITO NOVO: por que MAP e nao array de contagem?
  ----------------------------------------------------------------------
  O array de contagem (freq[26], soma[101]) so serve para indices numericos
  pequenos. Aqui a "chave" e um NOME (string). Nao da para fazer freq["ana"].
  O MAP resolve isso: associa uma CHAVE qualquer (string) a um VALOR (int).

  Veja o arquivo visto.cpp para os padroes ja conhecidos (contagem, sort...).
  O map sera explicado na conversa — este comentario e so um lembrete.
============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  map<string, int> freq;
  string nome, vencedor;
  int n, maior = 0;
  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> nome;
    freq[nome]++;
  }
  for(auto& par : freq){
    cout << par.first << " " << par.second << endl;
    if(par.second > maior){
      vencedor = par.first;
      maior = par.second;
    }
  }
  cout << "VENCEDOR: " << vencedor << endl;

  return 0;
}
