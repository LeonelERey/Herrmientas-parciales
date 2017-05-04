#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "para el parcial.h"

void inicializarAutos(xAutos autos[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        {
            autos[i].estado=0;
        }
    }
}
int buscarEspacio(xAutos espacio[],int tam)
{
    int lugar = -1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(espacio[i].estado==0)
        {
            lugar = i;
            break;
        }
    }
    return lugar;
}
void mostrarAuto(xAutos autos)
{
    printf("================================================================================\n");
    printf("\n%s\t\t\t%d\t%d\t%d\n\n", autos.patente, autos.marca, autos.modelo,autos.profesor);
}
void altas (xAutos autos[],int tam)
{
    int i;
    int flagLugar;
    int opcion;
    int posicion;

           posicion=buscarEspacio(autos,tam);
    if(posicion!=-1)
        {

    for(i=0; i<tam; i++)
    {
        printf("================================================================================\n");
        printf("ingrese la patente del vehiculo:");
        fflush(stdin);
        gets(autos[i].patente);
        printf("================================================================================\n");
        printf("ingrese la marca:\n");
        printf("================================================================================\n");

        printf("\n1- fiat\n");
        printf("2- ford\n");
        printf("3- peugeot\n");
        printf("4- chevrolet\n\nopcion:");

        scanf("%d",&autos[i].marca);
        while(autos[i].marca>4)
        {
            printf("================================================================================\n");
            printf("reingrese una opcion valida:\nopcion:");
            scanf("%d",&autos[i].marca);
            printf("================================================================================\n");

        }

        switch(autos[i].marca>4)
        {
        case 1:
            printf("usted eligio fiat.\n");
            break;
        case 2:
            printf("usted eligio ford.\n");
            break;
        case 3:
            printf("usted eligio peugeot.\n");
            break;
        case 4:
            printf("usted eligio chevrolet.\n");
            break;
        }
        printf("================================================================================\n");
        printf("ingrese el modelo del auto:");
        scanf("%d", &autos[i].modelo);
        while(autos[i].modelo<1900||autos[i].modelo>2017)
        {
            printf("================================================================================\n");
            printf("ingrese el modelo del auto mayor a 1900 y menor a 2017:");
            scanf("%d", &autos[i].modelo);
        }

        printf("================================================================================\n");
        printf("ingrese el id del profesor q usa el auto:");
        scanf("%d", &autos[i].profesor);
        autos[i].estado=1;

        mostrarAuto(autos[i]);
        break;
    }
        }
        else
        {
            printf("================================================================================\n");
            printf("No hay mas espacio disponible!\n");
        }


}

