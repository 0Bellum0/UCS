/*
1) Considere um arquivo texto que contém os nomes e as notas dos alunos de uma disciplina. As informações de cada aluno ocupam duas linhas do arquivo: a primeira linha contém o nome do aluno (com eventuais espaços em branco) e a segunda as três notas obtidas. Conside

Fulano de Tal
6.3 5.7 7.1
Sicrano Silva
3.4 5.4 4.7
Beltrano Alves
9.2 6.8 8.3

Escreva um programa que leia o arquivo “entrada.txt”, que contém as informações dos alunos no formato descrito acima, e imprima na tela o número de alunos aprovados e o número de alunos reprovados. Considere que um aluno é aprovado se obtiver média maior ou igual a cinco. Se não for possível abrir o arquivo, o programa deve ter como saída a mensagem “ERRO”. Para o exemplo ilustrado acima, a saída do programa seria:

Aprovados: 2
Reprovados: 1
*/

#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

int main(){
    char entrada[50] = "3.txt";

    FILE *f = fopen(entrada, "r");
    if(f==NULL){
        printf("Erro ao abrir o arquivo!");
        exit(0);
    }

    char nome[50];
    int a=0, r=0;
    float n1, n2, n3, media;

    while(fgets(nome, 50, f)){
        nome[strlen(nome)-1] = '\0';
        fscanf(f, "%f %f %f\n", &n1, &n2, &n3);
        media = (n1 + n2 + n3)/3;
        if(media>5){
            a++;
        }
        else{
            r++;
        }
    }

    printf("Aprovados: %d\n", a);
    printf("Reprovados: %d\n", r);

    fclose(f);
}