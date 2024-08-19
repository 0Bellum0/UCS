#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

// Estrutura para representar um nó na fila de prioridade
typedef struct MinHeapNode {
    int vertice;
    int distancia;
}MinHeapNode;

// Estrutura para representar uma fila de prioridade
typedef struct MinHeap {
    int tamanho;    // Número atual de elementos na fila
    int capacidade; // Capacidade máxima da fila
    struct MinHeapNode *array; // Array de nós do heap
}MinHeap;

// Função para criar um novo nó no heap
struct MinHeapNode* novoNoHeap(int vertice, int distancia) {
    struct MinHeapNode* no = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    no->vertice = vertice;
    no->distancia = distancia;
    return no;
}

// Função para criar uma fila de prioridade vazia
struct MinHeap* criarMinHeap(int capacidade) {
    struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->tamanho = 0;
    minHeap->capacidade = capacidade;
    minHeap->array = (struct MinHeapNode*) malloc(capacidade * sizeof(struct MinHeapNode));
    return minHeap;
}

// Função para trocar dois nós no heap
void trocarMinHeapNode(struct MinHeapNode *a, struct MinHeapNode *b) {
    struct MinHeapNode t = *a;
    *a = *b;
    *b = t;
}

// Função para heapificar o heap mínimo
void heapificar(struct MinHeap* minHeap, int indice) {
    int menor = indice;
    int esq = 2 * indice + 1;
    int dir = 2 * indice + 2;

    if (esq < minHeap->tamanho && minHeap->array[esq].distancia < minHeap->array[menor].distancia)
        menor = esq;

    if (dir < minHeap->tamanho && minHeap->array[dir].distancia < minHeap->array[menor].distancia)
        menor = dir;

    if (menor != indice) {
        trocarMinHeapNode(&minHeap->array[menor], &minHeap->array[indice]);
        heapificar(minHeap, menor);
    }
}

// Função para verificar se a fila de prioridade está vazia
int estaVazio(struct MinHeap* minHeap) {
    return minHeap->tamanho == 0;
}

// Função para extrair o nó com a menor distância da fila de prioridade
struct MinHeapNode* extrairMin(struct MinHeap* minHeap) {
    if (estaVazio(minHeap))
        return NULL;

    struct MinHeap* temp = minHeap;
    struct MinHeapNode* raiz = &temp->array[0];
    struct MinHeapNode* ultimoNo = &minHeap->array[minHeap->tamanho - 1];
    minHeap->array[0] = *ultimoNo;
    --minHeap->tamanho;
    heapificar(minHeap, 0);

    return raiz;
}

// Função para diminuir a distância de um vértice no heap, se necessário
void diminuirChave(struct MinHeap* minHeap, int vertice, int novaDistancia) {
    int i;
    for (i = 0; i < minHeap->tamanho; ++i) {
        if (minHeap->array[i].vertice == vertice) {
            minHeap->array[i].distancia = novaDistancia;
            break;
        }
    }

    while (i && minHeap->array[i].distancia < minHeap->array[(i - 1) / 2].distancia) {
        trocarMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Função para verificar se um vértice está no heap ou não
int isInMinHeap(struct MinHeap *minHeap, int vertice) {
    int i;
    for (i = 0; i < minHeap->tamanho; ++i) {
        if (minHeap->array[i].vertice == vertice) {
            return 1;
        }
    }
    return 0;
}

// Função principal que implementa o algoritmo de Dijkstra usando heap binário

void dijkstraHeap(struct MinHeap* minHeap, int *distancia, int *predecessor, int **grafo, int vertices, int origem) {
    // Initialize minHeap properly
    for (int v = 0; v < vertices; ++v) {
        distancia[v] = INT_MAX;
        predecessor[v] = -1;
        minHeap->array[v].vertice = v;  // Initialize vertice directly in the array
        minHeap->array[v].distancia = distancia[v];
        minHeap->tamanho++;
    }

    // A distância do vértice de origem para ele mesmo é sempre 0
    distancia[origem] = 0;
    diminuirChave(minHeap, origem, distancia[origem]);

    // Loop principal
    while (!estaVazio(minHeap)) {
        struct MinHeapNode* noHeap = extrairMin(minHeap);
        int u = noHeap->vertice;

        // Percorre todos os vértices adjacentes de u
        for (int v = 0; v < vertices; ++v) {
            // Atualiza a distância se v não estiver na fila de prioridade,
            // houver uma aresta de u para v, e a distância total até v através de u for menor
            if (grafo[u][v] && isInMinHeap(minHeap, v) && distancia[u] != INT_MAX && distancia[u] + grafo[u][v] < distancia[v]) {
                distancia[v] = distancia[u] + grafo[u][v];
                predecessor[v] = u;
                diminuirChave(minHeap, v, distancia[v]);
            }
        }

        //free(noHeap); // Free the extracted node to prevent memory leak
    }
}


// Função auxiliar para imprimir o caminho mais curto a partir do destino
void imprimirCaminho(int *distancia, int *predecessor, int destino, int origem) {
    if (destino == origem) {
        printf("%d ", origem);
    } else if (predecessor[destino] == -1) {
        printf("Caminho inexistente.\n");
    } else {
        imprimirCaminho(distancia, predecessor, predecessor[destino], origem);
        printf("%d ", destino);
    }
}

// Função para imprimir as distâncias mínimas de todos os vértices a partir da origem
void imprimirDistancias(int *distancia, int vertices, int origem) {
    printf("Distâncias mínimas do vértice %d:\n", origem);
    for (int i = 0; i < vertices; ++i) {
        printf("Para o vértice %d: ", i);
        if (distancia[i] == INT_MAX) {
            printf("INF\n");
        } else {
            printf("%d\n", distancia[i]);
        }
    }
}

// Função principal
int main() {
    srand(time(NULL)); // Seed the random number generator

    int vertices = 5;
    int origem = 0;
    int **grafo = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++)
        grafo[i] = (int *)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i == j) {
                grafo[i][j] = 0; // No self-loop
            }else {
                grafo[i][j] = rand() % 10 + 1; // Random weight between 1 and 10
            }
        }
    }
    
    int predecessor[vertices];
    int distancia[vertices];
    for (int i = 0; i < vertices; i++) {
        predecessor[i] = -1;
        distancia[i] = INT_MAX;
    }
    
    struct MinHeap* minHeap = criarMinHeap(vertices);
    
    dijkstraHeap(minHeap, distancia, predecessor, grafo, vertices, origem);
    
    for (int i = 0; i < vertices; i++) {
        free(grafo[i]);
    }
    free(grafo);
    // Remember to also free the heap nodes and the heap itself if necessary

    // Example usage of imprimirDistancias to print distances
    imprimirDistancias(distancia, vertices, origem);

    // Free dynamically allocated memory
    free(minHeap->array);  // Free the array within minHeap
    free(minHeap);         // Free the minHeap itself

    return 0;
}