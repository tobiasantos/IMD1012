#include <stdio.h>

void ehPar(int num) {
  if (num%2 == 0) {
    printf("true");
  } else {
    printf("false");
  }
}
int main() {
    int num;
    scanf("%d", &num);
    ehPar(num);
    return 0;
}