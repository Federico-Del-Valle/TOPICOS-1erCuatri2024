#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <stddef.h>
#include "../../BIBLIOS/func_Strings.h"
#include "../../BIBLIOS/func_Gen.h"
#include "../../BIBLIOS/func_Arch.h"
#include "../../BIBLIOS/func_Mat.h"


int main() {
    int mat[][3] = {
        {0, 6, 2},
        {1, 0, 3},
        {2, 3, 0}
    };

    int verifica = puntajes(mat, 3, 3);

    if (verifica == 1) {
        printf("La matriz de puntajes cumple con las condiciones.\n");
    } else {
        printf("La matriz de puntajes NO cumple con las condiciones.\n");
    }

    return 0;
}
