#ifndef FUNC_DINAMIC_H_INCLUDED
#define FUNC_DINAMIC_H_INCLUDED
//ESTRUCTURA PUNTO 3
typedef struct
{
    int dni;
    char nombre[31];
    float promedio;
    char condicion;
}sAlumno;
void mostrarAlumnos(sAlumno* vec, int tam);
int* crearVector(int tam);
void destruirVector(int* vec);
sAlumno* crearVectorAlumno(int tam);
#endif // FUNC_DINAMIC_H_INCLUDED