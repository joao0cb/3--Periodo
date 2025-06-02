#include <stdio.h>
#include <stdlib.h>

#define TAM 100

typedef struct No {
    int valor;
    struct No* prox;
} No;

No* tabela[TAM];

// QUESTÃO 8
void inserirInicio(No* tabela[], int valor) {
    No* temp = malloc(sizeof(No));
    if(temp == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return;
    }
    int chave = valor%TAM;
    temp->valor = valor;
    temp->prox = tabela[chave];
    tabela[chave] = temp;
}

// QUESTÃO 9
void inserirFinal(No* tabela[], int valor) {
    No* temp = malloc(sizeof(No));
    if(temp == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return;
    }
    int chave = valor%TAM;
    temp->prox = NULL;
    temp->valor = valor;
    if(tabela[chave] == NULL) {
        tabela[chave] = temp;
    } else {
        No* atual = tabela[chave];
        while(atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = temp;
    }
}

void imprimirTabela(No* tabela[]) {
    for (int i = 0; i < TAM; i++) {
        printf("Índice %d: ", i);
        No* atual = tabela[i];
        while (atual != NULL) {
            printf("%d -> ", atual->valor);
            atual = atual->prox;
        }
        printf("NULL\n");
    }
}


int main() {
    int opcao, valor;
    
    do {
        printf("Qual valor voce deseja inserir? ");
        scanf("%d", &valor);
        printf("\n--- Menu ---\n");
        printf("1. Inserir inicio\n");
        printf("2. Inserir Final\n");
        printf("3. Listar produtos\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1: inserirInicio(tabela, valor); break;
            case 2: inserirFinal(tabela, valor); break;
            case 3: imprimirTabela(tabela); break;
            case 4: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 4);

    return 0;
}
