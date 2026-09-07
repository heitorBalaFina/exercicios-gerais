#include "jogador.h"
#include "tabuleiro.h"
#include "jogada.h"

#define PECA_VAZIA '-'
#define PECA_0 '0'
#define PECA_X 'X'
#define ZERO 0
#define UM 1

tJogador CriaJogador(int idJogador){
    tJogador novoJogador;
    novoJogador.id = idJogador;
    return novoJogador;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro){
    
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro){
    int linha, coluna, diagonal;
    int contador = 0;
    
    // um for para verificar se todas as possicoes de uma mesma linha sao iguais
    for(linha = 0; linha < TAM_TABULEIRO; linha ++){
        contador = 0;
        for(coluna = 1; coluna < TAM_TABULEIRO; coluna++){
            if(tabuleiro.posicoes[linha][coluna] == tabuleiro.posicoes[linha][coluna-UM]){
                contador++;
            }
            // se todas as posicoes sao iguais verifica qual jogador ganhou
            if(contador == 2){
                if(tabuleiro.posicoes[linha][coluna] == PECA_X && jogador.id == PECA_1){
                    return 1;
                } else if(tabuleiro.posicoes[linha][coluna] == PECA_0 && jogador.id == PECA_2){
                    return 1;
                }
            }
        }
    }

    // um for para verificar se todas as possicoes de uma mesma linha sao iguais
    for(coluna = 0; coluna < TAM_TABULEIRO; coluna ++){
        contador = 0;
        for(linha = 1; linha < TAM_TABULEIRO; linha++){
            if(tabuleiro.posicoes[linha][coluna] == tabuleiro.posicoes[linha-UM][coluna]){
                contador++;
            }
            // se todas as posicoes sao iguais verifica qual jogador ganhou
            if(contador == 2){
                if(tabuleiro.posicoes[linha][coluna] == PECA_X && jogador.id == PECA_1){
                    return 1;
                } else if(tabuleiro.posicoes[linha][coluna] == PECA_0 && jogador.id == PECA_2){
                    return 1;
                }
            }
        }
    }

    if(tabuleiro.posicoes[0][0] == tabuleiro.posicoes[1][1] && tabuleiro.posicoes[1][1] == tabuleiro.posicoes[2][2]){
        if(jogador.id == PECA_1 && tabuleiro.posicoes[0][0] == PECA_X){
            return 1;
        } else if(jogador.id == PECA_2 && tabuleiro.posicoes[0][0] == PECA_0){
            return 1;
        }
    } else if(tabuleiro.posicoes[0][2] == tabuleiro.posicoes[1][1] && tabuleiro.posicoes[1][1] == tabuleiro.posicoes[2][0]){
        if(jogador.id == PECA_1 && tabuleiro.posicoes[UM][UM] == PECA_X){
            return 1;
        } else if(jogador.id == PECA_2 && tabuleiro.posicoes[UM][UM] == PECA_0){
            return 1;
        }
    }

    return 0;
}