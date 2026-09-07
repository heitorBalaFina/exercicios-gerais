#include <stdio.h>
#include "aluno.h"

int main(){
    int qtdAlunos, i, j;
    scanf("%d", &qtdAlunos);
    tAluno vetAlunos[qtdAlunos];
    tAluno maiorMatricula;
    
    // Leitura de todos os alunos
    for(i = 0; i < qtdAlunos; i++){
        vetAlunos[i] = LeAluno();
    }

    //Deixa o vetor em ordem crescente de numero matricula
    for(i = 0; i < qtdAlunos-1; i++){
        for(j = i+1; j <qtdAlunos; j++){
            if(ComparaMatricula(vetAlunos[i],vetAlunos[j]) == 1){
                maiorMatricula = vetAlunos[i];
                vetAlunos[i] = vetAlunos[j];
                vetAlunos[j] = maiorMatricula;
            }
        }
    }

    for(i = 0; i < qtdAlunos; i++){
        if(VerificaAprovacao(vetAlunos[i])){
            ImprimeAluno(vetAlunos[i]);
        }
    }

    return 0;
}