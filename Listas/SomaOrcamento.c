#include <stdio.h>

int main() {
    int quant, quantTotal = 0;
    double preco, precoTotal = 0;
    while (quant != -1) {
      scanf("%d", &quant);
      if (quant != -1) {
        scanf("%lf", &preco);
        quantTotal += quant;
        precoTotal += preco*quant;
      }
    }
    printf("%d %.2lf", quantTotal, precoTotal);
    return 0;
}