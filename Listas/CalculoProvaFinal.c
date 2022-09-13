#include <stdio.h>

double menorNota(double nota1, double nota2, double nota3) {
  if (nota1 <= nota2 && nota1 <= nota3) {
    return nota1;
  } else if (nota2 <= nota1 && nota2 <= nota3) {
    return nota2;
  } else {
    return nota3;
  }
}

double calcNota(double nota1, double nota2, double nota3) {
  double total;
  total = nota1 + nota2 + nota3;
  if (total >= 21) {
    return -1;
  } else if (total > 15 && menorNota(nota1, nota2, nota3) > 3) {
    return -1;
  } else if (total <= 15) {
    total -= menorNota(nota1, nota2, nota3);
    if (15 - total < 3) {
      return 3;
    }
    return 15 - total;
  }
  return 0;
}

int main() {
  double nota1, nota2, nota3;
  scanf("%lf %lf %lf", &nota1, &nota2, &nota3);
  if (nota1 < 3 || nota2 < 3 || nota3 < 3) {
    printf("Nao faz prova final");
  } else {
    printf("Final\n%.1lf", calcNota(nota1, nota2, nota3));
  }
    return 0;
}