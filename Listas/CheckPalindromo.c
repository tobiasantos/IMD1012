#include <stdio.h>

int potencia(int x, int y){
    int i;
    int pot = 1;

    for(i=0; i<y; i++)
        pot *= x;

    return pot;
}

int main() {
    int num, alg = 0, aux, checkPalin = 0, checkPar, entrada, doubleToInt;
    scanf("%d", &num);
    entrada = num;
    if (num%2 == 0) {
      checkPar = 1;
    } else {
      checkPar = 0;
    }
    while (num > 0) {
      num /= 10;
      alg++;
    }
    num = entrada;
    int i;
    for (i = 0; i < alg/2; i++) {
      aux = (num%potencia(10, i+1))/potencia(10, i);
      num /= potencia(10, alg-i-1);
      if (num == aux) {
        checkPalin = 1;
      } else {
          break;
      }
    }
    if (checkPar == 1 && checkPalin == 1) {
      printf("%d é um Palíndromo e par.", entrada);
    } else if (checkPar == 1 && checkPalin == 0) {
      printf("%d não é Palíndromo e par.", entrada);
    } else if (checkPar == 0 && checkPalin == 1) {
      printf("%d é Palíndromo e impar.", entrada);
    } else if (checkPar == 0 && checkPalin == 0) {
      printf("%d não é Palíndromo e impar.", entrada);
    }
    return 0;
}