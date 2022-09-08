#include <stdio.h>

int main() {
    int sup, esq, inf, dir, x, y;
    scanf("%d %d %d %d %d %d", &sup, &esq, &inf, &dir, &x, &y);
    if (x >= sup && x <= inf) {
      if (y >= esq && y <= dir) {
        printf("Dentro!");
      }
      else {
        printf("Fora!");
      }
    }
    else {
      printf("Fora!");
    }
    return 0;
}