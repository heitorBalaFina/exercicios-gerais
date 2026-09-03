#include "candidato.h"
#include <string.h>

tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id){
    tCandidato candidato;
    strcpy(candidato.nome, nome);
    strcpy(candidato.partido, nome);
    candidato.cargo = cargo;
    candidato.id = id;
    candidato.votos = 0;
    return candidato;
}

tCandidato LeCandidato(){
    tCandidato candidato;
    candidato.votos = 0;
    scanf(" %49[^,], %49[^,], %c, %d", candidato.nome, candidato.partido, &candidato.cargo, &candidato.id);
    return candidato;
}