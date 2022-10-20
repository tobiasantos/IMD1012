#include <stdio.h>
#include <string.h>

typedef struct {
  char nome[201];
  int golsM, golsS;
} Time;

void ordenaTime(int quant, Time t[quant]) {
  Time aux;
  for (int j=0; j<quant-1; j++) {
    for (int i=1; i<quant; i++) {
        if (t[i-1].golsM < t[i].golsM) {
            aux = t[i-1];
            t[i-1] = t[i];
            t[i] = aux;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d\n", &n);
    int len;
    Time times[n];
    for (int i=0; i<n; i++) {
        fgets(times[i].nome, 201, stdin);
        len = strlen(times[i].nome);
        times[i].nome[len-1] = '\0';
        scanf("%d\n%d\n", &times[i].golsM, &times[i].golsS);
    }
    ordenaTime(n, times);

    for (int i=0; i<n; i++) {
        printf("%d - %s\n", i+1, times[i].nome);
        printf("Gols marcados: %d\n", times[i].golsM);
        printf("Gols sofridos: %d\n", times[i].golsS);
    }
    return 0;
}