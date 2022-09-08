#include <stdio.h>

int main() {
    int equipes, cont = 0, contC = 0, contS = 0, contL = 0;
    char prova;
    scanf("%d", &equipes);
    while (cont < equipes) {
        prova = ' ';
      while (prova != 'F') {
        scanf("%c", &prova);
        switch (prova) {
          case 'C': contC++; break;
          case 'S': contS++; break;
          case 'L': contL++; break;
        }
      }
      cont++;
    }
    printf("%d %d %d %d", contC, contS, contL, contC + contS + contL);
    return 0;
} 