#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"

int main() {
    Pessoa *p = cria_pessoa("Nome", "Rua", "99");

    if (p == NULL) {
        printf("Erro ao criar pessoa.\n");
        return 1;
    }

    printf("O telefone da pessoa eh: %s\n", p->telefone);

    libera_pessoa(p);
    return 0;
}