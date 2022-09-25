#include <stdio.h>

void printAprovados(int len, int* aprovados, int* chamada, double* notas) {
    int i, aux;
    printf("Aprovados: ");
    for (i=0; i<len-1; i++) {
        aux = aprovados[i];
        printf("%d (%.1lf), ", chamada[aux], notas[aux]);
    }
    aux = aprovados[len-1];
    printf("%d (%.1lf)\n", chamada[aux], notas[aux]);
}

void printRecupera(int len, int* recuperando, int* chamada, double* notas) {
    int i, aux;
    printf("Recuperação: ");
    for (i=0; i<len-1; i++) {
        aux = recuperando[i];
        printf("%d (%.1lf), ", chamada[aux], notas[aux]);
    }
    aux = recuperando[len-1];
    printf("%d (%.1lf)\n", chamada[aux], notas[aux]);
}

void printReprovados(int len, int* reprovados, int* chamada, double* notas) {
    int i, aux;
    printf("Reprovados: ");
    for (i=0; i<len-1; i++) {
        aux = reprovados[i];
        printf("%d (%.1lf), ", chamada[aux], notas[aux]);
    }
    aux = reprovados[len-1];
    printf("%d (%.1lf)\n", chamada[aux], notas[aux]);
}

int main() {
    int matricula, i, alunos, aux1 = 0, aux2 = 0, aux3 = 0, aux = 0;
    scanf("%d", &alunos);
    int chamada[alunos], aprovados[alunos], reprovados[alunos], recuperando[alunos];
    double nota, notas[alunos];
    for (i = 0; i<alunos; i++) {
        scanf("%d - %lf", &matricula, &nota);
        chamada[i] = matricula;
        notas[i] = nota;
        if (nota >= 7) {
            aprovados[aux1] = i;
            aux1++;
        } else if (nota >= 5) {
            recuperando[aux2] = i;
            aux2++;
        } else {
            reprovados[aux3] = i;
            aux3++;
        }
    }

    printAprovados(aux1, aprovados, chamada, notas);
    printRecupera(aux2, recuperando, chamada, notas);
    printReprovados(aux3, reprovados, chamada, notas);
    
    return 0;
}