#include <stdio.h>
#include <string.h>
#include "aluno.h"
#include <stdlib.h>

void OrdenaVetor(tAluno **vetor, int tam);
void ApagaVetor(tAluno **vetor, int tam);
void ImprimeAprovados(tAluno **vetor, int tam);
void PreencheVetor(tAluno **vetor, int tam);

int main(){
    
    int tam;
    scanf("%d\n", &tam);
    //scanf("%*c");

    tAluno **vetor = (tAluno**) malloc(tam*sizeof(struct Aluno*));
    if(vetor == NULL) exit(0);

    PreencheVetor(vetor, tam);
    ImprimeAprovados(vetor, tam);
    ApagaVetor(vetor, tam);

    return 0;
}

void OrdenaVetor(tAluno **vetor, int tam){
    tAluno *maior = NULL;
    int i, j;

    for(i = 0; i < tam-1; i++){
        for(j = i+1; j < tam; j++){
            if(ComparaMatricula(vetor[i], vetor[j]) > 0){
                maior = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = maior;
            }
        }
    }
}

void ApagaVetor(tAluno **vetor, int tam){
    if(vetor == NULL) return;
    
    int i;
    for(i = 0; i< tam; i++) ApagaAluno(vetor[i]);
    free(vetor);
}

void ImprimeAprovados(tAluno **vetor, int tam){
    if(vetor == NULL) return;

    int i;
    OrdenaVetor(vetor, tam);
    for(i = 0; i< tam; i++) {
        if(VerificaAprovacao(vetor[i])) {
            ImprimeAluno(vetor[i]);
        }
    }
}

void PreencheVetor(tAluno **vetor, int tam){
    int i;
    for(i = 0; i < tam;i++){
        vetor[i] = CriaAluno();
        if(vetor[i] != NULL) LeAluno(vetor[i]);
    }
}