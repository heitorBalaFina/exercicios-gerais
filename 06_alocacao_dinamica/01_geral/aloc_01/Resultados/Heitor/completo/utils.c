#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

int *CriaVetor(int tamanho){
    return (int *) malloc(tamanho*sizeof(int));
}

void LeVetor(int *vetor, int tamanho){
    int i;
    for(i=0; i < tamanho; i++){
        scanf("%d", &vetor[i]);
    }
}

float CalculaMedia(int *vetor, int tamanho){
    float media = 0;
    int i;
    for(i=0; i < tamanho; i++){
        media += vetor[i];
    }
    return media/tamanho;
}

void LiberaVetor(int *vetor){
    free(vetor);
}