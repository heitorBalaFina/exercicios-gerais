#include "area.h"
#include <stdio.h>
#include <string.h>

Area lerArea(){
    Area a;
    scanf(" %99[^\n]", a.nome);
    scanf(" %4[^\n]", a.id);
    scanf("%d", &a.capacidade);
    return a;
}

void imprimeArea(Area a){
    //printf("Area reservada:\n");
    printf("Nome: %s\n", a.nome);
    printf("Id: %s\n", a.id);
    printf("Capacidade: %d convidado(s)\n", a.capacidade);
}

int comparaArea(Area a1, Area a2){
    if(!strcmp(a1.id, a2.id)){
        return 1;
    }
    return 0;
}

int verificaIdArea(Area a, char *id){
    if(!strcmp(a.id, id)){
        return 1;
    }
    return 0;
}

int getCapacidadeArea(Area a){
    return a.capacidade;
}