#include <stdio.h>
#include "tDepartamento.h"
#include <string.h>

/*
#define STRING_MAX 50

typedef struct departamento {
    char curso1[STRING_MAX];
    char curso2[STRING_MAX];
    char curso3[STRING_MAX];
    char diretor[STRING_MAX];
    char nome[STRING_MAX];
    int m1, m2, m3;
} tDepartamento;
*/

tDepartamento LerDepartamento();

int main(){
    int tam, i;
    scanf("%d", &tam);
    tDepartamento vetor[tam];
    for(i = 0; i < tam; i++) vetor[i] = LerDepartamento();
    OrdenaDepartamentosPorMedia(vetor, tam);
    for(i = 0; i < tam; i++) ImprimeAtributosDepartamento(vetor[i]);

    return 0;
}

tDepartamento LerDepartamento(){
    char curso1[STRING_MAX];
    char curso2[STRING_MAX];
    char curso3[STRING_MAX];
    char diretor[STRING_MAX];
    char nome[STRING_MAX];
    int m1 = -1, m2 = -1, m3 = -1;
    while (m1 < 0 || m2 < 0 || m3 < 0){
        scanf(" %49[^\n]", nome);
        scanf(" %49[^\n]", diretor);
        scanf(" %49[^\n]", curso1);
        scanf(" %49[^\n]", curso2);
        scanf(" %49[^\n]", curso3);
        scanf(" %d %d %d", &m1, &m2, &m3);
        if(m1 < 0 || m2 < 0 || m3 < 0) printf("\nDigite um departamento com médias válidas");
    }
    
    return CriaDepartamento(curso1, curso2, curso3, nome, m1, m2, m3, diretor);
}