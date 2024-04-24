/*
M100) Faça um programa que leia uma matriz M[5][5] e calcule e escreva a soma dos elementos da diagonal principal.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 5

void le_mat(int mat[N][N]){
    int i, j;

    srand(time(NULL));

    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            mat[i][j] = rand() % 10;
        }
    }
}

int esc_mat(int mat[N][N]){
    int i, j, soma;

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("% 4d", mat[i][j]);
        }
        printf("\n");
    }

    soma = 0;
    for(i=0; i<N; i++){
        j = i;
        soma += mat[i][j];
    }
    return soma;
}

int main(){
    int mat[N][N];

    le_mat(mat);
    printf("Soma: %d", esc_mat(mat));
    printf("\n");
}