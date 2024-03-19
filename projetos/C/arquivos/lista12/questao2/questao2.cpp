#include<stdio.h>
#include<stdlib.h>

int main(){
	
	char entrada[50] = "questao2.bin";
	char saida[50] = "saida2.txt";

	FILE *f = fopen(entrada, "rb");
	
	if(f==NULL){
		printf("Erro na abertura do arquivo!");
		exit(0);
	}
	
	int n, i, j;
	int c[6] = {0,0,0,0,0,0};
	
	while(fread(&n, sizeof(int), 1, f)){
		c[n]++;
	}
	
	FILE *s = fopen(saida, "w");
	
	if(s==NULL){
		printf("Erro ao abrir o arquivo!");
	}
	
	for(i=1; i<6; i++){
		fprintf(s, "%d ", i);
		for(j=0; j<c[i]; j++){
			fprintf(s, "*");
		}
		fprintf(s, "\n");
	}
	
	fclose(f);
	fclose(s);
}