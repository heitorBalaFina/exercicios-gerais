#include <stdio.h>
#include "matrix_utils.h"

int main(){
    int rows1, cols1, rows2, cols2;
    int opcao;

    scanf("%d %d", &rows1, &cols1);
    int matrix1[rows1][cols1];
    matrix_read(rows1, cols1, matrix1);
    
    scanf("%d %d", &rows2, &cols2);
    int matrix2[rows2][cols2];
    matrix_read(rows1, cols1, matrix2);

    scanf("%d", &opcao);
    while (opcao != 6){
    printf("1 - Somar matrizes\n");
    printf("2 - Subtrair matrizes\n");
    printf("3 - Multiplicar matrizes\n");
    printf("4 - Multiplicacao de uma matriz por escalar\n");
    printf("5 - Transposta de uma matriz\n");
    printf("6 - Encerrar o programa\n");
    switch (opcao){
    case 1:
        // Somar matrizes
        printf("Opcao escolhida: \n");
        if(possible_matrix_sum(rows1, cols1, rows2, cols2)){
            int soma[rows1][cols1];
            matrix_add(rows1, cols1, matrix1, rows2, cols2, matrix2, soma);
            matrix_print(rows1, cols1, soma);
        }
        break;
    case 2:
        // Subtrair matrizes
        printf("Opcao escolhida: \n");
        if(possible_matrix_sub(rows1, cols1, rows2, cols2)){
            int subtracao[rows1][cols1];
            matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2, subtracao);
            matrix_print(rows1, cols1, subtracao);
        }
        
        break;
    case 3:
        // Multiplicar matrizes
        printf("Opcao escolhida: \n");
        break;
    case 4:
        // Multiplicacao de uma matriz por escalar
        printf("Opcao escolhida: \n");
        break;
    case 5:
        // Transposta de uma matriz
        printf("Opcao escolhida: \n");
        break;
    case 6:
        // fim do programa ne amigao
        printf("Opcao escolhida: \n");
        break;
    default:
        break;
    }
    scanf("%d", &opcao);
    }
    


    return 0;
}