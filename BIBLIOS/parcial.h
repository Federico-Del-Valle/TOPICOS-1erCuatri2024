#ifndef PARCIAL_H_INCLUDED
#define PARCIAL_H_INCLUDED
#define MAX_COL 50
#define TAM_LINEA 500
#define ESLETRA(X) ((((X)>='a') && ((X)<='z')) ||(((X)>='A') && ((X)<='Z')))
#define AMINUS(X) (((X) >= 'A' && (X) <= 'Z') ? ((X) + ('a' - 'A')) : (X))

int leerArchTexto(const char* arch, char* frase, int* des);
char* ofuscar(char* cad, int* des);
int escribirArchOfus(const char* arch, char* frase, int* des);
int compararInt(const void* a, const void* b);
int trianguloDerecha(int Mat[][MAX_COL], int f, int c);

void intercambioGenerica1(void* dato1, void* dato2, unsigned tam);
#endif // PARCIAL_H_INCLUDED
