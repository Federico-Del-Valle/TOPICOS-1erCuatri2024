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
#include "../../BIBLIOS/parcial.h"

int main() {
    char oracion[1000];
    char* oracionOfus;
    int des;
    leerArchTexto("parcial.txt",oracion, &des);
    printf(" %-20s",oracion);
    oracionOfus = ofuscar(oracion, &des);
    printf("\n %s", oracionOfus);
    escribirArchOfus("parcialOfus.txt", oracionOfus, &des);
    return 0;
}
