#include <stdio.h>
#include "vetor.h"

int soma(int num1, int num2);
int produto(int num1, int num2);

int main(){
    int resultado;
    Vetor vetor;
    LeVetor(&vetor);
    Operation op;
    op = soma;
    resultado = AplicarOperacaoVetor(&vetor, op);
    printf("Soma: %d\n", resultado);
    op = produto;
    resultado = AplicarOperacaoVetor(&vetor, op);
    printf("Produto: %d\n", resultado);
    return 0;
}

int soma(int num1, int num2){
    return num1 + num2;
}

int produto(int num1, int num2){
    return num1 * num2;
}