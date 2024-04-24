/*
4) Faça uma função que receba como parâmetro uma matriz M[5][5] e retorne o maior valor existente na matriz, bem como a linha e coluna onde o valor ocorre.
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void matriz(int M[5][5]){
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
    printf("\n");
}

void maior_valor(int M[5][5], int *maior, int *c, int *l, int *co){
    int i, j, count = 0;
    int linha = 0, coluna = 0;
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if(*maior < M[i][j]){
                *maior = M[i][j];
                linha = i;
                coluna = j;
            }
        }
    }
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if(*maior == M[i][j]){
                count++;
            }
        }
    }
    *c = count;
    *l = linha;
    *co = coluna;
}

int main(){
    int M[5][5];
    int maior = 0;
    int c = 1, l = 0, co = 0;
    matriz(M);
    maior_valor(M, &maior, &c, &l, &co);
    printf("Maior: %d\nAparece %d vezes\n", maior, c);
    printf("Linha: %d\nColuna: %d\n", l+1, co+1);
}