#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils_char2.h"

char *CriaVetorTamPadrao(){
    
    //char *vetor = (char *) malloc((TAM_PADRAO+1)*sizeof(char));
    char *vetor = malloc((TAM_PADRAO+1)*sizeof(char));
    if(vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(0);
    }

    int i;
    for(i = 0; i < TAM_PADRAO; i++) vetor[i] = '_';
    vetor[i] = '\0';

    return vetor;
}

char *LeVetor(char *vetor, int *tamanho) {
    int i = 0;
    char letra;

    while (scanf("%c", &letra) == 1 && letra != '\n') {
        if (i == *tamanho) {
            vetor = AumentaTamanhoVetor(vetor, *tamanho);
            *tamanho += TAM_PADRAO;
        }

        vetor[i] = letra;
        i++;
    }

    return vetor;
}

void ImprimeString(char *vetor){
    printf("%s\n", vetor);
}

void LiberaVetor(char *vetor){
    free(vetor);
}

char *AumentaTamanhoVetor(char *vetor, int tamanhoantigo) {
    int novotamanho = tamanhoantigo + TAM_PADRAO;

    char *temporario = realloc(vetor,(novotamanho + 1) * sizeof(char));

    if (temporario == NULL) {
        printf("Erro ao realocar memoria.\n");
        free(vetor);
        exit(EXIT_FAILURE);
    }

    for (int i = tamanhoantigo; i < novotamanho; i++) {
        temporario[i] = '_';
    }

    temporario[novotamanho] = '\0';

    return temporario;
}