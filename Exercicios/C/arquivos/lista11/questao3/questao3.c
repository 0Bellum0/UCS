/*
3)  Dado um arquivo com o seguinte formato:

5
123.987.098-09
RODRIGO DA SILVA
1500.78
CONTABILIDADE
454.283.731.99
RODRIGO DE SOUZA 
567.00
PRODUCAO
723.987.098-15
PEDRO PAULO RANGEL
500.00
TESOURARIA
123.987.098-09
MARIA MENDONÇA DE SOUZA
400.15
FATURAMENTO
456.987.098-11
FELIPE DE MATTOS
700.76
CONTABILIDADE

onde o primeiro número (5 no exemplo) corresponde ao número de funcionários e para cada funcionário tem-se: CPF, nome, salário e departamento. Gerar um novo arquivo texto com as mesmas informações mas com os funcionários escreve_ordenadodos de acordo com o nome (um funcionário por linha).
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct funcionario{
    char cpf[16];
    char nome[50];
    float salario;
    char setor[30];
}FUN;


int conta(char entrada_conta[13]){

    FILE *f = fopen(entrada_conta, "r");
    if(f==NULL){
        printf("Erro - entrada_conta!\n");
        exit(0);
    }

    int N;

    fscanf(f, "%d", &N);

    fclose(f);
    return N;

}

void ler(char entrada_ler[13], FUN pf[]){

    FILE *f = fopen(entrada_ler, "r");
    if(f==NULL){
        printf("Erro - entrada_ler\n");
        exit(0);
    }

    int i, j=0, n;

    fscanf(f, "%d\n", &n);
    for(i=0; i<n; i++){
        fgets(pf[j].cpf, 16, f);
        pf[j].cpf[strlen(pf[j].cpf)-1] = '\0';
        fgets(pf[j].nome, 50, f);
        pf[j].nome[strlen(pf[j].nome)-1] = '\0';
        fscanf(f, "%f\n", &pf[j].salario);
        fgets(pf[j].setor, 30, f);
        pf[j].setor[strlen(pf[j].setor)-1] = '\0';
        j++;
    }
    fclose(f);
}

void escreve_ordenado(char saida[10], FUN pf[], int num){

    FILE *s = fopen(saida, "w");
    if(s==NULL){
        printf("Erro - saida\n");
        exit(0);
    }

    int i;
    for(i=0; i<num; i++){
        fprintf(s, "%s\n", pf[i].cpf);
        fprintf(s, "%s\n", pf[i].nome);
        fprintf(s, "%.2f\n", pf[i].salario);
        fprintf(s, "%s\n", pf[i].setor);
        if(i!=4){fprintf(s, "\n");
        }
    }
    fclose(s);
}

int main(){
    char entrada[13] = "questao3.txt";
    char saida[10] = "saida.txt";

    int num;
    num = conta(entrada);

    FUN funcionarios[num];

    ler(entrada, funcionarios);
    escreve_ordenado(saida, funcionarios, num);
}