#include <stdio.h>


void ordenaVetor(int len, int vetor[99]) {
  int i, j, aux, p;
  for (p=0; p<len; p++) {
      printf("%d ", vetor[p]);
    }
  printf("\n");
  for (i=0; i<len-1; i++) {
    for (j=i+1; j < len; j++) {
      if (vetor[i] > vetor[j]) {
        aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
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