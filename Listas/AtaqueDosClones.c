#include <stdio.h>

int verificaBomba(int x, int y, int lin, int col, int matriz[lin][col]) {
  int maior = 0;
  if (x-1 >= 0 && matriz[x][y] > matriz[x-1][y]) {
    maior++;
  } if (x+1 <= lin-1 && matriz[x][y] > matriz[x+1][y]) {
      maior++;
  } if (y-1 >= 0 && matriz[x][y] > matriz[x][y-1]) {
      maior++;
  } if (y+1 <= col-1 && matriz[x][y] > matriz[x][y+1]){
      maior++;
  } if (x-1 >=0 && y-1 >= 0 && matriz[x][y] > matriz[x-1][y-1]) {
      maior++;
  } if (x-1 >=0 && y+1<= col-1 && matriz[x][y] > matriz[x-1][y+1]) {
      maior++;
  } if (x+1 <= lin-1 && y-1>=0 && matriz[x][y] > matriz[x+1][y-1]) {
      maior++;
  } if (x+1 <= lin-1 && y+1<=col-1 && matriz[x][y] > matriz[x+1][y+1]) {
      maior++;
  }
    if (x == 0 || x == lin-1) {
        if (y == 0 || y == col-1) {
            if (maior == 3) {
                return 1;
            }
        } else {
            if (maior == 5) {
                return 1;
            }
        }
    } else if (y == 0 || y == col-1) {
        if (x != 0 || x != lin-1) {
            if (maior == 5) {
                return 1;
            }
        }
    } else {
        if (maior == 8) {
            return 1;
        }
    }
  return 0;
}



int main() {
    int i, j, n, m, elemento, xj, yj;
    scanf("%d %d", &n, &m);
    int tabuleiro[n][m];
    scanf("%d %d", &xj, &yj);
    for (i=0; i<n;i++) {
      for (j=0;j<m;j++) {
        scanf("%d", &elemento);
        tabuleiro[i][j] = elemento;
      }
    }
    // verificar bombas
    int check, aux = 1;;
    for (i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            check = verificaBomba(i, j, n, m, tabuleiro);
            if (check == 1) {
                printf("Local %d: %d %d\n", aux, i+1, j+1);
                aux++;
            }
        }
    }
    // verificar resgate
    int rescue;
    rescue = verificaBomba(xj-1, yj-1, n, m, tabuleiro);
    if (rescue == 1) {
        printf("Descanse na Força...");
    } else {
        printf("Ao resgate!");
    }
    return 0;
}