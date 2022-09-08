#include <stdio.h>

int main() {
    char letra;
    int linhas, cont = 1, quant, posicao = 1;
    scanf("%d %c", &linhas, &letra);
    quant = linhas;
    while (cont < linhas) {
      while (posicao < quant) {
        if (posicao == cont) {
          printf("%c", letra);
        };
        if (posicao == (quant - cont)) {
          if ((quant - cont) == cont) {
            printf(" ");
          } else {
            printf("%c", letra);
          }
        };
        if (posicao != cont && posicao != (quant-cont)) {
          printf(" ");
        }
        posicao++;
      }
      printf("\n");
      posicao = 1;
      cont++;
    }
    return 0;
}