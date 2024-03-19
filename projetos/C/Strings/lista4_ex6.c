/*
6)  Escreva uma função em C com o seguinte protótipo

int str2int(const char str[])

que receba uma string com um número válido, após converta o número lido para decimal, armazenando-o em uma variável inteira e a retorne.
*/

/*tabela ascii --> '0' a '9' --> 48 a 57*/

#include<stdio.h>

#define N 50

void le_str(char str[N]){

    printf("Digite o numero: ");
    gets(str);
}

int str_to_int(char str[N]){

    int i, dec;

    dec = 0;
    for(i=0; str[i]!='\0'; i++){
        dec = dec*10 + (str[i]-'0');
    }
    return dec;
}

int main(){

    char str[N];

    le_str(str);
    printf("Numero em int: %d", str_to_int(str));
    printf("\n");
}