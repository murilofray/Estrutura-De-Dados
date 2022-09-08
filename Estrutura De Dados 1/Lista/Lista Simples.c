#include <stdio.h>
#define TAM 5
typedef struct sLista
{
    int n;
    int vet[TAM];
}LISTA;

void inicializar(LISTA *lista)
{
    lista = lista->n = -1;
}

int vazia(LISTA *lista)
{
    if(lista->n == -1)
        return 1;
    return 0;
}

int cheia(LISTA *lista)
{
    if(lista->n == TAM-1)
        return 1;
    return 0;
}

void inserirFinal(LISTA *lista, int x)
{
    if(!cheia(lista))
    {
        lista->n++;
        lista->vet[lista->n] = x;
    }
    else
        printf("ERRO - LISTA CHEIA\n");
}

void removerFinal(LISTA *lista)
{
    if(!vazia(lista))
    {
        lista->n--;
    }
    else
        printf("ERRO - LISTA VAZIA\n");
}

void exibir(LISTA lista)
{
    if(!vazia(&lista))
    {
        for(int i=0;i<=lista.n;i++)
            printf("|%d|",lista.vet[i]);
    }
}
void main()
{
    LISTA lista;
    inicializar(&lista);
    inserirFinal(&lista,5);
    exibir(lista);

}
