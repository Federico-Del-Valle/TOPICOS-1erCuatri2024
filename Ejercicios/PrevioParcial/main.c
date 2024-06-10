#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <stddef.h>
#include "../../BIBLIOS/func_Strings.h"
#include "../../BIBLIOS/func_Gen.h"
#include "../../BIBLIOS/func_Arch.h"
#include "../../BIBLIOS/func_Mat.h"

int main()
{
    int identidad;
    int mat[MAX_FIL][MAX_COL] = {
        {1,3,4,9},
        {0,1,7,0},
        {4,3,1,0},
        {5,0,9,2}};
        int transpuesta[4][4];

        trasponerMatriz(mat,transpuesta,4,4);
        mostrarMatriz(mat,4,4);
        printf("\nLa traspuesta es:\n ");
        mostrarMatriz(transpuesta,4,4);

    /*char leng[100] = "Nj qemh v ljs kraenkqbres lj oqe qemh es oqevorme sgn ellhs --Istqt Asdmgj";
    //normalizarOracion(leng);
    puts("Cadena ofuscada:");
    printf("\n%s\n", leng);
    char * desofucada= desofuscarSinProximaPalabra(leng);
    puts("Cadena desofuscada:");

    printf("\n %s", leng);*/



    /*int vec[] = {1,20,4,50,30};
    char oracion[] = "La vida es bella";
    printf("\n %p", oracion);
    cad(oracion);
    printf("\n %p",oracion);
    //unsigned ce = sizeof(vec) / sizeof(int);
    _map(vec,&ce, sizeof(int), MultiplicarInt);
    _map(vec,&ce, sizeof(int),imprimirInt);
    _filter(vec,&ce,sizeof(int),filtroInt);
    _map(vec, &ce,sizeof(int),imprimirInt);
   // printf("\n%s", oracion);

    //_memmove(oracion, oracion +5 , 5);
    printf("\n%s", oracion);*/
    //crearArch();
    //leerArch("Estudiantes.dat", "Estudiantes.txt");*/
    return 0;
}
