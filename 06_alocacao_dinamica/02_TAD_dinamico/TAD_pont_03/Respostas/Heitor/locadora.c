#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "locadora.h"

/*
typedef struct Locadora {
    tFilme** filme; 
    int numFilmes; 
    int lucro; 
} tLocadora;
*/

tLocadora* CriarLocadora (){
    tLocadora *novaLocadora = (tLocadora*) malloc(sizeof(tLocadora));
    if(novaLocadora == NULL) exit(0);

    novaLocadora->numFilmes = 0;
    novaLocadora->lucro = 0;
    novaLocadora->filme = NULL;
    
    return novaLocadora;
}

void DestruirLocadora (tLocadora* locadora){
    if(locadora == NULL) return;
    
    int i;
    for(i = 0; i < locadora->numFilmes; i++){
        free(locadora->filme[i]);
    }
    free(locadora->filme);
    free(locadora);
}

int VerificarFilmeCadastrado (tLocadora* locadora, int codigo){
    if(locadora == NULL) return 0;

    int i;
    for(i = 0; i < locadora->numFilmes; i++){
        if(locadora->filme[i]->codigo == codigo) return 1;
    }
    return 0;
}

void CadastrarFilmeLocadora(tLocadora *locadora, tFilme *filme){
    tFilme **temporario;

    //if(locadora == NULL || filme == NULL) return;

    //verificacoes
    if(locadora->numFilmes >= 100) return;
    if(VerificarFilmeCadastrado(locadora, filme->codigo))return;

    //se nao haver filme alocado aloca esparaco para um filme
    if(locadora->filme == NULL){
        temporario = (tFilme**) malloc(sizeof(tFilme*));
    } else {
        // se ja tiver filme alocado aloca espaco para mais um
        temporario = (tFilme**) realloc(locadora->filme, (locadora->numFilmes+1)*sizeof(tFilme*));
    }

    if(temporario == NULL) return;

    locadora->filme = temporario;
    // cadastra o filme na ultima posicao do vetor de filmes
    locadora->filme[locadora->numFilmes] = filme;
    locadora->numFilmes++;

    printf("Filme cadastrado %d - %s\n", filme->codigo, filme->nome);
}
/*
void LerCadastroLocadora (tLocadora* Locadora){
    tFilme *novoFilme = CriarFilme();
    if(novoFilme == NULL) exit(0);
    
    int codigo;
    scanf("%d,", &codigo);
    LeFilme(novoFilme, codigo);
    
    CadastrarFilmeLocadora(Locadora, novoFilme);
}
    */

void LerCadastroLocadora(tLocadora* locadora){
    int codigo;
    char caractere;

    if(locadora == NULL) return;

    while(locadora->numFilmes < 100){
        //verificacao
        if(scanf("%d,", &codigo) != 1){
            scanf(" %c", &caractere);

            if(caractere == '#') break;

            return;
        }

        tFilme *novoFilme = CriarFilme();
        if(novoFilme == NULL) return;

        LeFilme(novoFilme, codigo);

        CadastrarFilmeLocadora(locadora, novoFilme);
    }
}
// ordena o vetor de filmes em ordem alfabetica
void OrdenarFilmesLocadora (tLocadora* locadora){
    int i, j;
    tFilme *maior = NULL;
    for(i = 0; i < locadora->numFilmes; i++){
        for(j = i+1; j < locadora->numFilmes; j++){
            if(CompararNomesFilmes(locadora->filme[i], locadora->filme[j]) > 0){
                maior = locadora->filme[i];
                locadora->filme[i] = locadora->filme[j];
                locadora->filme[j] = maior;
            }
        }
    }
}

//mostra todos os filmes (em ordem alfabetica)
void ConsultarEstoqueLocadora (tLocadora* locadora){
    OrdenarFilmesLocadora(locadora);
    printf("~ESTOQUE~\n");
    int i;
    for(i = 0; i < locadora->numFilmes; i++){
        printf("%d - ", locadora->filme[i]->codigo);
        ImprimirNomeFilme(locadora->filme[i]);
        printf(" Fitas em estoque: %d\n", locadora->filme[i]->qtdEstoque);
    }
}

void ConsultarLucroLocadora (tLocadora* locadora){
    if(locadora->lucro > 0) printf("\nLucro total R$%d\n", locadora->lucro);
    
}

