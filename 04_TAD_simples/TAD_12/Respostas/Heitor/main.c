#include <stdio.h>
#include <string.h>
#include "data.h"
#include "paciente.h"
#include "lesao.h"

#define MAX_PACIENTES 100

int RetornaMediaIdade(Paciente p[], int numPacientes, Data dataBase);
int RetornaTotalCirurgias(Paciente p[], int numPacientes);
void ImprimeNoFinal(Paciente p[], int numPacientes, int numLesoes, Data dataBase);
void ImprimePacientesComLesoes(Paciente p[], int numPacientes);

int main(){
    Data dataBase = {12, 9, 2023}; // dia/mes/ano
    Paciente pacientes[MAX_PACIENTES];
    Lesao lesao;
    int numPacientes = 0, numLesoes = 0;
    char opcao;

    while (scanf("%c ", &opcao)){
        if(opcao == 'P' && numPacientes < MAX_PACIENTES){
            pacientes[numPacientes] = lerPaciente();
            numPacientes++;
        } else if(opcao == 'L'){
            lesao = lerLesao();
            int i;
            for(i = 0; i < numPacientes; i++){
                if(!strcmp(pacientes[i].cartaoSus, lesao.cartaoSus)){
                    pacientes[i] = vinculaLesaoPaciente(pacientes[i], lesao);
                    numLesoes++;
                }
            }
        } else if(opcao == 'F'){
            ImprimeNoFinal(pacientes, numPacientes, numLesoes, dataBase);
            return 0;
        }
    }
    
    return 0;
}

int RetornaMediaIdade(Paciente p[], int numPacientes, Data dataBase){
    int i, somador = 0;
    for(i = 0; i < numPacientes; i++){
        somador += diferencaAnoData(p[i].dataNasc, dataBase);
    }
    return somador / numPacientes;
}

void ImprimeNoFinal(Paciente p[], int numPacientes, int numLesoes, Data dataBase){
    if(numPacientes == 0){
        printf(" - ");
    } else {
        int mediaIdades = RetornaMediaIdade(p, numPacientes, dataBase);
        int numCirurgias = RetornaTotalCirurgias(p, numPacientes);

        printf("TOTAL PACIENTES: %d\n", numPacientes);
        printf("MEDIA IDADE (ANOS): %d\n", mediaIdades);
        printf("TOTAL LESOES: %d\n", numLesoes);
        printf("TOTAL CIRURGIAS: %d\n", numCirurgias);
        printf("LISTA DE PACIENTES:\n");
        ImprimePacientesComLesoes(p, numPacientes);
    }
}

int RetornaTotalCirurgias(Paciente p[], int numPacientes){
    int i, j, cont = 0;
    for(i = 0; i < numPacientes; i++){
        for(j = 0; j < p[i].numLesoes; j++){
            if(verificaCirurgicaLesao(p[i].lesoes[j])) cont++;
        }
    }
    return cont;
}

void ImprimePacientesComLesoes(Paciente p[], int numPacientes){
    int i;
    for(i = 0; i < numPacientes; i++){
        imprimePaciente(p[i]);
    }
}