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

void* _filter(void* vec, unsigned* ce, unsigned tam, int filtro(const void*));
int filtroInt(const void* vec);

void ordSelec(void *vec, size_t ce, size_t tam, int cmp(const void *, const void *));
void ordSeleccionVoid(void *vec, size_t ce, size_t tam, int cmp(const void *, const void *));//es didactica mirar para entender el func de void pointer

void mostrarPersona(sPersona* vec, int tam);
unsigned insertarOrdenadoFede(void* vec, unsigned* ce, unsigned tamdato, unsigned tamvec, void* elem, int cmp(const void*, const void*));
void *bsearch(const void *dato, const void *vec,  size_t ce, size_t tamdato, int (*comparar)(const void *, const void *));
void* reduce(void* vec, unsigned tam, unsigned ce, void* (*funcion)(void*, const void*), void* init);
//funciones como parametros

void MultiplicarInt(void* vec);
int cmpAlumno(const void *a, const void *b);
int cmp(const void *a, const void *b);
int compararNombre(const void* a, const void* b);
int cmpDNI(const void* a, const void* b);
int cmpChar(const void* a, const void* b);
int cmpInt(const void* a, const void* b);

//funcion para reduce
void* funcionSumar(void* a, const void* b);
#endif // FUNC_GEN_H_INCLUDED
