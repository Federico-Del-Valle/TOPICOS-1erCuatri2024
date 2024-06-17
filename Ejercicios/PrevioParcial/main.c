#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <stddef.h>
#define ESPAR(X) ((((X) % 2) == 0) ? (X) : 0)
#include "../../BIBLIOS/func_Strings.h"
#include "../../BIBLIOS/func_Gen.h"
#include "../../BIBLIOS/func_Arch.h"
#include "../../BIBLIOS/func_Mat.h"
#include "../../BIBLIOS/func_Dinamic.h"
#include "../../BIBLIOS/func_Vec.h"

int main() {
    generarArchivoEmpleados("empleados.dat");
    generarArchivoEstudiantes("estudiantes.dat");
    recorrerArch("empleados.dat",sizeof(Empleado), mostrarEmpleado);
    printf("\nArchivo estudiantes----\n");

    recorrerArch("estudiantes.dat", sizeof(Estudiante),mostrarEstudiante);
    puts("");
   // Ejemplo con un array de enteros
    mergeEj7("empleados.dat", "estudiantes.dat");
    recorrerArch("empleados.dat", sizeof(Empleado), mostrarEmpleado);
    return 0;
}
