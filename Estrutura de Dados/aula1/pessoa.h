typedef struct pessoa
{
    char nome[40];
    char endereco[50];
    char telefone[20];
} Pessoa;


Pessoa* cria_pessoa(char *nome, char *endereco, char *telefone);

void libera_pessoa(Pessoa* pessoa);