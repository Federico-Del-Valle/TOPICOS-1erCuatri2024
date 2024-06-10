#include "func_Arch.h"
#include <stdio.h>
#include <stdlib.h>



int crearArch()
{
    int i;
    sEstudiante vec[5] = {{43316258, "Federico Del Valle", 7.5},
                          {45684444, "Pedro Melissari", 10},
                          {47433222, "Yesmina Veron", 8},
                          {50433211, "Lionel Messi", 10},
                          {3923329, "Stephen Curry", 30}};
    FILE* arch;
    arch = fopen("Estudiantes.dat", "wb");
    if(!arch)
    {
        printf("\nERROR");
        return 0;
    }
    for(i = 0; i< 5; i++ )
    {
        fwrite(&vec[i], sizeof(sEstudiante),1,arch);
    }
    fclose(arch);
    return 1;
}


void leerArch(char * arch, char* texto)
{
    FILE *archEstudiantes;
    sEstudiante estudiante;
    sEstudiante* punteroE = &estudiante;
    archEstudiantes = fopen(arch, "rb");
    FILE *archTexto;
    archTexto= fopen(texto, "w");

    fread(punteroE, sizeof(sEstudiante),1,archEstudiantes);
    while(!feof(archEstudiantes))
    {
        fprintf(archTexto,"%d | %-20s | %f\n", punteroE->leg, punteroE->nombre, punteroE->promedio);
        fread(punteroE,sizeof(sEstudiante),1,archEstudiantes);

    }
    fclose(archEstudiantes);
    fclose(archTexto);
}


/*void crearArch(char *archBinario, char* archTexto)
{
    sEstudiante estudiante;
    sNovedades novedad;
    FILE* archTmp;
    archTmp = fopen("Temporal.dat", "wb");
    FILE* archEstudiantes;
    archEstudiantes = fopen(archBinario, "rb");
    FILE* archNovedades;
    archNovedades = fopen(archTexto, "r");

    fread(&estudiante, sizeof(sEstudiante),1,archEstudiantes);
    fscanf()

}*/