/*
void AlugarFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos){
    int i, j;
    for(i = 0; i < quantidadeCodigos; i++){
        for(j = 0; j < locadora->numFilmes; j++){
            if(EhMesmoCodigoFilme(locadora->filme[j],codigos[i])){
                AlugarFilme(locadora->filme[j]);
                //locadora->lucro += locadora->filme[j]->valor;
                break;
            }
        }
    }
}
*/
/*
void AlugarFilmesLocadora(tLocadora* locadora, int* codigos, int quantidadeCodigos){
    int i, j;
    int encontrado;

    if(locadora == NULL || codigos == NULL) return;

    for(i = 0; i < quantidadeCodigos; i++){
        encontrado = 0;

        for(j = 0; j < locadora->numFilmes; j++){
            if(EhMesmoCodigoFilme(locadora->filme[j], codigos[i])){
                encontrado = 1;

                AlugarFilme(locadora->filme[j]);
                break;
            }
        }

        if(!encontrado){
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
    }
}
*/

void AlugarFilmesLocadora(tLocadora* locadora, int* codigos, int quantidadeCodigos){
    int i, j;
    int encontrado;

    if(locadora == NULL || codigos == NULL) return;

    for(i = 0; i < quantidadeCodigos; i++){
        encontrado = 0;

        for(j = 0; j < locadora->numFilmes; j++){
            if(EhMesmoCodigoFilme(locadora->filme[j], codigos[i])){
                encontrado = 1;

                if(locadora->filme[j]->qtdEstoque > 0){
                    AlugarFilme(locadora->filme[j]);
                } else {
                    printf("Filme %d - %s nao disponivel no estoque. Volte mais tarde.\n",
                           locadora->filme[j]->codigo,
                           locadora->filme[j]->nome);
                }

                break;
            }
        }

        if(!encontrado){
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
    }
}

void LerAluguelLocadora(tLocadora* locadora){
    int codigo;
    int quantidade = 0;
    int capacidade = 1;
    int *codigos = (int*) malloc(capacidade * sizeof(int));
    int AlugadosTotal = 0;
    int ValorTotal = 0;
    int i;

    if(codigos == NULL) return;

    while(scanf("%d", &codigo) == 1){
        if(quantidade == capacidade){
            int *temporario = (int*) realloc(codigos, (capacidade + 1)*sizeof(int));

            if(temporario == NULL){
                free(codigos);
                return;
            }

            codigos = temporario;
            capacidade++;
        }

        codigos[quantidade] = codigo;
        quantidade++;
    }

    AlugarFilmesLocadora(locadora, codigos, quantidade);

    for(i = 0; i< locadora->numFilmes; i++){
        AlugadosTotal += locadora->filme[i]->qtdAlugada;
        if(locadora->filme[i]->qtdAlugada)
            ValorTotal += locadora->filme[i]->valor;
    }

    free(codigos);
    if(AlugadosTotal)
    printf("Total de filmes alugados: %d com custo de R$%d\n", AlugadosTotal, ValorTotal);
}

void LerDevolucaoLocadora(tLocadora* locadora){
    int codigo;
    int quantidade = 0;
    int capacidade = 1;
    int *codigos = (int*) malloc(capacidade * sizeof(int));

    if(codigos == NULL) return;

    while(scanf("%d", &codigo) == 1){
        if(quantidade == capacidade){
            int *temporario = (int*) realloc(
                codigos,
                (capacidade + 1) * sizeof(int)
            );

            if(temporario == NULL){
                free(codigos);
                return;
            }

            codigos = temporario;
            capacidade++;
        }

        codigos[quantidade] = codigo;
        quantidade++;
    }

    DevolverFilmesLocadora(locadora, codigos, quantidade);
    //locadora->lucro += locadora->filme[j]->valor;
    free(codigos);
}

void DevolverFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos){
    int i, j;
    for(i = 0; i < quantidadeCodigos; i++){
        for(j = 0; j < locadora->numFilmes; j++){
            if(EhMesmoCodigoFilme(locadora->filme[j],codigos[i])){
                DevolverFilme(locadora->filme[j]);
                printf("Filme %d - %s Devolvido!\n", codigos[i], locadora->filme[j]->nome);
                locadora->lucro += locadora->filme[j]->valor;
                break;
            }
        }
    }
}