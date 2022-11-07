#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char nome[500];
  char **participantes, *participante;
  int n = 0;

  fgets(nome, 500, stdin);

  participante = calloc(strlen(nome), sizeof(char));
  strcpy(participante, nome);

  participantes = calloc(1, sizeof(char*));
  participantes[n] = participante;
  n++;

  while(strcmp(nome, "acabou\n") != 0) {
    fgets(nome, 500, stdin);

    if ((strcmp(nome, "acabou\n") != 0)) {
      participante = calloc(strlen(nome), sizeof(char));
      strcpy(participante, nome);

      participantes = realloc(participantes, sizeof(char*)*n+1);
      participantes[n] = participante;
      n++;
    }
  }

  int seed, indice_participante, aux = 0;
  scanf("%d", &seed);
  srand(seed);
  
  char sorteados[100] = "a";
  
  while (aux < n) {
        indice_participante = rand()%n;
        if (participantes[indice_participante][0] != '0') {
            printf("%s", participantes[indice_participante]);
            participantes[indice_participante][0] = '0';
            aux++;
        }
  }
  return 0;
}