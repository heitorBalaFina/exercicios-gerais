#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "botao.h"

/*
typedef struct {
    char texto[MAX_TAM_TEXTO];
    int tamFonte;
    char corHex[7];
    int tipo;
    void (*executa)(void); // ponteiro para função que irá executar um evento quando o botão for clicado
} Botao;
*/

void SetarTexto(Botao *b, char *novoTexto){
    if(strlen(novoTexto) < MAX_TAM_TEXTO-1){
        strcpy(b->texto, novoTexto);
    } else {
        exit(0);
    }
}

void SetarTamFonte(Botao *b, int novoTamFonte){
    if(novoTamFonte > 0){
        b->tamFonte = novoTamFonte;
    } else {
        exit(0);
    }
}

void SetarCor(Botao *b, char *novaCor){
    strcpy(b->corHex,novaCor);
}

void SetarTipo(Botao *b, int novoTipo){
    if(novoTipo == CLICK || novoTipo == LONGO_CLICK || novoTipo == HOVER){
        b->tipo = novoTipo;
    }
    
}

Botao CriarBotao(char *texto, int tamFonte, char *cor, int tipo, void (*executa)(void)){
    Botao b;
    SetarTexto(&b, texto);
    SetarTamFonte(&b, tamFonte);
    SetarCor(&b, cor);
    SetarTipo(&b, tipo);
    b.executa = executa;
    return b;
}

void ExecutaBotao(Botao b){
    // Verificamos se o tipo é válido (1, 2 ou 3) de acordo com o .h
    printf("- Executando o botao com evento de ");
    if(b.tipo == 1) printf("click\n");
    if(b.tipo == 2) printf("longo click\n");
    if(b.tipo == CLICK || b.tipo == LONGO_CLICK || b.tipo == HOVER){
        // Se a função existir, nós a executamos
        if(b.executa != NULL){
            b.executa();
        }
    } else {
        exit(0); // Se o tipo for inválido, o programa é encerrado conforme a regra
    }
}

void DesenhaBotao(Botao b, int idx){
    printf("-------------\n");
    printf("- Botao [%d]:\n", idx);
    printf("(%s | %s | %d | %d)\n", b.texto, b.corHex, b.tamFonte, b.tipo);
    printf("-------------\n");
}


/*
-------------
- Botao [1]:
(Excluir | 000 | 18 | 1)
-------------
*/