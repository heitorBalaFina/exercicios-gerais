#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "departamento.h"
#include <math.h>



tDepartamento* LerDepartamento();

int main(){
    int tam, i;
    scanf("%d", &tam);
    tDepartamento **vetor = (tDepartamento**) malloc(tam * sizeof(tDepartamento*));
    for(i = 0; i < tam; i++){
        vetor[i] = LerDepartamento();
    }
    OrdenaPorMediaDepartamentos(vetor, tam);
    for(i = 0; i < tam; i++){
        ImprimeAtributosDepartamento(vetor[i]);
        LiberaMemoriaDepartamento(vetor[i]);
    }
    free(vetor);

    return 0;
}

/*
typedef struct Departamento {
    char *nome;     // nome do departamento
    char *c1, *c2, *c3;    // nomes dos cursos do departamento
    int m1, m2, m3;     // médias de notas dos cursos do departamento
    char *diretor;    // nome do diretor do departamento
    float media_geral;
} tDepartamento;
*/

/*
CT
Luiz
EngComputacao
EngProducao
EngEletrica
9 7 6
*/

tDepartamento* LerDepartamento(){
    char c1[STRING_MAX];
    char c2[STRING_MAX];
    char c3[STRING_MAX];
    char nome[STRING_MAX];
    char diretor[STRING_MAX];    
    int m1,m2,m3;
    float media;
    scanf(" %100[^\n]", nome);
    scanf(" %100[^\n]", diretor);
    scanf(" %100[^\n]", c1);
    scanf(" %100[^\n]", c2);
    scanf(" %100[^\n]", c3);
    scanf("%d %d %d", &m1, &m2, &m3);
    tDepartamento *depto = CriaDepartamento();
    PreencheDadosDepartamento(depto, c1, c2, c3, nome, m1, m2, m3, diretor);
    return depto;
}