#include <stdio.h>

int main() {
    int quantAnos, anosRegistrados = 0, i;
    double tempo, soma = 0, indice;
    scanf("%d", &quantAnos);
    for (i = 0; i < quantAnos; i++) {
      scanf("%lf", &tempo);
      if (tempo != -1) {
        anosRegistrados++;
        soma += tempo;
      }
    }
    indice = soma/anosRegistrados;
    if (anosRegistrados > 0) {
        printf("%.2lf", indice);
    } else {
        printf("A competicao nao possui dados historicos!");
    }
    
    return 0;
}