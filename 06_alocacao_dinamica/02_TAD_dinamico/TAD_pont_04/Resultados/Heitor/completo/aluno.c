#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"

#define QTD_NOTAS 3

//typedef struct Aluno {
//    char* nome; /**< Ponteiro para nome do aluno, que será alocado dinamicamente*/
//   int matricula; /**< Matrícula do aluno */
//    int n1, n2, n3; /**< Notas das avaliações */
//} tAluno;

tAluno* CriaAluno(){
    tAluno *novoAluno = (tAluno *) malloc(sizeof(tAluno));
    if(novoAluno == NULL){
        return NULL;
    }
    
    novoAluno->nome = NULL;
    novoAluno->matricula = -1;
    novoAluno->n1 = -1;
    novoAluno->n2 = -1;
    novoAluno->n3 = -1;

    return novoAluno;
}

void ApagaAluno(tAluno *aluno){
    if (aluno == NULL) return;
    free(aluno->nome);
    free(aluno);
}

void LeAluno(tAluno *aluno){
    //inicializando o nome com uma posicao para poder fazer realloc em seguida
    aluno->nome = (char *) malloc(sizeof(char));
    if(aluno->nome == NULL) return;
    
    int posicao = 0;
    char letra;
    // Le o nome e para cada letra nova aumentando o espaco do vetor com realloc (maneira pouco otimizada)
    while(scanf("%c", &letra) == 1 && letra != '\n'){
        char *temporario = realloc(aluno->nome,(posicao+2)*sizeof(char));
        aluno->nome = temporario;
        aluno->nome[posicao] = letra;
        posicao++;
    }

    //'\0' no final para tratar como string
    aluno->nome[posicao] = '\0';
    scanf("%d ", &aluno->matricula);
    scanf(" %d %d %d ", &aluno->n1, &aluno->n2, &aluno->n3);
}

int ComparaMatricula(tAluno* aluno1, tAluno* aluno2){
    if(aluno1->matricula > aluno2->matricula) {
        return 1;
    } else if(aluno1->matricula < aluno2->matricula){
        return -1;
    }
    return 0;
}

int CalculaMediaAluno(tAluno* aluno){
    return (aluno->n1 + aluno->n2 + aluno->n3)/QTD_NOTAS;
}

int VerificaAprovacao(tAluno* aluno){
    if(CalculaMediaAluno(aluno) < 7) return 0;
    return 1;
}

void ImprimeAluno(tAluno* aluno){
    printf("%s\n", aluno->nome);
}