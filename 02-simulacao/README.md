# 🎬 Simulação — OBI 2021, Fase 1, Nível Sênior (prova completa)

Os 4 problemas da prova, todos resolvidos e validados.

| Arquivo | Problema | Conceito principal |
|---------|----------|--------------------|
| `obi2021_zero_para_cancelar.cpp` | Zero para cancelar | **pilha** (`stack`) |
| `obi2021_torneio_tenis.cpp` | Torneio de tênis | `if/else` encadeado, `switch` |
| `obi2021_baralho.cpp` | Baralho | **array de contagem**, função, parsing |
| `obi2021_tempo_de_resposta.cpp` | Tempo de resposta | **simulação** com estado (relógio, "gap" de tempo) |

## O que é "simulação"
Manter um **estado** que evolui passo a passo, exatamente como o enunciado
descreve. Não há truque — há **fidelidade ao enunciado**.

## Cuidados
- Se a estrutura **encolhe/cresce**, usar `v.size()` **ATUAL**, não o `n` fixo
  (senão: loop infinito).
- Avançar de 2 em 2 é `i += 2`, **não** `i + 2` (o `-Wall` avisa: *"statement
  has no effect"*).
