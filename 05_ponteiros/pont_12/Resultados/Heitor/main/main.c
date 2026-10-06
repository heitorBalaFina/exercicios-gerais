#include <stdio.h>
#include "vetor.h"

int soma(int num1, int num2);
int produto(int num1, int num2);

//tipo_de_retorno (*nome_do_ponteiro_para_funcao)(lista_de_argumentos);
//int (*PonteiroFuncao)(int, int);

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