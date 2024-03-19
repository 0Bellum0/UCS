/*
TAD jogo{
Dados: 
    lista de cartas
Operações:
          recebe_carta(E: carta);
          ver_lista_cartas(S: lista de cartas);
          ver_lista_cartas_invertida(S: lista de cartas);
}

Tarefa:

Considere a implementação das cartas recebidas em um jogo como um vetor de 9 posições. Fazer um menu de operações, para o usuário selecionar:

- implementar a operação de recebe_carta(...), na qual é realizada a inserção de um valor de forma ordenada no vetor (não utilize um método de ordenação, cada inserção deve ser feita na sua posição considerando a ordem). Deve ser controlado o número de cartas inserido, para não ultrapassar 9 (se ultrapassar, mostrar mensagem de erro). A ordenação deve ser em ordem crescente de valores, ou seja, a cada inserção de uma nova carta, ela deve ser colocada na sua posição correta na lista. Pode haver valores repetidos na lista, cada baralho tem 4 cartas de mesmo valor (considere ou não separação por naipes). O valor das cartas deve estar entre 1 e 13.

- implementar a operação ver_lista_cartas(...), que exiba a lista de cartas armazenada (exibir os valores das cartas em ordem crescente). --> tentar uma implementação recursiva
- implementar a operação ver_lista_cartas_invertida(...), que exiba a lista de cartas (exibir os valores das cartas)  em ordem decrescente de valores.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 9

void menu(int vet[N]){

    int opt = 1;

    int total = 0;

    while(total<N){
        
        printf("\nDeseja realizar qual ação?\n");
        printf("1 - Receber cartas.\n");
        printf("2 - Listar cartas.\n");
        printf("3 - Inverter cartas.\n");
        printf("4 - Encerrar programa!\n");
        //scanf("%d", &opt);

        switch(opt){
            case 1:
                recebe_carta(vet);
                break;
            case 2:
                listar_cartas(vet);
                break;
            case 3:
                listar_cartas_inv(vet);
                break;
            case 4:
                break;
            default:
                printf("Selecione uma opção válida!");
                break;
        }
        if(opt==4){
            break;
        }
        total++;
    }
}

void recebe_carta(int vet[N]){

    int i, j, aux1, aux2;

    int carta = rand() %13;
    printf("\nSua carta é: %d\n", carta);
    for(i=0; i<N; i++){
        if(carta < vet[i]){
            aux1 = vet[i];
            vet[i] = carta;
            for(j=i+1; j<N; j++){
                if(aux1 < vet[j]){
                    aux2 = vet[j];
                    vet[j] = aux1;
                    aux1 = aux2;
                }
            }
        }
    }
}

void listar_cartas(int vet[N]){
    int i;
    printf("\nCartas: ")
    for(i=0; i<N; i++){
        if(i==N-1){
            printf("%d", &vet[i]);
        }
        else{
            printf("%d, ", &vet[i]);
        }
    }
}

void listar_cartas_inv(int vet[N]){
    int i;
    printf("\nCartas invertidas: ")
    for(i=8; i<N; i--){
        if(i==0){
            printf("%d", &vet[i]);
        }
        else{
            printf("%d, ", &vet[i]);
        }
}

void main(){

    int vet[N];

    srand(time(NULL));

    menu(vet);
}

/*
switch(opt){
            case 1:
                ;

            case 2:
                ;

            case 3:
                ;

            case 4:
                ;

            case 5:
                ;

            case 6:
                ;

            case 7:
                ;

            case 8:
                ;

            case 9:
                ;

            case 10:
                ;

            case 11:
                ;

            case 12:
                ;

            case 13:
                ;

            default:
                break;
        }
*/