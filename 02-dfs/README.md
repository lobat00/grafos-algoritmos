## Algoritmo de Busca em Profundidade (DFS) — Lista de Adjacências

## Descrição

Implementação em C do Algoritmo de Busca em Profundidade (Depth-First Search - DFS)
utilizando lista de adjacência para representar grafos. O programa realiza a
travessia em profundidade a partir de um vértice de origem e demonstra a ordem de visita dos vértices.

## Objetivo

- Demonstrar a implementação prática do algoritmo DFS com listas de adjacência.
- Fornecer código de referência para aprendizado e experimentação em grafos.

## Autores

- Audrey Regison dos Santos Cardoso
- Francisco Ferreira Brito Neto
- Thiago Lobato Rodrigues

## Instituição

Universidade Federal do Amapá - UNIFAP
Curso de Ciência da Computação
Professor: Dr. Júlio Cezar Costa Furtado

## Requisitos

- Compilador GCC (ex.: `gcc`)
- Ambiente compatível com execução de binários gerados (Windows / Linux / WSL)

## Compilação

Para compilar o programa, execute:

```bash
gcc main.c dfs.c -o dfs.exe
```

ou (gerando um executável sem sufixo em sistemas Unix-like):

```bash
gcc main.c dfs.c -o dfs
```

## Execução

```bash
./dfs.exe
```

> Observação: em ambiente Windows nativo, use `dfs.exe` ou `./dfs.exe` conforme o
> terminal utilizado.

## Estrutura do repositório

- [main.c](main.c) — ponto de entrada e exemplos de uso
- [dfs.c](dfs.c) — implementação do algoritmo DFS
- [dfs.h](dfs.h) — definições e protótipos
- [README.md](README.md) — este arquivo

## Uso

1. Compile conforme instruções acima.
2. Execute o binário e siga as instruções exibidas para inserir o grafo.
	O programa solicita: número de vértices, número de arestas, tipo do grafo (0 não direcionado, 1 direcionado), lista de arestas (origem destino) e vértice inicial.

## Licença

Conteúdo fornecido para fins educacionais. Sinta-se livre para usar e adaptar
o código citando os autores.

