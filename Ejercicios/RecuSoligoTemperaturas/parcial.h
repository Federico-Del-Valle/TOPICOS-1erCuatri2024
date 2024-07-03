#ifndef PARCIAL_H_INCLUDED
#define PARCIAL_H_INCLUDED

typedef struct
{
    int fecha;
    char cod[9];
    float temp;
    char estado[13];
}sSensor;

typedef struct
{
    char cod[9];
    float promedio;
    int total;
    char estado[13];
}sPromedio;

int cmp(const void *n1, const void *n2);
int abrirArch(const char* nombre, sPromedio* vec, int ce);
int buscarSensor(sPromedio* vec, int ce, const char* cod);
void swap_(void *a, void* b, unsigned tamDato);
int cmpChar(const void* a, const void* b);
void ordSeleccion(void* vec, unsigned ce, unsigned tamDato, int cmp(const void*, const void*));
int compare_ints(const void *a, const void *b);

int pa(void* vec, int i, int f, unsigned tam, int cmp(const void*, const void*));

void myqsort(void *v, int i, int f, size_t size,int (*comp)(const void *, const void *));
int generic_partition(void *v, int i, int f, size_t size,int (*comp)(const void *, const void *));
#endif // PARCIAL_H_INCLUDED
