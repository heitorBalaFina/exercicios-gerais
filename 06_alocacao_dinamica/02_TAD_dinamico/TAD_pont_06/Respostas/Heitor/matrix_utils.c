#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "matrix_utils.h"

tMatrix* MatrixCreate(int rows, int cols){
    if(rows <= 0 || cols <= 0) return NULL;

    // Tenta alocar a matriz e se nao funcionar retorna NULL
    tMatrix *novaMatriz = (tMatrix*) malloc(sizeof(tMatrix));
    if(novaMatriz == NULL) return NULL;

    // Aloca espacao do tMatrix
    novaMatriz->rows = rows;
    novaMatriz->cols = cols;
    novaMatriz->data = (int**) malloc(rows * sizeof(int*));

    if(novaMatriz->data == NULL){
        free(novaMatriz);
        return NULL;
    }

    
    int i;
    for(i = 0; i < rows; i++){
        novaMatriz->data[i] = (int*) malloc(cols * sizeof(int));

        if(novaMatriz->data[i] == NULL){
            int j;

            for(j = 0; j < i; j++){
                free(novaMatriz->data[j]);
            }

            free(novaMatriz->data);
            free(novaMatriz);

            return NULL;
        }
    }

    return novaMatriz;
}

void MatrixFree(tMatrix* matrix){
    if(matrix == NULL) return;

    if(matrix->data != NULL){
        int i;

        for(i = 0; i < matrix->rows; i++){
            free(matrix->data[i]);
        }

        free(matrix->data);
    }

    free(matrix);
}

void MatrixRead(tMatrix* matrix){
    if(matrix == NULL || matrix->data == NULL) return;

    int i, j;

    for(i = 0; i < matrix->rows; i++){
        for(j = 0; j < matrix->cols; j++){
            if(scanf("%d", &matrix->data[i][j]) != 1){
                return;
            }
        }
    }
}

void MatrixPrint(tMatrix* matrix){
    if(matrix == NULL || matrix->data == NULL) return;

    int i, j;

    for(i = 0; i < matrix->rows; i++){
        for(j = 0; j < matrix->cols; j++){
            if(j == 0){
                printf("|%d", matrix->data[i][j]);
            } else {
                printf(" %d", matrix->data[i][j]);
            }
        }

        printf("|\n");
    }

    printf("\n");
}

int PossibleMatrixSum(tMatrix* matrix1, tMatrix* matrix2){
    if(matrix1 == NULL || matrix2 == NULL) return 0;

    return matrix1->rows == matrix2->rows &&
           matrix1->cols == matrix2->cols;
}

int PossibleMatrixSub(tMatrix* matrix1, tMatrix* matrix2){
    return PossibleMatrixSum(matrix1, matrix2);
}

int PossibleMatrixMultiply(tMatrix* matrix1, tMatrix* matrix2){
    if(matrix1 == NULL || matrix2 == NULL) return 0;

    return matrix1->cols == matrix2->rows;
}

tMatrix* MatrixAdd(tMatrix* matrix1, tMatrix* matrix2){
    if(!PossibleMatrixSum(matrix1, matrix2)) return NULL;

    tMatrix* soma = MatrixCreate(matrix1->rows, matrix1->cols);
    if(soma == NULL) return NULL;

    int i, j;

    for(i = 0; i < matrix1->rows; i++){
        for(j = 0; j < matrix1->cols; j++){
            soma->data[i][j] =
                matrix1->data[i][j] + matrix2->data[i][j];
        }
    }

    return soma;
}

tMatrix* MatrixSub(tMatrix* matrix1, tMatrix* matrix2){
    if(!PossibleMatrixSub(matrix1, matrix2)) return NULL;

    tMatrix* sub = MatrixCreate(matrix1->rows, matrix1->cols);
    if(sub == NULL) return NULL;

    int i, j;

    for(i = 0; i < matrix1->rows; i++){
        for(j = 0; j < matrix1->cols; j++){
            sub->data[i][j] =
                matrix1->data[i][j] - matrix2->data[i][j];
        }
    }

    return sub;
}
/*
tMatrix* MatrixMultiplyByScalar(tMatrix* matrix, int scalar){
    if(matrix == NULL || matrix->data == NULL) return NULL;

    int i, j;
    for(i = 0; i < matrix->rows; i++){
        for(j = 0; j < matrix->cols; j++){
            matrix->data[i][j] *= scalar; // Modifica o valor permanentemente na matriz original
        }
    }

    return matrix; // Retorna a própria matriz modificada
}
*/


tMatrix* MatrixMultiplyByScalar(tMatrix* matrix, int scalar){
    if(matrix == NULL || matrix->data == NULL) return NULL;

    tMatrix* resultado = MatrixCreate(matrix->rows, matrix->cols);
    if(resultado == NULL) return NULL;

    int i, j;
    for(i = 0; i < matrix->rows; i++){
        for(j = 0; j < matrix->cols; j++){
            resultado->data[i][j] = matrix->data[i][j] * scalar;
        }
    }

    return resultado;
}



tMatrix* TransposeMatrix(tMatrix* matrix){
    if(matrix == NULL || matrix->data == NULL) return NULL;

    tMatrix *trans = MatrixCreate(matrix->cols, matrix->rows);
    if(trans == NULL) return NULL;

    int i, j;

    for(i = 0; i < matrix->rows; i++){
        for(j = 0; j < matrix->cols; j++){
            trans->data[j][i] = matrix->data[i][j];
        }
    }

    return trans;
}

tMatrix* MatrixMultiply(tMatrix* matrix1, tMatrix* matrix2){
    if(!PossibleMatrixMultiply(matrix1, matrix2)) return NULL;

    tMatrix* resultado = MatrixCreate(matrix1->rows, matrix2->cols);
    if(resultado == NULL) return NULL;

    int i, j, k;

    // Inicializa a matriz de resultado com zero
    for(i = 0; i < matrix1->rows; i++){
        for(j = 0; j < matrix2->cols; j++){
            resultado->data[i][j] = 0;
        }
    }

    // Loop otimizado (IKJ) para máxima localidade de cache
    for(i = 0; i < matrix1->rows; i++){
        for(k = 0; k < matrix1->cols; k++){
            int r_ik = matrix1->data[i][k]; // Evita múltiplos acessos repetidos
            for(j = 0; j < matrix2->cols; j++){
                resultado->data[i][j] += r_ik * matrix2->data[k][j];
            }
        }
    }

    return resultado;
}