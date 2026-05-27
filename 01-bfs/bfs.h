#ifndef BFS_H
#define BFS_H

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

typedef struct {
	int itens[MAX_VERTICES];
	int frente;
	int tras;
} Fila;

/* Protótipos */
No* criarNo(int vertice);
void adicionarAresta(ListaAdj grafo[], int origem, int destino, int direcionado);
void mostrarGrafo(ListaAdj grafo[], int numVertices);
void bfs(ListaAdj grafo[], int numVertices, int origem);

/* Funções da fila (exportadas se necessário) */
void inicializarFila(Fila* f);
int filaVazia(Fila* f);
void enfileirar(Fila* f, int valor);
int desenfileirar(Fila* f);

/* Função para limpar a tela e exibir o cabeçalho */
void limparTela();

#endif /* BFS_H */

