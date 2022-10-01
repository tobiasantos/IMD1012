#include <stdio.h>

void organizaBandeira(int largura, int altura, int bandeira[altura][largura]) {
    int passo = largura/3;
    int aux=0;
    while (aux < largura) {
        if (aux < passo) {
            for (int i=0; i<altura; i++) {
                bandeira[i][aux] += 1; 
            }
        } else if (aux >= passo && aux < 2*passo) {
            for (int i=0; i<altura; i++) {
                bandeira[i][aux] += 2; 
            }
        } else {
            for (int i=0; i<altura; i++) {
                bandeira[i][aux] += 3; 
            }
        }
        aux++;
    }
}

int calcularAposta(int largura, int altura, int bandeira[altura][largura], char cor) {
    int passo = largura/3;
    int aposta = 0;
    if (cor == 'G') {
        aposta += bandeira[0][0]*altura*passo;
    } else if (cor == 'Y') {
        aposta += bandeira[0][passo]*altura*passo;
    } else if (cor == 'R') {
        aposta += bandeira[0][largura-1]*altura*passo;
    }
    return aposta;
}

int main() {
    int largura, numInicial;
    char cor;
    scanf("%d %d %c", &largura, &numInicial, &cor);
    // criando bandeira
    int altura = (largura/3)*2;
    int bandeira[altura][largura];
    for (int i=0; i<altura; i++) {
        for (int j=0; j<largura; j++) {
            bandeira[i][j] = numInicial;
        }
    }
    organizaBandeira(largura, altura, bandeira);
    // calcula aposta
    int aposta;
    aposta = calcularAposta(largura, altura, bandeira, cor);
    printf("%d\n", aposta);
    return 0;
}