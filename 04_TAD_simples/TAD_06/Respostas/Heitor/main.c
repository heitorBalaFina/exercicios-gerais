#include <stdio.h>
#include "matrix_utils.h"

int main(){
    int linhas, colunas;
    scanf("%d %d", &linhas, &colunas);
    tMatrix matrix1 = MatrixCreate(linhas, colunas);
    matrix1 = MatrixRead(matrix1);

    scanf("%d %d", &linhas, &colunas);
    tMatrix matrix2 = MatrixCreate(linhas, colunas);
    matrix2 = MatrixRead(matrix2);

    int escolha, escalar, opcao;
    do{
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida: \n");
        escolha = 0, escalar = 0, opcao = 0;
        scanf("%d", &escolha);
        
        switch (escolha){
        case 1:
           if(PossibleMatrixSum(matrix1, matrix2)){
                MatrixPrint(MatrixAdd(matrix1, matrix2));
            }
            break;
        case 2:
            if(PossibleMatrixSub(matrix1, matrix2)){
                MatrixPrint(MatrixSub(matrix1, matrix2));
            }
            break;
        case 3:
            if(PossibleMatrixMultiply(matrix1, matrix2)){
                MatrixPrint(MatrixMultiply(matrix1, matrix2));
            }
            break;
        case 4:
            scanf("%d %d", &escalar, &opcao);
            if(opcao == 1){
                matrix1 = MatrixMultiplyByScalar(matrix1, escalar);
                MatrixPrint(matrix1);
            } else if(opcao == 2){
                matrix2 = MatrixMultiplyByScalar(matrix2, escalar);
                MatrixPrint(matrix2);
            }
            break;
        case 5:
            scanf("%d", &opcao);
            if(opcao == 1){
                MatrixPrint(TransposeMatrix(matrix1));
                MatrixPrint(matrix2);
            } else if(opcao == 2){
                MatrixPrint(matrix1);
                MatrixPrint(TransposeMatrix(matrix2));
            }
            break;
        }
    } while (escolha != 6);
    
    return 0;
}