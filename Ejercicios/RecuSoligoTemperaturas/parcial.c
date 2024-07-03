#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parcial.h"



int abrirArch(const char* nombre, sPromedio* vec, int ce)
{
    char linea[40];
    sSensor sensor;
    int numSen = 0;
    FILE* arch = fopen(nombre, "rt");
    if(!arch)
    {
        printf("\nError al abrir el archivo de temp");
        return 0;
    }

    while(fgets(linea, sizeof(linea), arch))
    {
        sscanf(linea,"%12d%8s%6f%12s", &sensor.fecha, sensor.cod, &sensor.temp, sensor.estado);

            int index = buscarSensor(vec,ce, sensor.cod);
            if(index == -1)
            {

                strcpy((vec + numSen)->cod, sensor.cod);
                strcpy((vec+numSen)->estado, sensor.estado);
                if(strcmp(sensor.estado,"READY") == 0)
                {
                    (vec + numSen)->total += 1;
                    (vec + numSen)->promedio += sensor.temp;
                }
                numSen++;

            }
            else
            {
                (vec + index)->promedio += sensor.temp;
                (vec+index)->total ++;
            }
    }
    fclose(arch);
    return numSen;
}


int buscarSensor(sPromedio* vec, int ce, const char* cod)
{
    int i;
    int pos = -1;
    while(pos == -1 && i < ce)
    {
        if(strcmp((vec + i)->cod, cod) == 0)
            pos = i;
        else
            i++;
    }
    return pos;
}




void ordSeleccion(void* vec, unsigned ce, unsigned tamDato, int cmp(const void*, const void*))
{
    void* mayor = (char*)vec;
    int i, j;
    for(i = 0; i < ce; i++)
    {
        for(j = 1 + i; j < ce; j++)
        {
            mayor = (char*)vec + i *tamDato;
            char* actual = (char*)vec + j * tamDato;
            if(cmp(actual,mayor) < 0) //si mayor es menor que actual va a ser mayor que 0
            {
                swap_ (mayor, actual, tamDato);
            }

        }
    }
}

 int generic_partition(void *v, int i, int f, size_t size,int (*comp)(const void *, const void *))
{
    unsigned char *p = (unsigned char *)v;
    int j, k = i;
    // using first element as pivot

    for (j = i + 1; j < f; j++)
    {
        if (comp(p + j * size, p + i * size) <= 0)
        {
            k++;
            swap_(p + k * size, p + j * size, size);
        }
    }
    /* swap the pivot to the end of the left part */
    swap_(p + i * size, p + k * size, size);
    return k;
}

void myqsort(void *v, int i, int f, size_t size,int (*comp)(const void *, const void *))
{
    while (f > i + 1)
        {
            int p = generic_partition(v, i, f, size, comp);
            if (p - i < f - p)
            {
                myqsort(v, i, p, size, comp);
                i = p + 1;
            }
            else
            {
                myqsort(v, p + 1, f, size, comp);
                f = p;
            }
        }
}

void swap_(void *a, void* b, unsigned tamDato)
{
    char* va = (char*)a;
    char* vb = (char*)b;
    char temp;
    while(tamDato--)
    {
        temp = *va;
        *va = *vb;
        *vb = temp;
        va++;
        vb++;
    }
}

int cmpChar(const void* a, const void* b)
{
    sPromedio* sa = (sPromedio*)a;
    sPromedio* sb = (sPromedio*)b;
    return strcmpi(sa->cod, sb->cod);
}



int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}




void q(void* vec, int i, int f, unsigned tam, int cmp(const void*, const void*))
{
    while(f > i+1)
    {
        int p = pa(vec, i, f, tam, cmp);
        if(p-i < f-p)
        {
            q(vec,i,p,tam, cmp);
            i = p+1;
        }
        else
        {
            q(vec, p-1, f, tam,cmp);
            f=p;
        }
    }
}

int pa(void* vec, int i, int f, unsigned tam, int cmp(const void*, const void*))
{
    unsigned char* p= (unsigned char*)vec;
    int j, k = i;
    for(j = i+1; j < f; j++)
    {
        if(cmp(p+j * tam, p+i * tam) <= 0)
        {
            k++;
            swap_(p+k * tam, p+j * tam, tam);
        }
    }
    swap_(p+i * tam, p+k * tam, tam);
    return k;
}


int cmp(const void *n1, const void *n2){
    int n = *((int *)n2);
    return *((int *)n1) - *((int *)n2);
}


void* binarySearchArr(void *iniVec, size_t ce, size_t tamDatos, void *datoAcomparar, int cmp(const void *, const void*)){
    void *mitad = iniVec + (ce/2) * tamDatos;
    int n = *((int *)mitad);
    if(cmp(mitad, datoAcomparar) == 0)
            return mitad;
    if(iniVec < mitad)
    {
        if(cmp(mitad, datoAcomparar) < 0)
            return binarySearchArr(mitad + tamDatos, ce/2, tamDatos, datoAcomparar, cmp);
        else
            return binarySearchArr(iniVec, ce/2, tamDatos, datoAcomparar, cmp);
    }
    return NULL;
}
