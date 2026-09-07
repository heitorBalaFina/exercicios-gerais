#include <stdio.h>
#include "matrix_utils.h"

tMatrix MatrixCreate(int rows, int cols){
    tMatrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    return matrix;
}

tMatrix MatrixRead(tMatrix matrix){
    int linha, coluna;
    for(linha = 0; linha < matrix.rows; linha++){
        for(coluna = 0; coluna < matrix.cols; coluna++){
            scanf("%d", &matrix.data[linha][coluna]);
        }
    }
    return matrix;
}

void MatrixPrint(tMatrix matrix){
    int linha, coluna;
    for(linha = 0; linha < matrix.rows; linha++){
        
        for(coluna = 0; coluna < matrix.cols; coluna++){
            if(coluna == 0) printf("|");
            if(coluna == matrix.cols -1){
                printf("%d|\n", matrix.data[linha][coluna]);
            } else {
                printf("%d ", matrix.data[linha][coluna]);
            }
        }
    }
    printf("\n");
}

int PossibleMatrixSum(tMatrix matrix1, tMatrix matrix2){
    if(matrix1.cols == matrix2.cols && matrix1.rows == matrix2.rows){
        return 1;
    }
    return 0;
}

int PossibleMatrixSub(tMatrix matrix1, tMatrix matrix2){
    return PossibleMatrixSum(matrix1, matrix2);
}

int PossibleMatrixMultiply(tMatrix matrix1, tMatrix matrix2){
    if(matrix1.cols == matrix2.rows){
        return 1;
    }
    return 0;
}

tMatrix MatrixAdd(tMatrix matrix1, tMatrix matrix2){
    tMatrix soma = MatrixCreate(matrix1.rows, matrix1.cols);
    int linha, coluna;
    for(linha = 0; linha < matrix1.rows; linha++){
        for(coluna = 0; coluna < matrix1.cols; coluna++){
            soma.data[linha][coluna] = matrix1.data[linha][coluna] + matrix2.data[linha][coluna];
        }
    }
    return soma;
}

tMatrix MatrixSub(tMatrix matrix1, tMatrix matrix2){
    tMatrix sub = MatrixCreate(matrix1.rows, matrix1.cols);
    int linha, coluna;
    for(linha = 0; linha < matrix1.rows; linha++){
        for(coluna = 0; coluna < matrix1.cols; coluna++){
            sub.data[linha][coluna] = matrix1.data[linha][coluna] - matrix2.data[linha][coluna];
        }
    }
    return sub;
}

tMatrix MatrixMultiply(tMatrix matrix1, tMatrix matrix2){
    tMatrix mult = MatrixCreate(matrix1.rows, matrix2.cols);
    int linha, coluna, x;
    for(linha = 0; linha < matrix1.rows; linha++){
        for(coluna = 0; coluna < matrix2.cols; coluna++){
            mult.data[linha][coluna] = 0;
            for(x = 0; x < matrix1.cols; x++){

                mult.data[linha][coluna] += matrix1.data[linha][x] * matrix2.data[x][coluna];
            }
        }
    }
    return mult;
}

tMatrix TransposeMatrix(tMatrix matrix){
    tMatrix transpose = MatrixCreate(matrix.cols, matrix.rows);
    int linha, coluna;
    for(linha = 0; linha < matrix.rows; linha++){
        for(coluna = 0; coluna < matrix.cols; coluna++){
            transpose.data[coluna][linha] = matrix.data[linha][coluna];
        }
    }
    return transpose;
}

tMatrix MatrixMultiplyByScalar(tMatrix matrix, int scalar){
    tMatrix escalar = MatrixCreate(matrix.rows, matrix.cols);
    int linha, coluna;
    for(linha = 0; linha < matrix.rows; linha++){
        for(coluna = 0; coluna < matrix.cols; coluna++){
            escalar.data[linha][coluna] = matrix.data[linha][coluna] * scalar;
        }
    }
    return escalar;
}