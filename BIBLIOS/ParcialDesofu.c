#include "ParcialDesofu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int LeerArchOfus(char* nombre) // ARMENSE UN ARCHIVO DE TXT(BLOC DE NOTAS) Y HAGAN UNA PRUEBA. Yo no hice muchos casos de prueba pero en los que hice funco
{
    char linea[1024]; // Cambiado a arreglo de caracteres
    char* ini, *fin;
    char palabra[30]; // Cambiado a arreglo de caracteres
    int cantLetras;
    FILE *arch = fopen(nombre, "r");
    FILE *archT = fopen("temp.txt", "w");
    if(!arch)
    {
        printf("\nError al abrir el archivo citas");
        fclose(arch);
        return 0;
    }
    if(!archT)
    {
        printf("\nError al abrir el archivo");
        fclose(archT);
        return 0;
    }

    while(fgets(linea, 1024, arch))
    {
        while((cantLetras = proximaPalabra(linea, &ini, &fin)) > 0)
        {
            copiaCad(ini, fin, palabra); // Funcion creada por mi para copiar lo que tengo en pini y en pfin
            invertirCadena(palabra);
            desofuscarPalabra(palabra);
            fprintf(archT, "%s ", palabra);
        }
    }

    fclose(arch);
    fclose(archT);
    remove(nombre);
    rename("temp.txt", nombre);

    return 1;
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



// invertir la cadena que le paso
char* invertirCadena(char* cad)
{
    char* ini = cad;//inicio de la cadena
    char* fin = cad; // fin de la cadena
    char temp;
    while(*fin)
    {
        fin++;
    }
    fin--;
    while(cad < fin)
    {
        temp = *cad; //a loh
        *cad = *fin; // h
        *fin = temp; // a
        fin--; //oh
        cad++; //hloh
    }
    return ini;
}

char* desofuscarPalabra(char* cad)
{
    char* ini = cad; // Guardamos el inicio de la cadena original
    char mat[2][6] = {
        {'a', 'b', 'c', 'd', 'e', 'f'},
        {'f', 'e', 'd', 'c', 'b', 'a'}
    };

    while (*cad)
    {
        int posEncontrado = buscarChar(mat[0], *cad); // Buscamos la posición del carácter en mat[0]
        if (posEncontrado != -1)
        {
            *cad = mat[1][posEncontrado]; // Reemplazamos el carácter por su equivalente en mat[1]
        }
        cad++; // Avanzamos al siguiente carácter de la cadena original
    }

    return ini; // Devolvemos el inicio de la cadena modificada
}

int buscarChar(char* vec, char letra)
{
    int pos = -1;
    int cont = 0;
    while ((cont < 6) && (pos == -1))
    {
        if (*(vec + cont) == letra) {
            pos = cont;
        } else {
            cont++;
        }
    }
    return pos;
}

void imprimirProximaPalabra(char *ini, char *fin, FILE *pf)
{
    while(ini <= fin)
    {
        fprintf(pf, "%c", *ini);
        ini++;
    }
}

char* copiaCad(char* pini, char* pfin, char* cad)
{
    char* pmem = cad;
    while(pini <= pfin)
    {
        *cad = (*pini);
        pini++;
        cad++;
    }
    *cad= '\0';
    return pmem;
}
