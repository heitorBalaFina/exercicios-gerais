#include <stdio.h>
#include <string.h>
#include "pessoa.h"

int main(){
    int qtd, posicao;
    scanf("%d", &qtd);
    tPessoa vetor[qtd];
    for(posicao = 0; posicao < qtd; posicao++){
        vetor[posicao] = CriaPessoa();
        LePessoa(&vetor[posicao]);
    }
    AssociaFamiliasGruposPessoas(vetor, qtd);

    for(posicao = 0; posicao < qtd; posicao++) ImprimePessoa(&vetor[posicao]);
    
    return 0;
}