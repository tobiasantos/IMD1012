#include <stdio.h>

void verificaVetor(int len, int* vetor) {
    int i, aux, check = 0;
    for (i=1; i<len; i++) {
        aux = vetor[i-1] - vetor[i];
        if (aux%2 != 0) {
            printf("Chato");
            check = 0;
            break;
        } else {
            check = 1;
        }
    }
    if (check == 1) {
        printf("Legal");
    }
}

int main() {
    int len, i, valor;
    scanf("%d", &len);
    int vetor[len];
    for (i=0; i<len; i++) {
        scanf("%d", &valor);
        vetor[i] = valor;
    }
    verificaVetor(len, vetor);

    return 0;
}