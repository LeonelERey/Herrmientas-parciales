
typedef struct
{
    char nombre[30];
    int edad;
    int DNI;
    int flagEstado;

} xPersona;
/** \brief iniciar toda la estrutura en 0.
 *
 * \param estructura.
 * \param array de la estructura.
 * \return toda la estructura inicializada.
 *
 */
void inicializarPersona(xPersona[], int);

/** \brief buscar lugar dentro de la estructrura.
 *
 * \param estructura.
 * \param array de la estructura.
 * \return la posicion en la cual se pueda ingresar datos.
 *
 */
int buscarEspacio(xPersona[],int);

/** \brief mostrar los datos de una persona.
 *
 * \param la estructura con la posicion de array.
 * \return un texto con los datos de la persona.
 *
 */
void mostrarPersona(xPersona);

/** \brief realizar las preguntas correspondientes para registrar los datos.
 *
 * \param estructura.
 * \param el array de la estructura.
 * \return los datos ingresados por el usuario.
 *
 */
void preguntas(xPersona[],int);

/** \brief realizar la eliminacion de una persona reguistrada.
 *
 * \param estructura.
 * \param array de la estructura.
 * \return la persona dada de baja.
 *
 */
void eliminarPersona(xPersona[],int);

/** \brief mostar un listado, con los datos de todas las personas registraas.
 *
 * \param estructura.
 * \param array de la estructura.
 * \return mostrar una por una las personas ingresadas.
 *
 */
void mostrarPersonas(xPersona[],int);

 /** \brief ordenar las personas ingresadas alfabeticamente
  *
  * \param estructura.
  * \param array de la estructura.
  * \return las personas ordenadas alfabeticamente.
  *
  */
void listaPersonas(xPersona[],int);

/** \brief mostar las cntidada de personar con cierta edad.
 *
 * \param estructura.
 * \param array de la estructura.
 * \return un grafico marcando con '*' la cantidad de personas.
 *
 */
void graficar (xPersona[],int);

/** \brief contar la cantdad de personas, verificando q esta exista.
 *
 * \param estructura.
 * \param array de la estructura.
 * \return la cantidad de personas ya verificado.
 *
 */
int cont18(xPersona[],int);

/** \brief contar la cantdad de personas, verificando q esta exista.
 *
 * \param estructura.
 * \param array de la estructura.
 * \return la cantidad de personas ya verificado.
 *
 */
int cont35(xPersona[],int);

/** \brief contar la cantdad de personas, verificando q esta exista.
 *
 * \param estructura.
 * \param array de la estructura.
 * \return la cantidad de personas ya verificado.
 *
 */
int cont19a35(xPersona[],int);




