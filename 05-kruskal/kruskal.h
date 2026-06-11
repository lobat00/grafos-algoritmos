#ifndef KRUSKAL_H
#define KRUSKAL_H

// Estrutura para representar uma aresta individual
typedef struct Edge {
    int src;
    int dest;
    int weight;
} Edge;

// Estrutura para o Grafo (Apenas Não Dirigido)
typedef struct Graph {
    int numVertices;
    int numArestas;
    Edge* edges;    // Array de arestas
    int edgeCount;  // Contador de arestas inseridas
} Graph;

// Estruturas para o Union-Find
typedef struct Subset {
    int parent;
    int rank;
} Subset;

// Protótipos das funções
Graph* createGraph(int vertices, int arestas);
void addEdge(Graph* graph, int src, int dest, int weight);
void runKruskal(Graph* graph);
void freeGraph(Graph* graph);

#endif