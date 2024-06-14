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

void swap1(void *va, void *vb, size_t s);
void _map(void* vec, unsigned* ce, unsigned tam, void accion(void*));
void imprimirInt(void* vec);
void MultiplicarInt(void* vec);
void* _filter(void* vec, unsigned* ce, unsigned tam, int filtro(const void*));
int filtroInt(const void* vec);
void ordSelec(void *vec, size_t ce, size_t tam, int cmp(const void *, const void *));
int cmpAlumno(const void *a, const void *b);
int cmp(const void *a, const void *b);
#endif // FUNC_GEN_H_INCLUDED
