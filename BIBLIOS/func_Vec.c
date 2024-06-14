#include "func_Vec.h"
#include "func_Dinamic.h"
#include <stdio.h>
#include <stdlib.h>

void mostrarVector(int* vec, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", *(vec +i));
    }
    printf("\n");
}

void mostrarAlumnos(sAlumno* vec, int tam) {
    printf("\n%8s  %-20s  %8s  %8s\n", "DNI", "Nombre", "Promedio", "Condicion");
    for (int i = 0; i < tam; i++) {
        printf("%8d  %-20s  %8.2f  %8c\n", (vec + i)->dni, (vec + i)->nombre, (vec + i)->promedio, (vec + i)->condicion);
    }
    printf("\n");
}
