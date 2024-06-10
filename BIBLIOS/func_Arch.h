#ifndef FUNC_ARCH_H_INCLUDED
#define FUNC_ARCH_H_INCLUDED

typedef struct
{
    int leg;
    char nombre[30];
    float promedio;
}sEstudiante;

typedef struct
{
    int leg;
    char nombre[30];
    float promedio;
    char estado;
}sNovedades;

int crearArch();
void leerArch(char * arch, char* texto);

#endif // FUNC_ARCH_H_INCLUDED
