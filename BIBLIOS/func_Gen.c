#include "func_Gen.h"
#include <stdio.h>
#include <string.h>
#include <stddef.h>



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



int reemplazar(int cambio, void *menor, void *siguiente, void *fin, size_t tam, int cmp(const void*, const void*), void intercambiar(void*, void*, size_t)) {
        siguiente += tam; // Esta l nea se podr a implementar tranquilamente en ' ordSelec ', simplemente ajusta el puntero ' siguiente ' propiamente a la instancia posterior a ' menor '
        if((siguiente <= fin) && (cmp(menor, siguiente) > 0))
            { // Controlamos operar dentro de lo establecido y ya comenzamos a comparar campos/valores entre un par de elementos del array. [convenci n de retornos para ' cmp ': si ' menor ' > ' siguiente ' => r > 0 ; si ' menor ' < ' siguiente ' => r < 0; si ' menor ' == ' siguiente ' => r = 0]
                intercambiar(menor, siguiente, tam); // En caso de que corresponda, efectuamos intercambio gen rico
                cambio++; // Indicamos que hubo una modificaci n
                cambio = reemplazar(cambio, menor, siguiente, fin, tam, cmp, intercambiar);
            } // Iteramos nuevamente, verificando si el siguiente par de elementos, almacenados en ' menor ' y ' siguiente ' (no necesariamente adyacentes, sino respectivos a la  ltima instancia ejecutada), requieren ser intercambiados; mismas reglas, caso positivo (y estando todo en orden, es decir, que el puntero ' siguiente ' no haya excedido el fin del arreglo), entonces se efect a el cambio y repetimos el proceso
        else
            {
                if(siguiente < fin)
                {
                    cambio = reemplazar(cambio, menor, siguiente, fin, tam, cmp, intercambiar);
                }
            } // Esta l nea es el enlace para aquellos casos en que no se haya producido un cambio en el  ltimo par dado, pero quiz  queden m s casos por comparar (y hasta sean de relevancia), a su vez verificando si llegamos a la  ltima instancia (el  ltimo par) de comparaci n de acuerdo al alcance que tiene el vector enviado, en caso de tener margen a n, seguimos iterando
        return cambio;
}

void swap1(void *va, void *vb, size_t s) {
    char *a = (char *)va, *b = (char *)vb;
    while (s--) {
        char t = *a;   // Guardar el byte actual de 'a' en 't'
        *a = *b;      // Copiar el byte actual de 'b' en 'a'
        *b = t;       // Copiar el byte de 't' en 'b'
        a++;          // Avanzar al siguiente byte en 'a'
        b++;          // Avanzar al siguiente byte en 'b'
    }
}

void ordSelec(void *vec, size_t ce, size_t tam, int cmp(const void *, const void *)) {
    size_t i, j;
    char *menor = (char *)vec; // Puntero para el elemento menor
    char *ini = (char *)vec;   // Puntero al inicio del array

    for (i = 0; i < ce - 1; i++) {
        menor = ini + i * tam; // Establecer el menor como el elemento actual

        for (j = i + 1; j < ce; j++) {
            char *curr = ini + j * tam; // Puntero al elemento actual en el ciclo

            if (cmp(curr, menor) < 0) { // Verificar si el elemento actual es menor que el menor encontrado hasta ahora
                menor = curr; // Actualizar el menor encontrado
            }
        }

        if (menor != (ini + i * tam)) { // Si encontramos un menor diferente al actual, intercambiarlos
            swap1(menor, ini + i * tam, tam);
        }
    }
}

int cmpAlumno(const void *a, const void *b)
{
    const Alumno *ia = (const Alumno *)a;
    const Alumno *ib = (const Alumno *)b;
    return strcmp(ia->nombreyape, ib->nombreyape);
}

int cmp(const void *a, const void *b) {
    const Item *ia = (const Item *)a;
    const Item *ib = (const Item *)b;
    return (ia->id - ib->id);
}


