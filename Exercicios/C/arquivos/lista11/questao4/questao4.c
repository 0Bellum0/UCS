/*
4) Faça um programa que permita calcular o custo de uma lista de compras. O programa possui como entrada um arquivo texto que na primeira linha possui um inteiro M que indica a quantidade de produtos que estão disponíveis para venda. Seguem os M produtos com seus preços respectivos por unidade ou Kg. A próxima linha de entrada contém um inteiro P que indica a quantidade de diferentes produtos que serão comprados, sendo que após P linhas contendo cada uma delas um texto (com até 50 caracteres) e um valor inteiro, que indicam respectivamente o nome de cada produto e a quantidade deste produto. Abaixo um exemplo de um arquivo de entrada.

4
mamao 2.19
cebola 3.10
tomate 2.80
uva 2.73
3
mamao 2
tomate 1
uva 3

Como saída gere um arquivo texto com o valor que será gasto no seguinte formato: R$ seguido de um espaço e seguido do valor, com 2 casas decimais, conforme o exemplo abaixo.

R$ 15.37
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct itens{
    char item[50];
    float valor;
    int qtd;
}BAG;

int main(){
    char entrada[15] = "questao4.txt";
    char saida[13] = "saida.txt";

    FILE *f = fopen(entrada, "r");
    if(f==NULL){
        printf("Erro - entrada");
        exit(0);
    }

    int i, n, n2, j=0;

    fscanf(f, "%d", &n);
    BAG itens[n];
    for(i=0; i<n; i++){
        fgets(itens[j].item, 50, f);
        fscanf(f, "%f", &itens[j].valor);
        j++;
    }
    fscanf(f, "%d", &n2);
    BAG aux[n2];
    for(i=0; i<n2; i++){
        for(j=0; j<n; j++){
            if(fgets(aux[i].item, 50, f) == itens[j].item){
            fscanf(f, "%d", &itens[j].qtd);
            }
        }
    }

    fclose(f);

    FILE *s = fopen(saida, "w");
    if(s==NULL){
        printf("Erro - saida");
        exit(0);
    }

    float total = 0;
    for(i=0; i<n2; i++){
        for(j=0; j<n; j++){
            if(aux[i].item == itens[j].item){
                total += (itens[j].qtd * itens[j].valor);
            }
        }
    }
    fprintf(s, "%.2f", total);
    fclose(s);
}