/******************************************************

Autor: Thiago Straiotto Fabri

******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CalcPosFix.h"

/**
 * Verifica se a pilha está vazia
 * @param pilha Pilha
 * @return 1 se a pilha está vazia, 0 se contém elementos
 */
int estaVazia(PilhaDouble *pilha)
{
    if(pilha==NULL){
        printf("Pilha vazia!");
        return 1;
    }
    return 0;
}

/**
 * Exclui todos os valores contidos na pilha
 * @param pilha Pilha
 * @return
 */
void esvaziaPilha(PilhaDouble **pilha)
{
    if(*pilha == NULL){
        printf("Pilha ja esta vazia!");
    }
    double dado;
    do{
        PilhaDouble *topoantigo;
        dado = (*pilha) -> valor;
        topoantigo = *pilha;
        *pilha = topoantigo -> inferior;
        free(topoantigo);
    }while (dado!=0);

    return;
}

/**
 * Insere um valor na Pilha
 * @param pilha Pilha
 * @param valor Valor a ser inserido na pilha
 */
void push(PilhaDouble **pilha, double valor)
{
    PilhaDouble *novo = malloc(sizeof(PilhaDouble));
    novo->valor = valor;
    novo->inferior = *pilha;
    *pilha = novo;
    return;
}

/**
 * Retira um elemento da pilha
 * @param pilha Pilha
 * @return Elemento retirado da pilha
 */
double pop(PilhaDouble **pilha)
{
    if(*pilha == NULL){
        printf("Pilha ja esta vazia!");
        return -1;
    }

    double dado;
    PilhaDouble *topoantigo;
    dado = (*pilha) -> valor;
    topoantigo = *pilha;
    *pilha = topoantigo -> inferior;
    free(topoantigo);
    return dado;
}

/**
 * Retira dois valores do topo da pilha, soma e coloca o resultado na pilha
 * @param pilha Pilha
 * @return Sucesso da operação
 */
int soma(PilhaDouble **pilha)
{
    if(*pilha == NULL || (*pilha)->inferior == NULL){
        printf("Acao impossivel!");
        return -1;
    }

    double a = pop(pilha);
    double b = pop(pilha);
    push(pilha, a+b);

    return 0;
}
/**
 * Retira dois valores do topo da pilha, subtrai e coloca o resultado na pilha
 * @param pilha Pilha
 * @return Sucesso da operação
 */
int subtrai(PilhaDouble **pilha)
{
    if(*pilha == NULL || (*pilha)->inferior == NULL){
        printf("Acao impossivel!");
        return -1;
    }

    double a = pop(pilha);
    double b = pop(pilha);
    push(pilha, b-a);

    return 0;
}

/**
 * Retira dois valores do topo da pilha, multiplica e coloca o resultado na pilha
 * @param pilha Pilha
 * @return Sucesso da operação
 */
int multiplica(PilhaDouble **pilha)
{
    if(*pilha == NULL || (*pilha)->inferior == NULL){
        printf("Acao impossivel!");
        return -1;
    }

    double a = pop(pilha);
    double b = pop(pilha);

    push(pilha, b*a);

    return 0;
}
/**
 * Retira dois valores do topo da pilha, divide e coloca o resultado na pilha
 * @param pilha Pilha
 * @return Sucesso da operação
 */
int divide(PilhaDouble **pilha)
{
    if(*pilha == NULL || (*pilha)->inferior == NULL){
        printf("Acao impossivel!");
        return -1;
    }

    double a = pop(pilha);
    double b = pop(pilha);

    if(a==0){
        printf("Acao impossivel (divisao por 0)!");
        return -1;
    }

    push(pilha, b/a);

    return 0;
}

/**
 * Retorna o número de elementos que a pilha contém
 * @param pilha Pilha
 * @return Número de elementos
 */
int altura(PilhaDouble *pilha)
{
    int cont=0;
    PilhaDouble *iterador;
    iterador = pilha;
    while(iterador != NULL){
        iterador = iterador -> inferior;
        cont++;
    }
    return cont;
}

/**
* Retorna o nome do autor da classe
* @param Variavel que receberá o nome
* @return
*/
void autor(char nome[])
{
    sprintf(nome, "Thiago Straiotto Fabri");
}
