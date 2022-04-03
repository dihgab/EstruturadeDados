#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct elemento
{
    int valor;
    struct elemento *proximo;
} No;

typedef struct
{
    No *inicio;
    No *fim;
    int tamanho;
} Lista;

void inicializa(Lista *lista)
{
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

int inserirInicio(Lista *lista, int valor)
{
    No *novo;

    if ((novo = (No *)malloc(sizeof(No))) == NULL)
        return -1;

    novo->valor = valor;

    if (lista->inicio == NULL)
    {
        novo->proximo = NULL;
        lista->inicio = novo;
        lista->fim = novo;
    }
    else
    {
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }
    lista->tamanho++;
    return 0;
}

int inserirFim(Lista *lista, int valor)
{
    No *novo;

    if ((novo = (No *)malloc(sizeof(No))) == NULL)
        return -1;

    novo->valor = valor;
    novo->proximo = NULL;

    if (lista->inicio == NULL)
    {
        lista->inicio = novo;
        lista->fim = novo;
    }
    else
    {
        lista->fim->proximo = novo;
        lista->fim = novo;
    }
    lista->tamanho++;
    return 0;
}

void removeQualquer(Lista *lista, int valor)
{
    No *inicio = lista->inicio;
    No *aRemover = NULL;

    if (inicio != NULL && lista->inicio->valor == valor)
    {
        aRemover = lista->inicio;
        lista->inicio = aRemover->proximo;
        if (lista->inicio == NULL)
            lista->fim = NULL;
    }
    else
    {
        while (inicio != NULL && inicio->proximo != NULL && inicio->proximo->valor != valor)
            inicio = inicio->proximo;
        if (inicio != NULL && inicio->proximo != NULL)
        {
            aRemover = inicio->proximo;
            inicio->proximo = aRemover->proximo;
            if (inicio->proximo == NULL)
                lista->fim = NULL;
        }
    }
    if (aRemover)
    {
        free(aRemover);
        lista->tamanho--;
    }
}

void imprime(Lista *lista)
{
    No *atual = lista->inicio;
    printf("\t");
    printf("-> ");
    while (atual != NULL)
    {
        printf("[%d] -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("[NULL]\n");
    printf("Tamanho atual da lista = %d\n", lista->tamanho);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Lista *lista;
    int valor;
    char op;

    if ((lista = (Lista *)malloc(sizeof(Lista))) == NULL)
        return -1;

    inicializa(lista);

    while (op != 'E' && op != 'e')
    {
        printf("\n\n\tDigite a letra da função desejada;\n");
        printf("\tA - Adicionar elemento no início da lista;\n");
        printf("\tB - Adicionar elemento no fim da lista;\n");
        printf("\tC - Remover um elemento lista;\n");
        printf("\tD - Imprimir os elementos da lista;\n");
        printf("\tE - Sair do programa.\n\n");
        scanf(" %c", &op);
        if (op == 'A' || op == 'a')
        {
            printf("Digite o valor a ser inserido\n");
            scanf("%d", &valor);
            if (inserirInicio(lista, valor) == 0)
                printf("Elemento inserido com sucesso\n");
            else
                printf("Elemento não removido com sucesso\n");
        }
        else if (op == 'B' || op == 'b')
        {
            printf("Digite o valor a ser inserido\n");
            scanf("%d", &valor);
            if (inserirFim(lista, valor) == 0)
                printf("Elemento inserido com sucesso\n");
            else
                printf("Elemento não removido com sucesso\n");
        }
        else if (op == 'C' || op == 'c')
        {
            printf("Digite o valor a ser removido\n");
            scanf("%d", &valor);
            removeQualquer(lista, valor);
        }
        else if (op == 'D' || op == 'd')
        {
            printf("\nValor(es) dentro da Lista Encadeada:\n");
            imprime(lista);
        }
        else if (op == 'E' || op == 'e')
            printf("\n\tTchau :)\n");
        else
            printf("Função inválida.\n");
    }
}
