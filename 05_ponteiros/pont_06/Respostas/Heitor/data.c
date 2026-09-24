#include "data.h"
#include <stdio.h>

void InicializaDataParam( int dia, int mes, int ano, tData *data){
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
}

void LeData( tData *data ){
    int dia, mes, ano;
    scanf(" %d %d %d", &dia, &mes, &ano);
    InicializaDataParam(dia, mes, ano, data);
}

void ImprimeData( tData *data ){
    printf("'%02d/%02d/%d'", data->dia, data->mes, data->ano);
}

int EhBissexto( tData *data ){
    if((!(data->ano%4) && (data->ano%100)) || !(data->ano%400)){
        return 1;
    }
    return 0;
}

int InformaQtdDiasNoMes( tData *data ){
    if(data->mes == 2){
        if(EhBissexto(data)) return 29;
        return 28;
    } else if(data->mes == 4 || data->mes == 6 || data->mes == 9 || data->mes == 11){
        return 30;
    }
    return 31;
}

void AvancaParaDiaSeguinte( tData *data ){
    if(data->dia >= InformaQtdDiasNoMes(data)){
        data->dia = 1;
        data->mes++;
        if(data->mes > 12){
            data->mes = 1;
            data->ano++;
        }
    } else {
        data->dia ++;
    }
}

int EhIgual( tData *data1, tData *data2 ){
    if(data1->ano == data2->ano && data1->mes == data2->mes && data1->dia == data2->dia) return 1;
    return 0;
}