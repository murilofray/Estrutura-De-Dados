#include <stdio.h>
#define TAM 10

typedef struct sLista
{
    int n;
    int vet[TAM];
}LISTA;

void inicializar(LISTA *l)
{
    l->n = -1;
}
int vazia(LISTA *l)
{
    if(l->n == -1)
        return 1;
    return 0;
}
int cheia(LISTA *l)
{
    if(l->n == TAM-1)
        return 1;
    return 0;
}
void inserirOrdenado(LISTA *l, int x)
{
    int i=0;
    if(!cheia(l))
    {
        if(!vazia(l))
        {
          while(i <= l->n && x >= l->vet[i])
          {
              i++;
          }
          inserirNaPosicao(l,x,i);
        }
        else
          inserirNaPosicao(l,x,0);
    }
    else
        printf("ERRO - LISTA CHEIA");
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
    LISTA l;
    inicializar(&l);
    inserirOrdenado(&l,5);
    inserirOrdenado(&l,3);
    inserirOrdenado(&l,1);
    inserirOrdenado(&l,2);
    inserirOrdenado(&l,98);
    inserirOrdenado(&l,96);
    inserirOrdenado(&l,0);
    exibir(l);
}
