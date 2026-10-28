#include <stdio.h>
#include <math.h>
#include "ponto.h"
#include "circulo.h"
#include <stdlib.h>

int main(){
    float x,y,r, x1, y1;
    scanf("%f %f %f %f %f", &x, &y, &r, &x1, &y1);
    //printf("x: %.2f y: %.2f r: %.2f x1: %.2f y1: %.2f\n", x, y, r, x1, y1);
    tCirculo circulo = Circulo_Cria(x, y, r);
    tPonto ponto = Pto_Cria(x1,y1);

    printf("%d\n", Circulo_Interior(circulo, ponto));
    
    Pto_Apaga(ponto);
    Circulo_Apaga(circulo);

    return 0;
}