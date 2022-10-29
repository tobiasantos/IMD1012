#include <stdio.h>
#include <stdlib.h>

int get_range(int n, int cells[n], int distance, int user, int *left_index, int *right_index) {
    int aux, alterou = 0;
    for (int i=1; i<n; i++) {
        if (cells[i-1] <= user && cells[i] >= user) {
            aux = i;
            break;
        }
    }
    for (int i=1; i<n; i++) {
        if (cells[i-1] <= user-distance && cells[i] >= user-distance && cells[i]-distance < user-distance) {
            *left_index = i;
            alterou = 1;
        } else if (cells[i-1] <= user+distance && cells[i] >= user+distance && cells[i-1]+distance > user+distance) {
            *right_index = i-1;
            alterou = 1;
        } else if (user-distance < cells[0]) {
            *left_index = 0;
            alterou = 1;
        }
    }
    if (alterou) {
        return *right_index - *left_index + 1;
    } else {
        return 0;
    }
    
}

int main(void) {
  int num, alcance, posicao;
  scanf("%d %d %d\n", &num, &alcance, &posicao);
  int celulas[num];
  for (int i=0; i<num; i++) {
    scanf("%d", &celulas[i]);
  }

  int *limiteEsq, *limiteDir;

  limiteEsq = calloc(1, sizeof(int));
  limiteDir = calloc(1, sizeof(int));
  
  int quantidade;

  quantidade = get_range(num, celulas, alcance, posicao, limiteEsq, limiteDir);
  
  if (!quantidade) {
      printf("USUARIO DESCONECTADO");
  } else {
      for (int i=0; i<quantidade; i++) {
          printf("%d ", celulas[i + *limiteEsq]);
      }
  }
  return 0;
}