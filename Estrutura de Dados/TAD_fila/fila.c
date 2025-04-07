#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "fila.h"

No* criar_no(int novo_dado) {
	No* novo_no = (No*)malloc(sizeof(No));
	novo_no->dado = novo_dado;
	novo_no->prox = NULL;
	return(novo_no);
}

Fila *iniciar_fila() {
	Fila *f = (Fila *)malloc(sizeof(Fila));
	f->inicio = NULL;
	f->fim = NULL;
	return(f);
}

void inserir_fila(Fila* f, int novo_dado) {
	No* novo_no = criar_no(novo_dado);
	if (f->inicio == NULL) {
		f->inicio = novo_no;
		f->fim = novo_no;
	}
	else {
		f->fim->prox = novo_no;
		f->fim = novo_no;
	}
}

void retirar_fila(Fila* f) {
	No* temp = f->inicio;

	if (f->inicio == NULL) {
		printf("\nFila vazia!");
		return;
	}
	else {
		f->inicio = f->inicio->prox;
		if (f->inicio == NULL) {  //fila so tem um elemento
			f->fim = NULL;
		}
		free(temp);
	}
}

int consultar_inicio_fila(Fila* f) {
	if (f->inicio == NULL) {
		return (INT_MIN);
	}
	else {
		return(f->inicio->dado);
	}
}

void exibir_elementos_fila(Fila* f) {
	No* temp = f->inicio;
	printf("\nOs elementos da fila sao: ");
	while (temp != NULL) {
		printf("%d ", temp->dado);
		temp = temp->prox; 
	}
}

void combina_filas(Fila* F_res, Fila* F1, Fila* F2) {
	while(F1->inicio != NULL || F2->inicio != NULL) {
		if(F1->inicio != NULL) {
			int temp = consultar_inicio_fila(F1);
			inserir_fila(F_res, temp);
			retirar_fila(F1);
		}
		if(F2->inicio != NULL) {
			int temp2 = consultar_inicio_fila(F2);
			inserir_fila(F_res, temp2);
			retirar_fila(F2);
		}
	}
}