#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesP.h"
#define A 20

int main()
{
    xCliente cliente[A];
    xAuto autos[A];
    xPrecios precio[A];
    int opcion;
    int seguir='s';
    inicializarAutos(autos,A);
    inicializarCliente(cliente,A);
    inicializarPrecios(precio,A);

    while(seguir=='s')
    {
        printf("================================================================================\n");
        printf("\n1- Alta de cliente.\n");
        printf("2- Modificacion del cliente.\n");
        printf("3- Ingreso del automovil.\n");
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
            altasCliente(cliente,A);

            break;
        case 2:
            modificar(cliente,A);
            break;
        case 3:
            ingreso(autos,cliente,A);
            break;
        case 4:
            egreso(autos,cliente,precio,A);
            break;
        case 5:
            graficar(autos,cliente,precio,A);
            break;
        case 6:
            seguir = 'n';
            break;
        }
    }



}
