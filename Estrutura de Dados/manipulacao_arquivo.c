
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
    int ativo; // 1 = ativo, 0 = removido
} Produto;


void cadastrar_produto(FILE* f) {
    Produto p;

    printf("Codigo: ");
    scanf("%d", &p.codigo);
    getchar(); // Limpar buffer
    printf("Nome: ");
    fgets(p.nome, 50, stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0';
    printf("Preco: ");
    scanf("%f", &p.preco);
    printf("Quantidade: ");
    scanf("%d", &p.quantidade);
    p.ativo = 1;

    f = fopen("produtos.dat", "ab");
    if (!f) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    fwrite(&p, sizeof(Produto), 1, f);
    fclose(f);
    printf("Produto cadastrado com sucesso.\n");

}


void listar_produtos(FILE* f) {
    Produto p;
    f = fopen("produtos.dat", "rb");
    if (!f) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    printf("\n--- Lista de Produtos Ativos ---\n");
    while (fread(&p, sizeof(Produto), 1, f)) {
        if (p.ativo) {
            printf("Codigo: %d\nNome: %s\nPreco: %.2f\nQuantidade: %d\n\n",
                   p.codigo, p.nome, p.preco, p.quantidade);
        }
    }
    fclose(f);
}


void buscar_produto(FILE* f) {
    int codigo;
    Produto p;

    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo);
    f = fopen("produtos.dat", "rb");
    if (!f) {
        perror("Erro ao abrir o arquivo");
        return;
    }


    int encontrado = 0;
    while (fread(&p, sizeof(Produto), 1, f)) {
        if (p.ativo && p.codigo == codigo) {
            printf("Produto encontrado:\n");
            printf("Nome: %s\nPreco: %.2f\nQuantidade: %d\n", p.nome, p.preco, p.quantidade);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto não encontrado.\n");
    }
    fclose(f);

}


void atualizar_produto(FILE* f) {
    Produto p;
    int codigo;
    printf("Qual o codigo do produto que deseja mudar? ");
    scanf("%d", &codigo);
    printf("\n");

    printf("Novo codigo: ");
    scanf("%d", &p.codigo);
    getchar(); // Limpar buffer
    printf("Novo nome: ");
    fgets(p.nome, 50, stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0';
    printf("Novo preco: ");
    scanf("%f", &p.preco);
    printf("Quantidade: ");
    scanf("%d", &p.quantidade);
    p.ativo = 1;

    f = fopen("produtos.dat", "rb+");
    if (!f) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    Produto temp;
    while(fread(&temp, sizeof(Produto), 1, f)) {
        if(codigo == temp.codigo) {
            fseek(f, -sizeof(Produto), SEEK_CUR);
            fwrite(&p, sizeof(Produto), 1, f);
            printf("Produto encontrado com sucesso.\n");
            fclose(f);
            return;
        }
    }
    printf("Produto nao encontrado.\n");
    fclose(f);
}


void remover_produto(FILE* f) {
    int codigo;
    printf("Qual o codigo do produto que deseja remover? ");
    scanf("%d", &codigo);
    printf("\n");

    f = fopen("produtos.dat", "rb");
    FILE *arqTemp = fopen("tempProdutos.dat", "wb");
    if (!f || !arqTemp) {
        printf("Erro ao abrir arquivos temporarios.\n");
        return;
    }

    Produto temp;
    while (fread(&temp, sizeof(Produto), 1, f)) {
        if (codigo != temp.codigo) {
            fwrite(&temp, sizeof(Produto), 1, arqTemp);
        }
    }

    fclose(f);
    fclose(arqTemp);
    remove("produtos.dat");
    rename("tempProdutos.dat", "produtos.dat");
}


int main() {
    FILE* f = NULL;
    int opcao;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Cadastrar produto\n");
        printf("2. Listar produtos\n");
        printf("3. Buscar produto por codigo\n");
        printf("4. Atualizar produto\n");
        printf("5. Remover produto\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1: cadastrar_produto(f); break;
            case 2: listar_produtos(f); break;
            case 3: buscar_produto(f); break;
            case 4: atualizar_produto(f); break;
            case 5: remover_produto(f); break;
            case 6: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 6);

    return 0;
}
