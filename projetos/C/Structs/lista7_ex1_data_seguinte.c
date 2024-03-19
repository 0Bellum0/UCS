/*
Faça uma função que receba uma data como parâmetro e retorne uma nova estrutura com o dia seguinte. O tipo DATA foi criado a partir de uma estrutura que armazena os valores para dia, mês e ano conforme o código a seguir: 

struct data {
     int dia;
     int mes;
     int ano;
};
typedef struct data DATA;

A função deve ter o seguinte protótipo:

DATA proximoDia (DATA diaAtual)

Cuidado com os anos bissextos (múltiplos de 400 ou múltiplos de 4, mas não múltiplo de 100). O programa de teste deve ler N datas e retornar o próximo dia para cada dia após a leitura. 

11 1 2023
Dia seguinte: 12/01/2023
28 2 2023
Dia seguinte: 01/03/2023
28 2 2024
Dia seguinte: 29/02/2023
31 12 2022
Dia seguinte: 01/01/2023
31 10 2022
Dia seguinte: 01/11/2022
*/

#include<stdio.h>

#define N 5

typedef struct data{
    int dia;
    int mes;
    int ano;
}DATA;

DATA datas_testadas(DATA data_atual[N]){

    int i; 

    printf("Digite cinco datas: ");
    for(i=0; i<N; i++){
        scanf("%d/%d/%d", &data_atual[i].dia, &data_atual[i].mes, &data_atual[i].ano);
    }
}

DATA proximo_dia(DATA data_atual[N], DATA data_seguinte[N]){

    int i;

    for(i=0; i<N; i++){
        if(data_atual[i].dia == 31 && data_atual[i].mes == 1 
        || data_atual[i].mes == 3
        || data_atual[i].mes == 5
        || data_atual[i].mes == 7
        || data_atual[i].mes == 8
        || data_atual[i].mes == 10){

            data_seguinte[i].dia = 1;
            data_seguinte[i].mes = data_atual[i].mes + 1;
            data_seguinte[i].ano = data_atual[i].ano;

        }
        else if(data_atual[i].dia == 30 && data_atual[i].mes == 4
        || data_atual[i].mes == 6
        || data_atual[i].mes == 9
        || data_atual[i].mes == 11){

            data_seguinte[i].dia = 1;
            data_seguinte[i].mes = data_atual[i].mes + 1;
            data_seguinte[i].ano = data_atual[i].ano;

        }
        else if(data_atual[i].dia == 31 && data_atual[i].mes == 12){
            data_seguinte[i].dia = 1;
            data_seguinte[i].mes = 1;
            data_seguinte[i].ano = data_atual[i].ano + 1;
        }
        else if(data_atual[i].dia == 28 && data_atual[i].mes == 2 && (data_atual[i].ano % 4 == 0)){
            data_seguinte[i].dia = 1;
            data_seguinte[i].mes = 3;
            data_seguinte[i].ano = data_atual[i].ano;
        }
        else{
            data_seguinte[i].dia = data_atual[i].dia + 1;
            data_seguinte[i].mes = data_atual[i].mes;
            data_seguinte[i].ano = data_atual[i].ano;
        }
    }
}

DATA esc_datas(DATA data_atual[N], DATA data_seguinte[N]){

    int i;

    for(i=0; i<N; i++){
        printf("Data digitada: %d/%d/%d", data_atual[i].dia, data_atual[i].mes, data_atual[i].ano);
        printf("\n");
        printf("Data seguinte: %d/%d/%d", data_seguinte[i].dia, data_seguinte[i].mes, data_seguinte[i].ano);
        printf("\n\n");
    }
}

int main(){

    DATA data_atual[N];
    DATA data_seguinte[N];

    datas_testadas(data_atual);
    proximo_dia(data_atual, data_seguinte);
    esc_datas(data_atual, data_seguinte);
    printf("\n");
}