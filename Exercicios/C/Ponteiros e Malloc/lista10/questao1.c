/*
1) Fazer uma função que gere e retorne uma string S com N caracteres C. O protótipo da função é dado por:

char * gerastr(int n, char c)
*/

#include<stdio.h>
#include<stdlib.h>

char * gera_string(int n, char c){
    int i;
    char * str = NULL;
    str = (char *)malloc((n+1) * sizeof(char));
    for(i=0; i<n; i++){
        printf("\n%c\n", c);
        str[i] = c;
    }
    str[i] = '\0';
    return str;
}

int main(){
    int n;
    char c;
    char * str = NULL;
    printf("\nDigite o caractere: ");
    scanf("%c", &c);
    printf("\nDigite a quantidade de vezes que se repetira: ");
    scanf("%d", &n);
    str = gera_string(n, c);
    printf("\n%s\n", str);
}