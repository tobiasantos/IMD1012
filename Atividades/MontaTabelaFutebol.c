#include <stdio.h>
#include <string.h>

typedef struct {
  char nome[201];
  int vitorias, empates, derrotas, golsM, golsS;
} Time;

Time criaTime(char entrada[210]) {
    Time aux;
    

    fgets(entrada, 210, stdin);
    strcpy(aux.nome, strtok(entrada, ";"));
    sscanf(strtok(NULL, "\n"), "%d %d %d %d %d", &aux.vitorias, &aux.empates, &aux.derrotas, &aux.golsM, &aux.golsS);
    
    return aux;
}

void organizaTabela(int quant, Time times[quant]) {
    Time aux, aux1, aux2;
    int pontuacaoTimeA, pontuacaoTimeB;
    int sgA, sgB;
    for (int j=0; j<quant; j++) {
        for (int i=1; i<quant; i++) {
            pontuacaoTimeA = times[i-1].vitorias*3 + times[i-1].empates;
            pontuacaoTimeB = times[i].vitorias*3 + times[i].empates;
            sgA = times[i-1].golsM - times[i-1].golsS;
            sgB = times[i].golsM - times[i].golsS;
            if (pontuacaoTimeA < pontuacaoTimeB) {
                aux = times[i-1];
                times[i-1] = times[i];
                times[i] = aux;
            } else if (pontuacaoTimeA == pontuacaoTimeB && times[i-1].vitorias < times[i].vitorias) {
                aux = times[i-1];
                times[i-1] = times[i];
                times[i] = aux;
            } else if (pontuacaoTimeA == pontuacaoTimeB && times[i-1].vitorias == times[i].vitorias && sgA < sgB) {
                aux = times[i-1];
                times[i-1] = times[i];
                times[i] = aux;
            }
        }
    }
}

void imprimeTabela(int quant, Time times[quant]) {
    int pontuacao, sg, partidas;
    printf("Tabela do campeonato:\n");
    printf("Nome| Pontos| Jogos| Vitorias| Empates| Derrotas| Gols Pro| Gols Contra| Saldo de Gols\n");
    for (int i=0; i<quant; i++) {
        pontuacao = times[i].vitorias*3 + times[i].empates;
        sg = times[i].golsM - times[i].golsS;
        partidas = times[i].vitorias + times[i].empates + times[i].derrotas;
        printf("%s| %d| %d| %d| %d| %d| %d| %d| %d\n", times[i].nome, pontuacao, partidas , times[i].vitorias, times[i].empates, times[i].derrotas, times[i].golsM, times[i].golsS, sg);
    }
    printf("\nTimes na zona da libertadores:\n");
    for (int i=0; i<6; i++) {
        printf("%s\n", times[i].nome);
    }
    printf("\nTimes rebaixados:\n");
    for (int i=quant-1; i>quant-5; i--) {
        printf("%s\n", times[i].nome);
    }
}

int main() {
    int quant;
    scanf("%d\n", &quant);
    Time times[quant];
    char entrada[210];

    for (int i=0; i<quant; i++) {
        times[i] = criaTime(entrada);
    }

    organizaTabela(quant, times);
    imprimeTabela(quant, times);

  return 0;
}