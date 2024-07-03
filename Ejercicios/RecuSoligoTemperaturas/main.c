#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"parcial.h"

int main() {
    int vec[5] = {1, 2, 4, 8, 9};
    int dato = 8;

    // Llamar a binarySearchArr para buscar el valor 'dato' en 'vec'
    void *pos = binarySearchArr(vec, 5, sizeof(int), &dato, cmp);

    if (pos != NULL) {
        // Obtener el valor del elemento encontrado
        printf("Elemento encontrado: %d\n", *(int*)pos);

    } else {
        printf("Elemento no encontrado en el arreglo\n");
    }

    return 0;
}


