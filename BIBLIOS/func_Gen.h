#ifndef FUNC_GEN_H_INCLUDED
#define FUNC_GEN_H_INCLUDED
#include <stddef.h>

typedef struct {
    int id;
    float value;
}Item;

typedef struct {
    int dni;
    char nombreyape[30];
    float promedio;
}Alumno;

typedef struct
{
    int dni;
    char apellido[20];
    char nombres[30];
    float peso;
}sPersona;
//definicion funciones

void swap1(void *va, void *vb, size_t s);
void _map(void* vec, unsigned* ce, unsigned tam, void accion(void*));
void imprimirInt(void* vec);
void MultiplicarInt(void* vec);
void* _filter(void* vec, unsigned* ce, unsigned tam, int filtro(const void*));
int filtroInt(const void* vec);
void ordSelec(void *vec, size_t ce, size_t tam, int cmp(const void *, const void *));
void mostrarPersona(sPersona* vec, int tam);

//funciones como parametros
int cmpAlumno(const void *a, const void *b);
int cmp(const void *a, const void *b);
int compararNombre(const void* a, const void* b);
int cmpDNI(const void* a, const void* b);
int cmpChar(const void* a, const void* b);
int cmpInt(const void* a, const void* b);

#endif // FUNC_GEN_H_INCLUDED
