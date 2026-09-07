#include "tabuleiro.h"

#define PECA_VAZIA '-'
#define PECA_0 '0'
#define PECA_X 'X'
#define ZERO 0

tTabuleiro CriaTabuleiro(){
    tTabuleiro tabuleiro;
    tabuleiro.peca1 = PECA_X;
    tabuleiro.peca2 = PECA_0;
    tabuleiro.pecaVazio = PECA_VAZIA;
    int i, j;
    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            tabuleiro.posicoes[i][j] = tabuleiro.pecaVazio;
        }
    }
    return tabuleiro;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y){
    if(peca == PECA_1){
        tabuleiro.posicoes[y][x] = tabuleiro.peca1;
    } else if(peca == PECA_2){
        tabuleiro.posicoes[y][x] = tabuleiro.peca2;
    }
    return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro){
    int i, j;
    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            if(tabuleiro.posicoes[i][j] == tabuleiro.pecaVazio){
                return 1;
            }
        }
    }
    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca){
    if(peca == 1){
        if(tabuleiro.posicoes[y][x] == PECA_X){
            return 1;
        }
    } else if (peca == 2){
        if(tabuleiro.posicoes[y][x] == PECA_0){
            return 1;
        }
    }
    return 0;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y){
    if(tabuleiro.posicoes[y][x] == tabuleiro.pecaVazio){
        return 1;
    }
    return 0;
}

int EhPosicaoValidaTabuleiro(int x, int y){
    if(x < TAM_TABULEIRO && y < TAM_TABULEIRO && x >= ZERO && y >= ZERO){
        return 1;
    }
    return 0;
}

void ImprimeTabuleiro(tTabuleiro tabuleiro){
    int i, j;
    for(i = 0; i < TAM_TABULEIRO; i++){
        printf("    ");
        for(j = 0; j < TAM_TABULEIRO; j++){
            printf("%c", tabuleiro.posicoes[i][j]);
        }
        printf("\n");
    }
}