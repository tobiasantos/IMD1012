#include <stdio.h>

int main() {
    int a, b;
    scanf("%d", &a);
    if (a < 10) {
      printf("%d", a);
    } else if (a < 100) {
      b = a%10;
      a /= 10;
      printf("%d\n%d", a, b);
    } else if (a < 1000) {
      b = a%100;
      a /= 100;
      printf("%d\n", a);
      a = b/10;
      b %=10;
      printf("%d\n%d", a, b);
    } else if (a < 10000) {
      b = a%1000;
      a /= 1000;
      printf("%d\n", a);
      a = b/100;
      b %= 100;
      printf("%d\n", a);
      a = b/10;
      b %= 10;
      printf("%d\n%d", a, b);
    } else {
      b = a%10000;
      a /= 10000;
      printf("%d\n", a);
      a = b/1000;
      b %= 1000;
      printf("%d\n", a);
      a = b/100;
      b %= 100;
      printf("%d\n", a);
      a = b/10;
      b %= 10;
      printf("%d\n%d", a, b);
    }
    return 0;
}