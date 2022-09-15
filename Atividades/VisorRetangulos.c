#include <stdio.h>

void verificaRetangulo(double esq, double inf, double dir, double sup, double esq2, double inf2, double dir2, double sup2) {
  int aux;
  if (esq < esq2 && esq2 < dir) {
    if (esq < dir2 && dir2 < dir) {
      if (inf < inf2 && inf2 < sup) {
        if (inf < sup2 && sup2 < sup) {
          printf("(<%.2lf,%.2lf>,<%.2lf,%.2lf>) contem (<%.2lf,%.2lf>,<%.2lf,%.2lf>).\n", esq, inf, dir, sup, esq2, inf2, dir2, sup2);
        } else { aux = 1; }
      } else { aux = 1; }
    } else { aux = 1; }
  } else if (esq2 < esq && esq < dir2) {
    if (esq2 < dir  && dir < dir2) {
      if (inf2 < inf && inf < sup2) {
        if (inf2 < sup && sup < sup2) {
          printf("(<%.2lf,%.2lf>,<%.2lf,%.2lf>) contem (<%.2lf,%.2lf>,<%.2lf,%.2lf>).\n", esq2, inf2, dir2, sup2, esq, inf, dir, sup);
        } else { aux = 1; }
      } else { aux = 1; }
    } else { aux = 1; }
  } else {
    printf("Nao posso afirmar!\n");
  }
  if (aux == 1) {
    printf("Nao posso afirmar!\n");
  }
}

int verificaFim(double a, double b, double c, double d) {
  if (a == 0 && b == 0 && c == 0 && d == 0) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
    double esq, inf, dir, sup;
    double esq2, inf2, dir2, sup2;
    int aux;
    scanf("%lf %lf %lf %lf", &esq, &inf, &dir, &sup);
    aux = verificaFim(esq, inf, dir, sup);
    while (aux == 0) {
      scanf("%lf %lf %lf %lf", &esq2, &inf2, &dir2, &sup2);
      aux = verificaFim(esq2, inf2, dir2, sup2);
      if (aux == 0) {
        verificaRetangulo(esq, inf, dir, sup, esq2, inf2, dir2, sup2);
      }
    }
    
    return 0;
}