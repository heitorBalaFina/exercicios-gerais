#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"

void LiberaVetorAlunos(tAluno **vetAlunos, int qtdAlunos);
void OrganizaAlunosOrdemCrescente(tAluno **vetAlunos, int qtdAlunos);
tAluno** IniciaVetor(int qtdAlunos);
void ImprimeTodosAprovados(tAluno **vetAlunos, int qtdAlunos);

int main(){
    int qtdAlunos;
    scanf("%d ", &qtdAlunos);
    tAluno **vetAlunos = IniciaVetor(qtdAlunos);
    
    OrganizaAlunosOrdemCrescente(vetAlunos, qtdAlunos);
    ImprimeTodosAprovados(vetAlunos, qtdAlunos);
    LiberaVetorAlunos(vetAlunos, qtdAlunos);

    return 0;
}

tAluno** IniciaVetor(int qtdAlunos){
    int i;

    tAluno **novoVetor = (tAluno **) malloc(qtdAlunos * sizeof(tAluno *));

    if(novoVetor == NULL && qtdAlunos > 0){
        return NULL;
    }

    for(i = 0; i < qtdAlunos; i++){
        novoVetor[i] = CriaAluno();

        if(novoVetor[i] == NULL){
            LiberaVetorAlunos(novoVetor, i);
            return NULL;
        }

        LeAluno(novoVetor[i]);
    }

    return novoVetor;
}

void LiberaVetorAlunos(tAluno **vetAlunos, int qtdAlunos){
    int i;

    if(vetAlunos == NULL) return;

    for(i = 0; i < qtdAlunos; i++){
        ApagaAluno(vetAlunos[i]);
    }

    free(vetAlunos);
}

void OrganizaAlunosOrdemCrescente(tAluno **vetAlunos, int qtdAlunos){
    tAluno *maiorMat;
    int i, j;
    for(i = 0; i < qtdAlunos; i++){
        for(j = i; j < qtdAlunos; j++){
            if(ComparaMatricula(vetAlunos[i], vetAlunos[j]) == 1){
                maiorMat = vetAlunos[i];
                vetAlunos[i] = vetAlunos[j];
                vetAlunos[j] = maiorMat;
            }
        }
    }
}

void ImprimeTodosAprovados(tAluno **vetAlunos, int qtdAlunos){
    int i;
    for(i = 0; i < qtdAlunos; i++){
        if(VerificaAprovacao(vetAlunos[i])){
            ImprimeAluno(vetAlunos[i]);
        }
    }
}