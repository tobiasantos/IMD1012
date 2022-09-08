#include <stdio.h>

int main() {
    int linhas, cont = 1, posicao = 1, elemento = 1;
    scanf("%d", &linhas);
    if (linhas <= 0) {
      printf("Você entrou com %d, tente de novo na próxima", linhas);
    }
    while (cont <= linhas) {
      while (posicao <= cont) {
        if (elemento < 10) {
          printf(" %d ", elemento);
        } else {
          printf("%d ", elemento);
        }
        elemento++;
        posicao++;
      }
      posicao = 1;
      cont++;
      printf("\n");
    }
    return 0;
}