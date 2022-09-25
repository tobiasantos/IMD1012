#include <stdio.h>


void ordenaVetor(int len, int* vetor) {
  int i, j, aux, p;
  for (p=0; p<len; p++) {
      printf("%d ", vetor[p]);
    }
  printf("\n");
  for (j=0; j<len-1; j++) {
    for (i=1; i<len; i++) {
        if (vetor[i-1] > vetor[i]) {
            aux = vetor[i-1];
            vetor[i-1] = vetor[i];
            vetor[i] = aux;
            }
        }
    for (p=0; p<len; p++) {
      printf("%d ", vetor[p]);
        }
    printf("\n");
    }
  }

int main() {
    int len, i, valor;
    scanf("%d", &len);
    int vetor[len];
    for (i=0; i<len; i++) {
      scanf("%d", &valor);
      vetor[i] = valor;
    }
    ordenaVetor(len, vetor);
    return 0;
}