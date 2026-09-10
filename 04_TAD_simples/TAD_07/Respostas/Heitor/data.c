#include "data.h"
#include <stdio.h>
#include <math.h>

tData CriaData(int dia, int mes, int ano){
    tData data;
    data.dia = dia;
    data.mes = mes;
    data.ano = ano;
    return data;
}

int VerificaDataValida(tData data){
    int mes = data.mes;
    int dia = data.dia;
    if(mes >= 0 && mes <= 12){
        if(mes == 2){
            if(VerificaBissexto(data)){
                if(dia >= 0 && dia <= 29) return 1;
            } else {
                if(dia >= 0 && dia <= 28) return 1;
            }
        } else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
            if(dia >= 0 && dia <= 30) return 1;
        } else {
            if(dia >= 0 && dia <= 31) return 1;
        }
    }
    return 0;
}

int VerificaBissexto(tData data){
    if(!(data.ano % 4) && (data.ano % 100) || !(data.ano%400)){
        return 1;
    }
    return 0;
}

void ImprimeDataExtenso(tData data){
    printf("%02d de ", data.dia);
    ImprimeMesExtenso(data);
    printf(" de %d\n", data.ano);
}
//28 de Janeiro de 2002

void ImprimeMesExtenso(tData data){
    switch (data.mes){
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

int NumeroDiasMes(tData data){
    int mes = data.mes;
    if(mes == 2 && !VerificaBissexto(data)){
        return 28;
    } else if(mes == 2){
        return 29;
    } else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
        return 30;
    } else {
        return 31;
    }
}

int ComparaData(tData data1, tData data2){
    if(data1.ano == data2.ano && data1.mes == data2.mes && data1.dia == data2.dia){
        return 0;
    } else if(data1.ano > data2.ano){
        return 1;
    } else if(data1.ano == data2.ano && data1.mes > data2.mes){
        return 1;
    } else if(data1.ano == data2.ano && data1.mes == data2.mes && data1.dia > data2.dia){
        return 1;
    }
    return -1;
}

int CalculaDiferencaDias(tData data1, tData data2){
    int anos = 0, meses = 0, dias = 0;
    anos = data1.ano - 2000;
    meses = data1.mes;
    dias = data1.dia;
    int diasTotais1 = (anos*365) + ((anos + 3) / 4) + dias + CalculaDiasAteMes(data1);
    anos = data2.ano - 2000;
    meses = data2.mes;
    dias = data2.dia;
    int diasTotais2 = (anos*365) + ((anos + 3) / 4) + dias + CalculaDiasAteMes(data2);

    return sqrt(pow(diasTotais1-diasTotais2, 2));
}

int CalculaDiasAteMes(tData data){
    int mes = data.mes;
    int diasTotais = 0;
    int m;
    for(m = 1; m < mes; m++){
        if(m == 2){
            if(VerificaBissexto(data)){
                diasTotais += 29;
            } else {
                diasTotais += 28;
            }
        } else if(m == 4 || m == 6 || m == 9 || m == 11){
            diasTotais += 30;
        } else {
            diasTotais += 31;
        }
    }
    return diasTotais;
}