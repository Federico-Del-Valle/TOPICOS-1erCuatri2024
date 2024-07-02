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
    int i;
    int sumatoria = 0;
    for(i = 0; i < c; i++)
        sumatoria+= mat[i][i];
    return sumatoria;
}
//suma diagonal secundaria
int sumatoriaDiagonalSec(int mat[][MAX_COL], int f, int c)
{
    int i;
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

//Ejercicio 1.19
//Desarrollar una función para obtener la matriz producto entre dos matrices de enteros


int matrizProducto(int mata[][MAX_COL], int matb[][MAX_COL], int matProd[][MAX_COL], int cfa, int cca, int cfb, int ccb)
{
    int i, j,k;
    if(cca != cfb)
    {
        printf("\nNo se pudo hacer la multiplicacion de matrices");
        return 0;
    }
    else
    {
        for(i = 0; i< cfa; i++)
        {
            for(j = 0; j < ccb; j++)
            {
                for(k=0; k <cfb; k++)
                {
                    matProd[i][j] += mata[i][k] * matb[k][j];
                }
            }
        }
    }
    return 1;
}


/*Ejercicio 1.20
Se dispone de una matriz cuadrada de enteros de orden N, donde cada elemento [i][j] representa la
cantidad de puntos que obtuvo el equipo i frente al equipo j al fin de un torneo de fútbol (partidos
de ida y vuelta) en el que participaron N equipos. El sistema de puntuación es: 3 puntos para el
ganador del partido y ninguno para el perdedor; 1 punto para cada equipo en caso de empate.
Desarrollar una función que determine si la matriz está correctamente generada.
Desarrollar una función que genere un arreglo de N elementos tal que cada elemento V[k] contenga
la cantidad de puntos obtenidos por el equipo k.
*/

int puntajes(int mat[][3], int cf, int cc)
{
    int matReflex[2][6] = {
        {0,1,2,3,4,6},
        {6,4,2,3,1,0}};

        int pos,i,j;

    for( i =0; i < cf; i++)
    {
        for(j =i +1; j < cc; j++)
        {
            pos = buscar(matReflex[0], mat[i][j], 6);
            if(pos < 0 || (mat[j][i] != matReflex[1][pos]))
            {
                return 0;
            }

        }
    }
    return 1;
}

int buscar(int* vec, int elemento, int ce)
{
    int pos = -1;
    int i =0;
    while(pos == -1 && i < ce)
    {
        if(*(vec+i) == elemento)
            pos = i;
        else
            i++;
    }
    return pos;
}


