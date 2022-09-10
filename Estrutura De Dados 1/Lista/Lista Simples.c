#include <stdio.h>
#define TAM 5
typedef struct sLista
{
    int n;
    int vet[TAM];
} LISTA;

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

void inserirInicio(LISTA *lista,int x)
{
    if(!cheia(lista))
    {
        int i;
        for(i=lista->n+1; i>0; i--)
        {
            lista->vet[i] = lista->vet[i-1];
        }
        lista->n++;
        lista->vet[0] = x;
    }
    else
        printf("ERRO - LISTA CHEIA\n");
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


void inserirNaPosicao(LISTA* lista, int x, int posicao)
{
    if(!cheia(lista))
    {
        if(posicao <= lista->n+1 && posicao >= 0)
        {
            int i;
            for(i = lista->n+1 ; i > posicao ; i--)
            {
                lista->vet[i] = lista->vet[i-1];
            }
            lista->n++;
            lista->vet[posicao] = x;
        }
        else
            printf("ERRO - POSICAO INVALIDA\n");
    }
    else
        printf("ERRO - LISTA CHEIA\n");
}

void removerInicio (LISTA *lista)
{
    if(!vazia(lista))
    {
        int i;
        for(i=0; i<=lista->n; i++)
        {
            lista->vet[i] = lista->vet[i+1];
        }
        lista->n--;
    }
    else
        printf("ERRO - LISTA VAZIA\n");
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

void removerNaPosicao (LISTA *lista, int posicao)
{
    if(!vazia(lista))
    {
        int i;
        if(posicao <= lista->n && posicao >= 0)
        {
            for(i = posicao; i <= lista->n ; i++)
            {
                lista->vet[i] = lista->vet[i+1];
            }
            lista->n--;
        }
        else
            printf("ERRO - POSICAO INVALIDA\n");
    }
    else
        printf("ERRO - LISTA VAZIA\n");
}

void acessarPosicao(LISTA lista, int posicao)
{
    int i;
    if(!vazia(&lista))
    {
        if(posicao >= 0 && posicao <= lista.n)
        {
            printf("|%d|", lista.vet[posicao]);
        }
        printf("ERRO - POSICAO INVALIDA\n");
    }
    else
        printf("ERRO - LISTA VAZIA");
}

int procurarElemento(LISTA lista, int elemento)
{
    int i=0, aux=-1;
    if(!vazia(&lista))
    {
        while(i <= lista.n)
        {
            if(lista.vet[i] == elemento)
            {
                aux = i;
                i = lista.n+1;
            }
            i++;
        }
    }
    else
        printf("ERRO - LISTA VAZIA\n");
    return aux;

}

void exibir(LISTA lista)
{
    if(!vazia(&lista))
    {
        int i;
        for(i=0; i<=lista.n; i++)
            printf("|%d|",lista.vet[i]);
        printf("\n");
    }
}
void main()
{
    LISTA lista;
    inicializar(&lista);
    inserirInicio(&lista,3);
    inserirInicio(&lista,2);
    inserirInicio(&lista,1);
    inserirNaPosicao(&lista,4,2);
    exibir(lista);
    inserirNaPosicao(&lista,6,4);
    exibir(lista);
    //inserirInicio(&lista,2);
    removerInicio(&lista);
    exibir(lista);
    printf("%d",procurarElemento(lista,4));

}
