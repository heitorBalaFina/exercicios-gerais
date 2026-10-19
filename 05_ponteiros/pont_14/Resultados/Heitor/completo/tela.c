#include <stdio.h>
#include <stdlib.h>
#include "tela.h"
#include "botao.h"

Tela CriarTela(int altura, int largura){
    Tela t;
    t.altura = altura;
    t.largura = largura;
    t.qntBotoes = 0;
    return t;
}

void RegistraBotaoTela(Tela *t, Botao b){
    if (t->qntBotoes < MAX_BOTOES){
        t->botoes[t->qntBotoes] = b;
        t->qntBotoes++;
    }
}

void DesenhaTela(Tela t){
    int i;
    printf("##################\n");
    for (i = 0; i < t.qntBotoes; i++){
        DesenhaBotao(t.botoes[i], i);
        printf("\n");
    }
    printf("##################\n- Escolha sua acao: ");
}

void OuvidorEventosTela(Tela t){
    int indiceBotao;
    if (scanf("%d", &indiceBotao) != 1) exit(0);
    if (indiceBotao < 0 || indiceBotao >= t.qntBotoes) exit(0);
    ExecutaBotao(t.botoes[indiceBotao]);
}