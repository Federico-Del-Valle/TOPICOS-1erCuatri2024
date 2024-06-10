#include "func_Mat.h"
#include <stdio.h>
#include <stdlib.h>

//SUMA DIAGONAL SUP
int sumatoriaDiagonalSup(int mat[][MAX_COL], int f, int c)
{
    int i, j;
    int sumatoria = 0;
    for(i = 0; i< f; i ++)
    {
        for(j= i+ 1; j < MAX_COL; j++)
        {
            sumatoria += mat[i][j];
        }
    }
    return sumatoria;
}
//SUMA DIAGONAL INF
int sumatoriaDiagonalInf(int mat[][MAX_COL], int f, int c)
{
    int i, j;
    int sumatoria = 0;
    for(i = 1; i < f; i++)
    {
        for(j = 0; j < i; j++)
            sumatoria += mat[i][j];
    }
    return sumatoria;
}
//suma diagonal principal
int sumatoriaDiagonalPrincipal(int mat[][MAX_COL], int f, int c)
{
    int i, j;
    int sumatoria = 0;
    for(i = 0; i < c; i++)
        sumatoria+= mat[i][i];
    return sumatoria;
}
//suma diagonal secundaria
int sumatoriaDiagonalSec(int mat[][MAX_COL], int f, int c)
{
    int i, j;
    int sumatoria= 0;
    for(i = 0; i < c; i ++)
    {
        sumatoria += mat[i][f-1-i];
    }
    return sumatoria;
}

int esIdentidad(int mat[][MAX_COL], int f, int c)
{
    int i, j;
    for(i = 0; i < f; i++)
        if(mat[i][i] != 1)
            return 0;
    for(i = 0; i < f ; i++)
    {
        for(j=0; j< c ; j++)
        {
            if(i != j && (mat[i][j] != 0 || mat[j][i] != 0))
            {
                return 0;
            }
        }
    }
    return 1;
}

//Es el ejercicio 1.17
void trasponerMat(int mat[][MAX_COL], int f, int c)
{
    int i, j;
    int temp;
    for(i = 0; i< f; i++)
    {
        for(j= i +1; j< c; j++)
        {
            temp = mat[i][j];// 0 0
            mat[i][j] = mat[j][i]; // 0 0
            mat[j][i] = temp;
        }
    }
}

//Es el ejercicio 1.18
void trasponerMatriz(int mat[][MAX_COL], int traspuesta[][MAX_COL], int f, int c)
{
    int i , j;
    for(i = 0; i < f; i++)
    {
        for(j=0; j < c; j++)
        {
            traspuesta[j][i] = mat[i][j];
        }
    }
}

void mostrarMatriz(int mat[][MAX_COL], int f, int c)
{
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}


