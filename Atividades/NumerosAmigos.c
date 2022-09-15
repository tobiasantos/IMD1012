#include <stdio.h>
#include <stdbool.h>

bool testaDivisor(int num, int div) {
  if (num%div == 0) {
    return true;
  } else {
    return false;
  }
}

int somaDivisores(int num) {
  int i, soma = 0;
  for (i=1; i<(num/2)+1; i++) {
    if (testaDivisor(num, i)) {
      soma += i;
    }
  }
  return soma;
}
bool testaAmigos(int num1, int num2) {
  int soma1, soma2;
  soma1 = somaDivisores(num1);
  soma2 = somaDivisores(num2);
  if (soma1 == num2 && soma2 == num1 && num1 != num2) {
    return true;
  } else {
    return false;
  }
}

int main() {
    int a1, a2, b1, b2;
    scanf("%d %d %d %d", &a1, &b1, &a2, &b2);
    int i=a1, aux, amigo = 0;
    while (i < b1+1) {
      aux = somaDivisores(i);
      if (a2 < aux && aux < b2) {
        if (testaAmigos(aux, i)) {
          printf("O %d possui um amigo!\n", i);
          amigo = 1;
        }
      }
      i++;
    }
    if (amigo == 0) {
      printf("Os intervalos nao apresentam amigos!");
    }
    return 0;
}