#include "parcial.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/*Cifrado césar consonántico
En el siguiente ejercicio utilizaremos el cifrado cesar "consonántico". El cifrado Cesar es un
tipo de cifrado por sustitución en el que una letra en el texto original es reemplazada por
otra letra que se encuentra un número fijo de posiciones más adelante en el alfabeto.
“Consonántico” se refiere a que solo las consonantes serán reemplazadas en el alfabeto
sin las vocales. Por ejemplo, con un desplazamiento de 3, la B sería sustituida por la F (
situada 3 lugares a la derecha sin contar la E).
Escriba una función que lea un archivo de texto que contenga el desplazamiento y la frase
a cifrar separados por una coma, y luego escriba un nuevo archivo con el desplazamiento y
la frase cifrada.
Ejemplo de entrada:
3, Arriba la birra.
Ejemplo de salida:
3, Avvifa pa fivva.
NOTAS:
• Tenga en cuenta el correcto uso de punteros y memoria.
• Tenga en cuenta el correcto uso de funciones.
• Tenga en cuenta que el alfabeto no incluye "Ñ", "LL" ni "CH".*/

int leerArchTexto(const char* arch, char* frase, int* des)
{
    FILE* archTexto;
    archTexto = fopen(arch, "r");
    char linea[TAM_LINEA];
    if(!archTexto)
    {
        printf("\nNo se pudo abrir el archivo");
        return 0;
    }
    while(fgets(linea,sizeof(linea),archTexto))
    {
        char* actual = linea;
        actual = strrchr(linea, '|');
        strcpy(frase,actual +1);
        *actual = '\0';
        sscanf(linea , "%d", des);
    }
    fclose(archTexto);
    return 1;
}

char* ofuscar(char* cad, int* des)
{
    char* cadOfus = cad;
    char grupo[] = {"bcdfghjklmnpqrstvwxyz"};
    char* posEncontrado;
    int desplazamiento;

    while(*cad)
    {
        if(ESLETRA(*cad)) // si no es espacio
        {
            posEncontrado = strchr(grupo,AMINUS(*cad)); // busco el caracter en el grupo de consonantes
            if(posEncontrado != NULL) //si NO es NULL (NULL = no lo encontro), entro al bucle
                {
                    if(((posEncontrado - grupo) + *des) < strlen(grupo) ) // si la posicion donde se encontro mas el desplazamiento que nos pasaron es menor que el tamaño de grupo
                        *cad = *(posEncontrado + *des); // a lo que apunta el puntero de cadenaOfus sera reemplazado por lo que hay en la posicion de memoria de posEncontrado +3
                    else //si posEncontra + desplazamiento es mayor que strlen grupo. Significa que llegamos al final del vector grupo, por ende debemos contar desde donde nos quedamos
                        {
                            desplazamiento = (posEncontrado -grupo + *des) % strlen(grupo); //por ej: posEncontra = 22 + 3 = 25 < 22 ? NO,entonces hacemos el calculo de esta linea
                            *cad = *(grupo + desplazamiento); //movemos el puntero para que apunte a posEncotnrado + el desplazamiento
                        }

                }
        }
        cad++;
    }
    return cadOfus;
}


int escribirArchOfus(const char* arch, char* frase, int* des)
{
    FILE* archText = fopen(arch, "w");
    if(!archText)
    {
        printf("\nERROR AL ABRIR");
        return 0;
    }
    fprintf(archText,"%d| %s", *des, frase);
    fclose(archText);
    return 1;
}


//OTRO MODELO DE PARCIAL

/*Realice una función que reciba por parámetro una matriz (máximo 100 Filas y 100
columnas), la cantidad de filas y columnas reales y que realice lo siguiente:
-Recorra y muestre los elementos que conformarían la "Z" de la matriz.*/
void recorrerZ(int mat[][MAX_COL], int f, int c)
{
    int i,j;

    for(i=0;i<f;i++)
    {
        if((i==0)||(i==(f-1)))
        {
            for(j=0;j<c;j++)
            {
                printf("%d", mat[i][j]);
            }
            j--;
        }
        else
        {
            j--;
            printf("%d", mat[i][j]);
        }
    }
}
//OTRO EJERCICIO DE PARCIAL QUE PEDIA RECORRER EN N LA MATRIZ (no me sale perfecto, y prefiero practicar otras cosas)

void recorrerN(int mat[][MAX_COL], int f, int c)
{
    int i, j;
    for(j =0; j<c ; j++)
    {
        if((j==0)|| (j == c-1))
        {
            for(i = f-1; i >-1; i--)
            {
                printf("%d",mat[i][j]);
            }
            i++;
        }
        else
        {
            printf("%d", mat[i][j]);
            i++;
        }
    }
}


//RECORRER MATRIZ TRIANGULO SUPERIOR MEDIO, (me salio a la primera, voy a llorar)

void trianguloSuperior(int mat[][MAX_COL], int f, int c)
{
    int i,j;
    for(i = 0; i< f-i; i++)
    {
        for(j=0+i; j< c-i; j++)
        {
            printf("%d", mat[i][j]);
        }
        printf("\n");
    }
}


//PARCIAL MARTES TURNO TARDE PABLO SOLIGO 18/6/2024


char* str_cat( char* s1, const char* s2)
{
    while(*s1)
    {
        s1++; // vamos al final de la cadena
    }
    *s1 = ' ';
    s1++;
    while(*s2)
    {
        *s1= *s2;
        s2++;
        s1++;
    }
    *s1 = '\0';
    return s1;
}

int sumTrianInfEntreDiag(int mat[][MAX_COL], int fc){
    int i,j;
    int k=0,t=fc-1;
    int suma = 0;

    for(i= fc-1; i>fc/2;i--){
        for(j=k+1; j < t; j++){
            suma+=mat[i][j];
        }
        k++;
        t--;
        puts("");
    }


    return suma;
}

void qsort_m(void *base, unsigned nmemb, unsigned tamanyo, int (*comparar)(const void*, const void*)) {
    size_t i, j;
    char *menor = (char *)base; // Puntero para el elemento menor
    char *ini = (char *)base;   // Puntero al inicio del array

    for (i = 0; i < nmemb - 1; i++) {
        menor = ini + i * tamanyo; // Establecer el menor como el elemento actual

        for (j = i + 1; j < nmemb; j++) {
            char *curr = ini + j * tamanyo; // Puntero al elemento actual en el ciclo

            if (comparar(curr, menor) < 0) { // Verificar si el elemento actual es menor que el menor encontrado hasta ahora
                menor = curr; // Actualizar el menor encontrado
            }
        }

        if (menor != (ini + i * tamanyo)) { // Si encontramos un menor diferente al actual, intercambiarlos
            intercambioGenerica1(menor, ini + i * tamanyo, tamanyo);
        }
    }
}
void intercambioGenerica1(void* dato1, void* dato2, unsigned tam)
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

int compararInt(const void* a, const void* b)
{
    int* pa = (int*)a;
    int* pb = (int*)b;
    return *pa - *pb;
}

char* m_strchr(const char* oracion, int c)
{
    while(*oracion)
    {
        if(*oracion == (unsigned char)c)
            return (char*) oracion;
        oracion++;
    }
    return NULL;
}


// Qsort




int trianguloDerecha(int Mat[][MAX_COL], int f, int c) {
    int i, j = 0; // Inicializamos j aquí
    int sum = 0;
    for(i = 0; (i < c) && (j < f); i++) {
        sum += Mat[j][i]; // Suma correcta de los elementos
        j++; // Incremento de j dentro del bucle
    }
    return sum;
}


