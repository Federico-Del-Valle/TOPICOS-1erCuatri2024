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
    int tam;
    printf("\nINGRESE EL TAMAÑO DEL VECTOR:");
    scanf("%d", &tam);
    sAlumno* alumno = crearVectorAlumno(tam);

    mostrarAlumnos(alumno, tam);

    return 0;
}
