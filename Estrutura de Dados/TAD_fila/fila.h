typedef struct no {
	int dado;
	struct no* prox;
}No;


typedef struct fila {
	No* inicio;
	No* fim;
}Fila;

No* criar_no(int novo_dado);
Fila* iniciar_fila();
void inserir_fila(Fila* f, int novo_dado);
void retirar_fila(Fila* f);
void exibir_elementos_fila(Fila* f);
int consultar_inicio_fila(Fila* f);
void combina_filas(Fila* F_res, Fila* F1, Fila* F2);