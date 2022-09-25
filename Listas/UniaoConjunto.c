#include <stdio.h>


int main() {
    int n, m, aux, i, j, repete, valor;
    scanf("%d %d", &n, &m);
    int conjA[n], conjB[m], uniaoAB[n+m];
    aux = n;
    for (i=0; i<n; i++) {
      scanf("%d", &valor);
      conjA[i] = valor;
      uniaoAB[i] = valor;
    }
    for (i=0; i<m; i++) {
      scanf("%d", &valor);
      conjB[i] = valor;
      for (j=0; j<n; j++) {
        if (valor == conjA[j]) {
          repete = 1;
          break;
        } else {
          repete = 0;
        }
      }
      if (repete == 0) {
        uniaoAB[aux] = valor;
        aux++;
      }
    }
    for (i=0; i<aux; i++) {
      printf("%d ", uniaoAB[i]);
    }
  
    return 0;
}