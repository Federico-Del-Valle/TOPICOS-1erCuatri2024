#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <stddef.h>
#include "../../BIBLIOS/func_Strings.h"
#include "../../BIBLIOS/func_Gen.h"
#include "../../BIBLIOS/func_Arch.h"
#include "../../BIBLIOS/func_Mat.h"


int main() {

    int mata[MAX_FIL][MAX_COL] =
    {{1,2,3},
    {2,3,4},
    {4,5,6}};

    int matb[MAX_FIL][MAX_COL] =
    {{1,2},
    {2,3},
    {0,1}};
    int matProd[MAX_FIL][MAX_COL] = {{}};

    matrizProducto(mata,matb,matProd,3,3,3,2);
    mostrarMatriz(matProd,3,2);

    return 0;
}
