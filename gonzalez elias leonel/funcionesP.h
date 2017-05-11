#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char nombre[12];
    char apellido[12];
    char direccion[50];
    int tarjeta;
    int idCliente;
    int estado;

} xCliente;
typedef struct
{
    char patente[10];
    int marca;
    int idCliente;
    int horaEntrada;
    int estado;

} xAuto;

typedef struct
{
    int ALPHA_ROMEO;
    int FERRARY;
    int AUDI;
    int OTRO;

} xPrecios;



void inicializarAutos(xAuto[],int);
void inicializarCliente(xCliente[],int);
void inicializarPrecios(xPrecios[],int);
int buscarEspacio(xAuto[],int);
void mostrarAuto(xAuto);
void mostrarCliente(xCliente);
void altasCliente (xCliente[],int);
void modificar(xCliente[],int);
void informes(xAuto[],int);
void egreso(xAuto[],xCliente[],xPrecios[], int);
void mostrarClienAuto(xCliente[],int);
void graficar(xAuto[],xCliente[],xPrecios[],int);
void listaPatente(xAuto[],int);
