#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "matrix_utils.h"

int main(){
    
    int linha, coluna;
    
    scanf("%d %d", &linha, &coluna);
    tMatrix *matrix1 = MatrixCreate(linha, coluna);
    MatrixRead(matrix1);
    
    scanf("%d %d", &linha, &coluna);
    tMatrix *matrix2 = MatrixCreate(linha, coluna);
    MatrixRead(matrix2);

    int opcao = 0, escalar, escolha;
    while(scanf("%d", &opcao) == 1 && opcao != 6){
        
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");

        printf("Opcao escolhida: \n");

        switch (opcao){
        case 1:
            if(PossibleMatrixSum(matrix1, matrix2)){
                tMatrix *resultado = MatrixAdd(matrix1, matrix2);
                MatrixPrint(resultado);
                MatrixFree(resultado);
            } else {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
            break;
        case 2:
            if(PossibleMatrixSub(matrix1, matrix2)){
                tMatrix *resultado = MatrixSub(matrix1, matrix2);
                MatrixPrint(resultado);
                MatrixFree(resultado);
            } else {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
            break;
        case 3:
            if(PossibleMatrixMultiply(matrix1, matrix2)){
                tMatrix *resultado = MatrixMultiply(matrix1, matrix2);
                MatrixPrint(resultado);
                MatrixFree(resultado);
            } else {
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
            }
            break;
        case 4:
            scanf("%d %d", &escalar, &escolha);

            if(escolha == 1){
                tMatrix *resultado = MatrixMultiplyByScalar(matrix1, escalar);

                if(resultado != NULL){
                    MatrixFree(matrix1);
                    matrix1 = resultado;
                    MatrixPrint(matrix1);
                }

            } else if(escolha == 2){
                tMatrix *resultado = MatrixMultiplyByScalar(matrix2, escalar);

                if(resultado != NULL){
                    MatrixFree(matrix2);
                    matrix2 = resultado;
                    MatrixPrint(matrix2);
                }
            }
            break;
        case 5:
            //scanf("%d", &escolha);
                tMatrix *resultado1 = TransposeMatrix(matrix1);
                tMatrix *resultado2 = TransposeMatrix(matrix2);
                MatrixPrint(resultado1);
                MatrixPrint(resultado2);
                MatrixFree(resultado1);
                MatrixFree(resultado2);
            break;
        }
    }
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");

        printf("Opcao escolhida: \n");

    MatrixFree(matrix1);
    MatrixFree(matrix2);

    return 0;
}