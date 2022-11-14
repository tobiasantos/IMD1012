#include <stdio.h>

void decToBin(int n) {
  if (n < 2) {
    printf("%d", n%2);
  } else {
    decToBin(n/2);
    printf("%d", n%2);
  }
}

int main() {
  int num;
  scanf("%d", &num);
  decToBin(num);
  printf("\n");
  return 0;
}