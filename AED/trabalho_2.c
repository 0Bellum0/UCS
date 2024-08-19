#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define Num 26

typedef struct NodoAbp {
    char name[Num];
    int stock;
    struct NodoAbp *left;
    struct NodoAbp *right;
} NODOABP;

typedef struct list {
    char ltr;
    NODOABP *ABP;
} LIST;

NODOABP *createNodo(char name[Num], int stock) {
    NODOABP *newNode = (NODOABP *)malloc(sizeof(NODOABP));
    if (newNode == NULL) {
        printf("Malloc falhou!\n");
        exit(1);
    }
    strcpy(newNode->name, name);
    newNode->stock = stock;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

NODOABP *insertProd(NODOABP *root, char name[Num], int stock) {
    if (root == NULL) {
        return createNodo(name, stock);
    } else if (strcmp(name, root->name) == 0) {
        printf("Produto já existe!\n");
        printf("Atualizar estoque?\n");
        printf("0 - Não | 1 - Sim\n");
        int option, value;
        if (scanf("%d", &option) == 1 && option == 1) {
            printf("Qual o valor novo a ser inserido?\n");
            if (scanf("%d", &value) == 1) {
                root->stock = value;
                printf("Estoque atualizado!\n");
            }
        }
    } else if (strcmp(name, root->name) < 0) {
        root->left = insertProd(root->left, name, stock);
    } else {
        root->right = insertProd(root->right, name, stock);
    }
    return root;
}

NODOABP *findMin(NODOABP *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

NODOABP *removeProd(NODOABP *root, char name[Num]) {
    if (root == NULL) {
        return root;
    } else if (strcmp(name, root->name) < 0) {
        root->left = removeProd(root->left, name);
    } else if (strcmp(name, root->name) > 0) {
        root->right = removeProd(root->right, name);
    } else {
        if (root->left == NULL) {
            NODOABP *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            NODOABP *temp = root->left;
            free(root);
            return temp;
        }
        NODOABP *temp = findMin(root->right);
        strcpy(root->name, temp->name);
        root->stock = temp->stock;
        root->right = removeProd(root->right, temp->name);
    }
    return root;
}

int counterProd(NODOABP *root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + counterProd(root->left) + counterProd(root->right);
    }
}

void totalOfProd(NODOABP *root) {
    int total = counterProd(root);
    printf("\nTotal de produtos: %d\n", total);
}

int counterStock(NODOABP *root) {
    if (root == NULL) {
        return 0;
    } else {
        return root->stock + counterStock(root->left) + counterStock(root->right);
    }
}

void totalAmountOfProd(NODOABP *root) {
    int total = counterStock(root);
    printf("\nTotal em estoque: %d\n", total);
}

void listAllProd(NODOABP *root, int order) {
    if (root != NULL) {
        if (order == 1) { // A-Z
            listAllProd(root->left, order);
            printf("%s - %d\n", root->name, root->stock);
            listAllProd(root->right, order);
        } else if (order == 0) { // Z-A
            listAllProd(root->right, order);
            printf("%s - %d\n", root->name, root->stock);
            listAllProd(root->left, order);
        }
    }
}

void listProdByLtr(NODOABP *root, int order, char ltr) {
    if (root != NULL) {
        if (order == 1) { // A-Z
            listProdByLtr(root->left, order, ltr);
            if (toupper(root->name[0]) == toupper(ltr)) {
                printf("%s - %d\n", root->name, root->stock);
            }
            listProdByLtr(root->right, order, ltr);
        } else if (order == 0) { // Z-A
            listProdByLtr(root->right, order, ltr);
            if (toupper(root->name[0]) == toupper(ltr)) {
                printf("%s - %d\n", root->name, root->stock);
            }
            listProdByLtr(root->left, order, ltr);
        }
    }
}

void order(LIST list[Num], int opt) {
    int odr;
    printf("\nOrdem de apresentação: 1 - A-Z | 0 - Z-A\n");
    if (scanf("%d", &odr) == 1) {
        if (opt == 5) {
            if (odr == 1) {
                for (int i = 0; i < Num; i++) {
                    listAllProd(list[i].ABP, odr);
                }
            } else if (odr == 0) {
                for (int i = Num - 1; i >= 0; i--) {
                    listAllProd(list[i].ABP, odr);
                }
            }
        } else if (opt == 6) {
            char ltr;
            printf("\nDigite a letra a apresentar: ");
            if (scanf(" %c", &ltr) == 1) {
                int i = toupper(ltr) - 'A';
                if (i >= 0 && i < Num) {
                    listProdByLtr(list[i].ABP, odr, toupper(ltr));
                }
            }
        }
    }
}

NODOABP *findProd(NODOABP *root, char name[Num]) {
    if (root == NULL || strcmp(name, root->name) == 0) {
        return root;
    } else if (strcmp(name, root->name) < 0) {
        return findProd(root->left, name);
    } else {
        return findProd(root->right, name);
    }
}

void query(NODOABP *root, char name[Num]) {
    NODOABP *newNode = findProd(root, name);
    if (newNode != NULL) {
        printf("\nProduto cadastrado: \n");
        printf("%s\n", newNode->name);
        printf("%d\n", newNode->stock);
    } else {
        printf("Produto não cadastrado!\n");
    }
}

void stockAbove(NODOABP *root, int qtdM) {
    if (root != NULL) {
        stockAbove(root->left, qtdM);
        if (root->stock >= qtdM) {
            printf("\nProduto: %s\n", root->name);
            printf("Estoque: %d\n", root->stock);
        }
        stockAbove(root->right, qtdM);
    }
}

void stockBelow(NODOABP *root, int qtdM) {
    if (root != NULL) {
        stockBelow(root->left, qtdM);
        if (root->stock <= qtdM) {
            printf("\nProduto: %s\n", root->name);
            printf("Estoque: %d\n", root->stock);
        }
        stockBelow(root->right, qtdM);
    }
}

void stock(NODOABP *root, int ee, int qtdM) {
    if (ee == 1) {
        stockAbove(root, qtdM);
    } else if (ee == 0) {
        stockBelow(root, qtdM);
    }
}

void preOrder(NODOABP *root) {
    if (root != NULL) {
        printf("%s - %d\n", root->name, root->stock);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void menu(LIST list[Num]) {
    int opt;
    char name[Num];
    int stck;

    printf("|----------------------------------|\n");
    printf("|  1. Inserir produto              |\n");
    printf("|  2. Remover produto              |\n");
    printf("|  3. Consultar produto            |\n");
    printf("|  4. Total de produtos cadastrados|\n");
    printf("|  5. Listar produtos cadastrados  |\n");
    printf("|  6. Listar produtos por letra    |\n");
    printf("|  7. Total em estoque             |\n");
    printf("|  8. Total de estoque acima de... |\n");
    printf("|  9. Total de estoque abaixo de...|\n");
    printf("| 10. Pré Ordem                    |\n");
    printf("|  0. Sair                         |\n");
    printf("|----------------------------------|\n");

    if (scanf("%d", &opt) == 1) {
        switch (opt) {
            case 1:
                printf("\nDigite o nome do produto: ");
                /*getchar();
                fgets(name, Num, stdin);*/
                if (scanf("%s", name) == 1) {
                    printf("\nDigite a quantidade de estoque: ");
                    if (scanf("%d", &stck) == 1) {
                        int i = toupper(name[0]) - 'A';
                        list[i].ABP = insertProd(list[i].ABP, name, stck);
                    }
                }
                break;

            case 2:
                printf("\nDigite o nome do produto: ");
                /*getchar();
                fgets(name, Num, stdin);*/
                if (scanf("%s", name) == 1) {
                    int i = toupper(name[0]) - 'A';
                    list[i].ABP = removeProd(list[i].ABP, name);
                }
                break;

            case 3:
                printf("\nDigite o nome do produto: ");
                /*getchar();
                fgets(name, Num, stdin);*/
                if (scanf("%s", name) == 1) {
                    int i = toupper(name[0]) - 'A';
                    query(list[i].ABP, name);
                }
                break;

            case 4:
                for (int i = 0; i < Num; i++) {
                    totalOfProd(list[i].ABP);
                }
                break;

            case 5:
                order(list, opt);
                break;

            case 6:
                order(list, opt);
                break;

            case 7:
                for (int i = 0; i < Num; i++) {
                    totalAmountOfProd(list[i].ABP);
                }
                break;

            case 8:
                printf("Digite a quantidade mínima: ");
                if (scanf("%d", &stck) == 1) {
                    for (int i = 0; i < Num; i++) {
                        stock(list[i].ABP, 1, stck);
                    }
                }
                break;

            case 9:
                printf("Digite a quantidade máxima: ");
                if (scanf("%d", &stck) == 1) {
                    for (int i = 0; i < Num; i++) {
                        stock(list[i].ABP, 0, stck);
                    }
                }
                break;

            case 10:
                for (int j = 0; j < Num; j++) {
                    preOrder(list[j].ABP);
                }
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida!\n");
                break;
        }
    }
}

int main() {
    LIST list[Num];
    for (int i = 0; i < Num; i++) {
        list[i].ltr = 'A' + i;
        list[i].ABP = NULL;
    }

    int opt;
    do {
        menu(list);
        printf("Deseja continuar? 1 - Sim | 0 - Não\n");
        if (scanf("%d", &opt) != 1) {
            opt = 0;
        }
    } while (opt != 0);

    return 0;
}