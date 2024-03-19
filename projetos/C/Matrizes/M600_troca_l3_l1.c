/*
M600)  Faça um programa que leia uma matriz M[5][5] e troque cada elemento da linha 3 com elemento correspondente da linha 1. Escreva a matriz resultante.
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

void troca_linhas(int mat[N][N]){

    int i, j, aux;

    i=2;
    while(i==2){
        for(j=0; j<N; j++){
            aux = mat[0][j];
            mat[0][j] = mat[i][j];
            mat[i][j] = aux;
        }
        i++;
    }
}

int main(){

    int mat[N][N];

    le_mat(mat);
    esc_mat(mat);
    printf("\n");
    troca_linhas(mat);
    esc_mat(mat);
    printf("\n");
}