#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[3];
    float pop, idh;
} Country;

enum info {
    pop,
    idh
};

Country criaPais(char entrada[500]) {
    Country aux;
    char auxNome[3];
    int lenEntrada, index = 0, indexEspaco; 
    char *entradaPOP, *entradaIDH;
    
    entradaPOP = calloc(1, sizeof(char));
    entradaIDH = calloc(1, sizeof(char));
    
    lenEntrada = strlen(entrada);
    
    for (int i=0; i<3; i++) {
        auxNome[i] = entrada[i];
    }
    
    for (int i=4; i<lenEntrada; i++) {
        if (entrada[i] == ' ') {
            indexEspaco = i;
            index = 0;
            break;
        } else {
            entradaPOP[index] = entrada[i];
            index++;
            entradaPOP = realloc(entradaPOP, sizeof(char)*(index+1));
        }
    }
    
    for (int i=(indexEspaco+1); i<lenEntrada; i++) {
        entradaIDH[index] = entrada[i];
        index++;
        entradaIDH = realloc(entradaIDH, sizeof(char)*(index+1));
    }
    
    strcpy(aux.nome, auxNome);
    aux.pop = atof(entradaPOP);
    aux.idh = atof(entradaIDH);
    
    free(entradaPOP);
    free(entradaIDH);
    
    return aux;
}

float media(Country *paises, int quant, int tipo) {
    float media = 0;
    
    if (tipo == 0) {
        for (int i=0; i<quant; i++) {
            media += paises[i].pop;
        }
    } else {
        for (int i=0; i<quant; i++) {
            media += paises[i].idh;
        }
    }
    
    return media/quant;
}

int main() {
    char entrada[500];
    Country *paises;
    int quantPaises = 0;
    
    paises = calloc(1, sizeof(Country));
    
    fgets(entrada, 500, stdin);
    
    while (entrada[0] != '-') {
        paises[quantPaises] = criaPais(entrada);
        quantPaises++;
        paises = realloc(paises, sizeof(Country)*(quantPaises + 1));
        fgets(entrada, 500, stdin);
    }
    
    float mediaPOP, mediaIDH;
    
    mediaPOP = media(paises, quantPaises, pop);
    mediaIDH = media(paises, quantPaises, idh);
    
    Country *paisesPOP, *paisesIDH;
    int quantPOP = 0, quantIDH = 0;
    
    paisesPOP = calloc(1, sizeof(Country));
    paisesIDH = calloc(1, sizeof(Country));
    
    for (int i=0; i<quantPaises; i++) {
        if (paises[i].pop >= mediaPOP) {
            paisesPOP[quantPOP] = paises[i];
            quantPOP++;
            paisesPOP = realloc(paisesPOP, sizeof(Country)*(quantPOP+1));
        }
        
        if (paises[i].idh <= mediaIDH) {
            paisesIDH[quantIDH] = paises[i];
            quantIDH++;
            paisesIDH = realloc(paisesIDH, sizeof(Country)*(quantIDH+1));
        }
    }
    
    for (int i=0; i<quantIDH; i++) {
        for (int j=0; j<quantPOP; j++) {
            if (!strcmp(paisesIDH[i].nome, paisesPOP[j].nome)) {
                printf("%s\n", paisesIDH[i].nome);
            }
        }
    }
    
    free(paises);
    free(paisesIDH);
    free(paisesPOP);
    
    return 0;
}