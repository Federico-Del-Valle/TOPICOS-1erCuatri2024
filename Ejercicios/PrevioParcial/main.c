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

int main()
{
    int numero= 21;
    int* edad = (int*)copiaCosas(&numero, sizeof(int));
    printf("\n %d", *edad);
    return 0;
}
