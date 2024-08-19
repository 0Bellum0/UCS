#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define Num 26

typedef struct NodoAbp{
    char name[Num];
    int stock;
    struct NODOABP *left;
    struct NODOABP *rght;
}NODOABP;

typedef struct list{
    char ltr;
    NODOABP *ABP;
}LIST;

NODOABP *createNodo(char name[Num], int stock){
    NODOABP *new = (NODOABP*)malloc(sizeof(NODOABP));
    strcpy(new->name, name);
    new->stock = stock;
    new->left = NULL;
    new->rght = NULL;
    return new;
}

NODOABP *insertProd(NODOABP *root, char name[Num], int stock){
    /*permite a inserção de um produto e sua quantade na ABP.*/
    if(root == NULL){
        root = createNodo(name, stock);
    }
    else if(strcmp(name, root->name) == 0){
        printf("Produto já existe!\n");
        printf("Atualizar estoque?\n");
        printf("0 - Não | 1 - Sim\n");
        int option, value;
        if(scanf("%d", &option) == 1){
            printf("Qual o valor novo a ser inserido?\n");
            scanf("%d", &value);
            root->stock = value;
            printf("Estoque atualizado!\n");
        }
    }
    else if(strcmp(name, root->name) < 0){
        root->left = insertProd(root->left, name, stock);
    }
    else{
        root->rght = insertProd(root->rght, name, stock);
    }
    return root;
}

