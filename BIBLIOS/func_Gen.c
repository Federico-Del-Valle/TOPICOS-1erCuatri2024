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

/*Desarrolle una función genérica que permita insertar de forma ordenada un elemento en un vector.
Puede ayudarse, usando como patrón, la versión no genérica desarrollada y probada de la práctica 1
y con las funciones de biblioteca memcpy y memmove.*/


//Esta funcion estuve una banda de tiempo en hacerla, me canse asi que le mande lo que habia hecho a chatgpt y me la termino de corregir. Habria que chequearla bien.
unsigned insertarOrdenado(void* vec, unsigned* ce, unsigned tamdato, unsigned tamvec, void* elem, int cmp(const void*, const void*)) {
    char* base = (char*)vec;
    int i = 0;
    char* insertPos;
    char* prox;

    // Verificar que no se exceda el tamaño del vector
    if (*ce >= tamvec) {
        return *ce; // No se puede insertar porque el vector está lleno
    }

    // Caso especial: Si el vector está vacío, simplemente insertar el elemento
    if (*ce == 0) {
        memcpy(vec, elem, tamdato);
        (*ce)++;
        return *ce;
    }

    // Encontrar la posición correcta para insertar el nuevo elemento
    while (i < *ce && cmp(base + i * tamdato, elem) < 0) {
        i++;
    }

    // Calcular la posición de inserción
    insertPos = base + i * tamdato;
    prox = insertPos + tamdato;

    // Mover los elementos a la derecha para hacer espacio para el nuevo elemento
    memmove(prox, insertPos, (*ce - i) * tamdato);

    // Copiar el nuevo elemento en su posición correcta
    memcpy(insertPos, elem, tamdato);

    // Incrementar el tamaño del vector
    (*ce)++;
    return *ce;
}
int cmpInt(const void* a, const void* b) {
    int int_a = *(const int*)a;
    int int_b = *(const int*)b;
    return (int_a > int_b) - (int_a < int_b);
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
                swap1(menor, ini + i * tam, tam);
        }
}


