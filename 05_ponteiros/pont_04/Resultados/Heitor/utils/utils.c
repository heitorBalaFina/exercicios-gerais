#include "utils.h"
#include "stdio.h"

#define NUM_GRANDE 100000
#define NUM_PEQUENO 0
#define ZERO 0

void LeNumeros(int *array, int tamanho){
    int posicao;
    for(posicao = 0; posicao < tamanho; posicao++) 
        scanf(" %d", &array[posicao]);
}

void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media){
    *maior = NUM_PEQUENO;
    *menor = NUM_GRANDE;
    *media = ZERO;
    int posicao;
    for(posicao = 0; posicao < tamanho; posicao++){
        if(array[posicao] > *maior) *maior = array[posicao];
        if(array[posicao] < *menor) *menor = array[posicao];
        *media += array[posicao];
    }
    *media = *media/tamanho;
}
