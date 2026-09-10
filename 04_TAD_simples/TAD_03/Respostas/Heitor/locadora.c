#include "locadora.h"
#include <stdio.h>
#include <string.h>

tLocadora criarLocadora (){
    tLocadora locadora;
    // numero de filmes eh zero porque nenhum filme foi cadastrado ainda
    // talvez devesse comecar com 1, vou ver
    locadora.numFilmes = 0;
    locadora.lucro = 0;
    return locadora;
}

int verificarFilmeCadastrado (tLocadora locadora, int codigo){
    int i;
    for(i = 0; i < locadora.numFilmes; i++){
        if(locadora.filme[i].codigo == codigo) return 1;
    }
    return 0;
}

tLocadora cadastrarFilmeLocadora (tLocadora locadora, tFilme filme){
    if(!verificarFilmeCadastrado(locadora, filme.codigo)){
        locadora.filme[locadora.numFilmes] = filme;
        locadora.numFilmes++;
        printf("Filme cadastrado %d - ", filme.nome);
        imprimirNomeFilme(filme);
        printf("\n");
    } else {
        printf("Filme ja cadastrado no estoque\n");
    }

    return locadora;
}

tLocadora lerCadastroLocadora (tLocadora locadora){
    int codigo;
    // enquanto ele conseguir ler um numero ele vai cadastrandondo os filmes na locadora
    while(scanf(" %d,", &codigo) == 1){
        cadastrarFilmeLocadora(locadora, leFilme(codigo)) ;
    }
    return locadora;
}

tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos){
    int i;
    for(i = 0;i < quantidadeCodigos; i++){
        
    }
    return locadora;
}