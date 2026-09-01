#include <stdio.h>
#include "ponto.h"

int main(){
    float x = 0, y = 0;
    Ponto ponto1;
    Ponto ponto2;
    
    scanf(" %f %f", &x, &y);
    ponto1 = pto_cria(x, y);

    scanf(" %f %f", &x, &y);
    ponto2 = pto_cria(x, y);

    printf("%g", pto_distancia(ponto1, ponto2));

    return 0;
}