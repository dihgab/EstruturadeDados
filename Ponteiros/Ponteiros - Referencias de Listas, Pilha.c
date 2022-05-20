#include <stdio.h>
#include <stdlib.h>

/* Estrutura que será usada para criar os nós da lista */

typedef struct tipo_produto {
    int codigo;                  /* Codigo do produto */
    double preco;                /* Preco do produto */
    struct tipo_produto *proximo;    /* Proximo elemento da lista encadeada de Produtos */
}  TProduto;

/* Prototipos das funcoes para inserir e listar produtos */

void inserir(TProduto **cabeca);
void listar (TProduto *cabeca);

int main()
{
    TProduto *cabeca = NULL;        /* Ponteiro para a cabeca da lista */
    TProduto *noatual;               /* Ponteiro a ser usado para percorrer a lista no momento de desalocar seus elementos*/
    char q;                          /* Caractere para receber a opcao do usuario */
    do {
        printf("\n\nOpcoes: \nI -> para inserir novo produto;\nL -> para listar os produtos; \nS -> para sair \n:");
        scanf("%c", &q);     /* Le a opcao do usuario */
        switch(q) {
            case 'i': case 'I': inserir(&cabeca); break;
            case 'l': case 'L': listar(cabeca); break;
            case 's': case 'S': break;
            default: printf("\n\n Opcao nao valida");
        }
        fflush(stdin);    /* Limpa o buffer de entrada */
    } while ((q != 's') && (q != 'S') );

/* Desaloca a memoria alocada para os elementos da lista */

    noatual = cabeca;
    while (noatual != NULL)
    {
        cabeca = noatual->proximo;
        free(noatual);
        noatual = cabeca;
    }
}

/* Lista todos os elementos presentes na lista encadeada */


void listar (TProduto *noatual)
{
    int i=0;
    while( noatual != NULL)    /* Enquanto nao chega no fim da lista */
    {
        i++;
        printf("\n\nProduto numero %d\nCodigo: %d \nPreco:R$%.2lf", i, noatual->codigo, noatual->preco);
        noatual = noatual->proximo;     /* Faz noatual apontar para o proximo no */
    }
}

/* Funcao para inserir um novo no, ao final da lista */


void inserir (TProduto **cabeca)
{
    TProduto *noatual, *novono;
    int cod;
    double preco;
    printf("\n Codigo do novo produto: ");
    scanf("%d", &cod);
    printf("\n Preco do produto:R$");
    scanf("%lf", &preco);
    if (*cabeca == NULL)    /* Se ainda nao existe nenhum produto na lista */
    {
/* cria o no cabeca */
        *cabeca = (TProduto *) malloc(sizeof(TProduto));
        (*cabeca)->codigo = cod;
        (*cabeca)->preco = preco;
        (*cabeca)->proximo = NULL;
    }
    else
    {
/* Se ja existem elementos na lista, deve percorre-la ate' o seu final e inserir o novo elemento */
        noatual = *cabeca;
        while(noatual->proximo != NULL)
            noatual = noatual->proximo;    /* Ao final do while, noatual aponta para o ultimo no */
        novono = (TProduto *) malloc(sizeof(TProduto));/* Aloca memoria para o novo no */
        novono->codigo = cod;
        novono->preco = preco;
        novono->proximo = NULL;
        noatual->proximo = novono;     /* Faz o ultimo no apontar para o novo no */
    }
}
