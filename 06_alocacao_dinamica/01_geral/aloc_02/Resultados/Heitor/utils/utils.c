#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int **CriaMatriz(int linhas, int colunas){
    int **mat = (int **) malloc(linhas * sizeof(int *));
    if (mat == NULL) exit(0);
    
    int i;
    for (i = 0; i < linhas; i++) {
        mat[i] = (int *)malloc(colunas * sizeof(int));
        if (mat[i] == NULL) exit(0);
    }
    return mat;
}

void LeMatriz(int **matriz, int linhas, int colunas){
    int l, c;
    for(l = 0; l < linhas; l++){
        for(c = 0; c < colunas; c++){
            scanf("%d", &matriz[l][c]);
        }
    }
}

void ImprimeMatrizTransposta(int **matriz, int linhas, int colunas){
    int l, c;
    for(c = 0; c < colunas; c++){
        for(l = 0; l < linhas; l++){
            printf("%d ", matriz[l][c]);
        }
        printf("\n");
    }
}
/*
void ImprimeMatrizTransposta(int **matriz, int linhas, int colunas){
    int l, c;
    // CORRIGIDO: Transposta inverte a ordem de exibição (c vai até colunas, l até linhas)
    for(c = 0; c < colunas; c++){
        for(l = 0; l < linhas; l++){
            printf("%d ", matriz[l][c]);
        }
        printf("\n");
    }
}
*/


void LiberaMatriz(int **matriz, int linhas){
    int i;
    for (i = 0; i < linhas; i++) {
        free(matriz[i]); // libera cada linha
    }
    free(matriz);
}