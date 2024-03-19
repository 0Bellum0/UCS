/*
2) Fazer uma função que retorne os dois dígitos verificadores do cpf informado como parâmetro (inteiro).
*/

#include<stdio.h>

int final_cpf(char cpf[20], int *dg_vf){
    *dg_vf += (cpf[12] - '0') * 10;
    *dg_vf += (cpf[13] - '0');
    return *dg_vf;
}

int main(){
    char cpf[20];
    printf("Digite seu cpf: ");
    gets(cpf);
    int dg_vf = 0;
    final_cpf(cpf, &dg_vf);
    printf("\n%d\n", dg_vf);
}