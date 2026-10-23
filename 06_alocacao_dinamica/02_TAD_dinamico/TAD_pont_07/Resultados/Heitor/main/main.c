#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "data.h"

int main(){
    tData *data1 = CriaData();
    tData *data2 = CriaData();
    LeData(data1);
    LeData(data2);
    if(!VerificaDataValida(data1) || !VerificaDataValida(data2)){
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        LiberaData(data1);
        LiberaData(data2);
        return 0;
    }
    printf("Primeira data: ");
    ImprimeDataExtenso(data1);
    printf("Segunda data: ");
    ImprimeDataExtenso(data2);
    
    int comp = ComparaData(data1, data2);
    if(comp == -1){
        printf("A primeira data eh mais antiga\n");
    } else if(comp == 1){
        printf("A segunda data eh mais antiga\n");
    } else {
        printf("As datas sao iguais\n");
    }

    printf("A diferenca em dias entre as datas eh: %02d dias\n", CalculaDiferencaDias(data1,data2));

    LiberaData(data1);
    LiberaData(data2);
    return 0;
}