#include <stdio.h>
#include "rolagem.h"
#include <string.h>

void LeMensagens(char msg[NUM_MAX_MSGS][TAM_MAX_MSG], int *numMsgs);

int main(){
    int numPassos, numMsgs;
    char msg[NUM_MAX_MSGS][TAM_MAX_MSG];
    scanf("%d\n%d", &numPassos, &numMsgs);
    LeMensagens(msg, &numMsgs);
    
    return 0;
}

void LeMensagens(char msg[NUM_MAX_MSGS][TAM_MAX_MSG], int *numMsgs){
    int i;
    for (i = 0; i < *numMsgs && i < NUM_MAX_MSGS; i++) scanf(" %999[^\n]", msg[i]);
}
