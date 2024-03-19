#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#define N 10

typedef struct elementos{
    int num;
    char nome[50];
}ELM;

void inverte(ELM vet[N]){

    int i;

}

void preenche(ELM vet[N]){

    int i;

    for(i=0; i<N; i++){
        printf("Selecione um número: ");
        scanf("%d", &vet[i].num);
        getchar();
        printf("Digite o nome: ");
        gets(vet[i].nome);
}

}

void esc_vet(ELM vet[N]){
    int i;

    for(i=0; i<N; i++){
        printf("%d %s", vet[i].num, vet[i].nome);
    }
}

void main(){

    ELM vet[N];
    
    preenche(vet);
    esc_vet(vet);
    inverte(vet);
}