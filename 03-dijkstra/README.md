## Algoritmo de Caminho Mínimo (Dijkstra) — Lista de Adjacências

## Descrição

Implementação em C do Algoritmo de Dijkstra para encontrar caminhos mínimos a partir de uma origem única (Single-Source Shortest Path). O projeto utiliza uma estrutura de lista de adjacência para representar grafos de forma eficiente e suporta tanto grafos dirigidos quanto não dirigidos.

## Objetivo

- Demonstrar a implementação prática do algoritmo de Dijkstra com foco em grafos ponderados.
- Tratar as nuances estruturais entre representações de arestas direcionadas e bidirecionais.
- Fornecer código de referência para aprendizado, análise de limitações (como pesos negativos) e experimentação acadêmica.

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

```bash
gcc main.c dijkstra.c -o programa_dijkstra