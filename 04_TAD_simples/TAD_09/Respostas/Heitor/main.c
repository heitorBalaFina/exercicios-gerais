#include <stdio.h>
#include "empresa.h"
#include "funcionario.h"

int main(){
    int qtdEmpresas = 0;
    scanf("%d", &qtdEmpresas);

    tEmpresa empresas[qtdEmpresas];  

    for(int i = 0; i < qtdEmpresas; i++){
        empresas[i] = leEmpresa();     

    for(int i = 0; i < qtdEmpresas; i++){
        imprimeEmpresa(empresas[i]);   
    }

    return 0;
}