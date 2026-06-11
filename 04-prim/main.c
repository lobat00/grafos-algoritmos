#include <stdio.h>
#include "prim.h"

int main(void) {
    Grafo g;
    int inicio;

    printf("===========================================\n");
    printf("  Algoritmo de Prim - Matriz de Adjacencia \n");
    printf("===========================================\n\n");

    printf("Digite o numero de vertices: ");
    scanf("%d", &g.V);

    if (g.V <= 0 || g.V > MAX) {
        printf("\n[ERRO] Numero de vertices invalido. Use entre 1 e %d.\n", MAX);
        return 1;
    }

    if (!lerGrafo(&g)) {
        return 1;
    }

    printf("\nDigite o vertice inicial (0 a %d): ", g.V - 1);
    scanf("%d", &inicio);

    if (inicio < 0 || inicio >= g.V) {
        printf("\n[ERRO] Vertice inicial invalido. Use entre 0 e %d.\n", g.V - 1);
        return 1;
    }

    prim(&g, inicio);

    return 0;
}