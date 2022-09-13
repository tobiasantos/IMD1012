#include <stdio.h>

int mdc(int x, int y) {
  if (y == 0) {
    return x;
  } else {
    return mdc(y, x%y);
  }
}
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("MDC(%d , %d) = %d", a, b, mdc(a, b));
    return 0;
}