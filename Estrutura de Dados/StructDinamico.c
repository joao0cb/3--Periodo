#include <stdio.h>

#define QTD_NOME 50
#define QTD_CIDADE 50

struct Registros {
    char nome[QTD_NOME];
    char cidade[QTD_CIDADE];
    int telefone;
};

void lerRegistro(struct Registros *rgt);
void imprimirRegistro(struct Registros *rgt);

int main() {
    struct Registros rgt, *pt;
    pt = &rgt;
    lerRegistro(pt);
    imprimirRegistro(pt);

    return 0;
}

void lerRegistro(struct Registros *rgt) {
    printf("Nome: ");
    fgets(rgt->nome, QTD_NOME, stdin);
    printf("Cidade: ");
    fgets(rgt->cidade, QTD_CIDADE, stdin);
    printf("Telefone: ");
    scanf("%d", &rgt->telefone);
    getchar();
}

void imprimirRegistro(struct Registros *rgt) {
    printf("\nNome: %sCidade: %sTelefone: %d", rgt->nome, rgt->cidade, rgt->telefone);
}