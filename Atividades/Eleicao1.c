#include <stdio.h>
#include <stdlib.h>

void compute_votes(int n, int votes[n], int *most_voted, int *second_most_voted) {
  int aux1 = 0, aux2 = 0, quant = 0;
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      if (votes[i] == votes[j]) {
        quant++;
      }
    }
    if (votes[i] != *most_voted && votes[i] != *second_most_voted) {
        if (quant > aux1) {
        *second_most_voted = *most_voted;
        *most_voted = votes[i];
        aux2 = aux1;
        aux1 = quant;
        } else if (quant > aux2) {
        *second_most_voted = votes[i];
        aux2 = quant;
        }
    }
    quant = 0;
  }
}

int main(void) {
  int num;
  scanf("%d\n", &num);
  int votos[num];
  for (int i=0; i<num; i++) {
    scanf("%d", &votos[i]);
    }

  int *top1, *top2;
  
  top1 = calloc(1, sizeof(int));
  top2 = calloc(1, sizeof(int));
  
  compute_votes(num, votos, top1, top2);
  printf("%d %d", *top1, *top2);
  return 0;
}