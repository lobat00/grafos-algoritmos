# Algoritmo de Árvore Geradora Mínima (Prim) — Matriz de Adjacência

## Descrição

Implementação em C do **Algoritmo de Prim** para encontrar a **Árvore Geradora Mínima (AGM)** de um grafo não direcionado e ponderado. O projeto utiliza uma **matriz de adjacência** para representar o grafo e executa o algoritmo a partir de um vértice inicial escolhido pelo usuário, exibindo todas as arestas que compõem a AGM e o peso total.

## Objetivo

- Demonstrar a implementação prática do algoritmo de Prim com foco em grafos não direcionados e ponderados.
- Utilizar a representação por matriz de adjacência para armazenar e consultar as arestas do grafo.
- Fornecer código de referência para aprendizado, análise de complexidade e experimentação acadêmica.

## Autores

- Audrey Regison dos Santos Cardoso
- Francisco Ferreira Brito Neto
- Thiago Lobato Rodrigues

## Instituição

Universidade Federal do Amapá - UNIFAP  
Curso de Ciência da Computação  
Professor: Dr. Júlio Cezar Costa Furtado

## Estrutura do Projeto

```
.
├── main.c      # Ponto de entrada, leitura de dados e exemplo de uso
├── prim.c      # Implementação do algoritmo de Prim
├── prim.h      # Definições, estruturas e protótipos
└── README.md
```

## Requisitos

- Compilador GCC (ex.: `gcc`)
- Ambiente compatível com execução de binários gerados (Linux / Windows / WSL)

## Compilação

Para compilar o programa, execute no terminal:

```
gcc main.c prim.c -o programa_prim
```

## Execução

```
./programa_prim
```

## Exemplo de Uso

Grafo com 5 vértices e as seguintes arestas:

```
     0   1   2   3   4
0  [ 0   2   0   6   0 ]
1  [ 2   0   3   8   5 ]
2  [ 0   3   0   0   7 ]
3  [ 6   8   0   0   9 ]
4  [ 0   5   7   9   0 ]
```

Entrada no terminal:

```
Digite o numero de vertices: 5

Digite a matriz de adjacencia 5x5
  [0][0]: 0
  [0][1]: 2
  ...

Digite o vertice inicial (0 a 4): 0
```

Saída esperada:

```
+------------------------------------------+
|      ARVORE GERADORA MINIMA (Prim)       |
+------------------------------------------+
| Aresta       Direcao       Peso          |
+------------------------------------------+
|    0 -- 1    ( 0 <->  1)   Peso:   2    |
|    1 -- 2    ( 1 <->  2)   Peso:   3    |
|    0 -- 3    ( 0 <->  3)   Peso:   6    |
|    1 -- 4    ( 1 <->  4)   Peso:   5    |
+------------------------------------------+
|  Peso total da MST: 16                   |
+------------------------------------------+
```