#include "jogada.h"

tJogada LeJogada(){
    tJogada jogada;
    jogada.x = -1;
    jogada.y = -1;
    jogada.sucesso = 0;
    scanf("%d %d", &jogada.x, &jogada.y);
    if(jogada.x >= 0 && jogada.x <= 2 && jogada.y >= 0 && jogada.y <=2){
        jogada.sucesso = 1;
    }
    return jogada;
}

int ObtemJogadaX(tJogada jogada){
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada){
    return jogada.y;
}

int FoiJogadaBemSucedida(tJogada jogada){
    if(jogada.sucesso){
        return 1;
    }
    return 0;
}