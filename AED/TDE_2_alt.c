#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 9

void recebe_carta(int vet[N]){

    int i, j, b=0, aux1, aux2;
    
    srand(time(NULL));

    int carta = rand() %13;
    while(carta == 0){
        carta = rand() %13;
    }
    
    printf("\nSua carta é: %d\n", carta);
    
    for(i=0; i<N; i++){
    //implementar insersão no último espaço disponível no vetor e depois comparar com os anteriores. (A principio esta implementação usa somente um laço.)    
    }
}

void listar_cartas(int vet[N]){
    int i;
    printf("\nCartas: ");
    for(i=0; i<N; i++){
        if(i==N-1){
            printf("%d\n", vet[i]);
        }
        else{
            printf("%d, ", vet[i]);
        }
    }
}

void listar_cartas_inv(int vet[N]){
    int i;
    printf("\nCartas invertidas: ");
    for(i=8; i>=0; i--){
        if(i==0){
            printf("%d\n", vet[i]);
        }
        else{
            printf("%d, ", vet[i]);
        }
    }
}

void menu(int vet[N]){

    int opt = 0;

    int total = 0;

    while(opt!=4){
        
        printf("\nDeseja realizar qual ação?\n");
        printf("1 - Receber cartas.\n");
        printf("2 - Listar cartas.\n");
        printf("3 - Inverter cartas.\n");
        printf("4 - Encerrar programa!\n");
        scanf("%d", &opt);

        switch(opt){
            case 1:
                if(total==N){
                    printf("Limite de cartas atingido!\n");
                    break;
                }
                recebe_carta(vet);
                total++;
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
                printf("Selecione uma opção válida!\n");
                break;
        }
    }
}

int main(){
    int vet[N];
    for(int i=0; i<N; i++){
        vet[i] = 0;
    }
    menu(vet);
    return 1;
}