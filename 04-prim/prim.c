#include <stdio.h>
#include <limits.h>
#include "prim.h"

static int verticeMinimo(int chave[], int naMST[], int V) {
    int menor  = INT_MAX;
    int indice = -1;

    for (int v = 0; v < V; v++) {
        if (!naMST[v] && chave[v] < menor) {
            menor  = chave[v];
            indice = v;
        }
    }

    return indice;
}

static void exibirMST(int pai[], int chave[], Grafo *g) {
    int pesoTotal = 0;

    printf("\n+------------------------------------------+\n");
    printf("|      ARVORE GERADORA MINIMA (Prim)       |\n");
    printf("+------------------------------------------+\n");
    printf("| %-10s  %-10s  %-10s        |\n", "Aresta", "Direcao", "Peso");
    printf("+------------------------------------------+\n");

    for (int i = 0; i < g->V; i++) {
        if (pai[i] == -1) continue; /* raiz ou vertice isolado */

        printf("|   %2d -- %-4d   (%2d <-> %2d)   Peso: %3d   |\n",
               pai[i], i, pai[i], i, g->matriz[i][pai[i]]);

        pesoTotal += g->matriz[i][pai[i]];
    }

    printf("+------------------------------------------+\n");
    printf("|  Peso total da MST: %-20d  |\n", pesoTotal);
    printf("+------------------------------------------+\n\n");
}

/* ─────────────────────────────────────────
 * lerGrafo  (publica — declarada em prim.h)
 * ───────────────────────────────────────── */
int lerGrafo(Grafo *g) {
    printf("\nDigite a matriz de adjacencia %dx%d\n", g->V, g->V);
    printf("(0 = sem aresta, valor positivo = peso da aresta)\n\n");

    for (int i = 0; i < g->V; i++) {
        for (int j = 0; j < g->V; j++) {
            printf("  [%d][%d]: ", i, j);
            scanf("%d", &g->matriz[i][j]);

            /* Rejeita pesos negativos */
            if (g->matriz[i][j] < 0) {
                printf("\n[ERRO] Peso negativo em [%d][%d]. "
                       "Prim nao suporta pesos negativos.\n", i, j);
                return 0;
            }
        }
    }

    /* Valida simetria — grafo nao direcionado exige matriz simetrica */
    for (int i = 0; i < g->V; i++) {
        for (int j = 0; j < g->V; j++) {
            if (g->matriz[i][j] != g->matriz[j][i]) {
                printf("\n[ERRO] Matriz assimetrica em [%d][%d] != [%d][%d].\n",
                       i, j, j, i);
                printf("O grafo deve ser nao direcionado (matriz simetrica).\n");
                return 0;
            }
        }
    }

    return 1;
}

/* ─────────────────────────────────────────
 * prim  (publica — declarada em prim.h)
 * ───────────────────────────────────────── */
void prim(Grafo *g, int inicio) {
    int pai[MAX];   /* armazena a arvore geradora minima    */
    int chave[MAX]; /* menor peso conhecido para cada vertice */
    int naMST[MAX]; /* 1 = vertice ja incluido na MST       */

    /* Inicializa todos os vertices */
    for (int i = 0; i < g->V; i++) {
        pai[i]   = -1;
        chave[i] = INT_MAX;
        naMST[i] = 0;
    }

    /* Vertice inicial: custo zero para comecar a arvore */
    chave[inicio] = 0;

    /* Itera V-1 vezes para incluir todos os vertices na MST */
    for (int count = 0; count < g->V - 1; count++) {

        /* Seleciona o vertice de menor chave ainda fora da MST */
        int u = verticeMinimo(chave, naMST, g->V);

        /* Grafo desconexo: nenhum vertice alcancavel restante */
        if (u == -1) {
            printf("\n[AVISO] Grafo desconexo: nao e possivel gerar uma MST completa.\n");
            printf("Exibindo arestas alcancadas ate o momento:\n");
            break;
        }

        /* Inclui u na MST */
        naMST[u] = 1;

        for (int v = 0; v < g->V; v++) {
            if (g->matriz[u][v] != 0 &&
                !naMST[v]            &&
                g->matriz[u][v] < chave[v])
            {
                pai[v]   = u;
                chave[v] = g->matriz[u][v];
            }
        }
    }

    exibirMST(pai, chave, g);
}