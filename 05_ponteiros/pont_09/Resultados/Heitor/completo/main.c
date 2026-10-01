#include <stdio.h>
#include <string.h>
#include "pessoa.h"

int main(){
    int qtdPessoas = 0, i;
    scanf("%d", &qtdPessoas);
    tPessoa vetor[qtdPessoas];
    for(i = 0; i < qtdPessoas; i++){
        vetor[i] = CriaPessoa();
        LePessoa(&vetor[i]);
    } 
    AssociaFamiliasGruposPessoas(vetor);
    for(i = 0; i < qtdPessoas; i++){
        ImprimePessoa(&vetor[i]);
    }

    return 0;
}