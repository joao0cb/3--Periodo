#include <stdio.h>
#include <stdlib.h>

void preencherVetorNotas(float *v, int tam);
float *alocarVetorFloat(int tamanho);
void imprimirVetor(float *v, int tamanho);
float mediaNotas(float *v, int tam);

int main () {
	
	int tamanho = 10;
	float *v = alocarVetorFloat(tamanho);

	preencherVetorNotas(v, tamanho);
	imprimirVetor(v, tamanho); 
    float mediaN = mediaNotas(v, tamanho);
    printf("\n\nA media das notas eh: %f", mediaN);
	free(v);

    return 0;
}

void preencherVetorNotas(float *v, int tam) {
    float nota;
    for(int i = 0; i < tam; ++i) {
        scanf("%f", &nota);
        *(v+i) = nota;
    }
}

float *alocarVetorFloat(int tamanho){
	return( (float *)malloc(tamanho*sizeof(float)) );
}

void imprimirVetor(float *v, int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		printf("\n%.2f", *(v+i));
    }
}

float mediaNotas(float *v, int tam) {
    float soma, media;
    for(int i = 0; i < tam; ++i) {
        soma += *(v+i);
        media = soma/tam;
    }
    return media;
}

/*
void troca(int *x, int *y){
	int *aux;
	aux = (int *)malloc(sizeof(int));
	
	*aux = *x; 
	*x = *y;
	*y = *aux;
}
*/