#include <stdio.h>
#include "dijkstra.h"

int main() {
    int opcao;

    while (1) {
        printf("\n====================================\n");
        printf("           MENU PRINCIPAL           \n");
        printf("====================================\n");
        printf("[1] Inserir um novo grafo e rodar Dijkstra\n");
        printf("[2] Terminar o programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 2) {
            printf("\nEncerrando o programa... Ate logo!\n");
            break; // Sai do loop e encerra o programa
        } else if (opcao != 1) {
            printf("\nOpcao invalida! Tente novamente.\n");
            continue; // Volta para o inicio do loop
        }

        // Variáveis para a coleta de dados do grafo
        int tipo, vertices, arestas;
        int src, dest, peso;
        int verticeOrigem;

        printf("\n=== Configuração do Grafo ===\n");
        printf("Escolha o tipo de grafo:\n[0] Nao Dirigido\n[1] Dirigido\nOpcao: ");
        scanf("%d", &tipo);

        // Validação simples para o tipo de grafo
        if (tipo != 0 && tipo != 1) {
            printf("Erro: Opcao de tipo invalida! Retornando ao menu.\n");
            continue;
        }

        printf("Digite o numero de vertices: ");
        scanf("%d", &vertices);

        printf("Digite o numero de arestas: ");
        scanf("%d", &arestas);

        // Cria o grafo baseado nas escolhas
        Graph* graph = createGraph(vertices, tipo);

        printf("\nInsira as arestas no formato: [origem] [destino] [peso]\n");
        printf("(Lembre-se: os vertices vao de 0 a %d)\n", vertices - 1);
        for (int i = 0; i < arestas; i++) {
            printf("Aresta %d: ", i + 1);
            scanf("%d %d %d", &src, &dest, &peso);
            
            // Validação de escopo dos vértices
            if (src >= vertices || dest >= vertices || src < 0 || dest < 0) {
                printf("Erro: Vertice invalido! Insira novamente esta aresta.\n");
                i--;
                continue;
            }
            addEdge(graph, src, dest, peso);
        }

        printf("\nDigite o vertice de origem para iniciar o Dijkstra: ");
        scanf("%d", &verticeOrigem);

        if (verticeOrigem >= 0 && verticeOrigem < vertices) {
            runDijkstra(graph, verticeOrigem);
        } else {
            printf("Vertice de origem invalido.\n");
        }

        // MUITO IMPORTANTE: Libera a memória do grafo atual antes de iniciar o próximo ciclo
        freeGraph(graph);
    }

    return 0;
}