#ifndef CALCPOSFIX_H_INCLUDED
#define CALCPOSFIX_H_INCLUDED

typedef struct PilhaDouble
{
	double valor;
	struct PilhaDouble *inferior;
	
} PilhaDouble;

/* funcoes basicas */ 
int estaVazia(PilhaDouble *pilha);
void esvaziaPilha(PilhaDouble **pilha);
void push(PilhaDouble **pilha, double valor);
double pop(PilhaDouble **pilha);
int altura(PilhaDouble *pilha);

/*funcoes principais*/
int soma(PilhaDouble **pilha);
int subtrai(PilhaDouble **pilha);
int multiplica(PilhaDouble **pilha);
int divide(PilhaDouble **pilha);

/*auxiliares*/
void autor(char nome[]);

#endif // CALCPOSFIX_H_INCLUDED
