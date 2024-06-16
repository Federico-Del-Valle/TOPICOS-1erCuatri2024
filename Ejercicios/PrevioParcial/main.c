#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <stddef.h>
#include "../../BIBLIOS/func_Strings.h"
#include "../../BIBLIOS/func_Gen.h"
#include "../../BIBLIOS/func_Arch.h"
#include "../../BIBLIOS/func_Mat.h"
#include "../../BIBLIOS/func_Dinamic.h"
#include "../../BIBLIOS/func_Vec.h"

int main() {
    float* vector = NULL;
    int tam;
    float* min;
    int opcion;
    float promedio;
    printf("\nIngrese la cantidad de tamaño que va a tener el vector float:");
    scanf("%d", &tam);

    int ce = crearVectorFloat(&vector, tam);

    opcion = menu();
    while(opcion != 4)
    {
        switch(opcion)
        {
        case 1:
            min = minimo(vector,ce);
            printf("\n MINIMO: %.2f", *min);
            break;
        case 2:
            promedio = promedioPosPares(vector,ce);
            printf("\nPROMEDIO:%.2f", promedio);
            break;
        case 3:
            mostrarInverso(vector, ce);
            break;
        }
        opcion= menu();
    }
    printf("\n---FIN---");
    free(vector); // Liberar la memoria asignada
    return 0;
}
