#include <stdio.h>
#include <stdlib.h>

struct Node {
    int num;
    struct Node *prox;
};
typedef struct Node node;

int tam;

void inicia(node *FILA);
int menu(void);
void opcao(node *FILA, int op);
void insereInicio(node *FILA);
void exibe(node *FILA);
void libera(node *FILA);
node *retiraFim(node *FILA);

int main(void){
    node *FILA = (node *) malloc(sizeof(node));
    
    if(!FILA){
        printf("Sem memoria disponivel!\n");
        exit(1);
    } 
    
    else{
        inicia(FILA);
        int opt;

        do {
            opt=menu();
            opcao(FILA,opt);
        } while(opt);

        free(FILA);
        return 0;
    }
}

void inicia(node *FILA){
    FILA->prox = NULL;
    tam=0;
}

int menu(void){
    int opt;

    printf("Escolha a opcao\n");
    printf("0. Sair\n");
    printf("1. Zerar \n");
    printf("2. Exibir fila\n");
    printf("3. Adicionar node no inicio\n");
    printf("4. Retirar do fim\n");
    printf("Opcao: "); scanf("%d", &opt);
    printf("\n");

    return opt;
}

void opcao(node *FILA, int op){
    node *tmp;
    
    switch(op){
        case 0:
            libera(FILA);
            break;

        case 1:
            libera(FILA);
            inicia(FILA);
            break;

        case 2:
            exibe(FILA);
            break;

        case 3:
            insereInicio(FILA);
            break;

        case 4:
            tmp= retiraFim(FILA);
            printf("Retirado: %3d\n\n", tmp->num);
            break;

        default:
            printf("Comando invalido\n\n");
    }
}

int vazia(node *FILA){
    if(FILA->prox == NULL)
        return 1;
    else
        return 0;
}

node *aloca(){
    node *novo=(node *) malloc(sizeof(node));
    
    if(!novo){
        printf("Sem memoria disponivel!\n");
        exit(1);
    } 
    
    else{
        printf("Novo elemento: "); scanf("%d", &novo->num);
        return novo;
    }
}

void insereInicio(node *FILA){
    node *novo=aloca();
    node *oldHead = FILA->prox;

    FILA->prox = novo;
    novo->prox = oldHead;

    tam++;
}

void exibe(node *FILA){
    if(vazia(FILA)) {
        printf("Fila vazia!\n\n");
        return ;
    }

    node *tmp;
    tmp = FILA->prox;
    printf("Fila:  ");
    
    while( tmp != NULL) {
        printf("%5d", tmp->num);
        tmp = tmp->prox;
    }
    
    printf("\n        ");
    printf("\nPrimeiro:");
    
    int count;
    for(count=1 ; count <= tam ; count++){
        if(count == tam)
            printf("  ^  "); 
        else
            printf("     "); 
    }

    printf("\n\n");
}

void libera(node *FILA){
    if(!vazia(FILA)) {
        node *proxNode,
             *atual;

        atual = FILA->prox;
        
        while(atual != NULL) {
            proxNode = atual->prox;
            free(atual);
            atual = proxNode;
        }
    }
}

node *retiraFim(node *FILA){
    if(FILA->prox == NULL) {
        printf("Fila ja vazia\n\n");
        return NULL;
    } 
    
    else{
        node *ultimo = FILA->prox,
              *penultimo = FILA;

        while(ultimo->prox != NULL) {
            penultimo = ultimo;
            ultimo = ultimo->prox;
        }

        penultimo->prox = NULL;
        tam--;
        return ultimo;
    }
}

