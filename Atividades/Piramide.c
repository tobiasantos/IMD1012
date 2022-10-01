#include <stdio.h>

void modificaMatriz(int ordem, int matriz[ordem][ordem]) {
    for (int t=1; t<=ordem/2; t++) {
        for (int i=t; i<ordem-t; i++) {
            for (int j=t; j<ordem-t; j++) {
                matriz[i][j] += 1;
            }
        }
    }
}


void printaMatriz(int lin, int col, int matriz[lin][col]) {
    for (int i=0; i<lin; i++) {
        for (int j=0; j<col; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // cria matriz
    int ordem;
    scanf("%d", &ordem);
    int matriz[ordem][ordem];
    for (int i=0; i<ordem; i++) {
        for (int j=0; j<ordem; j++) {
            matriz[i][j] = 1;
        }
    }
    modificaMatriz(ordem, matriz);
    printaMatriz(ordem, ordem, matriz);
    return 0;
}