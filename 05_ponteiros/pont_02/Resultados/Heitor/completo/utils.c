#include "utils.h"
#include <stdio.h> 
#include <stdlib.h> 

#define NUMERO_GRANDE 100000
#define ZERO 0

void LeIntervalo(int * m, int * n){
    scanf("%d %d", m, n);
}

int EhPrimo(int n){
    int divisor;
    if(n < 2) return 0;
    for(divisor = 2; divisor < n; divisor++){
        if(!(n%divisor))return 0;
    }
    return 1;
}

void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior){
    *menor = NUMERO_GRANDE;
    *maior = ZERO;
    for(;m <= n; m++){
        if(EhPrimo(m)){
            if(m > *maior) *maior = m;
            if(m < *menor) *menor = m;
        }
    }
}