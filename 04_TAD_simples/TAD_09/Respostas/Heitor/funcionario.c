#include "funcionario.h"
#include <stdio.h>
#include <string.h>

tFuncionario criaFuncionario(int id, float salario){
    tFuncionario funcionario = {id, salario};
    return funcionario;
}

tFuncionario leFuncionario(){
    int id;
    float salario;
    scanf("%d %f", &id, &salario);
    return criaFuncionario(id, salario);
}

int getIdFuncionario(tFuncionario funcionario){
    return funcionario.id;
}

void imprimeFuncionario(tFuncionario funcionario){
    printf("- Funcionario %d: RS %.2f\n", funcionario.id, funcionario.salario);
}