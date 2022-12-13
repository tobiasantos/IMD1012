#include <stdio.h>

void modificaMatriz(int ordem, int matriz[ordem][ordem]) {
  for (int t=1; t<=(ordem/2); t++) {
    for (int i=t; i<ordem-t; i++) {
      matriz[0][i] += 1;
      matriz[ordem-1][i] += 1;
    }
  }

  for (int i=1; i<=ordem/2; i++) {
    for (int j=0; j<ordem; j++) {
      if (ordem%2 == 0 && i == ordem/2) {
        continue;
      }
      matriz[i][j] = matriz[i-1][j] + 1;
      matriz[ordem-(1+i)][j] = matriz[ordem-(i)][j] + 1;
    }
  }
}

void printaMatriz(int lin, int col, int matriz[lin][col]) {
    for (int i=0; i<lin; i++) {
        for (int j=0; j<col; j++) {
            printf("%2.1d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
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