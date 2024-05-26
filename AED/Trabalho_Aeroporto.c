#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Aviao {
    char id[6]; // Formato: LLNNN (BC123)
    int aterrissagens;
    int decolagens;
    struct Aviao *prox;
} Aviao;

typedef struct ListaAvioes {
    char letra;
    Aviao *lista;
    struct ListaAvioes *prox;
} ListaAvioes;

typedef struct Fila {
    /*Aviao *frente;
    Aviao *tras;*/
    Aviao queue[50];
    int ini, fim;
} Fila;

typedef struct Relatorio {
    char id[6];
    char operacao; // "D - decolagem" ou "A - aterrissagem"
    time_t horario;
    struct Relatorio *prox;
} Relatorio;

typedef struct Aeroporto {
    ListaAvioes *ldisp;
    Fila fate;
    Fila fdec;
    Relatorio *relatorio;
} Aeroporto;

void inicializa_aeroporto(Aeroporto *aeroporto){
    aeroporto->ldisp = NULL;
    aeroporto->relatorio = NULL;
    /*aeroporto->fate.frente = NULL;
    aeroporto->fate.tras = NULL;
    aeroporto->fdec.frente = NULL;
    aeroporto->fdec.tras = NULL;*/
    aeroporto->fate.ini = 0;
    aeroporto->fate.fim = 0;
}

Aviao *cria_aviao(char *id){
    Aviao *novo = (Aviao*)malloc(sizeof(Aviao));
    strcpy(novo->id, id);
    novo->aterrissagens = 0;
    novo->decolagens = 0;
    novo->prox = NULL;
    return novo;
}

void insere_na_lista(ListaAvioes **ldisp, Aviao *aviao){
    char letra = aviao->id[0];
    ListaAvioes *atual = *ldisp;
    ListaAvioes *anterior = NULL;

    while(atual != NULL && atual->letra < letra){
        anterior = atual;
        atual = atual->prox;
    }

    if(atual == NULL || atual->letra != letra){
        ListaAvioes *novo = (ListaAvioes*)malloc(sizeof(ListaAvioes));
        novo->letra = letra;
        novo->lista = aviao;
        novo->prox = atual;
        if(anterior == NULL){
            *ldisp = novo;
        } else {
            anterior->prox = novo;
        }
    } else {
        Aviao *avioes = atual->lista;
        while(avioes->prox != NULL){
            avioes = avioes->prox;
        }
        avioes->prox = aviao;
    }
}

void cadastra_aviao(Aeroporto *aeroporto, char *id){
    Aviao *aviao = cria_aviao(id);
    insere_na_lista(&(aeroporto->ldisp), aviao);
}

Aviao *busca_aviao(ListaAvioes *ldisp, char *id){
    char letra = id[0];
    while(ldisp != NULL && ldisp->letra < letra){
        ldisp = ldisp->prox;
    }
    if(ldisp == NULL || ldisp->letra != letra){
        return NULL;
    }
    Aviao *aviao = ldisp->lista;
    while(aviao != NULL && strcmp(aviao->id, id) != 0){
        aviao = aviao->prox;
    }
    return aviao;
}

void enfileira(Fila *fila, Aviao *aviao){
    if(fila->fim + 1 == sizeof(fila->queue)) {
        printf("Fila cheia!\n");
        return;
    }
    for(int i = fila->fim; i > 0; i--) {
        fila->queue[i] = fila->queue[i-1];
    }
    fila->queue[0] = *aviao;
    fila->fim++;
}

Aviao* desenfileira(Fila *fila){
    if(fila->fim == 0) {
        printf("Fila vazia!\n");
        return NULL;
    }
    Aviao *aviaoRemovido = (Aviao*)malloc(sizeof(Aviao));
    memcpy(aviaoRemovido, &(fila->queue[0]), sizeof(Aviao));
    for(int i = 0; i < fila->fim - 1; i++) {
        fila->queue[i] = fila->queue[i+1];
    }
    
    fila->fim--;
    return aviaoRemovido;
}

void insere_relatorio(Relatorio **relatorio, char *id, char operacao){
    Relatorio *novo = (Relatorio*)malloc(sizeof(Relatorio));
    strcpy(novo->id, id);
    novo->operacao = operacao;
    novo->horario = time(NULL);
    novo->prox = *relatorio;
    *relatorio = novo;
}

