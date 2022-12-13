#include <stdio.h>

int combinacao(int a, int b) {
    if (b == 0 || b == a) {
        return 1;
    } else if (b==1) {
        return a;
    } else {
        return combinacao(a-1, b-1) + combinacao(a-1, b);
    }
}

int main() {
    int a, b;
    
    scanf("%d %d", &a, &b);
    printf("%d ", combinacao(a, b));
    return 0;
}