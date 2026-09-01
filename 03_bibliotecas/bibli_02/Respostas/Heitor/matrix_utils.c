#include "matrix_utils.h"

void matrix_read(int rows, int cols, int matrix[rows][cols]){
    int r, c, num;
    for(r = 0; r < rows; r++){
        for(c = 0; c < cols; c++){ 
            scanf("%d", &num);
            matrix[r][c] = num;
        }
    }
}

void matrix_print(int rows, int cols, int matrix[rows][cols]){
    int r, c;
    for(r = 0; r < rows; r++){
        printf("|");
        for(c = 0; c < cols; c++){ 
            printf("%d", matrix[r][c]);
            if(c != cols-1){
                printf(" ");
            }
        }
        printf("|\n");
    }
    printf("\n");
}

int possible_matrix_sum(int rows1, int cols1, int rows2, int cols2){
    if(rows1 == rows2 && cols1 == cols2){
        return 1;
    }
    return 0;
}

int possible_matrix_sub(int rows1, int cols1, int rows2, int cols2){
    if(rows1 == rows2 && cols1 == cols2){
        return 1;
    }
    return 0;
}

int possible_matrix_multiply(int cols1, int rows2){
    if(cols1 == rows2){
        return 1;
    }
    return 0;
}

void matrix_add(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]){
    int r, c;
    for(r = 0; r < rows1; r++){
        for(c = 0; c < cols1; c++){
            result[r][c] = matrix1[r][c] + matrix2[r][c];
        }
    }
}

void matrix_sub(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]){
    int r, c;
    for(r = 0; r < rows1; r++){
        for(c = 0; c < cols1; c++){
            result[r][c] = matrix1[r][c] - matrix2[r][c];
        }
    }
}
