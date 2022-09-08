#include <stdio.h>

int main() {
  float temp1, temp2, temp3;
  char escala;
  scanf("%f %s", &temp1, &escala);
  if (escala == 'C') {
    temp2 = temp1 + 273.15;
    temp3 = temp1*1.8 + 32;
  } else if (escala == 'F') {
    temp3 = temp1;
    temp1 = (temp3 - 32)/1.8;
    temp2 = temp1 + 273.15;
  } else if (escala == 'K') {
    temp2 = temp1;
    temp1 = temp2 - 273.15;
    temp3 = temp1*1.8 + 32;
  }
  printf("Celsius: %.2f\nFarenheit: %.2f\nKelvin: %.2f", temp1, temp3, temp2);
    return 0;
}