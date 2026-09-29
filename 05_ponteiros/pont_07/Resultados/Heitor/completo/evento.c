#include "evento.h"
#include "stdio.h"
#include "string.h"

void cadastrarEvento(Evento* eventos, int* numEventos){
    if(*numEventos >= MAX_EVENTOS) return;
    scanf(" %49[^\n]", eventos[*numEventos].nome);
    scanf(" %d %d %d", &eventos[*numEventos].dia, &eventos[*numEventos].mes, &eventos[*numEventos].ano);
    *numEventos+=1;
    printf("Evento cadastrado com sucesso!\n");
}

void exibirEventos(Evento* eventos, int* numEventos){
    int posicao;
    for(posicao = 0; posicao < *numEventos; posicao++){
        printf("%d - %s - %d/%d/%d\n", posicao, eventos[posicao].nome, eventos[posicao].dia, eventos[posicao].mes, eventos[posicao].ano);
    }
}

void trocarDataEvento(Evento* eventos, int* numEventos){
    int indiceTroca = 0;
    int dia = 0, mes = 0, ano = 0;

    scanf("%d", &indiceTroca);

    if(indiceTroca < 0 || indiceTroca >= *numEventos){
        printf("Indice invalido!\n");
        return;
    }

    scanf("%d %d %d", &dia, &mes, &ano);

    eventos[indiceTroca].dia = dia;
    eventos[indiceTroca].mes = mes;
    eventos[indiceTroca].ano = ano;

    printf("Data modificada com sucesso!\n");
}

void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos){
    Evento troca;
    troca = eventos[*indiceA];
    eventos[*indiceA] = eventos[*indiceB];
    eventos[*indiceB] = troca;
    printf("Eventos trocados com sucesso!");
}