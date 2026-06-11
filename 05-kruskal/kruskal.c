#include <stdio.h>
#include <stdlib.h>
#include "kruskal.h"

// Inicializa o grafo alocando memória para o array de arestas
Graph* createGraph(int vertices, int arestas) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->numArestas = arestas;
    graph->edgeCount = 0;
    
    graph->edges = malloc(arestas * sizeof(Edge));
    return graph;
}

// Adiciona uma aresta ao array global de arestas do grafo
void addEdge(Graph* graph, int src, int dest, int weight) {
    if (graph->edgeCount < graph->numArestas) {
        graph->edges[graph->edgeCount].src = src;
        graph->edges[graph->edgeCount].dest = dest;
        graph->edges[graph->edgeCount].weight = weight;
        graph->edgeCount++;
    }
}

// Função auxiliar do Union-Find: Encontra o representante do conjunto
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent); // Compressão de caminho
    }
    return subsets[i].parent;
}

// Função auxiliar do Union-Find: Une dois conjuntos baseando-se no Rank
void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Função de comparação para o qsort (ordena as arestas por peso crescente)
int compareEdges(const void* a, const void* b) {
    Edge* aEdge = (Edge*)a;
    Edge* bEdge = (Edge*)b;
    return aEdge->weight - bEdge->weight;
}

// Algoritmo de Kruskal
void runKruskal(Graph* graph) {
    int V = graph->numVertices;
    Edge result[V]; 
    int e = 0;      
    int i = 0;      

    // Passo 1: Ordenar todas as arestas pelo peso
    qsort(graph->edges, graph->edgeCount, sizeof(Edge), compareEdges);

    // Aloca memória para criar V subconjuntos do Union-Find
    Subset* subsets = malloc(V * sizeof(Subset));
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // O número de arestas na MST será igual a V-1
    while (e < V - 1 && i < graph->edgeCount) {
        Edge nextEdge = graph->edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // Se não causar ciclo, inclui no resultado
        if (x != y) {
            result[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    // Exibe a MST construída
    printf("\n--- Resultado do Algoritmo de Kruskal (Arvore Geradora Minima) ---\n");
    printf("Aresta \tPeso\n");
    int custoMinimo = 0;
    for (i = 0; i < e; ++i) {
        printf("%d -- %d \t%d\n", result[i].src, result[i].dest, result[i].weight);
        custoMinimo += result[i].weight;
    }
    printf("Custo Total da MST: %d\n", custoMinimo);

    free(subsets);
}

// Libera a memória do grafo
void freeGraph(Graph* graph) {
    free(graph->edges);
    free(graph);
}