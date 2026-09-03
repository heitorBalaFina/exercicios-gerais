#include <stdio.h>
#include <string.h>
#include "reserva.h"
#include "morador.h"
#include "data.h"
#include "area.h"


Reserva criaReserva(Morador morRes, Area aRes, Data dRes, int qtdConvidados){
    Reserva r;
    r.morador = morRes;
    r.area = aRes;
    r.data = dRes;
    r.qtdConvidados = qtdConvidados;
    return r;
}

int verificaSolicitacaoReserva(Reserva *agendaReservas, int nRes, Morador morRes, Area aRes, Data dRes, int qtdConvidados){
    // verifica se quem ta reservando eh maior de idade
    if(calcularDiffAnosData(morRes.dataNasc, dRes) < 18){
        return 0;
    }
    // verifica se a quantidade de convidados eh maior que a capacidade do local
    if(qtdConvidados > aRes.capacidade){
        return 0;
    }
    int i;
    for(i = 0; i < nRes; i++){
        // ve se o dia coincide com o dia da reserva
        if(comparaData(agendaReservas[i].data, dRes)){
            // ve se o lugar ja esta reservado no dia
            if(comparaArea(agendaReservas[i].area, aRes)){
                return 0;
            // ve se o morador ja reservou algo nesse dia
            } else if(comparaMorador(agendaReservas[i].morador, morRes)){
                return 0;
            }
        }
    }
    return 1;
}

void imprimeReserva(Reserva r){
    printf("--------- RESERVA -----------\n");
    printf("Morador:\n");
    imprimeMorador(r.morador);
    printf("\n");
    printf("Area reservada:\n");
    imprimeArea(r.area);
    printf("\n");
    printf("Quantidade de convidados: %d\n", r.qtdConvidados);
    printf("Taxa de ocupação: %02d%%", (r.qtdConvidados*100/r.area.capacidade));
    printf("------------------------------");
}

/*
--------- RESERVA -----------
Morador: 
Nome: Renata Glasc
CPF: 126.458.235-32
Data de Nascimento: 15/11/1992
Residência: 302-B

Area reservada: 
Nome: Churrasqueira
Id: A1
Capacidade: 30 convidado(s)
Data da reserva: 4/10/2024

Quantidade de convidados: 20
Taxa de ocupação: 66%
------------------------------
*/