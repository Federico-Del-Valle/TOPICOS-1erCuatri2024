#ifndef FUNC_STRINGS_H
#define FUNC_STRINGS_H
#define ESLETRA(X) ((((X)>='a') && ((X)<='z')) ||(((X)>='A') && ((X)<='Z')))
#define AMAYUS(X) ((X >= 97 && X <= 122)) ? (X-('a'-'A')) : X
#define AMINUSC(X) (((X) >= 'A' && (X) <= 'Z') ? ((X) + 32) : (X))



int mstrlen(const char*);
int mstrcmp(const char*, const char*);
int cmp(const void*, const void*);
int proximaPalabra1(const char* cad, char** pini, char** pfin);
char* normalizarPalabra(char* cad);

#endif // FUNC_STRINGS_H
