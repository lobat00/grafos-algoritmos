#ifndef PRIM_H
#define PRIM_H

/* ─────────────────────────────────────────
 * Constante: numero maximo de vertices
 * ───────────────────────────────────────── */
#define MAX 100

/* ─────────────────────────────────────────
 * Estrutura que representa o grafo por
 * meio de uma matriz de adjacencia.
 *
 *  matriz[i][j] = peso da aresta (i, j)
 *  matriz[i][j] = 0 indica ausencia de aresta
 *  V            = numero de vertices
 * ───────────────────────────────────────── */
typedef struct {
    int matriz[MAX][MAX];
    int V;
} Grafo;

/* ─────────────────────────────────────────
 * Prototipos das funcoes publicas
 * ───────────────────────────────────────── */

/*
 * lerGrafo
 * --------
 * Le a matriz de adjacencia a partir da entrada padrao.
 * Valida pesos negativos e simetria da matriz.
 *
 * Parametros:
 *   g — ponteiro para o Grafo a ser preenchido
 *       (g->V ja deve estar definido antes da chamada)
 *
 * Retorno:
 *   1 se a leitura foi bem-sucedida
 *   0 se alguma validacao falhou
 */
int lerGrafo(Grafo *g);

/*
 * prim
 * ----
 * Executa o algoritmo de Prim sobre o grafo g
 * a partir do vertice inicial informado.
 * Ao final, exibe as arestas da AGM e o peso total.
 *
 * Parametros:
 *   g      — ponteiro para o Grafo
 *   inicio — indice do vertice de partida (0 a g->V - 1)
 */
void prim(Grafo *g, int inicio);

#endif /* PRIM_H */