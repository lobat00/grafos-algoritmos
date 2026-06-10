#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#define INF 999999 // Representação de infinito para distâncias iniciais

// Estrutura para um nó da lista de adjacência (aresta)
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// Estrutura para a lista de adjacência de cada vértice
typedef struct Graph {
    int numVertices;
    int isDirected; // 1 para dirigido, 0 para não dirigido
    Node** adjLists;
} Graph;

// Protótipos das funções
Graph* createGraph(int vertices, int isDirected);
void addEdge(Graph* graph, int src, int dest, int weight);
void runDijkstra(Graph* graph, int startVertex);
void freeGraph(Graph* graph);

#endif