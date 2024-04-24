#include<stdio.h>
#include<strings.h>
#include<ctype.h>
#include<stdlib.h>

#define N 50

typedef struct nodo{
    char info;
    struct nodo *ant, *prox;
}NODO;

NODO *ini = NULL;

void le_str(){
    int i;
    char str[N];
    printf("Digite o palindromo: ");
    fgets(str, N, stdin);
    NODO *new;
    for(i=0; i<strlen(str)-1; i++){
        new = (NODO*) malloc(sizeof(NODO));
        new->info = str[i];
        new->ant = NULL;
        new->prox = NULL;
        if(ini==NULL){
            ini = new;
        }
        else{
            new->prox = ini;
            ini->ant = new;
            ini = new;
        }
    }
}

int palindromo(){
    int i, j, p = 1;
    char str[N] = {0};
    NODO *aux = ini;
    i = 0;
    while(aux!=NULL){
        str[i++] = aux->info;
        aux = aux->prox;
    }
    for(i=0, j=strlen(str)-1; i<j; i++, j--){
        if(toupper(str[i]) != toupper(str[j])){
            p = 0;
            break;
        }
    }
    return p;
}

int main(){
    le_str();
    
    if(palindromo()==1){
        printf("Palavra eh palindromo!");
    }
    else{
        printf("Palavra nao eh palindromo!");
    }
    printf("\n");
    return 0;
}