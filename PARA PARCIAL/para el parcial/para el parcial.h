typedef struct
{
    char patente[7];
    int marca;
    int modelo;
    int profesor;
    int estado;

} xAutos;

void altas(xAutos[],int);
void mostrarAuto(xAutos);
void inicializarAutos(xAutos[], int);
int buscarEspacio(xAutos[],int);
