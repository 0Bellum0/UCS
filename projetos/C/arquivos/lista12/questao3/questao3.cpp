#include<stdio.h>
#include<stdlib.h>

typedef struct estado{
	char nome[31];
	int numveic;
	int numacid;
}ESTD;

ESTD maior_acidentes(char arquivo[80]){
	ESTD aux, m ={"", 0, 0};
	
	FILE *f = fopen(arquivo, "rb");
	if(f==NULL){
		printf("Erro ao abrir o arquivo %s", arquivo);
		exit(0);
	}
	
	while(fread(&aux, sizeof(ESTD), 1, f)){
		if(aux.numacid > m.numacid){
			m = aux;
		}
	}
	
	fclose(f);
	return m;
}

int main(){
	char arq[80] = "questao3.bin";
	ESTD m = maior_acidentes(arq);
	printf("%s %d\n", m.nome, m.numacid);
}