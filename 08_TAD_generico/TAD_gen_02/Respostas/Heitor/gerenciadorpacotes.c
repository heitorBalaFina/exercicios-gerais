#include <stdio.h>
#include <stdlib.h>
#include "gerenciadorpacotes.h"

//typedef struct gerenciadorpacotes tGerenciador;

struct gerenciadorpacotes
{
    tPacote **pacote;
    int numEle;
};


tGerenciador* CriaGerenciador(){
    tGerenciador *novoGen = malloc(sizeof(struct gerenciadorpacotes));
    if(novoGen == NULL) exit(0);

    novoGen->pacote = malloc(sizeof(struct pacote*));
    if(novoGen->pacote == NULL) exit(0);

    novoGen->numEle = 0;

    return novoGen;
}

void AdicionaPacoteNoGerenciador(tGerenciador* geren, tPacote* pac){
    if(geren == NULL || pac == NULL) return;
    
    geren->pacote[geren->numEle] = pac;
    geren->numEle++;
    geren->pacote = realloc(geren->pacote, (geren->numEle + 1)*sizeof(tPacote*));
    
}

void DestroiGerenciador(tGerenciador* geren){
    if(geren == NULL) return;
    
    int i;
    for(i = 0; i < geren->numEle; i++){
        DestroiPacote(geren->pacote[i]);
    }
    free(geren->pacote);
    free(geren);
}

void ImprimirPacoteNoIndice(tGerenciador* geren, int idx){
    if(geren == NULL) return;
    
    ImprimePacote(geren->pacote[idx]);
}

void ImprimirTodosPacotes(tGerenciador* geren){
    if(geren == NULL) return;

    int i;
    for(i = 0; i < geren->numEle; i++){
        ImprimirPacoteNoIndice(geren, i);
    }
}