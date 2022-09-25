#include <stdio.h>

int verificaEq(int a, int b) {
    if (a == b) {
        return 1;
    } else {
        return 0;
    }
}

void ordenaVetor(int len, int* vetor) {
  int i, j, aux, p;
  for (i=0; i<len-1; i++) {
    for (j=i+1; j < len; j++) {
      if (vetor[i] > vetor[j]) {
        aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
      }
    }
  }
  for (p=0; p<len; p++) {
      printf("%d ", vetor[p]);
    }
}

int main() {
    int n, m, aux, aux2 = 0, i, j, repete = 0, valor, respCheck = 1, aux3 = 0;
    scanf("%d %d", &n, &m);
    int conjA[n], conjB[m], uniaoAB[n+m], interAB[n+m], diferencaSim[n+m];
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
        repete = verificaEq(valor, conjA[j]);
        if (repete == 1) {
          break;
        }
      }
      if (repete == 0) {
        uniaoAB[aux] = valor;
        aux++;
      }
    }
    for (i=0; i<n; i++) {
      for (j=0; j<m; j++) {
        repete = verificaEq(conjA[i], conjB[j]);
        if (repete == 1)  {
          interAB[aux2] = conjA[i];
          aux2++;
        }
      }
    }
    for (i=0; i<aux; i++) {
      for (j=0; j<aux2; j++) {
        repete = verificaEq(uniaoAB[i], interAB[j]);
        if (repete == 1) {
          respCheck = 0;
          break;
        } else {
          respCheck = 1;
        }
      }
      if (respCheck == 1) {
        diferencaSim[aux3] = uniaoAB[i];
        aux3++;
      }
    }
    ordenaVetor(aux3, diferencaSim);
    return 0;
}