/*
3) Fazer um programa que leia uma string e a partir desta gere uma nova contendo um espaço em branco entre cada caracter da string original. Escreva a nova string. Por exemplo, para a string 

"LIVRO DE C"

o programa deverá gerar a string:

"L I V R O D E C"
*/

#include<stdio.h>

#define N 50

void le_str(char str[N]){

    printf("Digite a string: ");
    gets(str);

    printf("\n");
}

void space(char str[N], char str_2[N]){

    int i, j;

    for(i=0, j=0; i<N; i++){
        if(str[i] == ' '){
            continue;
        }
        str_2[j++] = str[i];
        str_2[j++] = ' ';
    }
    str_2[j] = '\0';

    printf("Nova string: %s", str_2);
}

int main(){
    char str[N], str_2[N];

    le_str(str);
    space(str, str_2);
    printf("\n");
}