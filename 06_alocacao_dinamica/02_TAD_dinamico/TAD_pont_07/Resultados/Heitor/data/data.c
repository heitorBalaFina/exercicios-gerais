#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "data.h"
#include <math.h>

/*
typedef struct Data {
    int dia;
    int mes;
    int ano; 
} tData;
*/

int CalculaDiasAcumulados(tData* data);

tData* CriaData(){
    tData *novaData = (tData *) malloc(sizeof(tData));
    if(novaData  == NULL) exit(0);
    novaData->ano = -1;
    novaData->mes = -1;
    novaData->dia = -1;
    return novaData;
}

void LeData(tData* data){
    scanf("%d/%d/%d ", &data->dia, &data->mes, &data->ano);
}

void LiberaData(tData* data){
    if(data == NULL) return;
    free(data);
}

int VerificaDataValida(tData* data){
    if(data->mes < 0 || data->mes > 12){
        return 0;
    } else if(data->dia > NumeroDiasMes(data)){
        return 0;
    }
    return 1;
}

void ImprimeMesExtenso(tData* data){
    switch (data->mes){
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
    }
}

void ImprimeDataExtenso(tData* data){
    printf("%02d de ", data->dia);
    ImprimeMesExtenso(data);
    printf(" de %d\n", data->ano);
}

int VerificaBissexto(tData* data){
    if((!(data->ano % 4) && (data->ano % 100)) || !(data->ano % 400)) return 1;
    return 0;
}

int NumeroDiasMes(tData* data){
    int mes = data->mes;
    if(mes == 2){
        if(VerificaBissexto(data)) return 29; 
        return 28;
    } else if(mes == 4 || mes == 6 || mes == 9||mes == 11){
        return 30;
    } else {
        return 31;
    }
}

int ComparaData(tData* data1, tData* data2){
    
    if(data1->ano == data2->ano && data1->mes == data2->mes && data1->dia == data2->dia){
        return 0;
    } else if(data1->ano > data2->ano){
        return 1;
    } else if(data1->ano == data2->ano && data1->mes > data2->mes){
        return 1;
    }else if(data1->ano == data2->ano && data1->mes == data2->mes && data1->dia > data2->dia){
        return 1;
    }
    return -1;

}

int CalculaDiasAteMes(tData* data){
    int dias = 0;
    int i;
    tData dataAux = *data;

    for(i = 1; i < data->mes; i++){
        dataAux.mes = i;
        dias += NumeroDiasMes(&dataAux);
    }

    return dias;
}

int CalculaDiferencaDias(tData* data1, tData* data2){
    
    int dias1 = CalculaDiasAcumulados(data1);
    int dias2 = CalculaDiasAcumulados(data2);

    if(!ComparaData(data1, data2)){
        return 0;
    }        
    return sqrt(pow(dias1-dias2,2));
    
}

int CalculaDiasAcumulados(tData* data){
    int dias = 0;
    int ano;
    tData dataAux = *data;

    for(ano = 1; ano < data->ano; ano++){
        dataAux.ano = ano;

        if(VerificaBissexto(&dataAux)){
            dias += 366;
        } else {
            dias += 365;
        }
    }

    dias += CalculaDiasAteMes(data);
    dias += data->dia - 1;

    return dias;
}