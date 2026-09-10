#include <stdio.h>
#include <string.h>
#include "filme.h"
#include "locadora.h"

int main(){
    int codigo;
    char opcao[MAX_CARACTERES];
    tLocadora locadora = criarLocadora();
    while(scanf("%19[^\n]") == 1){
        while(scanf("%d,", &codigo == 1)){
            locadora = cadastrarFilmeLocadora(locadora, leFilme(codigo));
        }
    }
    return 0;
}