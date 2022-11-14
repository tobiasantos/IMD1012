#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* modificaPalavra(char *palavra, int len) {
  // remove os espaços da string caso existam e devolve o resultado em UPPERCASE
  char modificada[len];
  char *retorno;
  int aux=0;

  for (int i=0; i<len; i++) {
    if (palavra[i] == ' ') {
      continue;
    } else {
      modificada[aux] = palavra[i];
      aux++;
    }
  }
  // coloque a linha pra fazer com q >modificada< fique em uppercase

  retorno = calloc(aux, sizeof(char));
  strcpy(retorno, modificada);

  return retorno;
}

int verificaPalindromo(char *palavra, int pos) {
  if (pos <= (strlen(palavra)/2)) {
    if (palavra[pos] == palavra[strlen(palavra)-(1+pos)]) {
      verificaPalindromo(palavra, pos+1);
    } else {
      return 0;
    }
  } else {
    return 1;
  }

}

int main() {
  int len;
  char linha[100];
  char *palavra;

  fgets(linha, 100, stdin);
  len = strlen(linha);
  linha[len-1] = '\0';
  // para funcionar no LOP, é necessário usar linha[len] = '\0';

  palavra = calloc(len, sizeof(char));
  strcpy(palavra, linha);

  char *novaPalavra;

  novaPalavra = calloc(len, sizeof(char));
  novaPalavra = modificaPalavra(palavra, len);

  if (verificaPalindromo(novaPalavra, 0)) {
    printf("O texto \"%s\" é palíndromo", palavra);
  } else {
    printf("O texto \"%s\" não é palíndromo", palavra);
  }

  free(palavra);
  palavra = NULL;
  free(novaPalavra);
  novaPalavra = NULL;
  
  return 0;
}