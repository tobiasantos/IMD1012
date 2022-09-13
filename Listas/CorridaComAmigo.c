#include <stdio.h>

int verificaEncontro(int velocidade1, int velocidade2) {
  if (velocidade1 > velocidade2) {
    return 1;
  } else {
    return 0;
  }
}

int calculaDistancia(int velocidade, int posicao, int tempo) {
  return velocidade*tempo + posicao;
}

int calculaEncontro(int distancia, int velocidade1, int velocidade2) {
  int tempo = 0, posicaoEu, posicaoAmigo;
  posicaoEu = calculaDistancia(velocidade1, 0, 0);
  posicaoAmigo = calculaDistancia(velocidade2, distancia, 0);
  while (posicaoEu != posicaoAmigo) {
    tempo++;
    posicaoEu = calculaDistancia(velocidade1, 0, tempo);
    posicaoAmigo = calculaDistancia(velocidade2, distancia, tempo);
  }
  return tempo;
}

int main() {
    int distancia, velocidade1, velocidade2, tempo;
    scanf("%d %d %d", &distancia, &velocidade1, &velocidade2);
    if (verificaEncontro(velocidade1, velocidade2) == 1) {
      tempo = calculaEncontro(distancia, velocidade1, velocidade2);
      printf("%ds", tempo);
    } else {
      printf("impossivel");
    }
    return 0;
}