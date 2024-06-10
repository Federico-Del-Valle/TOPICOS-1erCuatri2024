#ifndef FUNC_GEN_H_INCLUDED
#define FUNC_GEN_H_INCLUDED
#include <stddef.h>
void intercambio(void* a, void* b, size_t tam);
void _map(void* vec, unsigned* ce, unsigned tam, void accion(void*));
void imprimirInt(void* vec);
void MultiplicarInt(void* vec);
void* _filter(void* vec, unsigned* ce, unsigned tam, int filtro(const void*));
int filtroInt(const void* vec);
#endif // FUNC_GEN_H_INCLUDED
