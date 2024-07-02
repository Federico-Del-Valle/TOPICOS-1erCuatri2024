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
#include "../../BIBLIOS/ParcialDesofu.h"

int main()
{

    LeerArchOfus("citas.txt");
    /*char cadena[] = "     Esta es ,,,,, una secuenc    ia  ..__234 cualquie+ra de c a r a c t e res |||1 <a> {reconocer}  ",
        *ini,
        *fin;
        char palabra[30];
    short int cantidad;
    proximaPalabra(cadena, &ini, &fin);
    copiaCad(ini, fin, palabra);
    desofuscarPalabra(palabra);
    proximaPalabra(cadena, &ini, &fin);
    printf("%s", palabra);
    copiaCad(ini,fin,palabra);
    printf("%s", palabra);*/

    return 0;
}
