/******************************************************

Lista de Fun��es recursivas
Autor: Thiago Straiotto Fabri

******************************************************/

#include <stdio.h>
#include <string.h>
#include "CalcPosFix.h" /// recursao.h

/**
 * Calcula a soma dos inteiros de 1 at� N
 * @param n N
 * @return -1 se N for menor que 1, a soma caso contr�rio
 */
int soma(int n)
{
    if(n==0){
        return 0;
    }
    return n+soma(n-1);
}

/**
 * Calcula o fatorial de N
 * @param n N
 * @return -1 se N for menor que 0, o fatorial caso contr�rio
 */
int fatorial(int n)
{
    if(n==0){
        return 1;
    }
    return n*fatorial(n-1);
}

/**
 * Calcula o N-�simo elemento da s�rie de Fibonacci
 * @param n N
 * @return -1 se for menor que 0, o elemento caso contr�rio
 */
int fibonacci(int n)
{
    if(n<0){
        return -1;
    }
    if(n==1){
        return 1;
    }
    if(n==2){
        return 1;
    }
    if(n==0){
        return 0;
    }

    return fibonacci(n-1)+fibonacci(n-2);
}

/**
 * Calcula a soma dos elementos de um vetor
 * @param vetor Vetor
 * @param tamanho Tamanho do vetor
 * @return Soma dos elementos
 */
int somavetor(int vetor[], int tamanho)
{
    if(tamanho==1){
        return vetor[0];
    }
    if(tamanho==0){
        return 0;
    }
    if(tamanho<0){
        return -1;
    }
    else
        return vetor[tamanho-1]+somavetor(vetor, tamanho-2);
}


/**
 * Encontra um valor em um vetor atrav�s da busca bin�ria
 * @param vetor Vetor
 * @param alvo Valor a ser encontrado
 * @param primeiro Primeira posi��o do vetor
 * @param ultimo �ltima posi��o do vetor
 * @return Posi��o do elemento no vetor, ou -1 caso n�o encontre o elemento
 */
int buscaBinaria(int vetor[], int alvo, int primeiro, int ultimo)
{

    if(ultimo<=primeiro){
        return -1;
    }
    else{
        int meio=((ultimo+primeiro)/2);
        if(vetor[meio]==alvo){
            return meio;
        }else{
            if(vetor[meio]<alvo){
                return buscaBinaria(vetor, meio+1, ultimo,alvo);
            }else{
                return buscaBinaria(vetor, primeiro, meio-1, alvo);
            }
        }
    }
}


/**
 * Encontra o menor valor de um vetor
 * @param vetor Vetor
 * @param tamanho Tamanho do vetor
 * @return Menor elemento do vetor
 */
int findmin(int vetor[], int tamanho)
{
    if (tamanho <= 0)
        return -1;

    if (tamanho == 1)
        return vetor[0];

    int menor = findmin(vetor, tamanho- 1 );

    if (vetor[tamanho-1]< menor)
        return vetor[tamanho-1];

    else
        return menor;
}

/**
 * Verifica se uma string � um pal�ndromo (pode destruir a string no processo)
 * @param string String a ser avaliada
 * @return 1 se for um pal�ndromo, 0 se n�o for
 */
int palindromo(char *string)
{
	if (strlen(string) < 2)
		return 1;

	if (string[0] != string[strlen(string) - 1])
		return 0;

	string[strlen(string) - 1] = '\0';

	return palindromo(&(string[1]));
}

/**
* Retorna o nome do autor da classe
* @param Variavel que receber� o nome
* @return
*/
void autor(char nome[])
{
    sprintf(nome, "Thiago Straiotto Fabri");
}

int main(){

    int n=5;
    int vet[] = {1,2,3,4,5};
    char pa[] = "subionibus";
    printf("%d \n",soma(n));
    printf("%d \n",fatorial(n));
    printf("%d \n",fibonacci(n));
    printf("%d \n",somavetor(vet,n));
    printf("%d \n",buscaBinaria(vet,2, 0, 4));
    printf("%d \n", findmin(vet, n));
    printf("%d \n", palindromo(pa));
    return 0;
}

