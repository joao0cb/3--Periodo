#include <stdio.h>

#include "pilha.h"

#define TAM 5

void main() {
	Pilha* p;
	int topo;
	int v[TAM] = {1,2,3,4,5};

	p = iniciar_pilha();
	empilhar(p, 10);
	empilhar(p, 20);
	empilhar(p, 30);
	topo = top(p);
	printf("\nO topo da pilha eh igual a %d", topo);
	//desempilhar(p);
	topo = top(p);
	printf("\nO topo da pilha eh igual a %d", topo);
	liberarPilha(p);
	inverterVetor(p, v, TAM);
}