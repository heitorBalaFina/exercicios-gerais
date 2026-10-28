#include "data.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int RetornaDiasTotaisData(tData* data);

//typedef struct Data tData;
struct Data {
    int dia, mes, ano;
};

tData* CriaData(){
    tData *novaData = (tData*) malloc(sizeof(struct Data));
    if(novaData == NULL) return NULL;

    novaData->dia = -1;
    novaData->mes = -1;
    novaData->ano = -1;

    return novaData;
}

void LeData(tData* data){
    if(data == NULL) return;

    int dia, mes, ano;
    if(scanf("%d/%d/%d", &dia, &mes, &ano) != 3) return;

    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
}

void LiberaData(tData* data){
    free(data);
}

int VerificaDataValida(tData* data){
    if(data == NULL) return 0;
    if(data->ano < 1) return 0;
    if(data->mes < 1 || data->mes > 12) return 0;
    if(data->dia < 1 || data->dia > NumeroDiasMes(data)) return 0;
    return 1;
}

void ImprimeMesExtenso(tData* data){
    int mes = data->mes;
    switch (mes)
    {
    case 1:
        printf("Janeiro");
        break;
    case 2:
        printf("Fevereiro");
        break;
    case 3:
        printf("Marco");
        break;
    case 4:
        printf("Abril");
        break;
    case 5:
        printf("Maio");
        break;
    case 6:
        printf("Junho");
        break;
    case 7:
        printf("Julho");
        break;
    case 8:
        printf("Agosto");
        break;
    case 9:
        printf("Setembro");
        break;
    case 10:
        printf("Outubro");
        break;
    case 11:
        printf("Novembro");
        break;
    case 12:
        printf("Dezembro");
        break;
    default:
        break;
    }
}

void ImprimeDataExtenso(tData* data){
    if(VerificaDataValida(data)){
        //28 de Janeiro de 2002
        printf("%02d de ", data->dia);
        ImprimeMesExtenso(data);
        printf(" de %d\n", data->ano);
    }
}

int VerificaBissexto(tData* data){
    int ano = data->ano;
    if( (!(ano%4) && (ano%100)) || !(ano%400) ) return 1;
    return 0;
}

int NumeroDiasMes(tData* data){
    int mes = data->mes;

    if(mes == 2){
        if(VerificaBissexto(data)) return 29;
        return 28;
    } else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
        return 30;
    }
    return 31;
}

int ComparaData(tData* data1, tData* data2){
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

    LiberaData(aux);

    return dias;
}