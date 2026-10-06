#include "pessoa.h"
#include <string.h>
#include <stdio.h>

/*  EXEMPLO:
struct Pessoa{
    char nome[100];
    tPessoa *pai;
    tPessoa *mae;
    tPessoa *irmao;
};
*/

tPessoa CriaPessoa(){
    tPessoa pessoa;
    pessoa.nome[0] = '\0';
    pessoa.mae = NULL;
    pessoa.pai = NULL;
    pessoa.irmao = NULL;
    return pessoa;
}

void LePessoa(tPessoa *pessoa){
    scanf(" %99[^\n]", pessoa->nome);
}

int VerificaSeTemPaisPessoa(tPessoa *pessoa){
    if(pessoa->pai == NULL && pessoa->mae == NULL) return 0;
    return 1;
}

void ImprimePessoa(tPessoa *pessoa){
    /*  EXEMPLO:
    NOME COMPLETO: Maria Rodrigues
    PAI: Joao Rodrigues
    MAE: Laura Rodrigues
    IRMAO: Mariana Rodrigues
    */

    if(VerificaSeTemPaisPessoa(pessoa)){
        printf("NOME COMPLETO: %s\n", pessoa->nome);
        if(pessoa->pai == NULL){
            printf("PAI: NAO INFORMADO\n");
        } else {
            printf("PAI: %s\n", pessoa->pai->nome);
        }
        if(pessoa->mae == NULL){
            printf("MAE: NAO INFORMADO\n");
        } else {
            printf("MAE: %s\n", pessoa->mae->nome);
        }
        if(pessoa->irmao == NULL){
            printf("IRMAO: NAO INFORMADO\n");
        } else {
            printf("IRMAO: %s\n\n", pessoa->irmao->nome);
        }
    }
}

int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2){
    if(VerificaSeTemPaisPessoa(pessoa1) && VerificaSeTemPaisPessoa(pessoa2)){
        if(pessoa1->pai == pessoa2->pai && pessoa1->mae == pessoa2->mae) return 1;
    }
    //if(pessoa1->pai->nome == pessoa2->pai->nome && pessoa1->mae->nome == pessoa2->mae->nome) return 1;
    return 0;
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas){
    //EXEMPLO:
    //mae: 2, pai: -1, filho: 14
    int mae, pai, filho, i, j, associacoes;
    scanf(" %d", &associacoes);
    while(associacoes){
        scanf(" mae: %d, pai: %d, filho: %d", &mae, &pai, &filho);
        if(mae != -1) pessoas[filho].mae = &pessoas[mae];
        if(pai != -1) pessoas[filho].pai = &pessoas[pai];
        associacoes--;
    }

    for(i = 0; i < numPessoas; i++){
        for(j = 0; j < numPessoas; j++){
            if(i == j)
                continue;
            if(VerificaIrmaoPessoa(&pessoas[i], &pessoas[j])){
                pessoas[i].irmao = &pessoas[j];
                break;
            }
        }
    }
}