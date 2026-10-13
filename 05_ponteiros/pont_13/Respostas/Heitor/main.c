#include <stdio.h>
#include "rolagem.h"
#include <string.h>

#define MAX 30

// Ler as mensagens
void LeMensagens(char msg[NUM_MAX_MSGS][TAM_MAX_MSG], int *numMsgs);

// Transforma a matrix em uma char
void MatrixViraTxt(char destino[], char matrix[NUM_MAX_MSGS][TAM_MAX_MSG], int *numMsgs);

// Gira a mensagem pela quantidade de numPassos
void GiraMensagem(char mensagem[], int *numPassos);

// retorna o tamanho da mensagem
int RetTamMsg(char mensagem[]);

int main(){
    int numPassos, numMsgs;
    char msg[NUM_MAX_MSGS][TAM_MAX_MSG];
    char mensagem[NUM_MAX_MSGS*TAM_MAX_MSG];
    mensagem[0] = '\0';
    
    scanf("%d\n%d", &numPassos, &numMsgs);
    LeMensagens(msg, &numMsgs);
    MatrixViraTxt(mensagem, msg, &numMsgs);
    //printf("%s\n", mensagem);
    GiraMensagem(mensagem, &numPassos);

    return 0;
}

void LeMensagens(char msg[NUM_MAX_MSGS][TAM_MAX_MSG], int *numMsgs){
    int i;
    for (i = 0; i < *numMsgs && i < NUM_MAX_MSGS; i++){
        scanf(" %999[^\n]", msg[i]);
    } 
}

void MatrixViraTxt(char destino[], char matrix[NUM_MAX_MSGS][TAM_MAX_MSG], int *numMsgs){
    int i;
    for(i = 0; i < *numMsgs; i++){
        strcat(destino, matrix[i]);        
    }
}

int RetTamMsg(char mensagem[]){
    int i;
    for(i = 0; mensagem[i] != '\0'; i++);
    return i;
}

void GiraMensagem(char mensagem[], int *numPassos){
    int tamMsg = RetTamMsg(mensagem);
    int giro = 0;
    int i, j;
    for(i = 0; i < *numPassos; i++){
        for(j = i; j < MAX + i; j++){
            printf("%c", mensagem[j%tamMsg]);
            
        }
        printf("\n");
        printf("\033[H\033[J");
    }
}

//typedef void (*FptrMsg)(char msg[NUM_MAX_MSGS][TAM_MAX_MSG], int * numMsgs);
//void RolaMsg(FptrMsg FuncMsg, int tamanhoDisplay, int tempoFim);