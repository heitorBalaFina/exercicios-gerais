#include <stdio.h>
#include <string.h>
#include "aluno.h"
#include <stdlib.h>

//typedef struct Aluno tAluno;

#define QTD_MEDIAS 3

struct Aluno
{
    char *nome;
    int matricula;
    int m1, m2, m3;
};

void LeNome(tAluno *aluno);

tAluno* CriaAluno(){
    tAluno *novoAluno = (tAluno*) malloc(sizeof(struct Aluno));
    if(novoAluno == NULL) return NULL;

    novoAluno->nome = NULL;
    novoAluno->matricula = -1;
    novoAluno->m1 = -1;
    novoAluno->m2 = -1;
    novoAluno->m3 = -1;
    
    return novoAluno;
}

void ApagaAluno(tAluno *aluno){
    free(aluno->nome);
    free(aluno);
}

void LeAluno(tAluno *aluno){
    LeNome(aluno);
    scanf("%d", &aluno->matricula);
    scanf("%d %d %d ", &aluno->m1, &aluno->m2, &aluno->m3);
    //scanf("%*[^\n]");   // descarta o resto da linha, se houver
    //scanf("%*c");       // consome o \n
}

void LeNome(tAluno *aluno){
    int i = 0;
    char *nome = (char*) malloc(sizeof(char));
    char *temporario = NULL;
    char letra;
    
    while(scanf("%c", &letra) == 1 && letra != '\n'){
        nome[i] = letra;
        temporario = realloc(nome,(i+2)*sizeof(char));
        
        if(temporario == NULL){
            free(nome);
            return;
        }
        
        nome = temporario;
        i++;
    }
    
    nome[i] = '\0';

    aluno->nome = nome;
}

int ComparaMatricula(tAluno* aluno1, tAluno* aluno2){
    if(aluno1->matricula == aluno2->matricula) return 0;
    if(aluno1->matricula > aluno2->matricula) return 1;
    return -1;
}

int CalculaMediaAluno(tAluno* aluno){
    return (aluno->m1 + aluno->m2 + aluno->m3)/QTD_MEDIAS;
}

int VerificaAprovacao(tAluno* aluno){
    if(CalculaMediaAluno(aluno) >= 7) return 1;
    return 0;
}

void ImprimeAluno(tAluno* aluno){
    printf("%s\n", aluno->nome);
}