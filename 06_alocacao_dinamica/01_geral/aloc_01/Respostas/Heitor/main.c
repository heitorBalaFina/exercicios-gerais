#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

int main(){
    int tamanho;
    scanf("%d", &tamanho);
    int *vetor = CriaVetor(tamanho);
    LeVetor(vetor, tamanho);
    printf("%.2f", CalculaMedia(vetor, tamanho));
    LiberaVetor(vetor);
    //int *v = (int *) malloc (4 * sizeof(int));
    return 0;
}