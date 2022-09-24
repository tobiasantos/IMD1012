#include <stdio.h>


int main() {
    int i, valor, entrada[15];
    int aux1 = 0, aux2 = 0, aux3 = 0;
    for (i=0; i<15; i++) {
      scanf("%d", &valor);
      entrada[i] = valor;
      if (valor%2 == 0) {
        aux1++;
      }
      if (valor%3 == 0) {
        aux2++;
      }
      if (valor%2 != 0 && valor%3 != 0) {
        aux3++;
      }
      }
  int mult2[aux1], mult3[aux2], mult[aux3];
  int index1 = 0, index2 = 0, index3 = 0;
  
  for (i=0; i<15; i++) {
      if (entrada[i]%2 == 0) {
        mult2[index1] = entrada[i];
        index1++;
      }
      if (entrada[i]%3 == 0) {
        mult3[index2] = entrada[i];
        index2++;
      }
      if (entrada[i]%2 != 0 && entrada[i]%3 != 0) {
        mult[index3] = entrada[i];
        index3++;
      }
  }
  printf("B = [%d", mult2[0]);
  for (i=1;i<aux1;i++) {
    printf(", %d", mult2[i]);
  }
  printf("]\n");
  
  printf("C = [%d", mult3[0]);
  for (i=1;i<aux2;i++) {
    printf(", %d", mult3[i]);
  }
  printf("]\n");

  printf("D = [%d", mult[0]);
  for (i=1;i<aux3;i++) {
    printf(", %d", mult[i]);
  }
  printf("]\n");
    return 0;
}