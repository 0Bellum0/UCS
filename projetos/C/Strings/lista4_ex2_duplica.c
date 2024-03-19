/*
2) Fazer um programa que leia uma palavraing e a partir desta gere uma nova duplicando cada caracter da palavraing original. Escreva a nova palavraing. Por exemplo, para as palavraings abaixo, o programa deverá escrever:

"OI" => "OOII"
"PROVA 1" => "PPRROOVVAA 11".
*/

#include<stdio.h>

void le_e_duplica(char palavra[50], char palavra_nova[100]){

    int i, j;

    printf("Digite a palavra: ");
    gets(palavra);

    for(i=0, j=0; i<50; i++){
        palavra_nova[j++] = palavra[i];
        palavra_nova[j++] = palavra[i];
    }
    palavra_nova[j] = '\0';

    printf("%s", palavra_nova);
}

int main(){

    char palavra[50];
    char palavra_nova[100];

    le_e_duplica(palavra, palavra_nova);
    printf("\n");
}