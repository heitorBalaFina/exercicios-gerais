#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils_char.h"

char *CriaVetor(int tamanho){
    /*
    Aloca o espaco de memoria para o vetor sendo uma unidade a mais para
    poder colocar '\0' no final do vetor e poder tratar ele como string e 
    não apenas como vetor de caracteres
    */
    char *vetor = (char *) malloc((tamanho+1)*sizeof(char));
    
    // Inicializa o vetor com '_'
    int i;
    for(i = 0; i < tamanho; i++){
        vetor[i] = '_';
    }

    vetor[i] = '\0';
    
    return vetor;
}

void LeVetor(char *vetor, int tamanho){
    int i;
    char letra;
    //le tudo menos o '\n' para poder imprimir o vetor corretamente
    scanf(" %c", &letra);
    for(i=0; i < tamanho &&  letra != '\n'; i++){
        vetor[i] = letra;
        scanf("%c", &letra);
    }
}

void ImprimeString(char *vetor, int tamanho){
    printf("%s\n", vetor);
}

void LiberaVetor(char *vetor){
    free(vetor);
}