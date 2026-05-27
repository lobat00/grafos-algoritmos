#ifndef DFS_H
#define DFS_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct No {
	int vertice;
	struct No* prox;
} No;

typedef struct {
	No* inicio;
} ListaAdj;

/* Protótipos */
No* criarNo(int vertice);
void adicionarAresta(ListaAdj grafo[], int origem, int destino, int direcionado);
void mostrarGrafo(ListaAdj grafo[], int numVertices);
void dfs(ListaAdj grafo[], int numVertices, int origem);
void dfsUtil(ListaAdj grafo[], int atual, int visitado[]);

/* Libera memória alocada para o grafo */
void liberarGrafo(ListaAdj grafo[], int numVertices);

/* Função para limpar a tela e exibir o cabeçalho */
void limparTela();

#endif /* DFS_H */

