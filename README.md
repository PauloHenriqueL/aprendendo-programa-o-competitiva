# 🏆 Programação Competitiva — Jornada de Estudos

Repositório de estudos de **programação competitiva** em C++ (OBI, maratonas,
ICPC), partindo do zero.

> Estudante: **Paulo** (UFMG). Método: **eu resolvo sozinho**; o Claude é
> **juiz** (compila, roda casos de borda, aponta o erro — nunca entrega a
> solução). Foco em entender o **"porquê"**, não decorar.

📋 **Plano atual:** [`PLANO_DE_ESTUDO.md`](PLANO_DE_ESTUDO.md) ·
🤖 **Regras de trabalho:** [`CLAUDE.md`](CLAUDE.md)

---

## 🎯 Meta de julho/2026

> *"Se eu sair de julho sabendo bem tudo que vimos até aqui, principalmente
> **busca binária, guloso e grafos 1**, vou me sentir realizado."*

| Semana | Foco |
|--------|------|
| 14/07 – 20/07 | **Revisitar tudo** que já vimos (zero conceito novo) |
| 21/07 – 27/07 | **Grafos parte 1** (BFS/DFS) — o único conceito novo do mês |
| 28/07 – 31/07 | **Grafos mais forte** + revisão geral |

---

## 📂 Organização

Cada pasta é **um conceito**. O nome do arquivo diz **o que ele é**:
`teoria_*` (material de leitura) · `obi2021_*`, `CF*` (problemas reais).

### Trilha de conceitos
| Pasta | Conceito | Status |
|-------|----------|--------|
| [`00-referencia/`](00-referencia/) | 📖 **Caderno de referência** — todos os conceitos, um `demo_*()` cada. **Consulte quando esquecer a sintaxe.** | — |
| [`02-simulacao/`](02-simulacao/) | 🎬 Simulação — prova completa da **OBI 2021** (4/4 ✅) | ✅ |
| [`03-estruturas/`](03-estruturas/) | 🗺️ Estruturas: `map` · (a ver: `set`, `stack`, `queue`, `pair`, matriz) | 🔁 |
| [`04-ordenacao-busca/`](04-ordenacao-busca/) | 🔍 **Busca binária** · `sort` · `lower_bound` | 🎯 **meta** |
| [`05-recursao-backtracking/`](05-recursao-backtracking/) | 🔁 Recursão · backtracking (incluir/não-incluir) | ✅ |
| [`06-memoria-arquivos/`](06-memoria-arquivos/) | 💾 `vector` · matriz 2D · `ifstream`/`ofstream` | ✅ |
| [`07-guloso/`](07-guloso/) | 🤑 **Guloso** — ordenar + varrer, nunca voltar atrás | 🎯 **meta** |
| [`08-dois-ponteiros/`](08-dois-ponteiros/) | 👉👈 Dois ponteiros · **janela deslizante** · CF 279B (900) ✅ | 🔁 |
| [`09-bits-PAUSADO/`](09-bits-PAUSADO/) | ⏸️ Bits — **pausado** por decisão do aluno | ⏸️ |
| [`10-grafos/`](10-grafos/) | 🕸️ **Grafos: BFS/DFS** — Semana 4 | 🎯 **meta** |

### Apoio
| Pasta | Conteúdo |
|-------|----------|
| [`revisoes/`](revisoes/) | 🔥 Sessões de **repetição espaçada**. Um arquivo por dia: `AAAA-MM-DD_conceito_FAIXA.cpp` |
| [`codeforces/`](codeforces/) | Problemas **reais** do Codeforces (nome traz o ID e o rating) |
| [`contests/`](contests/) | Upsolving de contests (ex.: Seleção UDESC 2026-1) |

---

## 🏅 Marcos

- **CF 279B "Books" — rating 900** ✅ AC (2026-07-13). Janela deslizante,
  validado contra força bruta (500 casos, 0 falhas), 25ms com N=10⁵.
- **OBI 2021 Fase 1 Sênior** — prova completa, 4/4.
- **Seleção UDESC 2026-1** — 4/5 no upsolving.

---

## ⚙️ Como compilar

```bash
g++ -std=c++17 -Wall -Wextra -Wshadow -O2 arquivo.cpp -o a && ./a
```

Para caçar acesso fora do vetor e overflow:
```bash
g++ -std=c++17 -Wall -Wextra -Wshadow -fsanitize=address,undefined -g arquivo.cpp -o a
```

⚠️ **Warning = teste falhando.** Mas **compilação limpa é o PISO, não a
garantia** — o `-Wall` não pega um `cout` faltando. **Rode os exemplos.**
