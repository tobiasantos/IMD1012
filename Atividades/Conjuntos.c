#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int len;
    int *conteudo;
} Conjunto;

int verificaDentro(int num, int len, int *vetor) {
    for (int i=0; i<len; i++) {
        if (num == vetor[i]) {
            return 1;
        }
    }
    return 0;
}

Conjunto criaConjunto(int len, int *vetor) {
    Conjunto aux;

    aux.len = len;
    aux.conteudo = calloc(len, sizeof(int));

    for (int i=0; i<len; i++) {
        aux.conteudo[i] = vetor[i];
    }

    return aux;
}

Conjunto uniao(Conjunto *a, Conjunto *b) {
    Conjunto uniaoAB;
    int lenAux = 0;
    int conteudoAux[a->len + b->len];

    for (int i=0; i<(a->len); i++) {
        conteudoAux[i] = a->conteudo[i];
        lenAux++;
    }

    for (int i=0; i<(b->len); i++) {
        if (!verificaDentro(b->conteudo[i], a->len, a->conteudo)) {
            conteudoAux[lenAux] = b->conteudo[i];
            lenAux++;
        }
    }

    uniaoAB = criaConjunto(lenAux, conteudoAux);
    
    return uniaoAB;
}

Conjunto intersecao(Conjunto *a, Conjunto *b) {
    Conjunto intersecaoAB;
    int lenAux = 0;
    int conteudoAux[a->len + b->len];

    for (int i=0; i<(b->len); i++) {
        for (int j=0; j<(a->len); j++) {
            if (b->conteudo[i] == a->conteudo[j]) {
                conteudoAux[lenAux] = b->conteudo[i];
                lenAux++;
            }
        }
    }

    intersecaoAB = criaConjunto(lenAux, conteudoAux);

    return intersecaoAB;
}

void printaConjunto(int len, int *vetor) {
    if (len == 0) {
        printf("{vazio}");
        return;
    } else {
        printf("{");
        for (int i=0; i<len-1; i++) {
            printf("%d ", vetor[i]);
        }
        printf("%d}", vetor[len-1]);
    }

}

int main(void) {
    int tam;
    Conjunto conjA, conjB;

    scanf("%d ", &tam);
    int contA[tam];
    for (int i=0; i<tam; i++) {
        scanf("%d ", &contA[i]);
    }

    conjA = criaConjunto(tam, contA);

    scanf("%d", &tam);
    int contB[tam];
    for (int i=0; i<tam; i++) {
        scanf("%d ", &contB[i]);
    }

    conjB = criaConjunto(tam, contB);

    Conjunto uniaoAB, interAB;

    uniaoAB = uniao(&conjA, &conjB);
    interAB = intersecao(&conjA, &conjB);

    printf("A união B == ");
    printaConjunto(uniaoAB.len, uniaoAB.conteudo);
    printf("\n");
    printf("A interseção B == ");
    printaConjunto(interAB.len, interAB.conteudo);
    
  return 0;
}