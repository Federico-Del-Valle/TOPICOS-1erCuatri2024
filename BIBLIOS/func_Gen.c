#include "func_Gen.h"
#include <stdio.h>
#include<stdlib.h>
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

void* mem_cpy(void* dest, void* src, unsigned tam)
{
    char* origen = (char*)src;
    char* destino = (char*)dest;
    int i;
    for(i = 0; i < tam; i++)
    {
        *destino = *origen;
        origen++;
        destino++;
    }
    return dest;
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

void mostrarPersona(sPersona* vec, int tam) {
    printf("\n%8s  %-20s  %-20s  %-4s\n", "DNI", "Apellido", "Nombre", "Peso");
    for (int i = 0; i < tam; i++) {
        printf("%8d  %-20s  %-20s  %-.2f\n", (vec + i)->dni, (vec + i)->apellido, (vec + i)->nombres, (vec + i)->peso);
    }
    printf("\n");
}

int compararNombre(const void* a, const void* b)
{
    sPersona* personaA = (sPersona*)a;
    sPersona* personaB = (sPersona*)b;
    return strcmpi(personaA->nombres, personaB ->nombres);
}

/*Ejercicio 3.15
Desarrolle una función de intercambio genérica tal que pueda intercambiar 2 bloques de información
de manera independiente al tipo de dato. No utilice memoria dinámica.
*/

void intercambioGenerica(void* dato1, void* dato2, unsigned tam)
{
    char* valor1 = (char*)dato1;
    char* valor2 = (char*)dato2;
    char temp;
    while(tam--)
    {
        temp = *valor1;
        *valor1 = *valor2;
        *valor2 = temp;
        valor1++;
        valor2++;
    }
}


/*Desarrolle una función genérica que encuentre el menor elemento dentro de un vector. Verifique su
funcionamiento encontrando el menor entero, el menor flotante, y el menor alumno (Por DNI,
nombre y apellido o promedio). La función retornará la dirección del elemento menor*/

void* menorElementoGenerico(void* v, unsigned tam, unsigned ce, int cmpMenor(const void* a, const void* b))
{
    int i;
    char* ini = (char*)v;
    char* menor = (char*)v;
    char* curr;
    for(i=0; i< ce; i++)
    {
        curr = ini+i *tam;

        if(cmpMenor(curr, menor)< 0)
        {
            menor = curr;
        }
    }
    return menor;
}

int cmpDNI(const void* a, const void* b)
{
    // Convertimos los parámetros a sPersona*
    const sPersona* personaA = (const sPersona*)a;
    const sPersona* personaB = (const sPersona*)b;

    // Comparación por DNI
    return personaA->dni - personaB->dni;
}

int cmpChar(const void* a, const void* b)
{
    const char chara = *(const char*)a;
    const char charb = *(const char*)b;
    if(chara > charb)
        return 1;
    if(chara < charb)
        return -1;
    return 0;
}

/*Ordenamiento genérico - Desarrolle una función genérica que ordene un vector. Puede ayudarse con
las funciones intercambio y buscar menor desarrolladas en ejercicios anteriores e implementar un
algoritmo de selección.
*/
void ordSelec(void *vec, size_t ce, size_t tam, int cmp(const void *, const void *))
{
    size_t i, j;
    char *menor = (char *)vec; // Puntero para el elemento menor
    char *ini = (char *)vec;   // Puntero al inicio del array

    for (i = 0; i < ce - 1; i++)
        {
            menor = ini + i * tam; // Establecer el menor como el elemento actual

            for (j = i + 1; j < ce; j++)
                {
                    char *curr = ini + j * tam; // Puntero al elemento actual en el ciclo

                    if (cmp(curr, menor) < 0) // Verificar si el elemento actual es menor que el menor encontrado hasta ahora
                        menor = curr; // Actualizar el menor encontrado
                }

            if (menor != (ini + i * tam)) // Si encontramos un menor diferente al actual, intercambiarlos
                intercambioGenerica(ini + i *tam, menor, tam);
        }
}


/*Desarrolle una función genérica que permita insertar de forma ordenada un elemento en un vector.
Puede ayudarse, usando como patrón, la versión no genérica desarrollada y probada de la práctica 1
y con las funciones de biblioteca memcpy y memmove.*/

unsigned insertarOrdenadoFede(void* vec, unsigned* ce, unsigned tamdato, unsigned tamvec, void* elem, int cmp(const void*, const void*))
{
    void* ini = vec;
    void* fin = vec + ((*(ce) * tamdato)- tamdato); //apunto al ultimo elemento del vector

    if (*ce == 0)
    {
        memcpy(vec, elem, tamdato);
        (*ce)++;
        return *ce;
    }
    while((cmp(fin, elem) > 0) && fin >= ini)
    {
        memmove((fin+ tamdato), fin, tamdato );
        fin -= tamdato;
    }
    if(*(ce) < tamvec)
    {
        (*ce)++;
    }
    memcpy((fin+tamdato), elem, tamdato);
    return *ce;
}

int cmpInt(const void* a, const void* b) {
    int int_a = *(const int*)a;
    int int_b = *(const int*)b;
    return (int_a > int_b) - (int_a < int_b);
}


//Mi binary search. Busca un elemento en un array y retorna la posicion de memoria en donde se encuentra y null si no lo encontró

void *bsearch(const void *dato, const void *vec,  size_t ce, size_t tamdato, int (*comparar)(const void *, const void *))
{
    int ini = 0;
    int fin = ce -1;
    int mitad;
    char* posEncontrado;

    while(ini <= fin)
    {
        mitad = (ini + fin)/2;
        posEncontrado = (char*)vec+ mitad * tamdato;
        if(comparar(posEncontrado, dato) == 0)
        {
            return posEncontrado;
        }
        else
        {
            if(comparar(posEncontrado, dato) < 0)
                ini = mitad +1;
            else
                fin = mitad -1;
        }
    }
    return NULL; //si no lo encuentra
}

//funcion reduce

void* reduce(void* vec, unsigned tam, unsigned ce, void* funcion(void*, const void*), void* init)
{
    void* buffer = malloc(tam);
    if (!buffer)
    {
        return NULL;
    }
    memcpy(buffer, init, tam); // Copio el valor inicial en buffer

    for (unsigned i = 0; i < ce; i++)
    {
        funcion(buffer, vec + i * tam); // Paso el acumulador y el elemento actual
    }
    return buffer;
}

// Función que suma dos enteros
void* funcionSumar(void* a, const void* b)
{
    int* acc = (int*)a;
    *acc += *(const int*)b;
    return acc;
}


void ordSeleccionVoid(void *vec, size_t ce, size_t tam, int cmp(const void *, const void *)) // la estoy haciendo con fin didactico para que se vea que es lo mismo manejar con void o con char
{
    void* ini = vec;
    void* menor = vec;
    unsigned i,j;

    for(i = 0; i < ce; i++)
    {
        menor = ini + i * tam; //apunta al menor elemento del array
        for(j = i +1; j < ce; j ++)
        {
            if(cmp(menor, ini + j * tam) > 0)// si la cmp es mayor que 0 significa que el 2do parametro es menor que el primero por ende ahi que cambiarlos
            {
                menor = ini + j * tam;
            }
        }
        if(menor != ini+ i * tam)
        {
            intercambioGenerica(ini + i * tam, menor, tam);
        }
    }
}
