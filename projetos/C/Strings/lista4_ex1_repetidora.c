/*
1) Fazer um programa que leia uma letra (L) e um número (N), a seguir gere uma string contendo N letras L.
*/

#include<stdio.h>

int main(){
    int N;
    char L;

    printf("Digite uma letra: ");
    scanf("%c", &L);

    printf("Digite a quantidade de vezes: ");
    scanf("%d", &N);
    
    char str[N];
    int i = 0;
    while(i<N){
        str[i] = L;
        i++;
    }
    str[i] = '\0';
    
    printf("String gerada: %s", str);
    printf("\n");
}