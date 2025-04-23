#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "lista.h"

No* criar_no(int novo_dado) {
	No* novo_no = (No*)malloc(sizeof(No));
	novo_no->dado = novo_dado;
	novo_no->prox = NULL;
	return(novo_no);
}

LSE *criar_LSE() {
    LSE *L = (LSE*)malloc(sizeof(LSE));
    L->inicio = NULL;
    return L;
}

void inserir_inicio_LSE(LSE* L, int novo_dado) {
	No* novo_no = criar_no(novo_dado);
	novo_no->prox = L->inicio;
	L->inicio = novo_no;
}

void inserir_fim_LSE(LSE* L, int novo_dado) {
	No* novo_no = criar_no(novo_dado);
	if (L->inicio == NULL) {
		L->inicio = novo_no;
	} else {
        No *temp = L->inicio;
        while(temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo_no;
    }
}

void exibir_lista(LSE* L) {
	No *temp; 
	if(L->inicio == NULL){
		printf("Lista vazia!");
	}
	else {
		temp = L->inicio;
		printf("\nOs elementos da lista sao:");
		while(temp != NULL){
			printf("\n%d", temp->dado);
			temp = temp->prox;
		}
	}
}

int comprimento (LSE* L) {
	int i = 0;
	No* temp = L->inicio;
	while(temp != NULL) {
		++i;
		temp = temp->prox;
	}
	return i;
}

int maiores(LSE* L, int x) {
	int i = 0;
	No* temp = L->inicio;
	while(temp != NULL) {
		if(temp->dado > x) {
			++i;
		}
		temp = temp->prox;
	}
	return i;
}

int ultimo(LSE* L) {
	int i = 0;
	No* temp = L->inicio;
	while(temp != NULL) {
		i = temp->dado;
		temp = temp->prox;
	}
	return i;
}

void concatena(LSE* L1, LSE* L2) {
	No* temp = L1->inicio;
	while(temp->prox != NULL) {
		temp = temp->prox;
	}
	temp->prox = L2->inicio;
	L2->inicio = NULL;
}

void retira_n(LSE* L, int x) {
	No* temp = L->inicio;
	No* anterior = NULL;
	while(temp != NULL && temp->dado != x) {
		anterior = temp;
		temp = temp->prox;
	}
	anterior->prox = temp->prox;
	free(temp);
}


LSE* merge(LSE* L1, LSE* L2) {
	LSE* L3 = criar_LSE();
	No* temp1 = L1->inicio;
	No* temp2 = L2->inicio;
	while(temp1 != NULL || temp2 != NULL) {
		if(temp1 != NULL) {
			inserir_inicio_LSE(L3, temp1->dado);
			temp1 = temp1->prox;
			No* atual = L1->inicio;
			No* temp;
		
			while (atual != NULL) {
				temp = atual;
				atual = atual->prox;
				free(temp);
			}
		
			L1->inicio = NULL;
		}
		if(temp2 != NULL) {
			inserir_inicio_LSE(L3, temp1->dado);
			temp2 = temp2->prox;
			No* atual = L2->inicio;
			No* temp;
		
			while (atual != NULL) {
				temp = atual;
				atual = atual->prox;
				free(temp);
			}
		
			L2->inicio = NULL;
		}
	}
}

LSE* separa(LSE* L3, int x) {
    No* temp = L3->inicio;
    LSE* L4 = criar_LSE();

    // Procurar o elemento x
    while(temp != NULL && temp->dado != x) {
        temp = temp->prox;
    }

    // Se x foi encontrado, avançar para o próximo nó
    if(temp != NULL) {
        temp = temp->prox;
    }

    // Inserir os elementos restantes na nova lista
    while(temp != NULL) {
        inserir_fim_LSE(L4, temp->dado);
        temp = temp->prox;
    }

	return L4;
}