#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pessoa.h"

Pessoa* cria_pessoa(char *nome, char *endereco, char *telefone) {
    Pessoa* p = (Pessoa*)malloc(sizeof(Pessoa));
    if(p != NULL) {
        strcpy(p->nome, nome);
        strcpy(p->endereco, endereco);
        strcpy(p->telefone, telefone);
    }
    return p;   
}

void libera_pessoa(Pessoa* pessoa) {
    free(pessoa);
}