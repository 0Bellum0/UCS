/*
7) Escreva numa função em C com o seguinte protótipo

int int2str(int num, char str[])

que receba num número inteiro positivo e armazene os dígitos do mesmo em numa string recebida por parâmetro.
*/

#include<stdio.h>
#include<strings.h>

#define N 50

void fix_order(char str[N]){

    int i, j, aux, size;

    size = strlen(str);

    for(i=0, j=size; i<j; i++, j--){
        aux = str[i];
        str[i] = str[j];
        str[j] = aux;
    }
}

void int_to_str(int num, char str[N]){

    int i, size;

    i = 0;
    while(num>0){
        str[i++] = (num % 10) + '0';
        num /= 10;
    }
    str[i] = '\0';

    fix_order(str);
}

int main(){

    int num;
    char str[N];

    printf("Digite um numero: ");
    scanf("%d", &num);

    int_to_str(num, str);
    printf("Numero: %s", str);
    printf("\n");
}