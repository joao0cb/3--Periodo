#include <stdio.h>

#include "lista.h"

int main() {
    LSE* L = criar_LSE();
    LSE* L2 = criar_LSE();
    
    //int qtdNO, valor, maior, ult;

    inserir_inicio_LSE(L, 10);
    inserir_inicio_LSE(L, 20);
    inserir_inicio_LSE(L, 30);
    inserir_inicio_LSE(L, 40);
    inserir_inicio_LSE(L, 50);
    inserir_inicio_LSE(L2, 60);
    inserir_inicio_LSE(L2, 70);
    inserir_inicio_LSE(L2, 80);
    inserir_inicio_LSE(L2, 90);
    exibir_lista(L);
    exibir_lista(L2);
    LSE* L3 = merge(L, L2);
    exibir_lista(L3);


    /*qtdNO = comprimento(L);
    printf("\nExistem %d nos", qtdNO);

    printf("\nQual valor voce deseja conferir? ");
    scanf("%d", &valor);
    maior = maiores(L, valor);
    printf("Existem %d nos com o dado maior que %d", maior, valor);

    ult = ultimo(L);
    printf("\nO ultimo elemento da lista eh %d", ult);

    retira_n(L, 20);
    exibir_lista(L);*/




}