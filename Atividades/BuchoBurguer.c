#include <stdio.h>

int main() {
    int combo, capital, troco;
    scanf("%d %d", &combo, &capital);
    if (combo == 1) {
      troco = capital - 12;
    } else if (combo == 2) {
      troco = capital - 23;
    } else if (combo == 3) {
      troco = capital - 31;
    } else if (combo == 4) {
      troco = capital - 28;
    } else if (combo == 5) {
      troco = capital - 15;
    }

    if (troco > 0) {
      printf("Troco = %d reais", troco);
    } else if (troco < 0) {
      troco *= -1;
      printf("Saldo insuficiente! Falta %d reais", troco);
    } else {
      printf("Deu certim!");
    }
    return 0;
}