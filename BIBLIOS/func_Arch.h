#ifndef FUNC_ARCH_H_INCLUDED
#define FUNC_ARCH_H_INCLUDED
#define MAX_LEN 30
//estructuras
typedef struct {
    int dni;
    char apellido[MAX_LEN];
    char nombre[MAX_LEN];
    double sueldo;
} Empleado;

typedef struct {
    int dni;
    char apellido[MAX_LEN];
    char nombre[MAX_LEN];
    float promedio;
} Estudiante;

typedef struct
{
    char nombre[31];
    int edad;
    char condicion[31];
}sEstudiante;

//Prototipos de funciones

void mergeEj7(const char* archEmp, const char* archEst);

void mostrarEmpleado(void* val);

void mostrarEstudiante(void* val);

#endif // FUNC_ARCH_H_INCLUDED
