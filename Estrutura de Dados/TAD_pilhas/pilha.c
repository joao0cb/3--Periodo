#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "pilha.h"

No* criar_no(int novo_dado) {
	No *novo_no = (No*)malloc(sizeof(No));
	novo_no->dado = novo_dado;
	novo_no->prox = NULL;
	return(novo_no);
}

Pilha *iniciar_pilha() {
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	p->inicio = NULL;
	return(p);
}

void empilhar(Pilha* p, int novo_dado) {
	No* novo_no = criar_no(novo_dado);
	novo_no->prox = p->inicio;
	p->inicio = novo_no;
}

void desempilhar(Pilha* p) {
	if (p->inicio == NULL) {
		printf("Erro: pilha vazia!");
	}
	else {
		No* temp = p->inicio;
		p->inicio = p->inicio->prox;
		free(temp);
	}
}

int top(Pilha* p) {
	if (p->inicio != NULL) {
		return(p->inicio->dado);
	}
	else {
		printf("\nPilha vazia!");
		return(INT_MIN);
	}
	
}

void liberarPilha(Pilha* p) {
	while(p->inicio != NULL) {
		printf("\nDesempilhando... O topo da pilha eh igual a %d", top(p));
		desempilhar(p);
	}
	if(p->inicio == NULL) {
		printf("\nA pilha agora esta vazia.\n");
	}
}

void inverterVetor(Pilha* p, int v[], int tam) {
	for(int i = 0; i < tam; ++i) {
		empilhar(p, v[i]);
	}
	imprimirVetor(v, tam);
	printf("\n");
	for(int i = 0; i < tam; ++i) {
		v[i] = top(p);
		desempilhar(p);
	}
	imprimirVetor(v, tam);
}

void imprimirVetor(int v[], int tam) {
	for(int i = 0; i < tam; ++i) {
		printf("%d\t", v[i]);
	}
}

void concatena_pilha(Pilha* p1, Pilha* p2) {
	while(p2->inicio != NULL) {
		No* novo_no = criar_no(p2->inicio->dado);
		novo_no->prox = p1->inicio;
		p1->inicio = novo_no;

		No* temp = p2->inicio;
		p2->inicio = p2->inicio->prox;
		free(temp);
	}
}

void concatena_pilhas(Pilha* p1, Pilha* p2) {
	while(p2->inicio != NULL) {
		empilhar(p1, top(p2));
		desempilhar(p2);
	}
}