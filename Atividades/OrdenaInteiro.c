#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int charToInt(char c) {
  return c - '0';
}

void ordenaVetor(int len, int* vetor) {
  int i, j, aux, p;
  for (j=0; j<len-1; j++) {
    for (i=1; i<len; i++) {
        if (vetor[i-1] > vetor[i]) {
            aux = vetor[i-1];
            vetor[i-1] = vetor[i];
            vetor[i] = aux;
            }
        }
    }
  }
  
void printaVetor(int len, int *vetor) {
    for (int i=0; i<len; i++) {
        printf("%d ", vetor[i]);
    }
}

int main(void) {
    char *entrada;
    char entradaAux[501];
    int entradaLen;

    fgets(entradaAux, 501, stdin);
    entradaLen = strlen(entradaAux);
    if (entradaLen > 1) {
        entradaAux[entradaLen-1] = '\0';
        entradaLen--;
    }
    

    entrada = calloc(entradaLen, sizeof(char));
    strcpy(entrada, entradaAux);    

    int *lista;
    int elemento = 0, dezenas = 1, lenLista = 0;
    
    lista = calloc(1, sizeof(int));

    for (int i=entradaLen-1; i>=0; i--) {
        if (entrada[i] == ' ') {
            lista[lenLista] = elemento;
            lenLista++;
            lista = realloc(lista, sizeof(int)*(lenLista+1)); 
            dezenas = 1;
            elemento = 0;
        } else if (entrada[i] == '-') {
            elemento *= -1;
        } else {
            elemento += charToInt(entrada[i])*dezenas;
            dezenas *= 10;
        }
        if (i == 0) {
            lista[lenLista] = elemento;
            lenLista++;
        }
    }

    ordenaVetor(lenLista, lista);
    printaVetor(lenLista, lista);
    
  return 0;
}