#include <stdlib.h>
#include <stdio.h>
#include "tadgen.h"

int main(){
    printf("tad_gen_01\nDigite o tipo e numero de elementos: ");
    int type, numEle;
    scanf("%d %d", &type, &numEle);
    tGeneric *gen = CriaGenerico(type, numEle);
    LeGenerico(gen);
    ImprimeGenerico(gen);
    DestroiGenerico(gen);
    
    return 0;
}