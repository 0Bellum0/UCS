#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Função para inserir um nó na árvore
Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Percurso pré-fixado (preorder)
void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Percurso central (inorder)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Percurso pós-fixado (postorder)
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Função auxiliar para verificar se um nó é folha
int isLeaf(Node* node) {
    return (node->left == NULL && node->right == NULL);
}

// Função para calcular a soma dos nodos-folha
int sumOfLeaves(Node* root) {
    if (root == NULL) return 0;
    if (isLeaf(root)) return root->data;
    return sumOfLeaves(root->left) + sumOfLeaves(root->right);
}

// Função auxiliar para coletar folhas em um array (para ordenação)
void collectLeaves(Node* root, int leaves[], int* index) {
    if (root != NULL) {
        if (isLeaf(root)) {
            leaves[(*index)++] = root->data;
        }
        collectLeaves(root->left, leaves, index);
        collectLeaves(root->right, leaves, index);
    }
}

// Função de comparação para ordenação decrescente
int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

// Função para escrever nodos-folha em ordem decrescente
void printLeavesDescending(Node* root) {
    int leaves[100];  // Supondo que não haverá mais de 100 folhas
    int index = 0;
    collectLeaves(root, leaves, &index);
    qsort(leaves, index, sizeof(int), compare);
    for (int i = 0; i < index; i++) {
        printf("%d ", leaves[i]);
    }
}

// Função para calcular a altura da árvore
int height(Node* root) {
    if (root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Função para encontrar o nó mínimo (utilizado na remoção)
Node* findMin(Node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

// Função para remover um nó na árvore
Node* deleteNode(Node* root, int data) {
    if (root == NULL) return root;
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Função principal para testar as operações
int main() {
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    printf("Sum of leaf nodes: %d\n", sumOfLeaves(root));

    printf("Leaf nodes in descending order: ");
    printLeavesDescending(root);
    printf("\n");

    printf("Height of the tree: %d\n", height(root));

    printf("Deleting node 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");

    printf("Deleting node 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");

    printf("Deleting node 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}