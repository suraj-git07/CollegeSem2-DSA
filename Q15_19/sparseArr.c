#include <stdio.h>
#include <stdlib.h>

int findNZero(int **array, int rows, int columns)
{
    int ans = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (array[i][j] != 0)
            {
                ans++;
            }
        }
    }
    return ans;
}

void sparse(int sparseArr[][3], int **arr, int rows, int columns)
{
    int k = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (arr[i][j] != 0)
            {
                sparseArr[k][0] = i;
                sparseArr[k][1] = j;
                sparseArr[k][2] = arr[i][j];
                k++;
            }
        }
    }
}

int main()
{
    int rows, columns;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    int **array = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        array[i] = malloc(columns * sizeof(int));
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("Enter element (%d,%d): ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    // print the normal matrix

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    // create a sparse  matrix from the original matrix
    int non_zero = findNZero(array, rows, columns);
    int sparseArr[non_zero + 1][3];
    sparseArr[0][0] = rows;
    sparseArr[0][1] = columns;
    sparseArr[0][2] = non_zero;

    sparse(sparseArr, array, rows, columns);
    printf("\n");

    for (int i = 0; i < non_zero + 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", sparseArr[i][j]);
        }
        printf("\n");
    }

    return 0;
}