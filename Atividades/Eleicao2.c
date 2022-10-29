#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char *nome;
    int quantVotos;
} Party;

Party criaPartido() {
    char nome[501];
    Party aux;

    scanf("%d %s\n", &aux.id, nome);
    aux.nome = calloc(strlen(nome), sizeof(char));
    strcpy(aux.nome, nome);
    aux.quantVotos = 0;

    return aux;
}

int compute_votes(int num_votes, int votes[num_votes], int num_parties, Party parties[num_parties], Party *most_voted, Party *second_most_voted) {
    int valido = 0, totalValidos = 0;

    // contando votos
    for (int i=0; i<num_votes; i++) {
        for (int j=0; j<num_parties; j++) {
            if (votes[i] == parties[j].id) {
                valido = 1;
                parties[j].quantVotos++;
            }
        }
        if (valido) {
            totalValidos++;
            valido = 0;
        }
    }

    // checando top1 e top2 votados
    int aux1 = 0, aux2 = 0;
    for (int i=0; i<num_parties; i++) {
        if (parties[i].quantVotos > aux1) {
            *second_most_voted = *most_voted;
            *most_voted = parties[i];
            aux2 = aux1;
            aux1 = parties[i].quantVotos;
        } else if (parties[i].quantVotos > aux2) {
            *second_most_voted = parties[i];
            aux2 = parties[i].quantVotos;
        }
    }
    return totalValidos;
}

int main(void) {
    int numPartidos, lenNome;
    scanf("%d\n", &numPartidos);

    Party partidos[numPartidos];
    for (int i=0; i<numPartidos; i++) {
        partidos[i] = criaPartido();
    }

    int numVotos;
    scanf("%d\n", &numVotos);

    int totalVotos[numVotos];
    for (int i=0; i<numVotos; i++) {
        scanf("%d ", &totalVotos[i]);
    }

    Party *top1, *top2;
    double porcentagem;
    int validos;

    top1 = calloc(1, sizeof(Party));
    top2 = calloc(1, sizeof(Party));

    validos = compute_votes(numVotos, totalVotos, numPartidos, partidos, top1, top2);

    //printando resultado
    porcentagem = top1->quantVotos*100.0/validos;
    printf("VENCEDOR: %s (%d votos = %.2lf%%)\n", top1->nome, top1->quantVotos, porcentagem);
    porcentagem = top2->quantVotos*100.0/validos;
    printf("VICE: %s (%d votos = %.2lf%%)\n", top2->nome, top2->quantVotos, porcentagem);
  return 0;
}