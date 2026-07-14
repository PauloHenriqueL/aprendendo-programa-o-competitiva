# 💾 Memória dinâmica e Arquivos

| Arquivo | Conteúdo |
|---------|----------|
| `teoria_memoria_e_arquivos.cpp` | Teoria lado a lado: o jeito **C** (que ele viu antes) × o jeito **C++ idiomático**. Só para ler e rodar. |

Exercícios: `revisoes/2026-07-04_memoria_arquivos_M1-M5.cpp` (M1–M5, todos ✅).

## C++ idiomático (use ISTO)

| Em vez de… | Use |
|------------|-----|
| `malloc`/`free` (C) | **`vector`** |
| `new`/`delete` | **`vector`** |
| `FILE*`, `fopen` | **`ifstream`** / **`ofstream`** |

```cpp
vector<int> v(n);                              // 1D
vector<vector<int>> m(l, vector<int>(c));      // 2D

ofstream fout("res.txt");  fout << x;          // é o "cout de arquivo"
ifstream fin("dados.txt"); while (fin >> x) {} // é o "cin de arquivo"
if (!fin) { /* falhou ao abrir */ }
```

## Insight de competição
**Processar "em fluxo"** — ler e já somar, sem guardar tudo — usa **O(1)** de
memória em vez de O(N).

⚠️ **Overflow pegou 3x seguidas aqui:** soma acumulada precisa de `long long`.
