#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define A 20

int main()
{
    char seguir='s';
    int opcion=0;
    int posicion;
    xPersona personas[A];
    inicializarPersona(personas,A);


    while(seguir=='s')
    {
        printf("================================================================================\n");
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n\nopcion:");

        scanf("%d",&opcion);
        while(opcion>5)
        {
            printf("================================================================================\n");
            printf("reingrese una opcion valida:\nopcion:");
            scanf("%d",&opcion);
            printf("================================================================================\n");

        }

        switch(opcion)
        {
        case 1:
            posicion = buscarEspacio(autos,A);
            if(posicion!=-1)
            {
                preguntas(autos,A);
            }
            else
            {
                printf("================================================================================\n");
                printf("No hay espacio disponible!");
            }
            break;
        case 2:
            eliminarPersona(personas,A);
            break;
        case 3:
            listaPersonas(personas,A);
            mostrarPersonas(personas,A);

            break;
        case 4:
            graficar(personas,A);
            break;
        case 5:
            seguir = 'n';
            break;
        }
    }

    return 0;
}
