#include "data.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct Data{
    int dia, mes, ano;
    int hora, minuto;
    int diaSemana;
};

#define DIA_SEMANA 0
#define DATA_ENTRADA 3
#define HORA_ENTRADA 15
#define DATA_SAIDA 22
#define HORA_SAIDA 34

int RetornaDiasTotaisData(tData* data);
void CalculaDiaSemanaSaida(tData* entrada, tData* saida);


tData* CriaData(){
    tData *novaData = (tData*) malloc(sizeof(struct Data));
    if(novaData == NULL) return NULL;
    
    novaData->dia = -1;
    novaData->mes = -1;
    novaData->ano = -1;

    novaData->hora = -1;
    novaData->minuto = -1;

    novaData->diaSemana = -1;
    
    return novaData;
}

void DestroiData(tData* data){
    if(data == NULL) return;
    
    free(data);
}

void ProcessaDiaMesAno(tData* data, char* str) {
    if (data == NULL || str == NULL) return;

    sscanf(str, "%d/%d/%d",
           &data->dia, &data->mes, &data->ano);
}

void ProcessaDiaDaSemana(tData* data, char* str) {
    if (data == NULL || str == NULL) return;

    sscanf(str, "%d", &data->diaSemana);
}

void ProcessaHorario(tData* data, char* str) {
    if (data == NULL || str == NULL) return;

    sscanf(str, "%d:%d", &data->hora, &data->minuto);
}

int VerificaDataValida(tData* data) {
    if (data == NULL) return 0;

    if (data->ano < 1) return 0;
    if (data->mes < 1 || data->mes > 12) return 0;
    if (data->dia < 1 || data->dia > NumeroDiasMes(data)) return 0;

    return 1;
}

int VerificaBissexto(tData* data){
    if(data== NULL) return 0;
    
    int ano = data->ano;
    if((!(ano%4) && (ano%100)) || !(ano%400)) return 1;
    return 0;
}

int NumeroDiasMes(tData* data) {
    if (data == NULL || data->mes < 1 || data->mes > 12) return 0;

    int mes = data->mes;

    if (mes == 2) {
        if (VerificaBissexto(data)) return 29;
        return 28;
    }

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
        return 30;

    return 31;
}

int ComparaDiaMesAno(tData* data1, tData* data2){
    //verifica se sao iguais
    if(data1->ano == data2->ano && data1->mes == data2->mes && data1->dia == data2->dia) return 0;

    // verifica se data1 eh maior que data2
    if(data1->ano > data2->ano){
        return 1;
    } else if(data1->ano == data2->ano && data1->mes > data2->mes){
        return 1;
    } else if(data1->ano == data2->ano && data1->mes == data2->mes && data1->dia > data2->dia){
        return 1;
    }

    // retorna -1 porque ja passou por todas as outras verificacoes, logo a data2 eh maior
    return -1;
}

int CalculaDiasAteMes(tData* data){
    if(data == NULL || !(VerificaDataValida(data))) return 0;

    int qtdDias = 0;
    int mes;

    for(mes = 1; mes < data->mes; mes++){
        tData aux = *data;
        aux.mes = mes;
        qtdDias += NumeroDiasMes(&aux);
    }

    return qtdDias;
}

int CalculaDiferencaDias(tData* data1, tData* data2){
    if(!VerificaDataValida(data1) || !VerificaDataValida(data2)) return -1;
    
    int dias1 = RetornaDiasTotaisData(data1);
    int dias2 = RetornaDiasTotaisData(data2);

    if(dias1 < 0 || dias2 < 0) return -1;

    return abs(dias1 - dias2);
}

int RetornaDiasTotaisData(tData* data){
    if(!VerificaDataValida(data)) return -1;

    tData *aux = CriaData();
    if(aux == NULL) return -1;

    aux->ano = 1;

    int dias = 0;

    while(aux->ano < data->ano){
        if(VerificaBissexto(aux)){
            dias += 366;
        } else {
            dias += 365;
        }
        aux->ano++;
    }

    dias += CalculaDiasAteMes(data);
    dias += data->dia;

    DestroiData(aux);

    return dias;
}

float CalculaHorasEntreDatas(tData* data1, tData* data2) {
    if (!VerificaDataValida(data1) || !VerificaDataValida(data2))
        return -1.0f;

    if (data1->hora < 0 || data1->hora > 23 ||
        data2->hora < 0 || data2->hora > 23 ||
        data1->minuto < 0 || data1->minuto > 59 ||
        data2->minuto < 0 || data2->minuto > 59)
        return -1.0f;

    int comparacao = ComparaDiaMesAno(data1, data2);

    if (comparacao > 0) return -1.0f;

    int minutos1 = data1->hora * 60 + data1->minuto;
    int minutos2 = data2->hora * 60 + data2->minuto;

    if (comparacao == 0 && minutos2 < minutos1)
        return -1.0f;

    int diferencaDias = CalculaDiferencaDias(data1, data2);

    if (diferencaDias < 0) return -1.0f;

    float horas = diferencaDias * 24.0f;
    horas += (minutos2 - minutos1) / 60.0f;

    return horas;
}

int DataEhSabadoOuDomingo(tData* data){
    if(data== NULL) return 0;

    if(data->diaSemana==0 || data->diaSemana==6) return 1;
    return 0;
}

void DataDiaSeguinte(tData* data) {
    if (!VerificaDataValida(data)) return;

    if (data->dia < NumeroDiasMes(data)) {
        data->dia++;
    } else {
        data->dia = 1;

        if (data->mes < 12) {
            data->mes++;
        } else {
            data->mes = 1;
            data->ano++;
        }
    }

    if (data->diaSemana >= 0 && data->diaSemana <= 6) {
        data->diaSemana = (data->diaSemana + 1) % 7;
    }
}

void CopiaDiaMesAno(tData* src, tData* tgt){
    if (src == NULL || tgt == NULL) return;
   
    tgt->dia = src->dia;
    tgt->mes = src->mes;
    tgt->ano = src->ano;
}

void CalculaDiaSemanaSaida(tData* entrada, tData* saida) {
    if (entrada == NULL || saida == NULL) return;

    if (!VerificaDataValida(entrada) ||
        !VerificaDataValida(saida)) return;

    if (entrada->diaSemana < 0 || entrada->diaSemana > 6) return;

    if (ComparaDiaMesAno(entrada, saida) > 0) return;

    int diferenca = CalculaDiferencaDias(entrada, saida);

    if (diferenca < 0) return;

    saida->diaSemana = (entrada->diaSemana + diferenca) % 7;
}