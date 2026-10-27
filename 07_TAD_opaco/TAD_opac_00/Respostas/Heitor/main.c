#include <stdio.h>
#include <math.h>
#include "ponto.h"
#include "circulo.h"
#include <stdlib.h>

int main(){
    float x,y,r;
    scanf("%f %f %f", &x, &y, &r);
    tCirculo circulo = Circulo_Cria(x, y, r);
    scanf("%f %f", &x, &y);
    tPonto ponto = Pto_Cria(x,y);

    printf("%d\n", Circulo_Interior(circulo, ponto));
    
    Pto_Apaga(ponto);
    Circulo_Apaga(circulo);

    return 0;
}