#include <stdio.h>
#include <stdlib.h>

#define LIN 3
#define COL 4

void printMatriz(int *mat, int lin, int col);

int main() {
    int *mat = (int *)malloc(LIN*COL*sizeof(int));
    for(int i = 0; i < LIN; ++i) {
        for(int j = 0; j < COL; ++j) {
            mat[(i*COL)+j] = 0;
        }
    }
    printMatriz(mat, LIN, COL);
    free(mat);

    return 0;
}

void printMatriz(int *mat, int lin, int col) {
    for(int i = 0; i < lin; ++i) {
        for(int j = 0; j < col; ++j) {
            printf("%d ", mat[(i*col)+j]);
        }
        printf("\n\n");
    }
}