#include "aluno.h"
#include <stdio.h>
#include <string.h>

#define NUM_NOTAS 3

tAluno CriaAluno(char *nome, int matricula, int n1, int n2, int n3){
    tAluno novoAluno;
    strcpy(novoAluno.nome, nome);
    novoAluno.matricula = matricula;
    novoAluno.n1 = n1;
    novoAluno.n2 = n2;
    novoAluno.n3 = n3;
    return novoAluno;
}

tAluno LeAluno(){
    tAluno a;
    scanf(" %49[^\n]", a.nome);
    scanf(" %d", &a.matricula);
    scanf("%d %d %d", &a.n1, &a.n2, &a.n3);
    return a;
}

int ComparaMatricula(tAluno aluno1, tAluno aluno2){
    if(aluno1.matricula > aluno2.matricula){
        return 1;
    } else if(aluno1.matricula < aluno2.matricula){
        return -1;
    }
    return 0;
}

int CalculaMediaAluno(tAluno aluno){
    return (aluno.n1 + aluno.n2 + aluno.n3)/NUM_NOTAS;
}

int VerificaAprovacao(tAluno aluno){
    int media = CalculaMediaAluno(aluno);
    if(media >= 7){
        return 1;
    }
    return 0;
}

void ImprimeAluno(tAluno aluno){
    printf("%s\n", aluno.nome);
}