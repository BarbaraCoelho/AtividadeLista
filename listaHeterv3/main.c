#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CIRC 0
#define RET 1
#define PI 3.14159

typedef struct _lista_Heterogenea Lista_het;
typedef struct retangulo Retangulo;
typedef struct circulo Circulo;

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

struct circulo
{
    float cx;
    float cy;
    float r;
    struct color cor;
    float Thickness;
};

struct _lista_Heterogenea
{
    int tipo;
    Circulo* dado;
    Retangulo* info;
    Lista_het* prox_het;
};

Lista_het* inicializada (void)
{
    return NULL;
}

void insere_circ(Lista_het**lst, int cx, int cy, int r, int Thickness, int cor_r, int cor_g, int cor_b)
{
    Circulo* c = (Circulo*)malloc(sizeof(Circulo));
    Lista_het* novo = (Lista_het*)malloc(sizeof(Lista_het));
    if (novo==NULL) exit(EXIT_FAILURE);
    novo->dado = c;
    c->cx = cx;
    c->cy = cy;
    c->r = r;
    c->cor.r = cor_r;
    c->cor.g = cor_g;
    c->cor.b = cor_b;
    c->Thickness = Thickness;
    novo->tipo = CIRC;
    novo->prox_het = *lst;
    *lst = novo;
}

void insere_ret(Lista_het**lst, int x1, int y1, int x2, int y2, int Thickness, int cor_r, int cor_g, int cor_b)
{
    Retangulo* r = (Retangulo*)malloc(sizeof(Retangulo));
    Lista_het* novo = (Lista_het*)malloc(sizeof(Lista_het));
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
    novo->tipo = RET;
    novo->prox_het = *lst;
    *lst = novo;
}

void imprime(Lista_het*lst)
{
    Lista_het *p;
    for (p=lst; p!=NULL; p=p->prox_het)
    {
        switch (p->tipo)
        {
            case RET:
            {
                printf("Retangulo:\n x1: %.2f\n y1: %.2f\n x2: %.2f\n y2: %.2f\n Cor(%.2f,%.2f,%.2f)\n Thickness: %.2f\n",p->info->x1,p->info->y1,p->info->x2,p->info->y2,p->info->cor.r,p->info->cor.g,p->info->cor.b,p->info->Thickness);
            }
            break;
            case CIRC:
            {
                printf("Circulo:\n cx: %.2f\n cy: %.2f\n r: %.2f\n Cor(%.2f,%.2f,%.2f)\n Thickness: %.2f\n",p->dado->cx,p->dado->cy,p->dado->r,p->dado->cor.r,p->dado->cor.g,p->dado->cor.b,p->dado->Thickness);
            }
            break;
        }
    }
    printf("-----------------------------------------------------------------------------\n");
}

void libera(Lista_het* lst)
{
    Lista_het* p = lst;
    while(p!=NULL)
    {
        Lista_het* t=p->prox_het;
        free(p);
        p=t;
    }
}

float Area (Lista_het *p)
{
    float a;
    switch (p->tipo)
    {
        case RET:
        {
            Retangulo *r = (Retangulo*) p->info;
            a = ((r->x2)-(r->x1))*((r->y1)-(r->y2));
        }
        break;
        case CIRC:
        {
            Circulo *c = (Circulo*) p->info;
            a = PI * (c->r) * (c->r);
        }
        break;
    }
    return a;
}

int main()
{
    float area;
    Lista_het*lst = inicializada();
    insere_ret(&lst, 1, 4, 4, 1, 3, 255, 0 , 0);
    imprime(lst);

    area = Area(lst);
    printf("\nArea : %.2f\n",area);

    libera(lst);
    lst=NULL;

    return 0;
}

