#include <stdio.h>
#include "lesao.h"
#include "string.h"


Lesao criaLesao(char *cartaoSus, char *id, char *diagnostico, char *regiao, int malignidade){
    Lesao lesao;
    strcpy(lesao.cartaoSus, cartaoSus);
    strcpy(lesao.id, id);
    strcpy(lesao.diagnostico, diagnostico);
    strcpy(lesao.regiao, regiao);
    lesao.malignidade = malignidade;
    return lesao;
}

Lesao lerLesao(){
    char cartaoSus[MAX_CARTAO_LES];
    char id[MAX_ID_LES];
    char diagnostico[MAX_DIAG_LES];
    char regiao[MAX_REG_LES];
    int malignidade;
    scanf(" %18[^\n]", cartaoSus);
    scanf(" %10[^\n]", id);
    scanf(" %100[^\n]", diagnostico);
    scanf(" %100[^\n]", regiao);
    scanf("%d ", &malignidade);
    return criaLesao(cartaoSus, id, diagnostico, regiao, malignidade);
}

void getCartaoSusLesao(Lesao l, char *cartaoSus){
    strcpy(cartaoSus, l.cartaoSus);
}

int verificaCirurgicaLesao(Lesao l){
    if(l.malignidade > 50){
        return 1;
    }
    return 0;
}

void imprimeIdLesao(Lesao l){
    printf("%s", l.id);
}