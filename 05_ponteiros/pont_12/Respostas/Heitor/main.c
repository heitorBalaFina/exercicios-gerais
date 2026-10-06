#include <stdio.h>
#include "vetor.h"

int soma(int num1, int num2);
int produto(int num1, int num2);

int main(){
    Vetor vetor;
    LeVetor(&vetor);
    

    return 0;
}

int soma(int num1, int num2){
    return num1 + num2;
}

int produto(int num1, int num2){
    return num1 * num2;
}