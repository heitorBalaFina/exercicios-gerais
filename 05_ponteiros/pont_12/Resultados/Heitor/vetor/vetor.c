#include "vetor.h"
#include <stdio.h>
#include <string.h>

void LeVetor(Vetor *vetor){
    int i;
    scanf("%d", &vetor->tamanhoUtilizado);
    for(i = 0; i< vetor->tamanhoUtilizado; i++) {
        scanf("%d", &vetor->elementos[i]);
    }
}

int AplicarOperacaoVetor(Vetor *vetor, Operation op){
    int resultado = vetor->elementos[0];
    int i;
    for (i = 1; i < vetor->tamanhoUtilizado; i++) {
        resultado = op(resultado, vetor->elementos[i]);
    }
    return resultado;
}