void autoriza_decolar(Aeroporto *aeroporto, char *id){
    Aviao *aviao = busca_aviao(aeroporto->ldisp, id);
    if(aviao != NULL){
        enfileira(&(aeroporto->fdec), aviao);
    }
}

void decolar(Aeroporto *aeroporto){
    Aviao *aviao = desenfileira(&(aeroporto->fdec));
    if(aviao != NULL){
        aviao->decolagens++;
        insere_relatorio(&(aeroporto->relatorio), aviao->id, 'D');
    }
}

void autoriza_aterrissar(Aeroporto *aeroporto, char *id){
    Aviao *aviao = busca_aviao(aeroporto->ldisp, id);
    if(aviao != NULL){
        enfileira(&(aeroporto->fate), aviao);
    }
}

void aterrissar(Aeroporto *aeroporto){
    Aviao *aviao = desenfileira(&(aeroporto->fate));
    if(aviao != NULL){
        aviao->aterrissagens++;
        insere_relatorio(&(aeroporto->relatorio), aviao->id, 'A');
    }
}

void imprime_lista(ListaAvioes *ldisp){
    while(ldisp != NULL){
        Aviao *aviao = ldisp->lista;
        while(aviao != NULL){
            printf("ID: %s, Aterrissagens: %d, Decolagens: %d\n", aviao->id, aviao->aterrissagens, aviao->decolagens);
            aviao = aviao->prox;
        }
        ldisp = ldisp->prox;
    }
}

void avioes_cadastrados(Aeroporto *aeroporto){
    imprime_lista(aeroporto->ldisp);
}

void imprime_fila(Fila *fila){
    for(int i = fila->ini, j = fila->fim; i < fila->fim; i++, j--){
        printf("%d)ID: %s\n", i+1, fila->queue[j-1].id);
    }
}

void proximas_decolagens(Aeroporto *aeroporto){
    imprime_fila(&(aeroporto->fdec));
}

void proximas_aterrissagens(Aeroporto *aeroporto){
    imprime_fila(&(aeroporto->fate));
}

void relatorio_aeroporto(Aeroporto *aeroporto){
    Relatorio *rel = aeroporto->relatorio;
    while(rel != NULL){
        printf("ID: %s, Operação: %c, Horário: %s", rel->id, rel->operacao, ctime((const time_t*)&(rel->horario)));
        rel = rel->prox;
    }
}

void menu(Aeroporto *aeroporto){

    int opt;
    char id[6];
    printf("|----------------------------------|\n");
    printf("| 1. Cadastrar avião\n");
    printf("| 2. Mostrar aviões cadastrados\n");
    printf("| 3. Autorizar decolagem\n");
    printf("| 4. Decolar\n");
    printf("| 5. Autorizar aterrissagem\n");
    printf("| 6. Aterrissar\n");
    printf("| 7. Mostrar próximas decolagens\n");
    printf("| 8. Mostrar próximas aterrissagens\n");
    printf("| 9. Mostrar relatório\n");
    printf("| 0. Sair\n");
    printf("|----------------------------------|\n");

    do {
        printf("Escolha uma opção: ");
        scanf("%d", &opt);

        switch (opt){
            case 1:
                printf("ID do avião: ");
                scanf("%s", id);
                cadastra_aviao(aeroporto, id);
                break;
            case 2:
                avioes_cadastrados(aeroporto);
                break;
            case 3:
                printf("ID do avião: ");
                scanf("%s", id);
                autoriza_decolar(aeroporto, id);
                break;
            case 4:
                decolar(aeroporto);
                break;
            case 5:
                printf("ID do avião: ");
                scanf("%s", id);
                autoriza_aterrissar(aeroporto, id);
                break;
            case 6:
                aterrissar(aeroporto);
                break;
            case 7:
                proximas_decolagens(aeroporto);
                break;
            case 8:
                proximas_aterrissagens(aeroporto);
                break;
            case 9:
                relatorio_aeroporto(aeroporto);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while(opt != 0);
}

int main(){
    Aeroporto aeroporto;
    inicializa_aeroporto(&aeroporto);
    menu(&aeroporto);
    return 0;
}