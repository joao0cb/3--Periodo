#include <stdio.h>
#include <stdlib.h>

void troca(int *x, int *y);

int main() {
    int *x = (int *)malloc(sizeof(int));
    int *y = (int *)malloc(sizeof(int));
    *x=10, *y=20;
    troca(x, y);
    printf("X = %d, Y = %d\n", *x, *y);
    free(x);
    free(y);

    return 0;
}

void troca(int *x, int *y) {
    int *aux = (int *)malloc(sizeof(int));
    *aux = *x;
    *x = *y;
    *y = *aux;
    free(aux);
}