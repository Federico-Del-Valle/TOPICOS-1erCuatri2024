#ifndef PARCIALDESOFU_H_INCLUDED
#define PARCIALDESOFU_H_INCLUDED
#define ES_LETRA(x)( ((x) >= 'A' && (x) <= 'Z') || ((x) >= 'a' && (x) <= 'z'))

unsigned proximaPalabra(char* cad, char** pini, char** pfin);
char* invertirCadena(char* cad);
char* desofuscarPalabra(char* cad);
int buscarChar(char* vec, char letra);
char* copiaCad(char* pini, char* pfin, char* cad);
int LeerArchOfus(char* nombre);
#endif // PARCIALDESOFU_H_INCLUDED
