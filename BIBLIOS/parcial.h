#ifndef PARCIAL_H_INCLUDED
#define PARCIAL_H_INCLUDED
#define TAM_LINEA 500
#define ESLETRA(X) ((((X)>='a') && ((X)<='z')) ||(((X)>='A') && ((X)<='Z')))
#define AMINUS(X) (((X) >= 'A' && (X) <= 'Z') ? ((X) + ('a' - 'A')) : (X))

int leerArchTexto(const char* arch, char* frase, int* des);
char* ofuscar(char* cad, int* des);
int escribirArchOfus(const char* arch, char* frase, int* des);
#endif // PARCIAL_H_INCLUDED
