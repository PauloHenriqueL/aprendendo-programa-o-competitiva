# 🏆 SELETIVA — treino para a Seletiva Interna UFMG (07/08/2026)

Pasta criada em **2026-07-24**.

## O que ficou nesta pasta

| Arquivo | Conteúdo | Status |
|---------|----------|--------|
| `2026-07-24_unb2025_A-A2.cpp` | Problema A (Athleta Alemão) + A2 (Fornada) | A2 ✅ AC |

Os problemas **E, J e C** da Seletiva UnB 2025 chegaram a ser propostos mas
não foram resolvidos, e foram removidos ao encerrar. O caderno completo (14
problemas) está na fonte pública abaixo, caso queira retomar.

## Sobre o formato da Seletiva Interna UFMG (do site oficial)

| Item | Valor |
|------|-------|
| Duração | 5 horas · times de 3 · 1 computador |
| Problemas | 8 ou mais |
| Linguagens | C, C++ ou Java · sem internet |
| Material impresso | permitido |

A UFMG **não publica** os problemas das suas seletivas internas. Estes vieram
da **Seletiva UnB 2025**, prova real do mesmo formato (ICPC Brasil).

## Fontes públicas de provas reais (verificadas em 24/07/2026)

- **Seletiva UnB 2025** (caderno usado aqui):
  https://danielsaad.com/maratona/assets/seletiva-unb-2025/caderno-seletiva-unb-2025.pdf
- **Seletivas USP** (12 provas, 2010–2025): https://www.ime.usp.br/~maratona/seletivas.html
- **Seletiva Interna UDESC 2025**: https://codeforces.com/gym/105950
- **Maratona SBC subregional 2024-25**: https://codeforces.com/gym/105327

## O que foi trabalhado aqui

**A2 — Fornada de Pão de Queijo** (substituto do A, escrito por mim depois que
estraguei o A por um erro de transcrição do PDF). Treina:
- ler quantidade indeterminada de valores até EOF (`while(cin >> x)`)
- classificar em 3 faixas com borda estrita ("mais que 8%" — 8% exato ainda vale)
- **saída com texto exato** (foi onde os 2 WA aconteceram: primeiro strings
  cortadas, depois um ponto final faltando)
- contar durante o laço e resumir no fim ("acumula dentro, decide fora")

Resolvido em 2 rodadas, ambas de saída — a lógica saiu de primeira.
