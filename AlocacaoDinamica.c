#include <stdio.h>

void troca(int *x, int *y);

int main() {
    int x, y;
    x=10, y=20;
    troca(&x, &y);
    printf("X = %d, Y = %d", x, y);
}

void troca(int *x, int *y) {
    int aux = *x;
    *x = *y;
    *y = aux;
}