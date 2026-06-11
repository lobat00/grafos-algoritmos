## Algoritmo de Árvore Geradora Mínima (Kruskal) — Lista de Arestas

## Descrição

Implementação em C do Algoritmo de Kruskal para encontrar a Árvore Geradora Mínima (Minimum Spanning Tree - MST) de um grafo ponderado. O projeto utiliza uma abordagem baseada em vetor dinâmico de arestas ordenadas por peso e emprega a estrutura de dados eficiente **Union-Find** (com compressão de caminho e união por rank) para detecção de ciclos em tempo quase linear.

## Objetivo

- Demonstrar a aplicação prática de algoritmos gananciosos (*greedy*) na otimização de redes conectadas.
- Evidenciar o uso de estruturas de conjuntos disjuntos (Union-Find) para controle de conectividade.
- Fornecer código estruturado para experimentação acadêmica e estudo de estruturas de dados avançadas.

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
- Ambiente compatível com execução de binários gerados (Linux / Windows / WSL)

## Compilação

Para compilar o programa, execute no terminal:

``` bash
gcc main.c kruskal.c -o programa_kruskal
./programa_kruskal