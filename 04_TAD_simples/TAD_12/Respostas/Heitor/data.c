#include "data.h"
#include <stdio.h>
#include <string.h>


Data criaData(int dia, int mes, int ano){
    Data data = {dia, mes, ano};
    return data;
}

Data lerData(){
    int dia, mes, ano;
    scanf("%d/%d/%d ", &dia, &mes, &ano);
    return criaData(dia, mes, ano);
}

int diferencaAnoData(Data inicial, Data atual){
    if((atual.mes > inicial.mes) || (atual.mes == inicial.mes && atual.dia >= inicial.dia)){
        return atual.ano - inicial.ano;
    }
    return (atual.ano - inicial.ano) - 1;
}

void imprimeData(Data d){
    printf("%d/%d/%d", d.dia, d.mes, d.ano);
}