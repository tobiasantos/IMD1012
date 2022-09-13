#include <stdio.h>

int verificaPrimo(int a) {
  
  int cont = 2;
  if (a < 2) {
      return 0;
  }
  
  while (cont <= a/2) {
    if (a%cont == 0) {
      return 0;
    } else {
      cont++;
    }
  }
  return 1;
}

int main() {
    int a;
    scanf("%d", &a);
    if (verificaPrimo(a) == 1 && verificaPrimo(a+2) == 1) {
      printf("Numero forma par de gemeos");
    } else {
      printf("Numero nao forma par de gemeos");
    }
    return 0;
}