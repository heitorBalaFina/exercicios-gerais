#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "filme.h"
#include "locadora.h"

/*
#define MAX_CARACTERES 20

typedef struct Filme {
    int codigo;
    char nome[MAX_CARACTERES];
    int valor;
    int qtdEstoque;
    int qtdAlugada;
} tFilme;
*/

tFilme* CriarFilme(){
    tFilme *novoFilme = (tFilme*) malloc(sizeof(tFilme));
    if(novoFilme == NULL) exit(0);
    novoFilme->codigo = 0;
    novoFilme->qtdAlugada = 0;
    novoFilme->qtdEstoque = 0;
    novoFilme->valor = 0;
    return novoFilme;
}

// Entrada: 2,Shrek,4,1
void LeFilme(tFilme *filme, int codigo){
    filme->codigo = codigo;
    scanf("%19[^,],%d,%d", filme->nome,&filme->valor,&filme->qtdEstoque);
}

void DestruirFilme (tFilme* filme){
    free(filme);
}

int ObterCodigoFilme (tFilme* filme){
    //if(filme == NULL) return;
    return filme->codigo;
}

void ImprimirNomeFilme (tFilme* filme){
    //if(filme == NULL) return;
    printf("%s", filme->nome);
}

int ObterValorFilme (tFilme* filme){
    //if(filme == NULL) return;
    return filme->valor;
}

int ObterQtdEstoqueFilme (tFilme* filme){
    //if(filme == NULL) return;
    return filme->qtdEstoque;
}

int ObterQtdAlugadaFilme (tFilme* filme){
    //if(filme == NULL) return;
    return filme->qtdAlugada;
}

int EhMesmoCodigoFilme (tFilme* filme, int codigo){
    //if(filme == NULL) return;
    if(filme->codigo == codigo) return 1;
    return 0;
}

// essas duas funcoes podem ter problema de quantidade negativa
void AlugarFilme (tFilme* filme){
    if(filme->qtdEstoque > 0){
        filme->qtdAlugada++;
        filme->qtdEstoque--;
    }
}

void DevolverFilme (tFilme* filme){
    filme->qtdAlugada--;
    filme->qtdEstoque++;
}

int CompararNomesFilmes (tFilme* filme1, tFilme* filme2){
    return strcmp(filme1->nome, filme2->nome);
}