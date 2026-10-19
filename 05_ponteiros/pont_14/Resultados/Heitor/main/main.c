#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tela.h"
#include "botao.h"

#define ALTURA 400
#define LARGURA 200

void SalvarDados(void);
void ExcluirDados(void);
void AbrirOpcoes(void);

int main(){
    Tela tela = CriarTela(ALTURA, LARGURA);
  
    Botao salvar = CriarBotao("Salvar", 12, "FFF", CLICK, SalvarDados);
    Botao excluir = CriarBotao("Excluir", 18, "000", CLICK, ExcluirDados);
    Botao opcoes = CriarBotao("Opcoes", 10, "FF0000", LONGO_CLICK, AbrirOpcoes);
    
    RegistraBotaoTela(&tela, salvar);
    RegistraBotaoTela(&tela, excluir);
    RegistraBotaoTela(&tela, opcoes);

    DesenhaTela(tela);

    OuvidorEventosTela(tela);

    return 0;
}

void SalvarDados(void){
    printf("- Botao de SALVAR dados ativado!\n");
}

void ExcluirDados(void){
    printf("- Botao de EXCLUIR dados ativado!\n");
}

void AbrirOpcoes(void){
    printf("- Botao de OPCOES ativado!\n");
}