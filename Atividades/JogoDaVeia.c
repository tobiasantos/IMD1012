#include <stdio.h>

void verificaJogada(int x, int y, int c, char matriz[3][3]) {
    int check;
    if (matriz[x][y] != '.') {
        printf("Jogada inválida!\n");
        check = -1;
    } else {
        matriz[x][y] = c;
        check = 0;
        // verifica colunas
        for (int cont = 0; cont<3; cont++) {
            if (matriz[0][cont] != '.') {
                if (matriz[0][cont] == matriz[1][cont] && matriz[1][cont] == matriz[2][cont]) {
                check = 1;
                }
            }
        }
        // verifica linhas
        for (int cont = 0; cont<3; cont++) {
            if (matriz[cont][0] != '.') {
                if (matriz[cont][0] == matriz[cont][1] && matriz[cont][1] == matriz[cont][2]) {
                check = 1;
                }
            }
        }
        // verifica diagonais
        if (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2]) {
            check = 1;
        }
        if (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0]) {
            check = 1;
        }
        matriz[x][y] = '.';
    }
    if (check == 0) {
        printf("Continua o jogo.\n");
    } else if (check == 1) {
        printf("Boa jogada, vai vencer!\n");
    }
}

int main() {
    int i, j;
    // cria tabuleiro
    char tabuleiro[3][3]; 
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            scanf(" %c", &tabuleiro[i][j]);
        }
    }
    // lê jogadas
    int x, y, n;
    char c;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d %d %c", &x, &y, &c);
        verificaJogada(x-1, y-1, c, tabuleiro);
    }
    return 0;
}