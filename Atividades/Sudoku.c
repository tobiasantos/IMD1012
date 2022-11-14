#include <stdio.h>
#include <stdlib.h>

int leTabuleiro(char **m) {
  // devolve a quantidade de vazios
  int aux=0;
  for (int i=0; i<9; i++) {
    for (int j=0; j<9; j++) {
      scanf(" %c", &m[i][j]);
      if (m[i][j] == '*') {
        aux++;
      }
    }
  }
  return aux;
}

void localizaVazios(char **m, int *posX, int *posY, int quant) {
  int index=0;

  for (int i=0; i<9; i++) {
    for (int j=0; j<9; j++) {
      if (m[i][j] == '*') {
        posX[index] = i;
        posY[index] = j;
        index++;
      }
    }
  }
}

int repeteSubMatriz(char **m, int x, int y, char c) {
  for (int i=(x-(x%3)); i<(x-(x%3)+3); i++) {
    for (int j=(y-(y%3)); j<(y-(y%3)+3); j++) {
      if (m[i][j] == c) {
        return 1;
      }
    }
  }
  return 0;
}

int repeteLinha(char **m, int x, int y, char c) {
  for (int j=0; j<9; j++) {
    if (m[x][j] == c) {
      return 1;
    }
  }
  return 0;
}

int repeteColuna(char **m, int x, int y, char c) {
  for (int i=0; i<9; i++) {
    if (m[i][y] == c) {
      return 1;
    }
  }
  return 0;
}

void printTabuleiro(char **m) {
  for (int i=0; i<9; i++) {
    for (int j=0; j<9; j++) {
      printf("%c", m[i][j]);
    }
    printf("\n");
  }
}

int completaTabuleiro(char **m, int quant, int *posX, int *posY) {
  int x, y;
  if (quant == 0) {
    return 1;
  } else {
    for (int i=1; i<10; i++) {
      x = posX[quant-1];
      y = posY[quant-1];
      if (!repeteSubMatriz(m, x, y, i+'0') && !repeteLinha(m, x, y, i+'0') && !repeteColuna(m, x, y, i+'0')) {
        m[x][y] = i + '0';
        if (!completaTabuleiro(m, quant-1, posX, posY)) {
            m[x][y] = '*';
        } else {
          return 1;
        }
      }
    }
  }
  return 0;
}

int main() {
  char **matriz;

  matriz = calloc(9, sizeof(char*));
  for (int i=0; i<9; i++) {
    for (int j=0; j<9; j++) {
      matriz[i] = calloc(9, sizeof(char));
    }
  }

  int *posX, *posY;
  int quantVazios;

  quantVazios = leTabuleiro(matriz);

  posX = calloc(quantVazios, sizeof(int));
  posY = calloc(quantVazios, sizeof(int));
  
  localizaVazios(matriz, posX, posY, quantVazios);

  if (completaTabuleiro(matriz, quantVazios, posX, posY)) {
    printTabuleiro(matriz);
  } else {
    printf("Não tem solução!\n");
  }

  return 0;
}