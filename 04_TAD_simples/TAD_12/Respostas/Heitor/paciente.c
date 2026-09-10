#include <stdio.h>
#include "paciente.h"
#include "string.h"

Paciente criaPaciente(char *nome, char *cartaoSus, char genero, Data dataNasc){
    Paciente paciente;
    strcpy(paciente.nome, nome);
    strcpy(paciente.cartaoSus, cartaoSus);
    paciente.genero = genero;
    paciente.dataNasc = dataNasc;
    paciente.numLesoes = 0;
    return paciente;
}

Paciente lerPaciente(){
    char nome[MAX_NOME_PAC];    
    char cartaoSus[MAX_CARTAO_SUS];
    char genero;
    Data dataNasc;   
    Lesao lesoes[MAX_LESOES];
    scanf(" %100[^\n]", nome);
    dataNasc = lerData();
    scanf(" %18[^\n]", cartaoSus);
    scanf(" %c", &genero);
    return criaPaciente(nome, cartaoSus, genero, dataNasc);
}

Paciente vinculaLesaoPaciente(Paciente p, Lesao l){
    if(p.numLesoes < MAX_LESOES){
        p.lesoes[p.numLesoes] = l;
        p.numLesoes++;
    }
    return p;
}

int calculaIdadePaciente(Paciente p, Data dataBase){
    return diferencaAnoData(p.dataNasc, dataBase);
}

void getCartaoSusPaciente(Paciente p, char *cartaoSus){
    strcpy(cartaoSus, p.cartaoSus);
}

int getNumLesoesPaciente(Paciente p){
    return p.numLesoes;
}

int qtdLesoesCirurgicasPaciente(Paciente p){
    int i, cont = 0;
    for(i = 0; i < p.numLesoes; i++){
        if(verificaCirurgicaLesao(p.lesoes[i])){
            cont++;
        }
    }
    return cont;
}

void imprimePaciente(Paciente p){
    if(p.numLesoes > 0){
        printf("- %s - ", p.nome);
        int i;
        for(i = 0; i < p.numLesoes; i++){
            imprimeIdLesao(p.lesoes[i]);
            printf(" ");
        }
        printf("\n");
    }
}