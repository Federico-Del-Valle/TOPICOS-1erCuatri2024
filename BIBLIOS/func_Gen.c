#include "func_Gen.h"
#include <stdio.h>
#include <string.h>
#include <stddef.h>


void intercambio(void* a, void* b, size_t tam)
{
    int i;
    char aux;
    for(i =0; i < tam; i++)
    {
        aux = *(char*)a; //en aux guardamos el valor de a
        *(char*)a = *(char*)b;  //en a guardamos el valor de b
        *(char*)b = aux; //en b guardamos el valor que tenia aux(a)
        a++;
        b++;
    }
}


void _map(void* vec, unsigned* ce, unsigned tam, void accion(void*))
{
    int i;
    for(i = 0; i< *ce;i++ )
    {
        accion(vec); // va a mandar la posicion de memoria a la que se encuentra aputando el vector
        vec += tam;
    }
}

void imprimirInt(void* vec)
{
    printf("%d ", *(int*)vec);
}

void MultiplicarInt(void* vec)
{
    *(int*)vec *= 2;
}


void* _filter(void* vec, unsigned* ce, unsigned tam, int filtro(const void*)) //0 si se va 1 si se queda
{
    int i;
    void* pl = vec;
    void* pe = vec;
    unsigned ceInterna = *ce;
    for(i = 0; i < *ce; i++)
    {
        if(filtro(pl))
        {
            if(pe!= pl)
            {
                memcpy(pe,pl,tam);
            }
            pe+=tam;
        }
        else
        {
            ceInterna--;
        }
        pl += tam;
    }
    *ce = ceInterna;
    return vec;
}

int filtroInt(const void* vec)
{
    if(*(int *)vec > 10)
        return 1;
    else
        return 0;
}

void* _memmove(void* dest, void* src, unsigned tam)
{
    char* chard= (char*)dest;
    char* chars = (char*)src;
    if(dest <= src)
    {
        while(tam--)
            *chard++ = *chars++;
    }
    else
    {
        chard += tam-1;
        chars += tam-1;
        while(tam--)
            *chard-- = *chars--;
    }
    return dest;
}