NODOABP *findMin(NODOABP* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

NODOABP* removeProd(NODOABP* root, char name[Num]){
/*remove um produto da ABP, mantendo a ABP ordenada.*/
    if (root == NULL){
        return root;
    }else if(strcmp(name, root->name) < 0){
        root->left = removeProd(root->left, name);
    }else if(strcmp(name, root->name) > 0){
        root->rght = removeProd(root->rght, name);
    }else{
        if(root->left == NULL){
            NODOABP *temp = root->rght;
            free(root);
            return temp;
        }else if(root->rght == NULL){
            NODOABP *temp = root->left;
            free(root);
            return temp;
        }
        NODOABP *temp = findMin(root->rght);
        strcpy(root->name, temp->name);
        root->rght = removeProd(root->rght, temp->name);
    }
    return root;
}

int counterProd(NODOABP* root){
    if(root == NULL){
        return 0;
    }else{
        return 1 + counterProd(root->left) + counterProd(root->rght);
    }
}

void totalOfProd(NODOABP* root){
    /*retorna o número total de produtos (não as quantades).*/
    int total = 0;
    total = counterProd(root);
    printf("\nTotal de produtos: %d\n", total);
}

int counterStock(NODOABP* root){
    int qtd = 0;
    if(root == NULL){
        return 0;
    }else{
        qtd += root->stock;
    }
    return qtd + counterStock(root->left) + counterStock(root->rght);
}

void totalAmountOfProd(NODOABP* root){
/*retorna a soma total de todas as
quantidades de produtos.*/
    int total = 0;
    total = counterStock(root);
    printf("\nTotal em estoque: %d\n", total);
}

void listAllProd(NODOABP* root, int order){
/*exibe a lista dos produtos em ordem alfabética (de A
a Z) ou em ordem alfabética inversa (de Z a A) . Pode exibir a quantade de cada um
também.*/
    if(root != NULL){
        if(order == 1) { //A-Z
            listAllProd(root->left, order);
            printf("%s - %d\n", root->name, root->stock);
            listAllProd(root->rght, order);
        } else if(order == 0){ //Z-A
            listAllProd(root->rght, order);
            printf("%s - %d\n", root->name, root->stock);
            listAllProd(root->left, order);
        }
    }
}

void listProdByLtr(NODOABP* root, int order, char ltr){
    /*exibe a lista dos produtos iniciados por uma
determinada letra, em ordem alfabética (de A a Z) ou em ordem alfabética inversa (de Z a
A). Pode exibir a quantade de cada um também.*/
    if(root != NULL){
        if(order == 1) { //A-Z
            listProdByLtr(root->left, order, ltr);
            if(root->name[0] == ltr){
                printf("%s - %d\n", root->name, root->stock);
            }
            listProdByLtr(root->rght, order, ltr);
        } else if(order == 0){ //Z-A
            listProdByLtr(root->rght, order, ltr);
            if(root->name[0] == ltr){
                printf("%s - %d\n", root->name, root->stock);
            }
            listProdByLtr(root->left, order, ltr);
        }
    }
}

void order(LIST list[Num], int opt){
    int odr;
    printf("\nOrdem de apresentação: 1 - A-Z | 0 - Z-A\n");
    scanf(" %d\n", &odr);
    if(opt == 5){
        if(odr == 1){
            int i = 0;
            while(i < Num){
                listAllProd(list[i].ABP, odr);
                i++;
            }
        }else if(odr == 0){
            int i = Num-1;
            while(i > 0){
                listAllProd(list[i].ABP, odr);
                i--;
            }
        }
    }else if(opt == 6){
            char ltr;
            printf("\nDigite a letra a apresentar: ");
            scanf(" %c", &ltr);
            int i = ltr-65;
            listProdByLtr(list[i].ABP, odr, toupper(ltr));
        }
}

NODOABP* findProd(NODOABP* root, char name[Num]){
    if(root == NULL || strcmp(name, root->name) == 0){
        return root;
    } else if(strcmp(name, root->name) < 0){
        return findProd(root->left, name);
    } else {
        return findProd(root->rght, name);
    }
}

void query(NODOABP* root, char name[Num]){
/*consulta um produto, informando sua quantade em
estoque.*/
    NODOABP* new = findProd(root, name);
    if(new != NULL){
        printf("\nProduto cadastrado: \n");
        printf("%s\n", new->name);
        printf("%d\n", new->stock);
    }else{
        printf("Produto não cadastrado!\n");
    }
}

void stockAbove(NODOABP* root, int qtdM){
/*exibe, em ordem alfabética, os produtos que
tem uma quantade em estoque igual ou maior que uma quantade informada.*/
    if(root != NULL){
        stockAbove(root->left, qtdM);
        stockAbove(root->rght, qtdM);
        if(root->stock >= qtdM){
            printf("\nProduto: %s\n", root->name);
            printf("Estoque: %d\n", root->stock);
        }
    }
}

void stockBelow(NODOABP* root, int qtdM){
/*exibe, em ordem alfabética, os produtos
que tem uma quantade em estoque igual ou menor que uma quantade informada.*/
    if(root != NULL){
        stockBelow(root->left, qtdM);
        stockBelow(root->rght, qtdM);
        if(root->stock <= qtdM){
            printf("\nProduto: %s\n", root->name);
            printf("Estoque: %d\n", root->stock);
        }
    }
}

void stock(NODOABP* root, int ee, int qtdM){
    if(ee == 1){
        stockAbove(root, qtdM);
    } else if(ee == 0){
        stockBelow(root, qtdM);
    }
}

void preOrder(NODOABP* root){
/*exibe os produtos de uma letra em ordem pré-fixada.*/
    if(root != NULL){
        printf("%s - %d\n", root->name, root->stock); // Process current node
        preOrder(root->left); // Traverse left subtree
        preOrder(root->rght); // Traverse right subtree
    }
}

void menu(LIST list[Num]){

    int opt = 12;
    char name[Num];
    int stck;
    int i = 0;

    printf("|----------------------------------|\n");
    printf("|  1. Inserir produto              |\n");
    printf("|  2. Remover produto              |\n");
    printf("|  3. Total de produtos            |\n");
    printf("|  4. Total em estoque             |\n");
    printf("|  5. Listar todos os produtos     |\n");
    printf("|  6. Listar produtos por letra    |\n");
    printf("|  7. Consultar produto            |\n");
    printf("|  8. Verifica estoque             |\n");
    printf("|  9. Percurso préfixado           |\n");
    //printf("| 10. Menu                         |\n");
    printf("|  0. Sair                         |\n");
    printf("|----------------------------------|\n");

    do {
        printf("\nEscolha uma opção: ");
        scanf("%d\n", &opt);

        switch (opt){
            case 1:
            printf("Digite o nome do produto: ");
            fgets(name, Num, stdin);
            printf("\nDigite o estoque do produto: ");
            scanf("%d\n", &stck);
            int i = 0;
            do{
                if(toupper(name[0]) == toupper(list[i].ltr)){
                    list[i].ABP = insertProd(list[i].ABP, name, stck);
                    break;
                }
                i++;
            }
            while(toupper(name[0]) != toupper(list[i].ltr));
                break;
            case 2:
            printf("Digite o nome do produto: ");
            fgets(name, Num, stdin);
            int i = 0;
            do{
                if(toupper(name[0]) == toupper(list[i].ltr)){
                    list[i].ABP = removeProd(list[i].ABP, name);
                    break;
                }
                i++;
            }while(toupper(name[0]) != toupper(list[i].ltr));
                break;
            case 3:
            int i = 0;
            while(i < Num){
            totalOfProd(list[i].ABP);
            i++;
            }
                break;
            case 4:
            int i = 0;
            while(i < Num){
            totalAmountOfProd(list[i].ABP);
            i++;
            }
                break;
            case 5:
            case 6:
            order(list, opt);
                break;
            case 7:
            char name[Num];
            printf("Digite o nome do produto para busca-lo: ");
            fgets(name, Num, stdin);
            int i = 0;
            do{
                if(toupper(name[0]) == toupper(list[i].ltr)){
                    query(list[i].ABP, name);
                    break;
                }
                i++;
            }while(toupper(name[0]) != toupper(list[i].ltr));
                break;
            case 8:
            int i = 0;
            int qtdM, ee;
            printf("\nDigite a qtd média: ");
            scanf("%d\n", &qtdM);
            printf("Verificar 1 - excesso ou 0 - escassez: ");
            scanf("%d\n", &ee);
            while(i < Num){
                stock(list[i].ABP, ee, qtdM);
                i++;
            }
                break;
            case 9:
            int i = 0;
            while(i < Num){
            preOrder(list[i].ABP);
            i++;
            }
                break;
            /*case 10:
            menu(list);
                break;*/
            case 0:
                printf("Saindo...\n");
                break;
            default:
                //printf("Opção inválida!\n");
                printf("Digite uma opção válida!\n");
                break;
        }
    } while(opt != 0);
}
/*
int main(){
    //NODOABP* root = NULL;
    LIST list[Num];
    int i = 0;
    char ltr = 'A';
    while(i < Num){
        list[i].ltr = ltr;
        list[i].ABP = NULL;
        ltr++;
        i++;
    }
    menu(list);
    return 0;
}*/

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