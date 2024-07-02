#include "func_Arch.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MIN_REQ 7
//EJERCICIO 3.7

void generarArchivoEstudiantes(const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "wb");
    if (!archivo) {
        perror("Error al abrir el archivo de estudiantes");
        exit(EXIT_FAILURE);
    }

    Estudiante estudiantes[] = {
        {234544, "Amante", "Anastasia", 7.5},
        {433212, "Boludin", "Sargeant", 8},
        {534321, "Dolores", "Max", 6},
        {634214, "Leclerc", "Carlos", 4}
    };

    size_t numEstudiantes = sizeof(estudiantes) / sizeof(Estudiante);

    // Escribir los estudiantes en el archivo
    for (size_t i = 0; i < numEstudiantes; i++) {
        fwrite(&estudiantes[i], sizeof(Estudiante), 1, archivo);
    }

    fclose(archivo);
}

void generarArchivoEmpleados(const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "wb");
    if (!archivo) {
        perror("Error al abrir el archivo de empleados");
        exit(EXIT_FAILURE);
    }

    Empleado empleados[] = {
        {234544, "Amante", "Anastasia", 50000.0},
        {244321, "Berez", "Ana", 55000.0},
        {433212, "Boludin", "Sargeant", 60000.0},
        {534321, "Dolores", "Max", 65000.0},
        {634214, "Leclerc", "Carlos", 52000.0}
    };

    size_t numEmpleados = sizeof(empleados) / sizeof(Empleado);

    // Escribir los empleados en el archivo
    for (size_t i = 0; i < numEmpleados; i++) {
        fwrite(&empleados[i], sizeof(Empleado), 1, archivo);
    }

    fclose(archivo);
}

    //leer archivo binario y hacerlo texto
/*void leerArch(char * arch, char* texto)
{
    FILE *archEstudiantes;
    sEstudiante estudiante;
    sEstudiante* punteroE = &estudiante;
    archEstudiantes = fopen(arch, "rb");
    FILE *archTexto;
    archTexto= fopen(texto, "w");

    fread(punteroE, sizeof(sEstudiante),1,archEstudiantes);
    while(!feof(archEstudiantes))
    {
        fprintf(archTexto,"%d | %-20s | %f\n", punteroE->leg, punteroE->nombre, punteroE->promedio);
        fread(punteroE,sizeof(sEstudiante),1,archEstudiantes);

    }
    fclose(archEstudiantes);
    fclose(archTexto);
}*/




/*Ejercicio 5.7
Se dispone de dos archivos binarios: <empleados> y <estudiantes>.
Cada registro del primer archivo contiene los campos:
- <dni>, <apellido>, <nombre> y <sueldo>
en tanto que los del segundo:
- <dni>, <apellido>, <nombre> y <promedio>.
Ambos archivos están ordenados alfabéticamente por <apellido> / <nombre> / <dni>.
Ambos archivos deben ser leídos sólo una vez, y no deben ser almacenados en arrays. El sueldo es
double y el promedio es float.
Escriba un programa que, leyendo ambos archivos, actualice el sueldo de aquellos empleados que
tengan un registro de estudiante con un promedio superior a 7, en un 7,28%.
*/

void mergeEj7(const char* archEmp, const char* archEst)
{
    Estudiante auxE;
    Empleado auxEmpleado;
    FILE* archEmpleado = fopen(archEmp, "r+b");
    FILE* archEstudiantes = fopen(archEst, "rb");
    if(!archEmpleado)
    {
        printf("\nERROR AL ABRIR EMPLEADOS");
    }
    if(!archEstudiantes)
    {
        printf("\nERROR AL ABRIR EMPLEADOS");
    }
    fread(&auxE, sizeof(Estudiante),1, archEstudiantes);
    fread(&auxEmpleado, sizeof(Empleado),1,archEmpleado);
    while(!feof(archEstudiantes) && !feof(archEmpleado))
    {
        if((auxE.dni == auxEmpleado.dni) && (auxE.promedio >= MIN_REQ))
        {
            fseek(archEmpleado, sizeof(Empleado)*(-1),SEEK_CUR);
            auxEmpleado.sueldo = auxEmpleado.sueldo + auxEmpleado.sueldo * (7.28/100);
            fwrite(&auxEmpleado,sizeof(Empleado),1,archEmpleado);
            fflush(archEmpleado);
            fread(&auxE,sizeof(Estudiante),1,archEstudiantes);
            fread(&auxEmpleado,sizeof(Empleado),1,archEmpleado);
        }
        if(auxE.dni > auxEmpleado.dni)
            fread(&auxEmpleado,sizeof(Empleado),1,archEmpleado);
        else
            fread(&auxE,sizeof(Estudiante),1,archEstudiantes);

    }

    fclose(archEmpleado);
    fclose(archEstudiantes);

}

int recorrerArch(const char* nomArch, unsigned tamDato, int accion(void* val))
{
    FILE *arch;
    arch = fopen(nomArch,"rb");
    if(!arch)
    {
        printf("\nERROR AL ABRIR");
        return 0;
    }
    void* dato = malloc(tamDato);
    fread(dato, tamDato,1,arch);
    while(!feof(arch))
    {
        accion(dato);
        fread(dato,tamDato,1,arch);
    }
    free(dato);
    fclose(arch);

    return 1;
}

void mostrarEmpleado(void* val)
{
    Empleado* aux = (Empleado*)val;
    printf("%8d  %-20s  %-20s  %.2f\n", aux->dni, aux->apellido, aux->nombre, aux->sueldo);
}

void mostrarEstudiante(void* val)
{
    Estudiante* aux = (Estudiante*)val;
    printf("%8d  %-20s  %-20s  %.2f\n", aux->dni, aux->apellido, aux->nombre, aux->promedio);
}


int leerArchTxt(const char* nombre, unsigned tamDato)
{
    sEstudiante* estudiante = malloc(tamDato);
    FILE* arch = fopen(nombre, "r");
    //FILE* archBin = fopen("estudiantes.dat", "wb");
    char linea[100];
    if(!estudiante)
    {
        return 0;
    }
    while(fgets(linea,sizeof(linea), arch))
    {
        char* actual = linea;
        actual = strrchr(actual,'\n');
        *actual = '\0';
        //copiamos condicion
        actual = strrchr(linea,'|');
        strcpy(estudiante->condicion, actual+1);
        *actual = '\0';
        //edad
        actual = strrchr(linea, '|');
        sscanf(actual + 1, "%d", &estudiante->edad);
        *actual = '\0';
        //nombre
        strcpy(estudiante->nombre, linea);
        printf("%d\n", estudiante->edad);
    }
    free(estudiante);
    return 1;
}




