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
void mostrarVectorFloat(float* vec, int tam) {
    printf("\nDatos del vector:\n");
    for (int i = 0; i < tam; i++) {
        printf("%f ", *(vec + i));
    }
    printf("\n");
}


