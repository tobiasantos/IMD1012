#include <stdio.h>


int main() {
    int n, m, aux = 0, i, j = 0, repete, valor;
    scanf("%d %d", &n, &m);
    int conjA[n], conjB[m], interAB[n+m];

  // criando o conjunto A
    for (i=0; i<n; i++) {
      scanf("%d", &valor);
      conjA[i] = valor;
    }
// criando o conjunto B
    for (i=0; i<m; i++) {
      scanf("%d", &valor);
      conjB[i] = valor;
    }

    for (i=0; i<n; i++) {
      for (j=0; j<m; j++) {
        if (conjA[i] == conjB[j]) {
          interAB[aux] = conjA[i];
          aux++;
        }
      }
    }
// printando a resposta
    for (i=0; i<aux; i++) {
      printf("%d ", interAB[i]);
    }
  
    return 0;
}