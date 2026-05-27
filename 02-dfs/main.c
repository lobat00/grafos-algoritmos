#include <stdio.h>
#include <stdlib.h>
#include "dfs.h"

int main() {
	ListaAdj grafo[MAX_VERTICES];

	int numVertices;
	int numArestas;

	int origem, destino;

	int verticeInicial;

	int direcionado;

	limparTela();

	for (int i = 0; i < MAX_VERTICES; i++) {
		grafo[i].inicio = NULL;
	}

	printf("Quantidade de vertices: ");
	if (scanf("%d", &numVertices) != 1) return 1;

	if (numVertices < 1 || numVertices > MAX_VERTICES) {
		fprintf(stderr, "Numero de vertices invalido (1-%d)\n", MAX_VERTICES);
		return 1;
	}

	printf("Quantidade de arestas: ");
	if (scanf("%d", &numArestas) != 1) return 1;

	printf("\nTipo do grafo:\n");
	printf("0 - Nao direcionado\n");
	printf("1 - Direcionado\n");

	if (scanf("%d", &direcionado) != 1) return 1;

	printf("\nDigite as arestas (origem destino):\n");

	for (int i = 0; i < numArestas; i++) {
		if (scanf("%d %d", &origem, &destino) != 2) return 1;
		if (origem < 0 || origem >= numVertices || destino < 0 || destino >= numVertices) {
			fprintf(stderr, "Aresta invalida: %d %d\n", origem, destino);
			return 1;
		}

		adicionarAresta(grafo, origem, destino, direcionado);
	}

	mostrarGrafo(grafo, numVertices);

	printf("\nVertice inicial da DFS: ");
	if (scanf("%d", &verticeInicial) != 1) return 1;

	if (verticeInicial < 0 || verticeInicial >= numVertices) {
		fprintf(stderr, "Vertice inicial invalido\n");
		return 1;
	}

	dfs(grafo, numVertices, verticeInicial);

	/* Liberar memória alocada pelo grafo */
	liberarGrafo(grafo, numVertices);

#if defined(_WIN32) || defined(_WIN64)
	system("pause");
#else
	int _c;
	while ((_c = getchar()) != '\n' && _c != EOF) {}
	printf("\nPressione Enter para finalizar...");
	fflush(stdout);
	getchar();
#endif

	return 0;
}

