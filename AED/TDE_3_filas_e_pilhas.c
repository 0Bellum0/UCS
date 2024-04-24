#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 100

// Estrutura para representar a fila
typedef struct {
    char items[N];
    int ini, fim;
} Fila;

// Estrutura para representar a pilha
typedef struct {
    char items[N];
    int top;
} Stack;

// Funções para operações na fila
void enFila(Fila *q, char item) {
    if (q->fim == N - 1) {
        printf("Fila is full\n");
        exit(EXIT_FAILURE);
    }
    q->fim++;
    q->items[q->fim] = item;
}

char deFila(Fila *q) {
    if (q->ini > q->fim) {
        printf("Fila is empty\n");
        exit(EXIT_FAILURE);
    }
    char item = q->items[q->ini];
    q->ini++;
    return item;
}

bool isFilaEmpty(Fila *q) {
    return q->ini > q->fim;
}

// Funções para operações na pilha
void push(Stack *s, char item) {
    if (s->top == N - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->top++;
    s->items[s->top] = item;
}

char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    char item = s->items[s->top];
    s->top--;
    return item;
}

bool isStackEmpty(Stack *s) {
    return s->top == -1;
}

// Função para verificar se um caractere é um dígito
bool ehDigito(char ch) {
    return ch >= '0' && ch <= '9';
}

// Função principal para rearranjar a sequência
void rearranjarSequencia(char *sequencia, int tamanho) {
    Fila letras;
    Stack digitos;
    letras.ini = 0;
    letras.fim = -1;
    digitos.top = -1;

    // Percorre a sequência e adiciona letras à fila e dígitos à pilha
    for (int i = 0; i < tamanho; i++) {
        if (ehDigito(sequencia[i])) {
            push(&digitos, sequencia[i]);
        } else {
            enFila(&letras, sequencia[i]);
        }
    }

    // Reconstrói a sequência com letras na ordem original e dígitos na ordem inversa
    for (int i = 0; i < tamanho; i++) {
        if (!isFilaEmpty(&letras)) {
            sequencia[i] = deFila(&letras);
        } else {
            sequencia[i] = pop(&digitos);
        }
    }
}

int main() {
    // Exemplo de uso
    char sequencia1[] = {'A', '1', 'E', '5', 'T', '7', 'W', '8', 'G'};
    int tamanho1 = sizeof(sequencia1) / sizeof(sequencia1[0]);
    rearranjarSequencia(sequencia1, tamanho1);
    printf("Sequencia 1 rearranjada: ");
    for (int i = 0; i < tamanho1; i++) {
        printf("%c ", sequencia1[i]);
    }
    printf("\n");

    char sequencia2[] = {'3', 'C', '9', 'H', '4', 'Q', '6'};
    int tamanho2 = sizeof(sequencia2) / sizeof(sequencia2[0]);
    rearranjarSequencia(sequencia2, tamanho2);
    printf("Sequencia 2 rearranjada: ");
    for (int i = 0; i < tamanho2; i++) {
        printf("%c ", sequencia2[i]);
    }
    printf("\n");

    return 0;
}
