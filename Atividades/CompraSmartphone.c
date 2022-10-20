#include <stdio.h>
#include <string.h>

typedef struct {
  char modelo[40];
  int memoria;
  float processador, camera, bateria;
} Smartphone;

int cadastraSmartphone(int quant, Smartphone telefones[quant]) {
    int len;
    fgets(telefones[quant].modelo, 40, stdin);
    len = strlen(telefones[quant].modelo);
    telefones[quant].modelo[len-1] = '\0';
    scanf("%d\n%f\n%f\n%f\n", &telefones[quant].memoria, &telefones[quant].processador, &telefones[quant].camera, &telefones[quant].bateria);
    return quant+1;
}

int pesquisaSmartphones(int quant, Smartphone telefones[quant], Smartphone reqMin) {
    int cont = 0;
    for (int i=0; i<quant; i++) {
        if (reqMin.memoria <= telefones[i].memoria && reqMin.processador <= telefones[i].processador && reqMin.camera <= telefones[i].camera && reqMin.bateria <= telefones[i].bateria) {
            cont++;
            printf("Modelo: %s\n", telefones[i].modelo);
            printf("Memoria: %dGB\n", telefones[i].memoria);
            printf("Processador: %.2fGhz\n", telefones[i].processador);
            printf("Camera: %.2fMPixels\n", telefones[i]. camera);
            printf("Bateria: %.2fmA\n\n", telefones[i].bateria);
        }
    }
    printf("%d smartphones encontrados.", cont);
    return cont;
}

int main(){
    char verificador;
    int contador = 0;
    Smartphone telefones[100];
    Smartphone reqMin;

    scanf("%c\n", &verificador);
    while (verificador == 's') {
        contador = cadastraSmartphone(contador, telefones);
        scanf("%c\n", &verificador);
    }
    scanf("%d\n%f\n%f\n%f\n", &reqMin.memoria, &reqMin.processador, &reqMin.camera, &reqMin.bateria);
    pesquisaSmartphones(contador, telefones, reqMin);
    return 0;
}