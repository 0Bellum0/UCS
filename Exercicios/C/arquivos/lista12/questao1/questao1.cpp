#include<stdio.h>
#include<stdlib.h>

#define N 50

int main(){
	
	FILE *f = NULL;
	char entrada[N];
	char saida[N];
	
	printf("Digite o nome do arquivo: ");
	gets(entrada);
	
	f = fopen(entrada, "rb");
	
	if(f==NULL){
		printf("Erro ao abrir o arquivo: %s\n", entrada);
		exit(0);
	}
	
	float n, soma=0, m;
	int r, c=0, i;
	
	while(fread(&n, sizeof(float), 1, f)){
		printf("%f\n", n);
		soma += n;
		c++;
	}
	
	m = soma/c;
	
	printf("R= %d N= %f\nSoma= %f\nMedia= %f\n", r, n, soma, m);
	
	rewind(f);
	
	float *valores = (float *)malloc(c*sizeof(float));
	fread(valores, sizeof(float), c, f);
	
	printf("\nDigite o nome do arquivo de saida: ");
	gets(saida);
	
	FILE *s = fopen(saida, "w");
	
	if(s==NULL){
		printf("Erro ao abrir o arquivo %s\n", saida);
		exit(0);
	}
	
	for(i=0; i<c; i++){
		fread(&n, sizeof(float), 1, f);
		if(valores[i]>=m){
			fprintf(s, "%f\n", valores[i]);
		}
	}
	
	fclose(f);
	fclose(s);
	free(valores);
}