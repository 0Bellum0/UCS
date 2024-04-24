/*
1) Fazer uma função que troque o valor de duas variáveis inteiras informadas como parâmetro.
*/

#include<stdio.h>

void troca(int *a, int *b){
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
}

int main(){
    int a = 5, b = 3;

    troca(&a, &b);

    printf("a-> %d\nb-> %d\n", a, b);
}