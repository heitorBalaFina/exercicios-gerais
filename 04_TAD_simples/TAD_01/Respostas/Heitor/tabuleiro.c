#include "tabuleiro.h"

#define pecaX 'X'
#define peca0 '0'

tTabuleiro CriaTabuleiro(){
    tTabuleiro tabuleiro;
    int l,c;
    for(l = 0; l < TAM_TABULEIRO; l++){
        for(c = 0; c < TAM_TABULEIRO; c++){
            tabuleiro.posicoes[l][c] = '-';
        }
    }
    return tabuleiro;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y){
    if(peca == PECA_1){
        tabuleiro.posicoes[x][y] = pecaX;
    } else if(peca == PECA_2){
        tabuleiro.posicoes[x][y] = peca0;
    } else {
        printf("problema na funcao MarcaPosicaoTabuleiro em tabuleiro.c\nProvavelmente passando peca errada");
    }
    return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro){
    int l, c;
    for(l = 0; l < TAM_TABULEIRO; l++){
        for(c = 0; c < TAM_TABULEIRO; c++){
            // andar por todas as posicoes do tabuleiro e ve se a posicao esta livre
            if(EstaLivrePosicaoTabuleiro(tabuleiro, l, c)){
                return 1;
            }
        }
    }
    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca){
    if(peca == PECA_1){
        if(tabuleiro.posicoes[y][x] == pecaX){
            return 1;
        }
    } else if(peca == peca0){
        if(tabuleiro.posicoes[y][x] == peca0){
            return 1;
        }
    }
    if(peca != pecaX && peca != peca0){
        printf("peca passada errada como parametro na funcao EstaMarcadaPosicaoPecaTabuleiro em tabuleiro.c");
    }
    return 0;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y){
    if(tabuleiro.posicoes[x][y] == '-'){
        return 1;
    }
    return 0;
}


int EhPosicaoValidaTabuleiro(int x, int y){
    if(x >= 0 && x <=2 && y <= 0 && y <=2 ){
        return 1;
    }
    return 0;
}

void ImprimeTabuleiro(tTabuleiro tabuleiro){
    int l, c;
    for(l = 0; l < TAM_TABULEIRO; l++){
        printf("    ");
        for(c = 0; c < TAM_TABULEIRO; c++){
            printf("%c", tabuleiro.posicoes[l][c]);
        }
        printf("\n");
    }
}