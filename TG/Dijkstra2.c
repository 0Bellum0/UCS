#include <stdio.h>
#include <limits.h>

#define V 10 // Número de vértices no grafo
#define INF INT_MAX

void printCaminho(int pred[], int destino) {
    // Base da recursão
    if (pred[destino] == -1) {
        printf("%d", destino);
        return;
    }
    
    printCaminho(pred, pred[destino]);
    printf(" -> %d", destino);
}

void dijkstra(int graph[V][V], int origem) {
    int dist[V];  // Para armazenar a menor distância de origem até i
    int pred[V];  // Para armazenar o predecessor de cada vértice no caminho mais curto
    int visitado[V]; // Para rastrear se o vértice foi visitado

    // Inicialização
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        pred[i] = -1;
        visitado[i] = 0;
    }

    // Distância da origem até ela mesma é sempre zero
    dist[origem] = 0;

    // Encontrando o caminho mais curto para todos os vértices
    for (int count = 0; count < V - 1; count++) {
        // Escolhendo o vértice com a menor distância não visitada
        int u = -1;
        for (int v = 0; v < V; v++) {
            if (!visitado[v] && (u == -1 || dist[v] < dist[u]))
                u = v;
        }

        // Marcando o vértice escolhido como visitado
        visitado[u] = 1;

        // Atualizando distâncias dos vértices adjacentes do vértice escolhido
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visitado[v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                pred[v] = u;
            }
        }
    }

    // Imprimindo as distâncias e os caminhos mais curtos
    printf("Distâncias a partir da origem %d:\n", origem);
    for (int i = 0; i < V; i++) {
        printf("Para o vértice %d: Distância = %d, Caminho = ", i, dist[i]);
        printCaminho(pred, i);
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2, 0},
        {0, 0, 7, 0, 9, 14, 0, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6, 0},
        {8, 11, 0, 0, 0, 0, 1, 0, 7, 0},
        {0, 0, 2, 0, 0, 0, 6, 7, 0, 9},
        {0, 0, 0, 0, 0, 0, 0, 0, 9, 0}
    };

    int origem = 0;
    dijkstra(graph, origem);

    return 0;
}
