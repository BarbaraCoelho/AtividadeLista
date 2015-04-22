#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes_lista.h"

/*
    Curso: Engenharia Eletrônica
    Programação de Computadores II - 2015/1
    Aluna: Bárbara Coelho

                          Lista Encadeada
*/


int main()
{
    Lista*lst = inicializada();          //Inicializa NULL
    Lista*end1 = inicializada();         //Inicializa NULL
    int  valor_digitado, valor_retira,n;

    lst=insere_ordenado(lst,18);     //Insere em ordem os valores
    imprime(lst);                    //imprime o valor
    lst=insere_ordenado(lst,90);
    imprime(lst);
    lst=insere_ordenado(lst,47);
    imprime(lst);

    printf("Digite uma numero:");
    scanf("%d",&n);
    lst=insere_ordenado(lst, n);
    imprime(lst);

    printf("Entre com um numero para busca: \n");
    scanf("%d",&valor_digitado);
    end1 = busca(lst,valor_digitado);                  // Busca endereço do  numero digitado
    if(end1 != NULL)
        printf("O valor se encontra no endereço %p.\n",end1);
    else
        printf("Numero nao encontrado.\n");

    printf("Entre com o numero para retirar: ");
    scanf("%d",&valor_retira);
    retira(lst,valor_retira);                          // Retira o numero digitado
    imprime(lst);

    libera(lst);                             // libera a lista
    lst=NULL;                                // igual lista à NULL
    imprime(lst);

    return 0;
}
