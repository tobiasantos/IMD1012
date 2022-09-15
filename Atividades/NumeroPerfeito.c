#include <stdio.h>
#include <stdbool.h>

bool verificaPerfeito(int num) {
  int i, soma = 0;
  for (i=1; i<(num/2)+1; i++) {
    if (num%i == 0) {
        soma += i;
    }
  }
  if (soma == num) {
    return true;
  } else {
    return false;
  }
}

int main() {
    int n, i, num;
    scanf("%d", &n);
    for (i = 0; i<n; i++) {
      scanf("%d", &num);
      if (verificaPerfeito(num)) {
        printf("%d eh perfeito\n", num);
      } else {
        printf("%d nao eh perfeito\n", num);
      }
    }
    return 0;
}