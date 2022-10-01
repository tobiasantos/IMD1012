#include <stdio.h>

void analisaMapa(int lin, int col, char mapa[lin][col]) {
    double quantAgua = 0, quantDeserto = 0, quantVegetacao = 0, quantSemRecurso = 0, quantEspHostil = 0;
    for (int i=0; i<lin; i++) {
        for (int j=0; j<col; j++) {
            if (mapa[i][j] == '~') {
                quantAgua++;
            } else if (mapa[i][j] == 'X') {
                quantEspHostil++;
            } else if (mapa[i][j] == '^') {
                quantDeserto++;
            } else if (mapa[i][j] == '*') {
                quantVegetacao++;
            } else if (mapa[i][j] == '.') {
                quantSemRecurso++;
            }
        }
    }
    double total = lin*col;
    if (quantEspHostil > 0) {
        printf("Planeta Hostil");
    } else if (quantAgua/total >= 0.85) {
        printf("Planeta Aquático");
    } else if (quantDeserto/total >= 0.6) {
        printf("Planeta Desértico");
    } else if (quantVegetacao/total >= 0.65) {
        printf("Planeta Selvagem");
    } else if (quantAgua/total >= 0.5 && quantVegetacao/total >= 0.2 && quantEspHostil == 0) {
        printf("Planeta Classe M");
    } else {
        printf("Planeta Inóspito");
    }
}

int main() {
    int i, j;
    // criando o mapa
    int n, m;
    scanf("%d %d", &n, &m);
    char mapa[n][m];
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            scanf(" %c", &mapa[i][j]);
        }
    }
    // analisando mapa
    analisaMapa(n, m, mapa);
    return 0;
}