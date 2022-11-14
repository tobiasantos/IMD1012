#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int nlin, ncol;
  char **mat;
} Tabuleiro;

Tabuleiro* createMatrix(int nlin, int ncol) {
  Tabuleiro *aux;
  
  aux = calloc(1, sizeof(Tabuleiro));
  
  aux->nlin = nlin;
  aux->ncol = ncol;

  aux->mat = calloc(nlin, sizeof(char*));
  for (int i=0; i<nlin; i++) {
    aux->mat[i] = calloc(ncol, sizeof(char));
  }

  return aux;
}

void readMatrix(Tabuleiro *m) {
  for (int i=0; i<(m->nlin); i++) {
    for (int j=0; j<(m->ncol); j++) {
      scanf(" %c", &m->mat[i][j]);
    }
  }
}

void printMapa(Tabuleiro *m) {
  for (int i=0; i<(m->nlin); i++) {
    for (int j=0; j<(m->ncol); j++) {
      printf("%c", m->mat[i][j]);
    }
    printf("\n");
  }
}

void destroyMatrix(Tabuleiro **m) {
  for (int i=0; i<((*m)->nlin); i++) {
    (*m)->mat[i] = NULL;
    free((*m)->mat[i]);
  }
  
  free((*m)->mat);
  (*m)->mat = NULL;
  
  *m = NULL;
  free(*m);
}

int contaCaminho(Tabuleiro *mapa, int posX, int posY) {
  int contador = 0;
    if (posX-1 >= 0 && mapa->mat[posX-1][posY] == '.') {
      mapa->mat[posX-1][posY] = ' ';
      contador += (1 + contaCaminho(mapa, posX-1, posY));
    }
    if (posX+1 < (mapa->nlin) && mapa->mat[posX+1][posY] == '.') {
      mapa->mat[posX+1][posY] = ' ';
      contador += (1 + contaCaminho(mapa, posX+1, posY));
    }
    if (posY-1 >= 0 && mapa->mat[posX][posY-1] == '.') {
      mapa->mat[posX][posY-1] = ' ';
      contador += (1 + contaCaminho(mapa, posX, posY-1));
    }
    if (posY+1 < (mapa->ncol) && mapa->mat[posX][posY+1] == '.') {
      mapa->mat[posX][posY+1] = ' ';
      contador += (1 + contaCaminho(mapa, posX, posY+1));
    }
  
    return contador;
}

int main() {
  int lin, col;
  Tabuleiro* mapa;
  
  scanf("%i %i", &lin, &col);
  mapa = createMatrix(lin, col);
  readMatrix(mapa);
  int posX, posY, quant = 0;
  for (int i=0; i<(mapa->nlin); i++) {
    for (int j=0; j<(mapa->ncol); j++) {
      if ((mapa->mat[i][j]) == 'C') {
        posX = i;
        posY = j;
      }
    }
  }
  quant = contaCaminho(mapa, posX, posY);
  printf("Total de bolinhas devoradas: %d\n", quant);
  printf("Mapa final:\n");
  printMapa(mapa);
  destroyMatrix(&mapa);

  return 0;
}