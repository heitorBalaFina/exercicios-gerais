#include "pessoa.h"
#include <stdio.h>
#include <string.h>

tPessoa CriaPessoa() {
    tPessoa pessoa;
    pessoa.nome[0] = '\0';
    pessoa.pai = NULL;
    pessoa.mae = NULL;
    return pessoa;
}

void LePessoa(tPessoa *pessoa) {
    
    scanf(" %99[^\n]", pessoa->nome);
}

int VerificaSeTemPaisPessoa(tPessoa *pessoa) {
    if (pessoa->mae != NULL || pessoa->pai != NULL) return 1;
    return 0;
}

void ImprimePessoa(tPessoa *pessoa) {
    // Imprime o nome da pessoa
    if(VerificaSeTemPaisPessoa(pessoa)){
        printf("NOME COMPLETO: %s\n", pessoa->nome);
                
        if (pessoa->pai == NULL) {
            printf("PAI: NAO INFORMADO\n");    
        } else {
            printf("PAI: %s\n", pessoa->pai->nome);
        }

        if (pessoa->mae == NULL) {
            printf("MAE: NAO INFORMADO\n\n");    
        } else {
            printf("MAE: %s\n\n", pessoa->mae->nome);
        }
    }
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas) {    
    int mae, pai, filho;
    int qtdAssoc = 0;
    for (scanf(" %d", &qtdAssoc); qtdAssoc > 0; qtdAssoc--) {
        
        scanf(" mae: %d, pai: %d, filho: %d", &mae, &pai, &filho);
        //printf("maezinha%d paizinho:%d filhinho:%d\n", mae, pai, filho);

        if (pai != -1) pessoas[filho].pai = &pessoas[pai];
        if (mae != -1) pessoas[filho].mae = &pessoas[mae];
    }
}