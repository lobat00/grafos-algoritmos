#include "dfs.h"

No* criarNo(int vertice) {
	No* novo = (No*) malloc(sizeof(No));
	if (!novo) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	novo->vertice = vertice;
	novo->prox = NULL;
	return novo;
}

void adicionarAresta(
	ListaAdj grafo[],
	int origem,
	int destino,
	int direcionado
) {
	No* novo = criarNo(destino);
	novo->prox = grafo[origem].inicio;
	grafo[origem].inicio = novo;

	if (!direcionado) {
		novo = criarNo(origem);
		novo->prox = grafo[destino].inicio;
		grafo[destino].inicio = novo;
	}
}

void dfsUtil(ListaAdj grafo[], int atual, int visitado[]) {
	visitado[atual] = 1;
	printf("%d ", atual);

	No* temp = grafo[atual].inicio;
	while (temp != NULL) {
		int vizinho = temp->vertice;
		if (!visitado[vizinho]) {
			dfsUtil(grafo, vizinho, visitado);
		}
		temp = temp->prox;
	}
}

void dfs(ListaAdj grafo[], int numVertices, int origem) {
	int visitado[MAX_VERTICES] = {0};

	printf("\nOrdem da DFS:\n");
	dfsUtil(grafo, origem, visitado);
	printf("\n\n");
}

void mostrarGrafo(ListaAdj grafo[], int numVertices) {
	printf("\nLista de adjacencia:\n");

	for (int i = 0; i < numVertices; i++) {
		printf("%d -> ", i);

		No* temp = grafo[i].inicio;

		while (temp != NULL) {
			printf("%d ", temp->vertice);
			temp = temp->prox;
		}

		printf("\n");
	}
}

void limparTela() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif

	printf("=== Algoritmo de Busca em Profundidade (DFS) ===\n\n");

}

void liberarGrafo(ListaAdj grafo[], int numVertices) {
	for (int i = 0; i < numVertices; i++) {
		No* atual = grafo[i].inicio;
		while (atual != NULL) {
			No* temp = atual;
			atual = atual->prox;
			free(temp);
		}
		grafo[i].inicio = NULL;
	}
}

