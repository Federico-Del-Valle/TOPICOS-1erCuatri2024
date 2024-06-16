#include "func_Dinamic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//PUNTO 1 Y 2
int* crearVector(int tam)
{
    int i;
    int* vector = malloc(sizeof(int) * tam);

    if (vector == NULL)
        {
        return NULL;
        }
    printf("\nIngrese valores");
    for(i= 0; i< tam; i++)
    {
        scanf("%d", vector+i);
    }
    return vector;
}

void destruirVector(int* vec)
{
    free(vec);
    vec = NULL;
}


//PUNTO 3

sAlumno* crearVectorAlumno(int tam)
{
    int i;
    sAlumno* vectorAlumno = malloc(sizeof(sAlumno) * tam);
    if (!vectorAlumno)
    {
        return NULL;
    }
    puts("Ingrese los datos del alumno:");
    for (i = 0; i < tam; i++)
    {
        printf("\nIngrese el dni: ");
        scanf("%d", &(vectorAlumno + i)->dni);
        fflush(stdin);

        printf("\nIngrese el nombre: ");
        gets((vectorAlumno + i)->nombre);


        printf("\nIngrese el promedio: ");
        scanf("%f", &(vectorAlumno + i)->promedio);
        fflush(stdin);

        printf("\nIngrese la condicion (Aprobado/A o Reprobado/R): ");
        scanf(" %c", &(vectorAlumno + i)->condicion);
        fflush(stdin);
    }
    return vectorAlumno;
}
void destruirAlumno(sAlumno* vec)
{
    free(vec);
    vec = NULL;
}

//PUNTO 4

char* cadenaCopia(const char* cadenaOriginal)
{
    unsigned tamanio = strlen(cadenaOriginal);
    char* copia = malloc(sizeof(char)* (tamanio +1));
    char* copiaInicio = copia;
    while(*cadenaOriginal)
    {
        *copia = *cadenaOriginal;
        copia++;
        cadenaOriginal++;
    }
    *copia = '\0';
    return copiaInicio;
}

void* copiaCosas(void* elemento, unsigned tam)
{
    void* cosa = malloc(tam);
    if(!cosa)
    {
        return NULL;
    }
    memcpy(cosa, elemento, tam);
    return cosa;
}


/*Ejercicio 3.1
Escriba una función que permita desplegar un menú de opciones, devolviendo una opción válida.
Escriba una función que reciba por argumento la dirección de comienzo de un array de float y la
cantidad máxima de elementos a ingresar (no utilice subíndices). La función permitirá terminar el
ingreso con una condición fijada por el alumno y devolverá la cantidad de elementos ingresados
(puede ser cero).
Escriba una función que permita buscar el mínimo elemento de un array de float.
Escriba una función que determine el promedio de los elementos que se encuentran en las
posiciones pares de un array de float.
Escriba una función que muestre los elementos de un array de float en orden inverso.
Escriba una función que almacene en un archivo de texto los elementos de un array de float, a razón
de un flotante por línea de texto.
Haciendo uso de las funciones anteriores, escriba un programa que al comenzar su ejecución permita
el ingreso para un array de float, luego de lo cual muestre un menú de opciones para:
1- Buscar el mínimo elemento,
2- Calcular el promedio de los valores de las posiciones pares,
3- Mostrarlo en orden inverso,
4- Salir.
Consulte de qué modo puede hacer que el programa trabaje con otros tipos de datos (double, long
double, int, unsigned, etc.), con mínimas modificaciones.
*/

int menu()
{
    int opcion;
    printf("\n---MENU---\n");
    printf("\n1- BUSCAR EL MINIMO ELEMENTO");
    printf("\n2- CALCULAR EL PROMEDIO DE LOS VALORES DE LAS POSICIONES PARES");
    printf("\n3- MOSTRARLO EN ORDEN INVERSO");
    printf("\n4- SALIR");
    printf("\n\nSELECCIONE UNA OPCION:");

    scanf("%d", &opcion);
    return opcion;
}

int crearVectorFloat(float** vec, int tam)
{
    int ce = 0;
    float dato;
    *vec = (float*)malloc(sizeof(float) * tam);
    if(!*vec)
    {
        return 0;
    }
    printf("\n---Ingrese los datos del vector---\n");
    printf("\nIngrese el dato n° %d (negativo para terminar): ", ce + 1);
    scanf("%f", &dato);
    while (dato >= 0 && ce < tam)
    {
        *(*vec + ce) = dato;
        ce++;
        if (ce < tam) {
            printf("\nIngrese el dato n° %d (negativo para terminar): ", ce + 1);
            scanf("%f", &dato);
        }
    }

    return ce;
}

float* minimo(float* vec, unsigned ce)
{
    int i;
    float* min = vec;
    for(i=1; i< ce; i++)
    {
        if(*(vec+i) < *min)
        {
            min = vec+i;
        }
    }
    return min;
}

float promedioPosPares(float* vec, unsigned ce)
{
    float sumaPar=0;
    int i, cant = 0;
    float promedio;
    for(i = 0; i < ce; i++)
    {
        if((i%2) == 0)
        {
            sumaPar += *(vec +i);
            cant++;
        }
    }
    promedio = sumaPar /cant;
    return promedio;
}

void mostrarInverso(float* vec, unsigned ce)
{
    int i;
    for(i = ce-1; i > -1; i--)
    {
        printf("\n%.2f", *(vec +i));
    }
}

