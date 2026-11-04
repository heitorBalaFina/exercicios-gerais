#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pacote.h"

//typedef struct pacote tPacote;

struct pacote
{
    int acumulador;
    int type;
    int numElem;

    char *vetChar;
    int *vetInt;
    /* data */
};

tPacote* CriaPacote(Type type, int numElem){
    tPacote *novoPacote = malloc(sizeof(struct pacote));
    if(novoPacote == NULL) exit(0);

    novoPacote->acumulador = 0;
    novoPacote->numElem = numElem;
    novoPacote->type = type;
    
    if(type == INT){
        novoPacote->vetInt = malloc(numElem*sizeof(int));
        novoPacote->vetChar = NULL;
    } else if(type == CHAR){
        novoPacote->vetChar = malloc((numElem+1)*sizeof(char));
        novoPacote->vetInt = NULL;
    }

    return novoPacote;
}

void DestroiPacote(tPacote* pac){
    if(pac == NULL) return;

    free(pac->vetChar);
    free(pac->vetInt);
    free(pac);
}

void LePacote(tPacote* pac){
    int i;
    for(i = 0; i < pac->numElem; i++){
        if(pac->type == INT){
            scanf("%d", &pac->vetInt[i]);
        } else {
            scanf("%c", &pac->vetChar[i]);
        }
    }
    if(pac->type == CHAR) pac->vetChar[i] = '\0';
}

void ImprimePacote(tPacote* pac){
    CalculaSomaVerificacaoPacote(pac);
    printf("%d ", pac->acumulador);
    if(pac->type == INT){
        int i;
        for(i = 0; i < pac->numElem; i++){
            printf("%d ", pac->vetInt[i]);
        }
    } else {
        printf("%s", pac->vetChar);
    }
    printf("\n");
}

void CalculaSomaVerificacaoPacote(tPacote* pac){
    pac->acumulador = 0;
    int i;
    for(i = 0; i < pac->numElem; i++){
        if(pac->type == INT){
            pac->acumulador += pac->vetInt[i];
        } else {
            pac->acumulador += pac->vetChar[i];
        }
    }
}