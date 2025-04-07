typedef struct no {
	int dado;
	struct no* prox;
}No;


typedef struct lse {
	No* inicio;
}LSE;

No* criar_no(int novo_dado);
LSE *criar_LSE();
void inserir_inicio_LSE(LSE* L, int novo_dado);
void inserir_fim_LSE(LSE* L, int novo_dado);
void exibir_lista(LSE* L);
int comprimento (LSE* L);
int maiores(LSE* L, int x);
int ultimo(LSE* L);
void retira_n(LSE* L, int x);
LSE* separa(LSE* L, int x);
LSE* merge(LSE* L1, LSE* L2);