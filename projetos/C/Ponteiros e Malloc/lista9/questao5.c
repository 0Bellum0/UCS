/*
5) Na Teoria de Sistemas, define-se como elemento minimax de uma matriz o menor elemento da linha em que se encontra o maior elemento da matriz. Faça uma função que receba como parâmetro uma matriz A[5][5] e retorne o valor do elemento minimax, bem como a linha e coluna onde ocorreu.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void gera_matriz(int M[5][5]){
    srand(time(NULL));
    int i, j;
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            M[i][j] = rand () % 10;
        }
    }
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            printf("% 4d", M[i][j]);
        }
        printf("\n");
    }
}

void minimax(int M[5][5], int *maior, int *mmx, int *l, int *c){
    int i, j, linha;
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if(*maior < M[i][j]){
                *maior = M[i][j];
                linha = i;
            }
        }
    }
    for(i=0; i<5; i++){
        if(*mmx <= M[linha][i]){
            *mmx = M[linha][i];
            *l = linha;
            *c = i;
        }
    }
}

int main(){
    int M[5][5];
    gera_matriz(M);
    int maior = 0;
    int mmx = 0, l = 0, c = 0;
    minimax(M, &maior, &mmx, &l, &c);
    printf("\nMinimax: %d\nLinha: %d\nColuna: %d\n", mmx, l, c);
}