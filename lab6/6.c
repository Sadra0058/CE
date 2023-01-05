#include <stdio.h>
#define LENGTH 3
#define WIDTH 3
void cal_transported_matrix(int matrix1[LENGTH][WIDTH], int matris2[LENGTH][WIDTH]);

int main()
{
    int tmatrix[LENGTH][WIDTH] = {0};
    int matrix[LENGTH][WIDTH];
    for (int i = 0; i < LENGTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            printf("enter element[%i][%i]: ", i + 1, j + 1);
            scanf("%i", &matrix[i][j]);
        }
    }

    cal_transported_matrix(matrix, tmatrix);

    for (int i = 0; i < LENGTH; i++)
    {
        printf("\n");
        for (int j = 0; j < WIDTH; j++)
        {
            printf("%i ", matrix[i][j]);
        }
    }

    printf("\n");

    for (int i = 0; i < LENGTH; i++)
    {
        printf("\n");
        for (int j = 0; j < WIDTH; j++)
        {
            printf("%i ", tmatrix[i][j]);
        }
    }
}


void cal_transported_matrix(int matrix1[LENGTH][WIDTH], int matrix2[LENGTH][WIDTH])
{
    for (int i = 0; i < LENGTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            
            matrix2[j][i] = matrix1[i][j];
        }
    }
}