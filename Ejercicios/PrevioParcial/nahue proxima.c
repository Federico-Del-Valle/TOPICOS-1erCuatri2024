#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ES_LETRA(x)( ((x) >= 'A' && (x) <= 'Z') || ((x) >= 'a' && (x) <= 'z'))


void imprimirProximaPalabra(char *ini, char *fin, FILE *pf)
{
    while(ini <= fin)
    {
        fprintf(pf, "%c", *ini);
        ini++;
    }
}

unsigned proximaPalabra(char *cadena, char **iniPalabra, char **finPalabra)
{
    short int longitudPalabra = 0; /// cuenta cuántos caracteres tiene la próxima palabra

    if(!(*cadena))
        return longitudPalabra;

    if((*iniPalabra < cadena) || (*iniPalabra > (cadena + strlen(cadena)))) /// esta condición detecta si previamente se ejecutó la fn. sobre la cadena enviada
        *iniPalabra = cadena;
    else
        *iniPalabra = (*finPalabra) + 1; /// si previamente se ejecutó la fn. sobre la cadena enviada, retomamos en la siguiente posición del final de la palabra anterior detectada

    while(**iniPalabra && !ES_LETRA(**iniPalabra)) /// adelantamos el puntero al inicio de la siguiente palabra
        (*iniPalabra)++;

    *finPalabra = *iniPalabra; /// establecemos una referencia para que ' finPalabra ' delimite la secuencia

    while(**finPalabra && ES_LETRA(**finPalabra))
    {
        longitudPalabra++;
        (*finPalabra)++;
    }

    (*finPalabra)--; /// corrijo porque ' finPalabra ' cuando corte es justamente porque el último caracter no es letra (o termino la cadena)

    return longitudPalabra;
}

int main()
{
    char cadena[] = "     Esta es ,,,,, una secuenc    ia  ..__234 cualquie+ra de c a r a c t e res |||1 <a> {reconocer}  ",
        *ini,
        *fin;
    short int cantidad;
    while(proximaPalabra(cadena, &ini, &fin))
    {
        imprimirProximaPalabra(ini, fin, stdout);
        fprintf(stdout, "%c", 32);
    }
    puts("\n");
    fprintf(stdout, "Otras pruebas\n\n");
    while((cantidad = proximaPalabra("     Ips *¨¨¨¨$# um M O R___T;i^^^^If ññññññ", &ini, &fin)))
        printf("%.*s", cantidad, ini);
    printf("\n\n%25s", "FIN\n\n");
    return 0;
}
