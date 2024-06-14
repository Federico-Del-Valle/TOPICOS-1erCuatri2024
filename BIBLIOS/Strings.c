#include "Strings.h"
#include <stdio.h>
#include <string.h>


//unsigned m

int mstrlen(const char* oracion)
{
    const char* pt = oracion;
    int cant =0;
    while(*pt != '\0')
    {
        if(ESLETRA(*pt) == 1)
        {
            cant++;
        }
        pt++;
    }
    return cant;
}

//COPIA UN STRING

char* mstrcpy(char* dest, const char* src)
{
    char* cad = dest;
    while(*src)
    {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
    return cad;
}

// STRING COMPARE

int mstrcmp(const char* oracion1, const char* oracion2)
{
    const char* pt1 = oracion1;
    const char* pt2 = oracion2;
    while(*pt1 && (*pt1 == *pt2))
    {
        pt1++;
        pt2++;
    }
    return *(unsigned char*)pt1 - *(unsigned char*)pt2;
}


//A una cadena le agrega otra palabra o frase

char* mstrcat(char* cadena,const char* concat )
{
    while(*cadena)
        cadena++;//nos posicionamos al final de la cadena
    *cadena = ' ';
    cadena++;
    while(*concat)
    {
        *cadena = *concat;
        concat++;
        cadena++;
    }
    *cadena = '\0';
    return cadena;
}

//Funcion que cuenta la cantidad de veces que aparece una palabra (cambia todo a minus, si no queres que funcione asi, sacale la macro crack ;)  )

int contarAparicionesDeUnaPalabra(const char* cad, const char* pal)
{
    int cont =0, contPal = 0;
    const char* ptrpal = pal;
    int cantLetras = mstrlen(pal);
    while(*cad)
    {
        if(AMINUSC(*cad) == AMINUSC(*pal))
        {
            cont++;
            pal++;
        }
        else
        {
            cont = 0;
            pal = ptrpal;
        }
        if(cont == cantLetras)
            contPal++;
        cad++;
    }
    return contPal;
}

//FUNCION QUE DE VUELTA UN STRING
void invertirCad(char* cad)
{
    char* finCad = cad;
    char temp;
    finCad += strlen(cad) -1; //apunta al ultimo elemento de la cadena
    while(finCad > cad)
    {
        temp = *cad;
        *cad = *finCad;
        *finCad = temp;
        finCad--;
        cad++;
    }
}

//Normalizar oracion por ej=  "LA viDa Es  uNA    pOrQUEriA", normalizada = "La Vida Es Una Porqueria"
void normalizarOracion(char* cad)
{
    int first = 1;
    char* cadNor = cad;
    while(*cadNor)
    {
        if(first)
        {
            *cad = AMAYUS(*cadNor);
            first = 0;
            cad++;
            cadNor++;
        }
        while(*cadNor != ' ' && *cadNor)
        {
            *cad = AMINUSC(*cadNor);
            cad++;
            cadNor++;
        }
        while(*cadNor == ' ')
            cadNor++;
        if(*cadNor)
        {
            *cad = ' ';
            cad++;
            first=1;
        }
    }
    *cad = '\0';
}


/*int cmp(const void* a, const void* b)
{
    return *((int*) a) - *((int*)b);
}*/

int esLetra1(char letra) {
    int r;
    r = (letra >= 'A' && letra <= 'Z') || (letra >= 'a' && letra <= 'z')?1:0;
    return r;
}


int proximaPalabra1(const char* cad, char** pini, char** pfin) { // Busca todas las palabras de la cadena hasta que se encuentra con el \0
    char *plect, *pfin_aux = (*pfin) + 1;
    int f = 1, reg = 1, cont = 0;
    if(!(*pfin_aux))
        {
            plect = *pini;
        } // acá se verifica si anteriormente ya se ejecutó la fn con la cadena en cuestión (ya que en la primer llamada ' *pfin ' apuntará al final ('\0') de la cadena-frase, caso contrario será cualquier otro char), por lo tanto si: 1) es la primera vez que se llama, plect (puntero de lectura) deberá comenzar a recorrer desde el comienzo de la frase, *pini tendrá la dir del inicio de la cadena que debemos asignarle a aquél puntero (plect); 2) en caso de que anteriormente ya se haya reconocido una palabra, entonces plect debe retomar desde la instancia siguiente al último caracter de tal última palabra
    else
        {
            plect = (*pfin) + 1;
        } // j servirá para indicar próximamente a *pini dónde comienza la próxima palabra luego de la primer llamada a la fn.
    while((*plect) && reg)
        { // reg: en complemento con ' f ', quien delimita el comienzo de una palabra, reg se encargará de determinar el fin de la misma.; el término (*plect) se encargará de definir a nivel frase cuándo es que se termina el string, osea, al detectar un ' \0 '
            if(esLetra1(*plect))
            {
                if(f)
                    {
                        *pini = plect;
                    } // guardamos la primer instancia reconocida de la palabra (una vez que ' f ' se desactive, *pini se establecerá en el inicio de la misma)
                plect++;
                cont++;
                f = 0;
            }
            else
                { // al no ser letra el caracter tenemos dos contextos: o bien puede ser que efectivamente haya terminado la extensión de la palabra (ya que se presenta un espacio, coma, signo, etc.), o bien que todavía no se haya detectado el incio de una palabra, por lo tanto deberíamos seguir recorriendo
                    if(f == 0)
                        {
                            reg = 0; *pfin = plect - 1;
                        } // entonces, como ' f ' nos indica que ya se inició una palabra, y la línea 38 deriva que el actual caracter no es letra, podemos concluir en que finalizó la extensión de la palabra; ya que el actual caracter no es letra, corresponde ajustar el puntero pfin a la instancia anterior de plect
                    else
                        {
                            plect++;
                        } // caso contrario, el actual caracter no es letra pero de igual manera no se inició ninguna secuencia de palabra, por lo tanto seguimos recorriendo
            }
        }
    if(!(*plect))
        {
            *pfin = plect - 1;
        } // esta línea ajusta el *pfin de la última palabra de la frase, ya que si por ej. aquella no es precedida por otro caracter no considerado letra (como lo puede ser un punto, espacio, signo, etc.), debido a la condición del while automáticamente finaliza el proceso, no pasando por la línea 47 que delimita dicho puntero en cuestión
    return cont;
}


//Otra forma de normalizar oracion, pero con el uso de proxima palabra
char* normalizarPalabra(char* cad)
{
    char *inicio = cad, *fin = cad;
    char *dest = cad;  // Puntero de destino para la cadena normalizada
    int primeraLetra = 1;

    while (*cad) {
        while (*cad && !ESLETRA(*cad)) {
            cad++;
        }
        if (*cad == '\0') {
            break;
        }
        int cantPalabras = proximaPalabra1(cad, &inicio, &fin);

        if (cantPalabras > 0)
            {
                if (primeraLetra)
                {
                    *dest = AMAYUS(*inicio);
                    primeraLetra = 0;
                }
                else
                    {
                        *dest = ' ';
                        dest++;
                        *dest = AMAYUS(*inicio);
                    }
                    dest++;
                for (int i = 1; i < cantPalabras; i++)
                    {
                        *dest = AMINUSC(*(inicio + i));
                        dest++;
                    }
                cad = fin + 1;
            }
    }
    *dest = '\0';
}


/*Ejercicio 1.10
La siguiente línea “Nj qemh v ljs kraenkqbres; lj oqe qemh es oqevorme sgn ellhs --Istqt Asdmgj” ha
sido ofuscada para impedir su lectura desplazando desplazado hacia atrás dentro del grupo
"abcdghijkoqtuv" tantos caracteres como posición tiene en la palabra.
Ejemplo, si la palabra es “hola”
● "h":un lugar atrás porque es la primera letra de la palabra, queda "g"
● "o":dos lugares atrás, queda "j"
● "l":No figura en grupo, no se modifica, queda "l"
● "a":cuatro lugares hacia atrás, queda "q", antes de la “a” está la “v”.
Quedando una vez ofuscada como “gjlq”.
● No considere ningún carácter que no figura dentro del grupo
● Una palabra es todo conjunto de uno o mas caracteres que responden a la función isalpha
● La frase desofuscada esta en Español.*/


//Busca un caracter en un string

char* mstrchr(const char* oracion, int c) {
    while (*oracion) {
        if (*oracion == (char)c)
            return (char*)oracion;
        oracion++;
    }
    return NULL;
}

char* desofuscarSinProximaPalabra(char* cad)
{
    char grupo[] = "abcdghijkoqtuv";
    char* cadenaOriginal= cad;
    char* posEncontrado;
    int pos = 1, desplazamiento;

    while(*cad)
    {
        if(!ESLETRA(*cad))
        {
           pos = 0;
        }
        posEncontrado = mstrchr(grupo,*cad);
        if(posEncontrado!= NULL)
        {
            if(posEncontrado - grupo + pos < strlen(grupo))
                *cad = *(posEncontrado + pos);
            else
            {
                desplazamiento = (posEncontrado - grupo + pos) % strlen(grupo);
                *cad = *(grupo+ desplazamiento);
            }
        }
        cad++;
        pos++;
    }
    return cadenaOriginal;
}

