#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

void main() {
	Fila* f1;
	Fila* f2;
	Fila* f_res;
	int i;

	f1 = iniciar_fila();
	f2 = iniciar_fila();
	f_res = iniciar_fila();
	inserir_fila(f1, 10);
	inserir_fila(f1, 5);
	inserir_fila(f1, 20);
	inserir_fila(f2, 13);
	inserir_fila(f2, 245);
	inserir_fila(f2, 0);
	inserir_fila(f2, 76);
	inserir_fila(f_res, 4);
	inserir_fila(f_res, 23);

	combina_filas(f_res, f1, f2);
	exibir_elementos_fila(f1);
	exibir_elementos_fila(f2);
	exibir_elementos_fila(f_res);
	/*retirar_fila(f);
	exibir_elementos_fila(f);
	i = consultar_inicio_fila(f);
	printf("\nO elemento do inicio da fila eh: %d", i);*/
	
}