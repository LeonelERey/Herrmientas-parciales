#include <stdio.h>
#include <stdlib.h>
#include "para el parcial.h"
#define A 1

int main()
{
    char seguir='s';
    int opcion=0;
    int posicion;
    int flagPreg=0;
    xAutos autos[A];
    inicializarAutos(autos,A);

   // inicializarPersona(personas,A);


    while(seguir=='s')
    {
        printf("================================================================================\n");
        printf("\n1- Alta de Automovil.\n");
        printf("2- Baja de Automovil.\n");
        printf("3- Ingreso del auto al Estacionamiento.\n");
        printf("4- Egreso del auto.\n");
        printf("5- informe.\n\n");
        printf("6- salir.\n\nopcion:");

        scanf("%d",&opcion);
        while(opcion>6)
        {
            printf("================================================================================\n");
            printf("reingrese una opcion valida:\nopcion:");
            scanf("%d",&opcion);
            printf("================================================================================\n");

        }

        switch(opcion)
        {
        case 1:

            altas (autos,A);
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:
            break;
        case 6:
            seguir = 'n';
            break;
        }
    }

}
