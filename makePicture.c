#include <stdlib.h>
#include <stdio.h>
#include "makePicture.h"

// abrir um arquivo
// manipular um arquivo
// abrir uma imagem
// manipular uma imagem

int main(void){
    FILE *photo;
    char namesInFile[20];

    photo = fopen("picture.txt", "w+");

    if(!photo){
        printf("Erro ao abrir o arquivo");
        return EXIT_FAILURE;
    }
    fscanf(photo, "%s", namesInFile);
    printf("%s", namesInFile);

    /*int line, colum;
    int **matrix;

    line = 3;
    colum = 3;

    matrix = makeMatrix(line, colum);
    fillMatrix(matrix, line, colum);
    printMatrix(matrix, line, colum);
    freeMatrix(matrix, line);*/
    fclose(photo);
}

// preencher matriz
void fillMatrix(int **matrix, int line, int colum){
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < colum; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

// fazer uma alocação de matrizes
int **makeMatrix (int line, int colum){
    int **matrix;
    
    matrix = malloc(line * sizeof(int *));
    
    if (matrix == NULL){
        printf("unvalible");
        exit(-1);
    }

    for (int i = 0; i < line; i++)
    {
        matrix[i] = malloc(colum * sizeof(int));
    }
    return matrix;
}

// liberar a matriz
void freeMatrix(int **matrix, int line){
    // liberar
    for (int i = 0; i < line; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

// imprimir a matriz
void printMatrix(int **matrix, int line, int colum){
    for (int i = 0; i < line; i++){
        for (int j = 0; j < colum; j++) printf("%d", matrix[i][j]);
        printf("\n");
    }
}