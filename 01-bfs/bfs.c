#include "bfs.h"

/* =========================
   Funções da Fila
   ========================= */

void inicializarFila(Fila* f) {
	f->frente = 0;
	f->tras = -1;
}

int filaVazia(Fila* f) {
	return f->frente > f->tras;
}

void enfileirar(Fila* f, int valor) {
	f->tras++;
	f->itens[f->tras] = valor;
}

int desenfileirar(Fila* f) {
	return f->itens[f->frente++];
}

/* =========================
   Funções do Grafo
   ========================= */

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

/* =========================
   BFS
   ========================= */

void bfs(ListaAdj grafo[], int numVertices, int origem) {
	int visitado[MAX_VERTICES] = {0};

	Fila fila;
	inicializarFila(&fila);

	visitado[origem] = 1;
	enfileirar(&fila, origem);

	printf("\nOrdem da BFS:\n");

	while (!filaVazia(&fila)) {
		int atual = desenfileirar(&fila);
		printf("%d ", atual);

		No* temp = grafo[atual].inicio;

		while (temp != NULL) {
			int vizinho = temp->vertice;
			if (!visitado[vizinho]) {
				visitado[vizinho] = 1;
				enfileirar(&fila, vizinho);
			}
			temp = temp->prox;
		}
	}

	printf("\n\n");
}

/* =========================
   Exibir grafo
   ========================= */

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

/* ===============================
   Limpar tela e cabeçalho inicial
   =============================== */
void limparTela() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");	
#endif

printf("=== Algoritmo de Busca em Largura (BFS) ===\n\n");

}


