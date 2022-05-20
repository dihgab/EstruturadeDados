#include <stdio.h>
#include <stdlib.h>

struct Node {
    int num;
    struct Node *prox;
};
typedef struct Node node;

int tam;

void inicia(node *PILHA);
int menu(void);
void opcao(node *PILHA, int op);
void insereInicio(node *PILHA);
void exibe(node *PILHA);
void libera(node *PILHA);
node *retiraInicio(node *PILHA);

int main(void){
    node *PILHA = (node *) malloc(sizeof(node));

    if(!PILHA){
        printf("Sem memoria disponivel!\n");
        exit(1);
    } 
    
    else{
        inicia(PILHA);
        int opt;

        do {
            opt=menu();
            opcao(PILHA,opt);
        } while(opt);

        free(PILHA);
        return 0;
    }
}

void inicia(node *PILHA){
    PILHA->prox = NULL;
    tam=0;
}

int menu(void){ 
    int opt;

    printf("Escolha a opcao\n");
    printf("0. Sair\n");
    printf("1. Zerar pilha\n");
    printf("2. Exibir pilha\n");
    printf("3. Adicionar node no inicio\n");
    printf("4. Retirar do inicio\n");
    printf("Opcao: "); scanf("%d", &opt);
    printf("\n");

    return opt;
}

void opcao(node *PILHA, int op){
    node *tmp;
    
    switch(op){
    
        case 0:
            libera(PILHA);
            break;

        case 1:
            libera(PILHA);
            inicia(PILHA);
            break;

        case 2:
            exibe(PILHA);
            break;

        case 3:
            insereInicio(PILHA);
            break;

        case 4:
            tmp= retiraInicio(PILHA);
            printf("Retirado: %3d\n\n", tmp->num);
            break;

        default:
            printf("Comando invalido\n\n");
    }
}

int vazia(node *PILHA){
    if(PILHA->prox == NULL)
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

void insereInicio(node *PILHA){
    node *novo=aloca();
    node *oldHead = PILHA->prox;

    PILHA->prox = novo;
    novo->prox = oldHead;

    tam++;
}

void exibe(node *PILHA){
    if(vazia(PILHA)){
        printf("Pilha vazia!\n\n");
        return ;
    }

    node *tmp;
    tmp = PILHA->prox;
    printf("Pilha:");
    
    while( tmp != NULL){
        printf("%5d", tmp->num);
        tmp = tmp->prox;
    }
    
    printf("\n        ");
    printf("\nTopo:     ^");
    printf("\n\n");
}

void libera(node *PILHA){
    if(!vazia(PILHA)){  
        node *proxNode,
             *atual;

        atual = PILHA->prox;
        
        while(atual != NULL) {
            proxNode = atual->prox;
            free(atual);
            atual = proxNode;
        }
    }
}

node *retiraInicio(node *PILHA){
    if(PILHA->prox == NULL){
        printf("Pilha ja esta vazia\n");
        return NULL;
    } 
    
    else{
        node *tmp = PILHA->prox;
        PILHA->prox = tmp->prox;
        tam--;
        return tmp;
    }
}


