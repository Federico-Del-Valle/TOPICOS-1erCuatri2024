#include "func_Dinamic.h"
#include <stdio.h>
#include <stdlib.h>

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
