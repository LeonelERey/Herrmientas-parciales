#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void inicializarPersona(xPersona persona[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        {
            persona[i].flagEstado=0;
        }
    }
}

int buscarEspacio(xPersona espacio[],int tam)
{
    int lugar = -1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(espacio[i].flagEstado==0)
        {
            lugar = i;
            break;
        }
    }
    return lugar;
}

void mostrarPersona(xPersona persona)
{
    printf("================================================================================\n");
    printf("\n%s\t%d\t%d\n\n", persona.nombre, persona.edad, persona.DNI);
}

void preguntas (xPersona preguntas[],int tam)
{
    int i;
    int flagLugar;

    flagLugar=0;
    for(i=0; i<tam; i++)
    {
        if(preguntas[i].flagEstado==0)
        {
            printf("================================================================================\n");
            printf("ingrese el nombre de la persona que quiere ingresar: ");
            fflush(stdin);
            gets(preguntas[i].nombre);
            printf("================================================================================\n");
            printf("ingrese la edad de la persona:");
            scanf("%d", &preguntas[i].edad);
            if(preguntas[i].edad>-9999999999&&preguntas[i].edad<9999999999)
            {
             while(preguntas[i].edad>105||preguntas[i].edad<0)
            {
                printf("================================================================================\n");
                printf("ingrese una edad coherente:");
                scanf("%d", &preguntas[i].edad);

            }
            }
            else
            {
                printf("debe ingresar numeros.");
            }
            printf("================================================================================\n");
            printf("ingrese el DNI de la persona:");
            scanf("%d", &preguntas[i].DNI);
            while(preguntas[i].DNI>99999999||preguntas[i].DNI<10000000)
            {
                printf("================================================================================\n");
                printf("ingrese un numero de DNI valido:");
                scanf("%d", &preguntas[i].DNI);

            }
            preguntas[i].flagEstado=1;
            mostrarPersona(preguntas[i]);

            flagLugar=1;
            break;

        }
    }
}

void eliminarPersona(xPersona personas[],int tam)
{
    int i;
    int flagLugar;
    int auxDNI;
    char respuesta;

    flagLugar=0;
    printf("================================================================================\n");
    printf("ingresa el numero de documento de la persona que desea eliminar:");
    scanf("%d", &auxDNI);

    for(i=0; i<tam; i++)
        {
    if(personas[i].flagEstado==1&&auxDNI==personas[i].DNI)
        {
            mostrarPersona(personas[i]);
            printf("================================================================================\n");
            printf("esta seguro que quiere eliminar a esta persona?\n");
            respuesta=getche();

            if(respuesta=='s')
            {
                personas[i].flagEstado=0;
                printf("================================================================================\n");
                printf("\nla eliminacion fue realizada con exito.\n");
            }
            else
            {
                printf("\n================================================================================\n");
                printf("la eliminacion se a cancelado.\n");
            }
            flagLugar=1;

            break;
            }
        }
            if(flagLugar==0)
            {
                printf("================================================================================\n");
                printf("esa persona no a sido registrada previamente o ya fue eliminada.\n");
            }
}

void mostrarPersonas(xPersona personas[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(personas[i].flagEstado!=0)
        {
            mostrarPersona(personas[i]);
        }
    }
}

void listaPersonas(xPersona personas[], int tam)
{
    int i;
    int j;
    xPersona auxPersona;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(stricmp(personas[i].nombre,personas[j].nombre)>0)
            {
                auxPersona = personas[i];
                personas[i] = personas[j];
                personas[j] = auxPersona;
            }
        }
    }
}

void graficar (xPersona personas[],int tam)
{
    int contMenor18;
    int contEntre19y35;
    int contMayor35;
    int i;
    int maximo;
    int flag;

    contMenor18=cont18(personas,tam);
    contMayor35=cont35(personas,tam);
    contEntre19y35=cont19a35(personas,tam);

    if(contMenor18>=contMayor35&&contMenor18>=contEntre19y35)
    {
        maximo=contMenor18;
    }
    else
    {
        if(contEntre19y35>=contMenor18&&contEntre19y35>=contMayor35)
        {
            maximo=contEntre19y35;
        }
        else
        {
            maximo=contMayor35;
        }
    }

    for(i=maximo;i>0;i--)
    {
        flag=0;
        while(flag!=1)
        {
                printf("================================================================================\n");

                if(i<= contMenor18)
                {
                    printf("    *");
                }
                if(i<= contEntre19y35)
                {
                    flag=1;
                    printf("\t  *");
                }
                if(i<= contMayor35)
                {
                    if(flag==1)
                    {
                        printf("\t *");
                    }
                    else
                    {
                        printf("\t\t *");
                    }
                }
                flag=1;
            printf("\n");
        }

    }
    printf("  |<18\t19-35\t>35|\n");
}

int cont18 (xPersona personas[],int tam)
{
    int i;
    int contMenor18=0;

    for(i=0;i<tam;i++)
    {
        if(personas[i].edad<=18&&personas[i].flagEstado==1)
        {
            contMenor18++;
        }

    }
    return contMenor18;
}

int cont19a35 (xPersona personas[],int tam)
{
    int i;
    int contEntre19y35=0;

    for(i=0;i<tam;i++)
    {
        if(personas[i].edad<=35&&personas[i].edad>=19&&personas[i].flagEstado==1)
        {
            contEntre19y35++;
        }

    }
    return contEntre19y35;
}

int cont35 (xPersona personas[],int tam)
{
    int i;
    int contMayor35=0;

    for(i=0;i<tam;i++)
    {
        if(personas[i].edad>35&&personas[i].flagEstado==1)
        {
            contMayor35++;
        }

    }
    return contMayor35;
}
