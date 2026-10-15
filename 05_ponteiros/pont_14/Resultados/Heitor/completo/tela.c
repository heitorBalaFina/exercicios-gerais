#include <stdio.h>
#include <string.h>
#include "tela.h"
#include "botao.h"


/*
typedef struct {
    int altura; 
    int largura; 
    Botao botoes[MAX_BOTOES]; 
    int qntBotoes;
} Tela;
*/

Tela CriarTela(int altura, int largura){
    Tela t;
    t.altura = altura;
    t.largura = largura;
    return t;
}

void RegistraBotaoTela(Tela *t, Botao b){
    if(t->qntBotoes < MAX_BOTOES){
        t->botoes[t->qntBotoes] = b;
    }
}

void DesenhaTela(Tela t){
    if(t.qntBotoes > 0){
        int i;
        for(i = 0; i < t.qntBotoes;i++){
            DesenhaBotao(t.botoes[i], i);
        }
    }
}

void OuvidorEventosTela(Tela t){

}