#include <stdio.h>
#include <string.h>
#include "rolagem.h"

// Transforma a matriz de mensagens em um único texto
void MatrixViraTxt(char destino[], char matrix[NUM_MAX_MSGS][TAM_MAX_MSG], int numMsgs){
    int i;
    destino[0] = '\0';
    for (i = 0; i < numMsgs; i++){
        strcat(destino, matrix[i]);
    }
}

// Retorna o tamanho da mensagem
int RetTamMsg(char mensagem[]){
    int i;
    for (i = 0; mensagem[i] != '\0'; i++);
    return i;
}

// Realiza a rolagem das mensagens
void GiraMensagem(char mensagem[], int tamanhoDisplay, int tempoFim){
    int tamMsg = RetTamMsg(mensagem);
    int i, j;

    if (tamMsg == 0) return;

    for (i = 0; i < tempoFim; i++){
        for (j = i; j < tamanhoDisplay + i; j++){
            printf("%c", mensagem[j % tamMsg]);
        }
        printf("\n");
        printf("\033[H\033[J");
    }
}

// Função principal da biblioteca
void RolaMsg(FptrMsg FuncMsg, int tamanhoDisplay, int tempoFim){
    char msg[NUM_MAX_MSGS][TAM_MAX_MSG];
    char mensagem[NUM_MAX_MSGS * TAM_MAX_MSG];
    int numMsgs = 0;

    // 1. Obtém as mensagens através do callback
    FuncMsg(msg, &numMsgs);

    // 2. Junta todas as mensagens em um único texto
    MatrixViraTxt(mensagem, msg, numMsgs);

    // 3. Realiza a rolagem
    GiraMensagem(mensagem, tamanhoDisplay, tempoFim);
}