#include "utils.h"
#include <stdio.h> 
#include <stdlib.h> 

void LeIntervalo(int * m, int * n){
    scanf("%d %d", m, n);
}

int EhPrimo(int n){
    int divisor, cont = 0;
    for(divisor = 1; divisor <= n; divisor++){
        if(!(n%divisor)){
            cont++;
            if(cont > 2) return 0;
        }
    }
    if(cont == 1) return 0;
    return 1;
}

void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior){
    menor = 0;
    maior = 0;
    for(;m <= n; m++){
        
    }
}