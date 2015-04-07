#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _lista Lista;
typedef struct _lista_retangulo Lista_ret;

struct _lista
{
    int dado;
    Lista* prox;
};

Lista* inicializada (void)
{
    return NULL;
}

Lista* insere(int dado, Lista*lst)
{
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    if (novo==NULL) exit(EXIT_FAILURE);
    novo->dado = dado;
    novo->prox = lst;
    return novo;
}

void insere2(int dado,Lista**lst)
{
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    if (novo==NULL) exit(EXIT_FAILURE);
    novo->dado = dado;
    novo->prox = *lst;
    *lst = novo;
}

Lista* cria (int num)
{
    Lista* p = (Lista*) malloc(sizeof(Lista));
    p->dado = num;
    return p;
}

Lista* insere_ordenado (Lista* lst, int num) // INSERE ELEMENTOS EM ORDEM
{
    Lista* novo = cria(num); // cria novo nó
    Lista* ant = NULL; // ponteiro para elemento anterior
    Lista* p = lst; // ponteiro para percorrer a lista

    while (p != NULL && p->dado < num) // PROCURA POSIÇÃO DE INSERÇÃO
    {
        ant = p;
        p = p->prox;
    }
    if (ant == NULL)// INSERE ELEMENTO NO INICIO
        {
            novo->prox = lst;
            lst = novo;
        }
    else  //INSERE O ELEMENTO NO MEIO DA LISTA
    {
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return lst;
}

int vazia (Lista* lst)
{
    if (lst == NULL)
        return 1;
    else
        return 0;
}

void imprime(Lista* lst)
{
    Lista *p;
    int k=0;
    for (p=lst; p!=NULL; p=p->prox)
    {
        printf("Item: %d  End: %p  Dado: %d  prox: %p\n",k,p,p->dado,p->prox);
        k++;
    }
    printf("-------------------------------------------------\n");
}

void imprime_rec (Lista* lst)
{
    if (vazia(lst))
        return;
    printf("Dado: %d\n",lst->dado);
    imprime_rec(lst->prox);
    printf("---------------------------------\n");
}

void libera(Lista* lst)
{
    Lista* p = lst;
    while(p!=NULL)
    {
        Lista* t=p->prox;/* Guarda referencia para o pro...  */
        free(p); /* Libera a memória apontada por p */
        p=t; /* Faz p apontar para o proximo */
    }
}

Lista* busca (Lista* lst, int num)
{
    Lista* p;
    for (p = lst; p != NULL; p = p->prox)
    if (p->dado == num)
        return p;
    return NULL; /* não achou o elemento */
}

Lista* retira (Lista* lst, int num)
{
    Lista* ant = NULL; // ponteiro para elemento anterior
    Lista* p = lst; // ponteiro para percorrer a lista

    while (p != NULL && p->dado != num)  // procura elemento na lista, guardando anterior
    {
        ant = p;
        p = p->prox;
    }
    if (p == NULL) //verifica se achou elemento
        return lst; // não achou: retorna lista original
    if (ant == NULL) // retira o elemento
        lst = p->prox;  // retira elemento do inicio
    else
        ant->prox = p->prox; // retira elemento do meio da lista
    free(p);
    return lst;
}

int main()
{
    Lista*lst = inicializada();
    int  valor_digitado, valor_retira,n;
    Lista*end1 = inicializada();
    lst=insere_ordenado(lst,18);
    imprime_rec(lst);
    lst=insere_ordenado(lst,90);
    imprime_rec(lst);
    lst=insere_ordenado(lst,47);
    imprime_rec(lst);

    printf("Digite uma numero:");
    scanf("%d",&n);
    lst = insere_ordenado(lst, n);
    imprime_rec(lst);

    printf("Entre com o numero para busca: ");
    scanf("%d",&valor_digitado);
    end1 = busca(lst,valor_digitado);
    if(end1 != NULL)
        printf("O valor se encontra no endereço %p.\n",end1);
    else
        printf("Numero nao encontrado.\n");

    printf("Entre com o numero para retirar: ");
    scanf("%d",&valor_retira);
    lst = retira(lst,valor_retira);
    imprime(lst);

    libera(lst);
    lst=NULL;
    imprime(lst);


    return 0;
}
