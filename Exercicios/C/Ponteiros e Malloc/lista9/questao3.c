/*
3) Fazer uma função que calcule a partir de um horário inicial (hora e minuto) mais uma quantidade de minutos, o horário correspondente ao horario inicial adicionado a essa quantidade de minutos. Protótipo: 

void calc_horario(int h1, int m1, int qtdmin, int *h2, int *m2)
*/

#include<stdio.h>


void calc_horario(int hi, int mi, int qtdmin, int *hf, int *mf){
    int aux = ((hi*60) + mi + qtdmin);
    *hf = aux/60;
    aux %= 60;
    *mf = aux;
}

int main(){
    int hi, mi, hf, mf, qtdmin;
    hi = 22;
    mi = 30;
    hf = 0;
    mf = 0;
    printf("\nDigite a qtdmin: ");
    scanf("%d", &qtdmin);
    calc_horario(hi, mi, qtdmin, &hf, &mf);
    printf("%d:%.2d\n", hf, mf);
}