/*
M800) Faça um programa que leia uma matriz M[5][5] e escreva o número da linha que contenha a maior soma de seus elementos. Considere que a matriz só contem valores positivos.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 5

void le_mat(int mat[N][N]){

    int i, j;

    srand(time(NULL));

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            mat[i][j] = rand() % 10;
        }
    }
}

void esc_mat(int mat[N][N]){

    int i, j;

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("% 4d", mat[i][j]);
        }
        printf("\n");
    }
}

int maior_soma(int mat[N][N]){

    int i, j;
    int maior = 0;
    int soma_atual, soma_anterior;

    soma_anterior = 0;
    for(i=0; i<N; i++){
        soma_atual = 0;
        for(j=0; j<N; j++){
            soma_atual += mat[i][j];
        }
        if(soma_atual>soma_anterior){
            soma_anterior = soma_atual;
            maior = i+1;
        }
    }
    return maior;
}

int main(){

    int mat[N][N];

    le_mat(mat);
    esc_mat(mat);
    printf("A maior soma eh da linha: %d", maior_soma(mat));
    printf("\n");
}