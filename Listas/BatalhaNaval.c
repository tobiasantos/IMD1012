#include <stdio.h>
#include <stdlib.h>

char** criaMapa(char **m) {
    m = calloc(10, sizeof(char*));
    for (int i=0; i<10; i++) {
        m[i] = calloc(10, sizeof(char));
    }

    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            m[i][j] = '~';
        }
    }
    return m;
}

void printMapa(char **m) {
  for (int i=0; i<10; i++) {
    for (int j=0; j<10; j++) {
      printf("%c", m[i][j]);
    }
    printf("\n");
  }
}

void insereCanoa(char **m) {
  int x, y;
  scanf("%d %d", &x, &y);
  m[x][y] = '*';
}

void insereBarco(char **m) {
  int x[2], y[2];
  for (int i=0; i<2; i++) {
    scanf("%d %d", &x[i], &y[i]);
  }
    if (x[0] == x[1]) {
      m[x[0]][y[0]] = '<';
      m[x[1]][y[1]] = '>';
    } else {
      m[x[0]][y[0]] = '^';
      m[x[1]][y[1]] = 'v';
    }
}

void insereFragata(char **m) {
  int x[3], y[3];
  for (int i=0; i<3; i++) {
    scanf("%d %d", &x[i], &y[i]);
  }
    if (x[0] == x[1]) {
      m[x[0]][y[0]] = '<';
      m[x[1]][y[1]] = '=';
      m[x[2]][y[2]] = '>';
    } else {
      m[x[0]][y[0]] = '^';
      m[x[1]][y[1]] = '|';
      m[x[2]][y[2]] = 'v';
    }
}

void insereDestroyer(char **m) {
  int x[4], y[4];
  for (int i=0; i<4; i++) {
    scanf("%d %d", &x[i], &y[i]);
  }
    if (x[0] == x[1]) {
      m[x[0]][y[0]] = '<';
      m[x[1]][y[1]] = '=';
      m[x[2]][y[2]] = '=';
      m[x[3]][y[3]] = '>';
    } else {
      m[x[0]][y[0]] = '^';
      m[x[1]][y[1]] = '|';
      m[x[2]][y[2]] = '|';
      m[x[3]][y[3]] = 'v';
    }
}

void desalocaMatriz(char **m) {
  for (int i=0; i<10; i++) {
    free(m[i]);
  }
  
  free(m);
}

int main() {
  char **mapa;
  int posX[10], posY[10];
  
  mapa = criaMapa(mapa);
  
  insereCanoa(mapa);
  insereBarco(mapa);
  insereFragata(mapa);
  insereDestroyer(mapa);
  printMapa(mapa);
  desalocaMatriz(mapa);
  
  return 0;
}