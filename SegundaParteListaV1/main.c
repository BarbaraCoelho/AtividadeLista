#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _lista_retangulo Lista_ret;

struct color
{
    unsigned int r;
    unsigned int g;
    unsigned int b;
};

struct retangulo
{
    int x1;
    int y1;
    int x2;
    int y2;
    struct color cor;
    int Thickness;
};

struct _lista_retangulo
{
    struct retangulo ret;
    Lista_ret* prox_ret;
};

Lista_ret* inicializada (void)
{
    return NULL;
}

void insere(Lista_ret**lst, int x1, int y1, int x2, int y2, int Thickness, int cor_r, int cor_g, int cor_b)
{
    Lista_ret* novo = (Lista_ret*)malloc(sizeof(Lista_ret));
    if (novo==NULL) exit(EXIT_FAILURE);
    novo->ret.x1 = x1;
    novo->ret.y1 = y1;
    novo->ret.x2 = x2;
    novo->ret.y2 = y2;
    novo->ret.cor.r = cor_r;
    novo->ret.cor.g = cor_g;
    novo->ret.cor.b = cor_b;
    novo->ret.Thickness = Thickness;
    novo->prox_ret = *lst;
    *lst = novo;
}

void imprime(Lista_ret* lst)
{
    Lista_ret *p;
    int k=0;
    for (p=lst; p!=NULL; p=p->prox_ret)
    {
        printf("Item: %d\n x1: %d\n y1: %d\n x2: %d\n y2: %d\n Cor(%d,%d,%d)\n Thickness: %d\n",k,p->ret.x1,p->ret.y1,p->ret.x2,p->ret.y2,p->ret.cor.r,p->ret.cor.g,p->ret.cor.b,p->ret.Thickness);
        k++;
    }
    printf("-----------------------------------------------------------------------------\n");
}

void libera(Lista_ret* lst)
{
    Lista_ret* p = lst;
    while(p!=NULL)
    {
        Lista_ret* t=p->prox_ret;/* Guarda referencia para o pro...  */
        free(p); /* Libera a memória apontada por p */
        p=t; /* Faz p apontar para o proximo */
    }
}

int main()
{
    Lista_ret*lst = inicializada();
    insere(&lst, 1, 1, 4, 4, 3, 255, 0 , 0);
    imprime(lst);
    insere(&lst, 1, 4, 8, 8, 7, 255, 0 , 0);
    imprime(lst);
    libera(lst);
    lst=NULL;
    imprime(lst);
    return 0;
}
