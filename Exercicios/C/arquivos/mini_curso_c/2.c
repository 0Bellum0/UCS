#include<stdio.h>
#include<stdlib.h>

int main(){
    char entrada[50] = "2.bin";
    char saida[50] = "2.txt";

    FILE *f = fopen(entrada, "rb");

    if(f==NULL){
        printf("Erro ao ler o arquivo!");
        exit(0);
    }

    int conceitos[5] = {0, 0, 0, 0, 0};
    int i, j, n;

    while(fread(&n, sizeof(int), 1, f)){
        conceitos[n-1]++;
    }

    fclose(f);

    FILE *s = fopen(saida, "w");

    for(i=0; i<5; i++){
        fprintf(s, "%d ", i+1);
        for(j=0; j<=conceitos[i]; j++){
            fprintf(s, "*");
        }
        fprintf(s, "\n");
    }

    fclose(s);
}