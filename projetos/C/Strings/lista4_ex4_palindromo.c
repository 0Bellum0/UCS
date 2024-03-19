/*
4) Escreva uma função em C com o seguinte protótipo

int palindromo(const char str[])

A função deverá retornar 1 caso a string  for palíndromo e 0  caso contrário.  São exemplos de strings palíndromos:

ARARA
ovo
*/

#include<stdio.h>
#include<strings.h>
#include<ctype.h>

#define N 50

void le_str(char str[N]){

    printf("Digite o palindromo: ");
    gets(str);
}

int palindromo(char str[N]){

    int size, i, j, p;
    size = strlen(str);

    for(i=0, j=size-1; i<j; i++, j--){
        if(toupper(str[i]) == toupper(str[j])){
            p = 1;
        }
        else{
            p = 0;
        }
    }
    return p;
}

int main(){

    char str[N];

    le_str(str);
    
    if(palindromo(str)){
        printf("Palavra eh palidromo!");
    }
    else{
        printf("Palavra nao eh palidromo!");
    }
    printf("\n");
}