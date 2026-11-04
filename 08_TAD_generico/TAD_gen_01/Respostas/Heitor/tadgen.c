#include <stdlib.h>
#include <stdio.h>
#include "tadgen.h"

//typedef struct generic tGeneric;

struct generic
{
    int type;
    int numElem;

    int *vetInt;
    float *vetFloat;
};

tGeneric* CriaGenerico(Type type, int numElem){
    tGeneric *novoGenerico = malloc(sizeof(struct generic));
    if(novoGenerico == NULL) exit(0);
    
    novoGenerico->type = type;
    if(type == INT){
        novoGenerico->numElem = numElem;
        novoGenerico->vetInt = malloc(numElem*sizeof(int));
        if(novoGenerico->vetInt == NULL) exit(0);
        novoGenerico->vetFloat = NULL;
    } else if(type == FLOAT){
        novoGenerico->numElem = numElem;
        novoGenerico->vetFloat = malloc(numElem*sizeof(float));
        if(novoGenerico->vetFloat == NULL) exit(0);
        novoGenerico->vetInt = NULL;
    }

    return novoGenerico;
}

void DestroiGenerico(tGeneric* gen){
    if(gen == NULL) return;

    free(gen->vetFloat);
    free(gen->vetInt);
    free(gen);
}

void LeGenerico(tGeneric* gen){
    printf("\nDigite o vetor:\n");
    
    int i;
    if(gen->type == FLOAT){
        for(i = 0; i < gen->numElem; i++){
            scanf("%f", &gen->vetFloat[i]);
        }
    } else if(gen->type == INT){
        for(i = 0; i < gen->numElem; i++){
            scanf("%d", &gen->vetInt[i]);
        }
    }
}

void ImprimeGenerico(tGeneric* gen){
    int i;
    if(gen->type == FLOAT){
        for(i = 0; i < gen->numElem; i++){
            printf("%.2f ", gen->vetFloat[i]);
        }
    } else if(gen->type == INT){
        for(i = 0; i < gen->numElem; i++){
            printf("%d ", gen->vetInt[i]);
        }
    }
    printf("\n");
}

