#include "parcial.h"
#include <stdlib.h>
#include <stdio.h>


/*Cifrado césar consonántico
En el siguiente ejercicio utilizaremos el cifrado cesar "consonántico". El cifrado Cesar es un
tipo de cifrado por sustitución en el que una letra en el texto original es reemplazada por
otra letra que se encuentra un número fijo de posiciones más adelante en el alfabeto.
“Consonántico” se refiere a que solo las consonantes serán reemplazadas en el alfabeto
sin las vocales. Por ejemplo, con un desplazamiento de 3, la B sería sustituida por la F (
situada 3 lugares a la derecha sin contar la E).
Escriba una función que lea un archivo de texto que contenga el desplazamiento y la frase
a cifrar separados por una coma, y luego escriba un nuevo archivo con el desplazamiento y
la frase cifrada.
Ejemplo de entrada:
3, Arriba la birra.
Ejemplo de salida:
3, Avvifa pa fivva.
NOTAS:
• Tenga en cuenta el correcto uso de punteros y memoria.
• Tenga en cuenta el correcto uso de funciones.
• Tenga en cuenta que el alfabeto no incluye "Ñ", "LL" ni "CH".*/

int leerArchTexto(const char* arch, char* frase, int* des)
{
    FILE* archTexto;
    archTexto = fopen(arch, "r");
    char linea[TAM_LINEA];
    if(!archTexto)
    {
        printf("\nNo se pudo abrir el archivo");
        return 0;
    }
    while(fgets(linea,sizeof(linea),archTexto))
    {
        char* actual = linea;
        actual = strrchr(linea, '|');
        strcpy(frase,actual +1);
        *actual = '\0';
        sscanf(linea , "%d", des);
    }
    fclose(archTexto);
    return 1;
}

char* ofuscar(char* cad, int* des)
{
    char* cadOfus = cad;
    char grupo[] = {"bcdfghjklmnpqrstvwxyz"};
    char* posEncontrado;
    int desplazamiento;

    while(*cad)
    {
        if(ESLETRA(*cad)) // si no es espacio
        {
            posEncontrado = strchr(grupo,AMINUS(*cad)); // busco el caracter en el grupo de consonantes
            if(posEncontrado != NULL) //si NO es NULL (NULL = no lo encontro), entro al bucle
                {
                    if(((posEncontrado - grupo) + *des) < strlen(grupo) ) // si la posicion donde se encontro mas el desplazamiento que nos pasaron es menor que el tamaño de grupo
                        *cad = *(posEncontrado + *des); // a lo que apunta el puntero de cadenaOfus sera reemplazado por lo que hay en la posicion de memoria de posEncontrado +3
                    else //si posEncontra + desplazamiento es mayor que strlen grupo. Significa que llegamos al final del vector grupo, por ende debemos contar desde donde nos quedamos
                        {
                            desplazamiento = (posEncontrado -grupo + *des) % strlen(grupo); //por ej: posEncontra = 22 + 3 = 25 < 22 ? NO,entonces hacemos el calculo de esta linea
                            *cad = *(grupo + desplazamiento); //movemos el puntero para que apunte a posEncotnrado + el desplazamiento
                        }

                }
        }
        cad++;
    }
    return cadOfus;
}


int escribirArchOfus(const char* arch, char* frase, int* des)
{
    FILE* archText = fopen(arch, "w");
    if(!archText)
    {
        printf("\nERROR AL ABRIR");
        return 0;
    }
    fprintf(archText,"%d| %s", *des, frase);
    fclose(archText);
}


