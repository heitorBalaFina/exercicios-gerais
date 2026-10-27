#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "departamento.h"
#include <math.h>
/*
typedef struct Departamento {
    char *nome;     // nome do departamento
    char *c1, *c2, *c3;    // nomes dos cursos do departamento
    int m1, m2, m3;     // médias de notas dos cursos do departamento
    char *diretor;    // nome do diretor do departamento
    float media_geral;
} tDepartamento;
*/

char* CopiaString(char* origem){
    if(origem == NULL) return NULL;

    char* copia = (char*) malloc((strlen(origem) + 1) * sizeof(char));

    if(copia == NULL) return NULL;

    strcpy(copia, origem);

    return copia;
}

tDepartamento* CriaDepartamento(){
    tDepartamento *novoDep  =  (tDepartamento*) malloc(sizeof(tDepartamento));
    
    if(novoDep == NULL) return NULL;

    novoDep->nome = NULL;
    novoDep->c1 = NULL;
    novoDep->c2 = NULL;
    novoDep->c3 = NULL;
    novoDep->m1 = -1;
    novoDep->m2 = -1;
    novoDep->m3 = -1;
    novoDep->diretor = NULL;
    novoDep->media_geral = -1;
    return novoDep;
}

void PreencheDadosDepartamento(tDepartamento* depto, char* c1, char* c2, char* c3, char* nome, int m1, int m2, int m3, char* diretor){
    depto->m1 = m1;
    depto->m2 = m2;
    depto->m3 = m3;
    
    depto->c1 = CopiaString(c1);
    depto->c2 = CopiaString(c2);
    depto->c3 = CopiaString(c3);
    depto->nome = CopiaString(nome);
    depto->diretor = CopiaString(diretor);
}

/*

*/
void LiberaMemoriaDepartamento(tDepartamento* depto){
    if(depto == NULL) return;
    free(depto->nome);
    free(depto->c1);
    free(depto->c2);
    free(depto->c3);
    free(depto->diretor);
    free(depto);
}

void LiberaStringsDepartamento(tDepartamento* depto){
    if(depto == NULL) return;

    free(depto->nome);
    free(depto->c1);
    free(depto->c2);
    free(depto->c3);
    free(depto->diretor);
}


void ImprimeAtributosDepartamento (tDepartamento* depto){
    printf("ATRIBUTOS:\n");
    printf("departamento => %s\n", depto->nome);
    printf("diretor => %s\n", depto->diretor);
    printf("curso1 => %s, media1 => %d\n", depto->c1, depto->m1);
    printf("curso2 => %s, media2 => %d\n", depto->c2, depto->m2);
    printf("curso3 => %s, media3 => %d\n", depto->c3, depto->m3);
    printf("media geral => %.2f\n", CalculaMediaGeralDepartamento(depto));
    printf("desvio padrao => %.2f\n", CalculaDesvioPadraoDepartamento(depto));
    printf("\n");
}

int ValidaMediaDepartamento (int media){
    if(media >= 0 && media <= 10) return 1;
    return 0;
}

double CalculaDesvioPadraoDepartamento(tDepartamento* depto){
    double media = CalculaMediaGeralDepartamento(depto);
    double desvio = -1;
    if(ValidaMediaDepartamento(media)){
        desvio = sqrt((pow(depto->m1-media,2) + pow(depto->m2-media,2) + pow(depto->m3-media,2))/ 3.00);
    }
    return desvio;
}

double CalculaMediaGeralDepartamento(tDepartamento* depto){
    return (depto->m1 + depto->m2 + depto->m3)/3.00;
}

void OrdenaPorMediaDepartamentos(tDepartamento* d[], int tamanho){
    tDepartamento *menor;
    int i, j;
    double mi, mj;
    for(i = 0; i < tamanho; i++){
        for(j = i+1; j < tamanho; j++){
            mi = CalculaMediaGeralDepartamento(d[i]);
            mj = CalculaMediaGeralDepartamento(d[j]);
            if(mi < mj){
                menor = d[i];
                d[i] = d[j];
                d[j] = menor;
            }
        }
    }
}