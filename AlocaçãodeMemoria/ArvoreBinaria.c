#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int conteudo;
    struct no *esquerda, *direita;
} No;

typedef struct
{
    No *raiz;
} ArvB;

void inserirEsquerda(No *no, int valor)
{
    if (no->esquerda == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->esquerda = novo;
    }
    else
    {
        if (valor < no->esquerda->conteudo)
        {
            inserirEsquerda(no->esquerda, valor);
        }
        if (valor > no->esquerda->conteudo)
        {
            inserirDireita(no->esquerda, valor);
        }
    }
}
void inserirDireita(No *no, int valor)
{
    if (no->direita == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->direita = novo;
    }
    else
    {
        if (valor > no->direita->conteudo)
        {
            inserirDireita(no->direita, valor);
        }
        if (valor > no->esquerda->conteudo)
        {
            inserirEsquerda(no->direita, valor);
        }
    }
}
void inserir(ArvB *arv, int valor)
{
    if (arv->raiz == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        arv->raiz = novo;
    }
    else
    {
        if (valor < arv->raiz->conteudo)
        {
            inserirEsquerda(arv->raiz, valor);
        }
        if (valor > arv->raiz->conteudo)
        {
            inserirDireita(arv->raiz, valor);
        }
    }
}

No *inserirNovaVersao(No *raiz, int valor)
{
    if (raiz == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }
    else
    {
        if (valor < raiz->conteudo)
        {
            raiz->esquerda = inserirNovaVersao(raiz->esquerda, valor);
        }
        if (valor > raiz->conteudo)
        {
            raiz->direita = inserirNovaVersao(raiz->direita, valor);
        }
        return raiz;
    }
}

int tamanho(No *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);
    }
}

int buscar(No *raiz, int chave)
{
    if (raiz == NULL)
    {
        return 0; // não achou o valor
    }
    else
    {
        if (raiz->conteudo == chave)
        {
            return 1; // achou o valor
        }
        else
        {
            if (chave < raiz->conteudo)
            {
                return buscar(raiz->esquerda, chave);
            }
            else
            {
                return buscar(raiz->direita, chave);
            }
        }
    }
}

void imprimir(No *raiz)
{
    if (raiz != NULL)
    {
        imprimir(raiz->esquerda);
        printf("%d ", raiz->conteudo);
        imprimir(raiz->direita);
    }
}

No* remover(No *raiz, int chave)
{
    if(raiz == NULL)
    {
        printf("Valor nao encontrado.\n");
        return NULL;
    }
    else
    {
        if(raiz->conteudo == chave)
        {
            if(raiz->esquerda == NULL && raiz->direita == NULL)
            {
                free(raiz);
                return NULL;
            }
        }
        else
        {
            if(chave < raiz->conteudo)
            {
                raiz->esquerda = remover(raiz->esquerda, chave);
            }
            else
            {
               raiz->direita = remover(raiz->direita, chave);
            }
            return raiz;
        }
        
    }

}
int main()
{
    int op, valor;
    ArvB arv;
    arv.raiz = NULL;

    No *raiz = NULL;

    do
    {
        printf("\nMENU\n0 - sair\n1 - inserir\n2 - imprimir\n3 - buscar\n4 - remover\n");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            printf("\nSaindo...\n");
            break;
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            raiz = inserirNovaVersao(raiz, valor);
            break;
        case 2:
            printf("\nImpressao da arvore binaria.\n");
            printf("Tamanho: %d\n\n", tamanho(raiz));
            imprimir(raiz);
            printf("\n");
            break;
        case 3:
            printf("Qual valor deseja buscar? ");
            scanf("%d", &valor);
            printf("Retorno: %d.\n", buscar(raiz, valor));
            break;
        case 4:
            printf("Digite um valor a ser removido: ");
            scanf("%d", &valor);
            raiz = remover(raiz, valor);
            break;
        default:
            printf("\nOpcao invalida...\n");
            break;
        }
    } while (op != 0);
}