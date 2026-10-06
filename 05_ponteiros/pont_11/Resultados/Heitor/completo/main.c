#include <stdio.h>
#include "calculadora.h"
#include <string.h>
#include <math.h>

float adicao(float num1, float num2){
    return num1+num2;
}

float subtracao(float num1, float num2){
    return num1-num2;
}

float multiplicacao(float num1, float num2){
    return num1*num2;
}

float divisao(float num1, float num2){
    if(num2) return num1/num2;
    return 0;
}

int main(){
    char operacao = ' ';
    float num1, num2;
    while(operacao != 'f'){
        scanf(" %c", &operacao);
        if(operacao == 'f') break;
        scanf("%f %f", &num1, &num2);
        switch (operacao)
        {
            /*
            10.00 + 59.00 = 69.00
            59.00 - 10.00 = 49.00
            15.00 x 12.00 = 180.00
            68.00 + 156.00 = 224.00
            12.00 / 6.00 = 2.00
            */
        case 'a':
            printf("%.2f + %.2f = %.2f\n",num1, num2, Calcular(num1, num2, adicao));
            break;
        case 's':
            printf("%.2f - %.2f = %.2f\n",num1, num2, Calcular(num1, num2, subtracao));
            break;
        case 'm':
            printf("%.2f x %.2f = %.2f\n",num1, num2, Calcular(num1, num2, multiplicacao));
            break;
        case 'd':
            printf("%.2f / %.2f = %.2f\n",num1, num2, Calcular(num1, num2, divisao));
            break;
        default:
            break;
        }
    }
    

    return 0;
}