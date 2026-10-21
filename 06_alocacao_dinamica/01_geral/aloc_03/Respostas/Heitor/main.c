#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils_char.h"

int main(){
    int tamanho;
    scanf("%d ", &tamanho);
    char *vetor = CriaVetor(tamanho);

    ImprimeString(vetor, tamanho);
    LeVetor(vetor, tamanho);
    ImprimeString(vetor, tamanho);

    LiberaVetor(vetor);

    return 0;
}