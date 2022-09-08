#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    double soma = 0, somaInv = 0, produto = 1, mediaA, mediaG, mediaH, erroH, erroG, erroMedio;
    for (i = 0; i < 10; i++) {
      scanf("%d", &n);
      soma += n;
      somaInv += 1./n;
      produto *= n;
    }
  
    mediaA = soma/10;
    mediaH = 10/somaInv;
    mediaG = pow(produto, 1./10);

    erroH = (mediaH - mediaA) / mediaA;
    erroG = (mediaG- mediaA) / mediaA;
    erroMedio = (erroH + erroG)/2;
    erroMedio *= 100;

    printf("Média aritmética é %.2lf\nMédia harmônica é %.2lf\nMédia geométrica é %.2lf\nErro médio é %.2lf %%", mediaA, mediaH, mediaG, erroMedio);
    return 0;
}