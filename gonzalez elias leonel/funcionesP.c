
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesP.h"

void inicializarAutos(xAuto autos[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        {
            autos[i].estado=0;
            autos[i].idCliente=-1;
            autos[i].marca=0;
        }
    }
}
void inicializarCliente(xCliente cliente[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        {
            cliente[i].estado=0;
        }
    }
}
void inicializarPrecios(xPrecios precios[],int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        {
            precios[i].FERRARY=0;
            precios[i].ALPHA_ROMEO=0;
            precios[i].AUDI=0;
            precios[i].OTRO=0;

        }
    }
}
int buscarEspacio(xAuto espacio[],int tam)
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
int buscarEspacioCliente(xCliente espacio[],int tam)
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
void mostrarAuto(xAuto autos)
{
    printf("================================================================================\n");
    printf("\n%s\t%d\t%d\t%d\n\n", autos.patente, autos.marca, autos.idCliente,autos.horaEntrada);
}
void mostrarCliente(xCliente cliente)
{
    printf("================================================================================\n");
    printf("\n%s %s\t%s\t%d\t%d\n\n", cliente.nombre, cliente.apellido, cliente.direccion,cliente.idCliente,cliente.tarjeta);
}


void altasCliente(xCliente cliente[],int tam)
{

    int i;
    int j;
    int posicion;
    int id;
    posicion=buscarEspacioCliente(cliente,tam);
    if(posicion!=-1)
    {

        for(i=0; i<tam; i++)
        {
            printf("================================================================================\n");
            printf("ingrese nombre del cliente:");
            fflush(stdin);
            gets(cliente[i].nombre);
            printf("================================================================================\n");
            printf("ingrese apellido del cliente:");
            fflush(stdin);
            gets(cliente[i].apellido);
            printf("================================================================================\n");
            printf("ingrese el id del cliente:");
            scanf("%d", &id);
            for(j=0; j<tam; j++)
            {
                while(cliente[j].idCliente==id)
                {
                    printf("================================================================================\n");
                    printf("esa id ya esta registrada\ningrese una id valida:");
                    scanf("%d",&cliente[i].idCliente);
                    printf("================================================================================\n");


                }
            }
            while(id>10020||id<10000)
            {
                printf("================================================================================\n");
                printf("reingrese una opcion valida entre 10000 y 10020:\nopcion:");
                scanf("%d",&id);
                printf("================================================================================\n");

            }
            cliente[i].idCliente=id;
            printf("================================================================================\n");
            printf("ingrese la direccion del cliente:");
            fflush(stdin);
            gets(cliente[i].direccion);
            printf("================================================================================\n");

            printf("ingrese el numero de tarjeta:");
            scanf("%d", &cliente[i].tarjeta);
            while(cliente[i].tarjeta<10000000||cliente[i].tarjeta>99999999)
            {
                printf("================================================================================\n");
                printf("ingrese un numero de tarjeta entre 10000000 y 99999999:");
                scanf("%d", &cliente[i].tarjeta);
            }


            cliente[i].estado=1;

            mostrarCliente(cliente[i]);
            break;
        }
    }
    else
    {
        printf("================================================================================\n");
        printf("No hay mas espacio disponible!\n");
    }


}
void modificar(xCliente cliente[],int tam)
{
    int i;
    int num;
    int numMod;

    printf("ingresa el numero de id del cliente del cual modificaras el numero de tarjeta:");
    scanf("%d", &num);

    while(num<10000||num>10020)
    {
        printf("================================================================================\n");
        printf("ingrese un numero de tarjeta entre 10000 y 10020, y que ya este registrado:");
        scanf("%d", &num);
    }

    for(i=0; i<tam; i++)
    {

        if(num==cliente[i].idCliente)
        {
            mostrarCliente(cliente[i]);
            printf("================================================================================\n");
            printf("ingresa el nuevo numero de tarjeta.");
            scanf("%d", &numMod);
            while(cliente[i].tarjeta<10000000||cliente[i].tarjeta>99999999)
            {
                printf("================================================================================\n");
                printf("ingrese un numero de tarjeta entre 10000000 y 99999999:");
                scanf("%d", &cliente[i].tarjeta);
            }


            printf("================================================================================\n");
            cliente[i].tarjeta=numMod;
            printf("se a realizado el cambio de tarjeta.\n");
            // flagSeguir=1;
            break;

        }

        else
        {
            printf("================================================================================\n");
            printf("ingrese un numero de tarjeta que ya este registrado:");
            scanf("%d", &num);

        }




    }
}
void ingreso (xAuto autos[],xCliente cliente[],int tam)
{
    int i;
    int j;
    int posicion;
    int opcion;

    posicion=buscarEspacio(autos,tam);
    if(posicion!=-1)
    {

        for(i=0; i<tam; i++)
        {
            printf("================================================================================\n");

            printf("ingrese la marca:\n");
            printf("================================================================================\n");
            printf("\n1- ALPHA_ROMERO\n");
            printf("2- FERRARI\n");
            printf("3- AUDI\n");
            printf("4- OTRO\n\nopcion:");

            scanf("%d",&opcion);
            while(opcion>4)
            {
                printf("================================================================================\n");
                printf("reingrese una opcion valida:\nopcion:");
                scanf("%d",&opcion);
                printf("================================================================================\n");

            }

            switch(opcion)
            {
            case 1:
                printf("usted eligio ALPHA_ROMERO.\n");
                autos[i].marca=opcion;
                break;
            case 2:
                printf("usted eligio FERRARI.\n");
                autos[i].marca=opcion;
                break;
            case 3:
                printf("usted eligio AUDI.\n");
                autos[i].marca=opcion;
                break;
            case 4:

                printf("usted eligio OTRO.\n");
                autos[i].marca=opcion;
                break;
            }
            printf("================================================================================\n");
            printf("ingrese la patente del vehiculo:");
            fflush(stdin);
            gets(autos[i].patente);
            printf("================================================================================\n");

            printf("ingrese el id del cliente q usa el auto:");
            scanf("%d", &autos[i].idCliente);

            if(autos[i].idCliente!=cliente[i].idCliente)
            {
                printf("================================================================================\n");
                printf("el ID del cliente no esta registrado.");

            }

            while(autos[i].idCliente>10020||autos[i].idCliente<10000)
            {
                printf("================================================================================\n");
                printf("reingrese una opcion valida entre 10000 y 10020:\nopcion:");
                scanf("%d",&autos[i].idCliente);

            }
            printf("================================================================================\n");
            printf("ingrese el horario de entrada:");
            scanf("%d", &autos[i].horaEntrada);
            if(autos[i].horaEntrada<0||autos[i].horaEntrada>24)
            {
                printf("================================================================================\n");
                printf("debe ingresar un horario entre 0 y 24 HS\n");
                scanf("%d", &autos[i].horaEntrada);
                break;
            }

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
void egreso(xAuto autos[],xCliente cliente[],xPrecios cobrar[], int tam)
{
    char auxCliente[7];
    int horaSalida;
    int i;
    int j;
    int horasDentro;
    int precio;
    int pAlpha;
    int pFerrari;
    int pAudi;
    int pOtro;


    for(i=0; i<tam; i++)
    {

        if(autos[i].estado == 1)
        {
            //printf("ingrece el id del cliente");
            printf("================================================================================\n");
            printf("\nIngrese la patente del auto que esgresa del estacionamiento: ");
            scanf("%s", &auxCliente);
            printf("================================================================================\n");

            if(stricmp(auxCliente,autos[i].patente)!=-0)
            {

                printf("La patente ingresado no existe\n");

                break;
            }
            else
            {
                printf("\ningrese el horario en el que saldra el auto:");
                scanf("%d",&horaSalida);
                printf("================================================================================\n");
                printf("\ncuantas horas estubo ingresado el auto");
                scanf("%d",&horasDentro);
                printf("================================================================================\n");
                if(horasDentro>24)
                {
                    printf("lo sentimo el veicuo a pasado mas 24hs dendro del estacionamiento, no puede retirarlo.\n");
                    printf("================================================================================\n");
                }
                else
                {
                    if(autos[i].marca==1)
                    {
                        pAlpha=horasDentro*150;
                        cobrar[i].ALPHA_ROMEO=pAlpha;
                        precio=pAlpha;

                    }
                    if(autos[i].marca==2)
                    {
                        pFerrari=horasDentro*175;
                        cobrar[i].FERRARY=pFerrari;
                        precio=pFerrari;

                    }
                    if(autos[i].marca==3)
                    {
                        pAudi=horasDentro*200;
                        cobrar[i].AUDI=pAudi;
                        precio=pAudi;

                    }
                     if(autos[i].marca==4)
                    {
                        pOtro=horasDentro*250;
                        cobrar[i].OTRO=pOtro;
                        precio=pOtro;

                    }
                    printf("a egresado del playon el siguiente auto:\n\nNOMBRE\t\t\tPATENTE\t\tMARCA\t\tVALOR HORAS\n%s %s\t\t%s\t\t%d\t\t$%d\n",cliente[i].nombre,cliente[i].apellido,autos[i].patente,autos[i].marca,precio);
                    break;
                }

            }

        }
        else
        {
            printf("================================================================================\n");
            printf("no se ingreso ningun dato previamente.\n");

        }

    }
}
void graficar(xAuto autos[],xCliente clientes[],xPrecios precios[],int tam)
{
    int i;
    int j;

    int resultado=0;
    int alpha=0;
    int ferrari=0;
    int audi=0;
    int otro=0;
    int flag=0;
    int flag2=0;

    if(flag==0)
        {
            printf("NOMBRE\t\t\tHORA ENTRADA\tPATENTE\n");
            flag=1;
        }
          for(i=0;i<tam;i++)
        {
            if(autos[i].estado==1)
        {
            printf("%s %s\t\t%d\t\t%s\n",clientes[i].nombre,clientes[i].apellido,autos[i].horaEntrada,autos[i].patente);
        }
        }

        if(flag2==0)
        {
            printf("================================================================================\n");
            printf("CLIENTES REGISTRADOS CON MARCA AUDI:\n");
        }
          for(i=0;i<tam;i++)
        {
            if(autos[i].estado==1&&autos[i].marca==3)
        {
            printf("%s %s\t%s\t%d\t%d\n",clientes[i].nombre,clientes[i].apellido,autos[i].patente,clientes[i].idCliente,clientes[i].tarjeta);

        }
        }


    for(i=0;i<tam;i++)
    {
        alpha=alpha+precios[i].ALPHA_ROMEO;
        ferrari=ferrari+precios[i].FERRARY;
        audi=audi+precios[i].AUDI;
        otro=otro+precios[i].OTRO;
    }
    resultado=alpha+ferrari+audi+otro;
    printf("================================================================================\n");
    printf("ALPHA_PROMEO\t\tFERRARI\t\tAUDI\t\tOTROS\n%d\t\t\t%d\t\t%d\t\t%d\n",alpha,ferrari,audi,otro);
    printf("================================================================================\n");
    printf("PRECIO TOTAL RECUADADO POR EL ESTACIONAMIENTO\n$%d\n",resultado);
}
/*void listaPatente(xAuto autos[], int tam)
{
    int i;
    int j;
    xAuto auxPatente;
    xAuto auxHora;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(stricmp(autos[i].patente,autos[j].patente)>0&&autos[i].horaEntrada>autos[j].horaEntrada)
            {
                auxPersona = autos[i];
                autos[i] = autos[j];
                autos[j] = autos;

            }
        }
    }
}*/

