#include "tDepartamento.h"
#include <stdio.h>
#include <string.h>

#define QTD_MEDIAS 3

float media(tDepartamento depto);

tDepartamento CriaDepartamento( char *curso1, char *curso2, char *curso3, char *nome, int m1, int m2, int m3, char *diretor ){
    tDepartamento departamento;
    strcpy(departamento.curso1, curso1);
    strcpy(departamento.curso2, curso2);
    strcpy(departamento.curso3, curso3);
    strcpy(departamento.nome, nome);
    departamento.m1 = m1;
    departamento.m2 = m2;
    departamento.m3 = m3;
    strcpy(departamento.diretor, diretor);
    return departamento;
}
/*
typedef struct departamento {
    char curso1[STRING_MAX];
    char curso2[STRING_MAX];
    char curso3[STRING_MAX];
    char diretor[STRING_MAX];
    char nome[STRING_MAX];
    int m1, m2, m3;
} tDepartamento;
 */

void ImprimeAtributosDepartamento(tDepartamento depto){
    printf("\nDepartamento: %s\n", depto.nome);
    printf("    Diretor: %s\n", depto.diretor);
    printf("    1o curso: %s\n", depto.curso1);
    printf("    Media do 1o curso: %d\n", depto.m1);
    printf("    2o curso: %s\n", depto.curso2);
    printf("    Media do 2o curso: %d\n", depto.m2);
    printf("    3o curso: %s\n", depto.curso3);
    printf("    Media do 3o curso: %d\n", depto.m3);
    printf("    Media dos cursos: %.2f\n", media(depto));
}
/*
    Diretor: Patricia
	1o curso: CC
	Media do 1o curso: 10
	2o curso: EC
	Media do 2o curso: 7
	3o curso: SI
    Media do 3o curso: 5
	Media dos cursos: 7.33
*/

void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos){
    int i, j;
    tDepartamento maior;
    
    for(i = 0; i < num_deptos; i++){
        for(j = 0; j < num_deptos; j++){
            if(media(vetor_deptos[i]) > media(vetor_deptos[j])){
                maior = vetor_deptos[i];
                vetor_deptos[i] = vetor_deptos[j];
                vetor_deptos[j] = maior;
            }
        }
    }
}

float media(tDepartamento depto){
    return (depto.m1 + depto.m2 + depto.m3)/3.0;
}