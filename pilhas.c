/******************************************************

Autor: firulion

******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaInt.h"

/**
 * Verifica se a pilha está vazia
 * @param pilha Pilha
 * @return 1 se a pilha está vazia, 0 se contém elementos
 */
int estaVazia(PilhaInt *pilha)
{
    if( pilha == NULL){
       printf("Pilha vazia!");
       return 1;
    }

    else return -1;
}

/**
 * Exclui todos os valores contidos na pilha
 * @param pilha Pilha
 * @return
 */
void esvaziaPilha(PilhaInt **pilha)
{
    if(*pilha == NULL){
        printf("Pilha ja esta vazia!");
        return -1;
    }
    int dado;
    do{
        PilhaInt *topoantigo;
        dado = (*pilha) -> valor;
        topoantigo = *pilha;
        *pilha = topoantigo -> inferior;
        free(topoantigo);
    }while (dado!=NULL);

}

/**
 * Insere um valor na Pilha
 * @param pilha Pilha
 * @param valor Valor a ser inserido na pilha
 */
void push(PilhaInt **pilha, int valor)
{
    PilhaInt *novo = malloc(sizeof(PilhaInt));
    novo -> valor = valor;
    novo -> inferior = *pilha;
    *pilha = novo;
    return;
}

/**
 * Retira um elemento da pilha
 * @param pilha Pilha
 * @return Elemento retirado da pilha
 */
int pop(PilhaInt **pilha){

    if(*pilha == NULL){
        printf("Pilha ja esta vazia!");
        return -1;
    }
    int valor;
    PilhaInt *topoantigo;
    valor = (*pilha) -> valor;
    topoantigo = *pilha;
    *pilha = topoantigo -> inferior;
    free(topoantigo);
    return valor;
}

/**
 * Retorna o número de elementos que a pilha contém
 * @param pilha Pilha
 * @return Número de elementos
 */
int altura(PilhaInt *pilha)
{
    int cont=0;
    PilhaInt *iterador;
    iterador = pilha;
    while(iterador != NULL){
        iterador = iterador -> inferior;
        cont++;
    }
    return cont;
}
