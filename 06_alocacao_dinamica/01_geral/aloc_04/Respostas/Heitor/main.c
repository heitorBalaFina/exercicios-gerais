#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils_char2.h"

int main(){
    int tamanho = TAM_PADRAO;
    char *vetor = CriaVetorTamPadrao();
    
    vetor = LeVetor(vetor, &tamanho);
    ImprimeString(vetor);
    LiberaVetor(vetor);
    return 0;
}