#include <stdio.h>
#include <string.h>

void lePalavra(char palavra[50]) {
  // palavra[len] para funcionar no LOP
  int len;
  fgets(palavra, 50, stdin);
  len = strlen(palavra);
  palavra[len-1] = '\0';
}

int verificaLetra(char letra, char palavra[50], int len) {
  int i, presente = 0;
  for (i = 0; i<len; i++) {
    if (palavra[i] == letra) {
      presente = 1;
      return presente;
    }
  }
  return presente;
}

void imprimeSeq(int len, char padrao[50]) {
  for (int a=0; a<=len; a++) {
      if (padrao[a] != '\0') {
          printf("%c ", padrao[a]);
      }
  }
}

void verificaPadrao(char padrao[50], char palavra[50], int len1, int len2) {
  char verificador[50] = {0};
  int i, j = 0, aux = 0, verificadorAux = 0;
  for (i=0; i<len1; i++) {
    if (palavra[i] == padrao[j]) {
      verificador[verificadorAux] = palavra[i];
      verificadorAux++;
      j++;
    } else {
      verificador[verificadorAux] = palavra[i];
      verificador[verificadorAux+1] = '\0';
      imprimeSeq(verificadorAux, verificador);
      printf("não\n");
      verificadorAux = 0;
      if (len1-i == len2) {
          break;
      }
      if (verificaLetra(palavra[i], padrao, len2) && j != 0) {
        aux++;
        j = 0;
        i = aux-1;
      } else {
        aux++;
        j = 0;
        continue;
      }
    }
    if (verificadorAux == len2) {
      imprimeSeq(len2, padrao);
      printf("sim\n");
      printf("Achei o padrão no índice %d", i-len2+1);
      break;
    }
  }
  if (verificadorAux != len2) {
      printf("Não achei o padrão\n");
  }
}

int main() {
  char sequencia[50] = {0};
  int tamanhoSequencia;
  // le sequencia e pega o tamanho
  lePalavra(sequencia);
  tamanhoSequencia = strlen(sequencia) - 1;
  // le padrao e pega o tamanho
  char padrao[50] = {0};
  int tamanhoPadrao;
  lePalavra(padrao);
  tamanhoPadrao = strlen(padrao);
  verificaPadrao(padrao, sequencia, tamanhoSequencia, tamanhoPadrao);
  return 0;
}