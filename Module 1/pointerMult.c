#include <stdio.h>
#include <stdlib.h>

void readMatrix(int** mat, int n){
    for(int i = 0; i < n; i++){
        *(mat+i) = (int*)malloc(sizeof(int)*n);
        for(int j = 0; j < n; j++){
            printf("Enter element (%d,%d): ", i, j);
            scanf("%d", (*(mat+i)+j));
        }
    }
}

void printMatrix(int** mat, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", *(*(mat + i) + j));
        }
        printf("\n");
    }
}

int** multiplyMatrices(int** mat1, int** mat2, int n) {
    int **result = (int**)malloc(sizeof(int*)*n);
    for (int i = 0; i < n; ++i) {
        *(result+i) = (int*)malloc(sizeof(int)*n);
        for (int j = 0; j < n; ++j) {
            *(*(result + i) + j) = 0;
            for (int k = 0; k < n; ++k) {
                *(*(result + i) + j) += *(*(mat1 + i) + k) * *(*(mat2 + k) + j);
            }
        }
    }
    return result;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int **mat1 = (int**)malloc(sizeof(int*)*n);
    printf("Enter elements for matrix 1:\n");
    readMatrix(mat1, n);
    printMatrix(mat1, n);
    int **mat2 = (int**)malloc(sizeof(int*)*n);
    printf("Enter elements for matrix 2:\n");
    readMatrix(mat2, n);
    printMatrix(mat2, n);
    
    
    int **result = (int**)malloc(sizeof(int*)*n);
    result = multiplyMatrices(mat1, mat2, n);
    printf("Product of both matrices:\n");
    printMatrix(result, n);

    free(mat1);
    free(mat2);
    free(result);
    return 0;
}
