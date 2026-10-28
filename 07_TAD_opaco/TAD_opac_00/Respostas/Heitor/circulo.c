#include "circulo.h"
#include "ponto.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct circulo{
    tPonto ponto;
    float raio;
};

tCirculo Circulo_Cria (float x, float y, float r){
    tCirculo novoCirculo = (tCirculo) malloc(sizeof(struct circulo));
    Circulo_Atribui_Raio(novoCirculo, r);
    novoCirculo->ponto = Pto_Cria(x, y);
    return novoCirculo;
}

void Circulo_Apaga (tCirculo c){
    if(c == NULL) return;

    Pto_Apaga(c->ponto);
    free(c);
}

tPonto Circulo_Acessa_Centro (tCirculo c){
    //if(c == NULL) EXIT_FAILURE;

    return c->ponto;
}

float Circulo_Acessa_Raio (tCirculo c){
    //if(c == NULL) EXIT_FAILURE;

    return c->raio;
}

void Circulo_Atribui_Centro (tCirculo c, tPonto p){
    //if(c == NULL || p == NULL) return;
    Pto_Atribui_x(Circulo_Acessa_Centro(c), Pto_Acessa_x(p));
    Pto_Atribui_y(Circulo_Acessa_Centro(c), Pto_Acessa_y(p));
}

void Circulo_Atribui_Raio (tCirculo c, float r){
    //if(c == NULL) return;
    c->raio = r;
}

int Circulo_Interior (tCirculo c, tPonto p){
    float raio = Circulo_Acessa_Raio(c);
    float distancia = Pto_Distancia(Circulo_Acessa_Centro(c), p);
    //printf("1 - x: %f y: %f\n", Pto_Acessa_x(c->ponto), Pto_Acessa_y(c->ponto));
    //printf("2 - x: %f y: %f\n", Pto_Acessa_x(p), Pto_Acessa_y(p));
    //printf("Raio: %.2f Distancia: %.2f\n", raio, distancia);
    //if(Pto_Distancia(Circulo_Acessa_Centro(c), p) <= Circulo_Acessa_Raio(c)) return 1; 
    if(distancia <= raio) return 1;
    return 0;
}