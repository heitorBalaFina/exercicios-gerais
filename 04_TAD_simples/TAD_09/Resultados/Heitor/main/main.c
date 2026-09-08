#include <stdio.h>
#include "empresa.h"
#include "funcionario.h"

int main(){
    int qtdEmpresas = 0;
    scanf("%d", &qtdEmpresas);

    tEmpresa empresas[qtdEmpresas];   // guarda todas antes de imprimir

    for(int i = 0; i < qtdEmpresas; i++){
        empresas[i] = leEmpresa();     // lê todas (erros de duplicidade saem aqui, na hora certa)
    }

    for(int i = 0; i < qtdEmpresas; i++){
        imprimeEmpresa(empresas[i]);   // só depois, imprime o relatório de todas
    }

    return 0;
}