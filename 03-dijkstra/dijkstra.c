#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"

// Cria um novo nó na lista de adjacência
Node* createNode(int v, int weight) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Inicializa o grafo
Graph* createGraph(int vertices, int isDirected) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->isDirected = isDirected;

    graph->adjLists = malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Adiciona aresta (respeitando se é dirigido ou não)
void addEdge(Graph* graph, int src, int dest, int weight) {
    // Adiciona aresta de src para dest
    Node* newNode = createNode(dest, weight);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Se NÃO for dirigido, adiciona a volta de dest para src
    if (!graph->isDirected) {
        newNode = createNode(src, weight);
        newNode->next = graph->adjLists[dest];
        graph->adjLists[dest] = newNode;
    }
}

// Algoritmo de Dijkstra
void runDijkstra(Graph* graph, int startVertex) {
    int numV = graph->numVertices;
    int dist[numV];
    int visited[numV];

    // Inicializa distâncias como INF e visitados como 0 (falso)
    for (int i = 0; i < numV; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    // A distância do vértice inicial para ele mesmo é 0
    dist[startVertex] = 0;

    for (int count = 0; count < numV - 1; count++) {
        // Encontra o vértice com a menor distância do conjunto de não visitados
        int min = INF;
        int u = -1;

        for (int v = 0; v < numV; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                u = v;
            }
        }

        // Se u continuar -1, os vértices restantes são inacessíveis
        if (u == -1) break;

        visited[u] = 1;

        // Atualiza as distâncias dos vértices adjacentes ao vértice escolhido (u)
        Node* temp = graph->adjLists[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (!visited[v] && dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
            temp = temp->next;
        }
    }

    // Exibe o resultado das menores distâncias
    printf("\n--- Resultado do Algoritmo de Dijkstra (Origem: %d) ---\n", startVertex);
    printf("Vertice\tDistancia Minima da Origem\n");
    for (int i = 0; i < numV; i++) {
        if (dist[i] == INF) {
            printf("%d \t INF\n", i);
        } else {
            printf("%d \t %d\n", i);
        }
    }
}

// Libera a memória alocada para o grafo
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);
}