#include <stdio.h>
#include "data.h"

int main(){
    int dia, mes, ano;
    scanf("%d/%d/%d ", &dia, &mes, &ano);
    tData data1 = CriaData(dia, mes, ano);
    scanf("%d/%d/%d ", &dia, &mes, &ano);
    tData data2 = CriaData(dia, mes, ano);

    if(VerificaDataValida(data1) && VerificaDataValida(data2)){
        printf("Primeira data: ");
        ImprimeDataExtenso(data1);
        printf("Segunda data: ");
        ImprimeDataExtenso(data2);
        
        int ehMaior = ComparaData(data1, data2);

        if(ehMaior == 1){
            printf("A segunda data eh mais antiga\n");
        } else if(ehMaior == -1){
            printf("A primeira data eh mais antiga\n");
        } else if(!ehMaior){
            printf("As datas sao iguais\n");
        }

        if(ehMaior == -1){
            printf("A diferenca em dias entre as datas eh: %02d dias", CalculaDiferencaDias(data1, data2));
        } else {
            printf("A diferenca em dias entre as datas eh: %02d dias", CalculaDiferencaDias(data2, data1));
        }
    } else {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
    }
    
    return 0;
}