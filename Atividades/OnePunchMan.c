#include <stdio.h>

int main() {
    int herois, classe, monstro;
    scanf("%d %d %d", &herois, &classe, &monstro);
  if (herois <= 0) {
    printf("Melhor chamar Saitama!");
  } else {
    switch (monstro) {
      case 1:
        if (classe >= 2 || herois >= 3) {
          printf("Heróis vencerão!");
        } else {
          printf("Melhor chamar Saitama!");
        }
        break;
      case 2:
        if (classe >= 3) {
          printf("Heróis vencerão!");
        } else if (classe == 2 && herois >= 3) {
          printf("Heróis vencerão!");
        } else {
          printf("Melhor chamar Saitama!");
        }
        break;
      case 3:
        if (classe >= 4) {
          printf("Heróis vencerão!");
        } else if (classe == 3 && herois >= 3) {
          printf("Heróis vencerão!");
        } else {
          printf("Melhor chamar Saitama!");
        }
        break;
      case 4:
        if (classe >= 5) {
          printf("Heróis vencerão!");
        } else if (classe == 4 && herois >= 3) {
          printf("Heróis vencerão!");
        } else {
          printf("Melhor chamar Saitama!");
        }
        break;
      case 5:
        if (classe == 5) {
          printf("Heróis vencerão!");
        } else {
          printf("Melhor chamar Saitama!");
        }
        break;
      }
  }
    
    return 0;
}