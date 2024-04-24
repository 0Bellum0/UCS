#include <stdio.h>
#include <stdlib.h>

struct elemento2 {
	int info;
	struct elemento2 *prox, *ant;
};

typedef struct elemento2 Elemento2;

Elemento2 *inicio2;

void insereprimeiro(int valor){
	Elemento2 *novo;	
	novo = (Elemento2*) malloc(sizeof(Elemento2));
	novo->info = valor;
	novo->prox = NULL;
	novo->ant = NULL;
	if(inicio2==NULL) // inserção do primeiro e único
		inicio2 = novo;
	else { //inserção do primeiro
		novo->prox = inicio2;
		inicio2->ant = novo;
		inicio2 = novo;
	}	
}

void insereultimo(int valor){
	Elemento2 *novo, *aux=inicio2;
	novo = (Elemento2*) malloc(sizeof(Elemento2));
	novo->info = valor;
	novo->prox = NULL;
	novo->ant = NULL;
	if (inicio2==NULL)
		inicio2=novo;
	else{
		while (aux->prox != NULL)
			aux = aux->prox;
		aux->prox = novo;
		novo->ant = aux;
	}
}

void insereordenado(int valor){
	Elemento2 *novo,*anterior,*aux=inicio2;	
	novo = (Elemento2*) malloc(sizeof(Elemento2));
	novo->info = valor;
	novo->prox = NULL;
	novo->ant = NULL;
	if(inicio2==NULL) // inserção do primeiro e único
		inicio2 = novo;
	else { //inserção do primeiro
		if (valor<=inicio2->info){
			novo->prox = inicio2;
			inicio2->ant = novo;
			inicio2 = novo;
		}
		else{
			while (aux != NULL && aux->info < valor ){
				anterior=aux;
				aux = aux->prox;
			}
			if(aux==NULL){ //inserção no fim
				anterior->prox=novo;
				novo->ant=anterior;
			}
			else{
				novo->prox=aux;
				novo->ant=anterior;
				anterior->prox=novo;
				aux->ant=novo;
			}
		}
	}	
}

void remove(int valor){
	Elemento2 *aux=inicio2;	
	
	if(inicio2!=NULL){
		if(inicio2->info==valor){
			inicio2=inicio2->prox; //primeiro
			if(inicio2!=NULL)
				inicio2->ant=NULL; //primeiro e tem outros
			free(aux);
		}
		else{
			while(aux!=NULL && aux->info!=valor)
				aux=aux->prox;
			if(aux!=NULL){
				if(aux->prox==NULL) //remove último
					(aux->ant)->prox=NULL;
				else{ //remove "no meio"
					(aux->ant)->prox=aux->prox;
					(aux->prox)->ant=aux->ant;
				}
				free(aux);
			}
			else
				printf("\nvalor %d nao esta na lista\n\n",valor);
		}
	}
}

void escreve(){
	Elemento2 *aux=inicio2;
	printf("\nLista:\n");
	while(aux!=NULL){
		printf("%d (%ld) ",aux->info,aux);
		aux=aux->prox;
	}
}

int main(){
	inicio2=NULL;
	
/*	insereprimeiro(3);
	escreve();
	insereprimeiro(5);
	escreve();
	insereprimeiro(1);
	escreve();
	insereultimo(2);
	escreve();*/
	insereordenado(10);
	escreve();
	insereordenado(1);
	escreve();
	insereordenado(10);
	escreve();
	insereordenado(6);
	escreve();
	insereordenado(7);
	escreve();
	remove(1);
	escreve();
	remove(10);
	escreve();
	remove(7);
	escreve();
	remove(5);
	escreve();
	remove(10);
	escreve();
	remove(6);
	escreve();

}
