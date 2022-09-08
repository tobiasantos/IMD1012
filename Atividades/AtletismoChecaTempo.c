#include <stdio.h>

int main() {
    double corte, nota = 0;
    scanf("%lf", &corte);
    int participantes = 0;
    while (nota != -1) {
      scanf("%lf", &nota);
      if (nota <= corte && nota != -1) {
        participantes++;
      }
    }
    if (participantes%8 == 0) {
      printf("%d %d", participantes, participantes/8);
    } else if (participantes != 0) {
      printf("%d %d", participantes, participantes/8 + 1);
    } else {
      printf("%d", participantes);
    }
    return 0;
}