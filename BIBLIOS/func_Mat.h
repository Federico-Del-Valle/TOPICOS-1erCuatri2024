#ifndef FUNC_MAT_H_INCLUDED
#define FUNC_MAT_H_INCLUDED
#define MAX_COL 50
#define MAX_FIL 50
int sumatoriaDiagonalSup(int mat[][MAX_COL], int f, int c);
int sumatoriaDiagonalInf(int mat[][MAX_COL], int f, int c);
int sumatoriaDiagonalPrincipal(int mat[][MAX_COL], int f, int c);
int sumatoriaDiagonalSec(int mat[][MAX_COL], int f, int c);
int esIdentidad(int mat[][MAX_COL], int f, int c);
void trasponerMat(int mat[][MAX_COL], int f, int c);
void mostrarMatriz(int mat[][MAX_COL], int f, int c);
void trasponerMatriz(int mat[][MAX_COL], int traspuesta[][MAX_COL], int f, int c);
int buscar(int* vec, int elemento, int ce);
int puntajes(int mat[][3], int cf, int cc);
#endif // FUNC_MAT_H_INCLUDED
