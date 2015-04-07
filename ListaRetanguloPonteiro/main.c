#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _lista_retangulo Lista_ret;
typedef struct retangulo Retangulo;

struct color
{
    float r;
    float g;
    float b;
};

struct retangulo
{
    float x1;
    float y1;
    float x2;
    float y2;
    struct color cor;
    float Thickness;
};

struct _lista_retangulo
{
    Retangulo* info;
    Lista_ret* prox_ret;
};


Lista_ret* inicializada (void)
{
    return NULL;
}

void insere(Lista_ret**lst, int x1, int y1, int x2, int y2, int Thickness, int cor_r, int cor_g, int cor_b)
{
    Retangulo* r = (Retangulo*)malloc(sizeof(Retangulo));
    Lista_ret* novo = (Lista_ret*)malloc(sizeof(Lista_ret));
    if (novo==NULL) exit(EXIT_FAILURE);
    novo->info = r;
    r->x1 = x1;
    r->y1 = y1;
    r->x2 = x2;
    r->y2 = y2;
    r->cor.r = cor_r;
    r->cor.g = cor_g;
    r->cor.b = cor_b;
    r->Thickness = Thickness;
    novo->prox_ret = *lst;
    *lst = novo;
}

void imprime(Lista_ret* lst)
{
    Lista_ret *p;
    int k=0;
    for (p=lst; p!=NULL; p=p->prox_ret)
    {
        printf("Item: %d\n x1: %.2f\n y1: %.2f\n x2: %.2f\n y2: %.2f\n Cor(%.2f,%.2f,%.2f)\n Thickness: %.2f\n",k,p->info->x1,p->info->y1,p->info->x2,p->info->y2,p->info->cor.r,p->info->cor.g,p->info->cor.b,p->info->Thickness);
        k++;
    }
    printf("-----------------------------------------------------------------------------\n");
}

void libera(Lista_ret* lst)
{
    Lista_ret* p = lst;
    while(p!=NULL)
    {
        Lista_ret* t=p->prox_ret;
        free(p);
        p=t;
    }
}

int main()
{
    Lista_ret*lst = inicializada();
    insere(&lst, 1, 1, 4, 4, 3, 255, 0 , 0);
    imprime(lst);
    libera(lst);
    lst=NULL;
    imprime(lst);
    return 0;
}
