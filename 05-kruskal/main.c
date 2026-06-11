#include <stdio.h>
#include "kruskal.h"

int main() {
    int opcao;

    while (1) {
        printf("\n====================================\n");
        printf("       MENU PRINCIPAL (KRUSKAL)     \n");
        printf("====================================\n");
        printf("[1] Inserir um novo grafo e rodar Kruskal\n");
        printf("[2] Terminar o programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 2) {
            printf("\nEncerrando o programa... Ate logo!\n");
            break;
        } else if (opcao != 1) {
            printf("\nOpcao invalida! Tente novamente.\n");
            continue;
        }

        int vertices, arestas;
        int src, dest, peso;

        printf("\n=== Configuração do Grafo (Nao Dirigido) ===\n");
        printf("Digite o numero de vertices: ");
        scanf("%d", &vertices);

        printf("Digite o numero de arestas: ");
        scanf("%d", &arestas);

        // Cria o grafo não dirigido
        Graph* graph = createGraph(vertices, arestas);

        printf("\nInsira as arestas no formato: [origem] [destino] [peso]\n");
        printf("(Lembre-se: os vertices vao de 0 a %d)\n", vertices - 1);
        for (int i = 0; i < arestas; i++) {
            printf("Aresta %d: ", i + 1);
            scanf("%d %d %d", &src, &dest, &peso);
            
            if (src >= vertices || dest >= vertices || src < 0 || dest < 0) {
                printf("Erro: Vertice invalido! Insira novamente esta aresta.\n");
                i--;
                continue;
            }
            addEdge(graph, src, dest, peso);
        }

        // Executa o algoritmo de Kruskal
        runKruskal(graph);

        // Libera memória
        freeGraph(graph);
    }

    return 0;
}