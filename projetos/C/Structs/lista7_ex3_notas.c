/*
3) Faça um programa que leia os dados relativos a N alunos (o valor N é definido pela diretiva #define), cada aluno contendo as seguintes informações:

nome: até 50 caracteres
nota1: float
nota2: float
nota3: float

Após a entrada dos dados o programa deve escrever o nome e a média aritmética dos alunos. Os alunos devem estar organizados em ordem decrescente em relação a média final e se dois alunos tiverem a mesma  média eles deverão ser organizados em ordem alfabética. Por exemplo, considerando um valor de N=6 e para as entradas

Fábio Cunha Lima 
3.4 5.6 6.6
Rafaela Azevedo Gomes 
5.6 6.5 7.2
Marina Goncalves Martins 
6.5 7.5 8.5
Murilo Pereira Correia 
8.0 7.0 7.5
Otávio Santos Souza 
7.2 8.0 8.2
Júlia Oliveira Correia 
5.1 7.5 6.0

o programa deve produzir a seguinte saída:

Otávio Santos Souza 7.8
Marina Goncalves Martins 7.5
Murilo Pereira Correia 7.5
Rafaela Azevedo Gomes 6.4
Júlia Oliveira Correia 6.2
Fábio Cunha Lima 5.2
*/

#include<stdio.h>

#define N 6

typedef struct alunos{
    char nome[50];
    float n1;
    float n2;
    float n3;
    float media;
}ALUNO;

void le_notas(ALUNO aluno[N]){

    int i;

    for(i=0; i<N; i++){
        printf("Digite o nome do aluno: ");
        gets(aluno[i].nome);

        printf("Digite a nota 1: ");
        scanf("%f", &aluno[i].n1);

        printf("Digite a nota 2: ");
        scanf("%f", &aluno[i].n2);
        
        printf("Digite a nota 3: ");
        scanf("%f", &aluno[i].n3);

        printf("\n");
        fflush(stdin);
    }
}

void calc_media_n_sort(ALUNO aluno[N]){

    int i, j;
    ALUNO aux;

    for(i=0; i<N; i++){
        aluno[i].media = (aluno[i].n1 + aluno[i].n2 + aluno[i].n3) / 3;
    }

    for(i=0; i<N; i++){
        for(j=0; j<N-1; j++){
            if(aluno[j].media < aluno[j+1].media ||
            aluno[j].media == aluno[j+1].media && strcasecmp(aluno[j].nome, aluno[j+1].nome)>0){
                aux = aluno[j];
                aluno[j] = aluno[j+1];
                aluno[j+1] = aux;
            }
        }
    }
}

void lista_alunos(ALUNO aluno[N]){

    int i;

    for(i=0; i<N; i++){
        printf("Aluno: %s\nMedia: %.2f\n", aluno[i].nome, aluno[i].media);
        printf("\n");
    }
}

int main(){

    ALUNO aluno[N];

    le_notas(aluno);
    calc_media_n_sort(aluno);
    lista_alunos(aluno);
    printf("\n");
}