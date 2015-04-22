#include <stdio.h>
#include <stdlib.h>
#include "funcoes_lista.h"

/*Inicializa a Lista no NULL*/
Lista* inicializada (void)
{
    return NULL;
}

/*Insere elementos na lista*/
void insere(int dado,Lista**lst)
{
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    if (novo==NULL) exit(EXIT_FAILURE);
    novo->dado = dado;
    novo->prox = *lst;
    *lst = novo;
}

/*Função cria*/
Lista* cria (int num) // usada na função insere_ordenado
{
    Lista* p = (Lista*) malloc(sizeof(Lista));
    p->dado = num;
    return p;
}

/*Insere elementos em ordem na lista*/
Lista* insere_ordenado (Lista* lst, int num) // INSERE ELEMENTOS EM ORDEM
{
    Lista* novo = cria(num); // cria novo n�
    Lista* ant = NULL; // ponteiro para elemento anterior
    Lista* p = lst; // ponteiro para percorrer a lista

    while (p != NULL && p->dado < num) // PROCURA POSI��O DE INSER��O
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

/*Imprime os valores*/
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

/*Vazia*/
int vazia (Lista* lst)
{
    if (lst == NULL)
        return 1;
    else
        return 0;
}

/*Imprime recursiva*/
void imprime_rec (Lista* lst)
{
    if (vazia(lst))
        return;
    printf("Dado: %d\n",lst->dado);
    imprime_rec(lst->prox);
    printf("---------------------------------\n");
}

/*Libera*/
void libera(Lista* lst)
{
    Lista* p = lst;
    while(p!=NULL)
    {
        Lista* t = p -> prox;   // Guarda referencia para o proximo
        free(p);                // Libera a memória apontada por p
        p=t;                    // Faz p apontar para o proximo
    }
}

/*Procura elementos na lista*/
Lista* busca (Lista* lst, int num)
{
    Lista* p;
    for (p = lst; p != NULL; p = p->prox)
    if (p->dado == num)
        return p;
    return NULL;     // não achou o elemento
}

/*Retira elementos da lista*/
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
    {
        printf("\nValor nao encontrado.\n\n");
        return lst; // não achou: retorna lista original
    }

    if (ant == NULL) // retira o elemento
        lst = p->prox;  // retira elemento do inicio
    else
        ant->prox = p->prox; // retira elemento do meio da lista
    free(p);
    return lst;
}
