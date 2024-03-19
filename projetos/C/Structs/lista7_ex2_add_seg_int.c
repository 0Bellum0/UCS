/*
2) Faça uma função que receba uma hora como parâmetro e retorne uma nova estrutura com a hora mais um segundo. O tipo HORA foi criado a partir de uma estrutura que armazena os valores para a hora, minuto e segundo conforme o código a seguir: 

struct hora {
     int hora;
     int minutos;
     int segundo;
};
typedef struct hora HORA;

A função deve ter o seguinte protótipo:

HORA adicionaSegundo(HORA horaAtual)

O programa de teste deve ler 5 horas e retornar, após  leitura, a hora com um segundo a mais para cada uma. 

12 12 2
Segundo a mais: 12:12:03
23 59 59
Segundo a mais: 00:00:00
14 59 59
Segundo a mais: 15:00:00
15 12 59
Segundo a mais: 15:13:00
8 12 45
Segundo a mais: 08:12:46
*/

#include<stdio.h>

#define N 5
typedef struct hora{
     int hora;
     int min;
     int seg;
}HORA;

void le_horario(HORA hora_atual[N]){

     int i;

     for(i=0; i<N; i++){
          printf("Digite o horario: ");
          scanf("%d:%d:%d", &hora_atual[i].hora, &hora_atual[i].min, &hora_atual[i].seg);
          printf("\n");
     }
     printf("\n");
}

void add_segundo(HORA hora_atual[N], int soma[N]){

     int i;

     for(i=0; i<N; i++){
          soma[i] = (hora_atual[i].hora * 3600) + (hora_atual[i].min * 60) + hora_atual[i].seg + 1;
     }

     for(i=0; i<N; i++){
          hora_atual[i].hora = soma[i]/3600;
          soma[i] = soma[i] % 3600;
          hora_atual[i].min = soma[i]/60;
          soma[i] = soma[i] % 60;
          hora_atual[i].seg = soma[i];
          if(hora_atual[i].hora == 24 && hora_atual[i].min == 0 && hora_atual[i].seg == 0){
               hora_atual[i].hora = 0;
               hora_atual[i].min = 0;
               hora_atual[i].seg = 0;
          }
     }

     for(i=0; i<N; i++){
          printf("%.2d:%.2d:%.2d", hora_atual[i].hora, hora_atual[i].min, hora_atual[i].seg);
          printf("\n");
     }
}

int main(){

     HORA hora_atual[N];
     int soma[N];

     le_horario(hora_atual);
     add_segundo(hora_atual, soma);
     printf("\n");
}