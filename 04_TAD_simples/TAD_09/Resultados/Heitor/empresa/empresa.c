#include <stdio.h>
#include "empresa.h"
#include "funcionario.h"

tEmpresa criaEmpresa(int id){
    tEmpresa empresa;
    empresa.id = id;
    // EMPRESA COMECA COM ZERO PARA DEPOIS UTILIZAR ISSO COMO PARAMETRO
    empresa.qtdFuncionarios = 0;
    return empresa;
}

tEmpresa leEmpresa(){
    int id, qtdFuncionarios;
    scanf("%d %d", &id, &qtdFuncionarios);
    tEmpresa empresa = criaEmpresa(id);

    int i;
    for(i = 0; i < qtdFuncionarios; i++){
        // VAI CRIANDO E CONTRATANDO O FUNCIONARIO
        tFuncionario funcionario = leFuncionario();
        empresa = contrataFuncionarioEmpresa(empresa, funcionario);
    }
    
    return empresa;
}

tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario){
    int i;

    for(i = 0; i < empresa.qtdFuncionarios; i++){
        if(empresa.funcionarios[i].id == funcionario.id){
            printf("A empresa %d ja possui um funcionario com o id %d\n",
                   empresa.id, funcionario.id);
            return empresa;
        }
    }

    empresa.funcionarios[empresa.qtdFuncionarios] = funcionario;
    empresa.qtdFuncionarios++;

    return empresa;
}

void imprimeEmpresa(tEmpresa empresa){
    int i;
    printf("Empresa %d:\n", empresa.id);
    for(i = 0; i < empresa.qtdFuncionarios; i++){
        imprimeFuncionario(empresa.funcionarios[i]);
    }
    printf("\n");
}