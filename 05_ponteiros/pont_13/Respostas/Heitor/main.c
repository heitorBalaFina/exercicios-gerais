#include <stdio.h>
#include "rolagem.h"

#define MAX 30

void LeMensagens(char msg[NUM_MAX_MSGS][TAM_MAX_MSG], int *numMsgs);

int main()
{
    int numPassos;

    scanf("%d", &numPassos);

    RolaMsg(LeMensagens, MAX, numPassos);

    return 0;
}

void LeMensagens(char msg[NUM_MAX_MSGS][TAM_MAX_MSG], int *numMsgs){
    int i;
    scanf("%d", numMsgs);
    
    for (i = 0; i < *numMsgs && i < NUM_MAX_MSGS; i++){
        scanf(" %999[^\n]", msg[i]);
    }
}