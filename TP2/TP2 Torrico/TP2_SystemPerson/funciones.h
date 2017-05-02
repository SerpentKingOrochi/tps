#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct {

    char nombre[50];
    int edad;
    int dni;
    int estado;

}EPersona;

/** Se encarga de generar un nuevo dato en base a la estructura dada.
 * \brief Lectura por teclado
 * \param Estructura de Personas
 * \param Longitud de la estructura
 * \return una bandera bolean de dato 1 para true o 0 para false
 *
 */
int newPerson(EPersona xPerson[],int tam);

/** Imprime en pantalla todos los datos que figuran en la estructura con estado igual a 1
 * \brief Imprimir en pantalla
 * \param Estructura de Personas
 * \param Longitud de la estructura
 * \return null
 *
 */
void viewPersons(EPersona lasPersonas[], int tam);

/** Imprime en pantalla solo un dato especificado del vector de estructuras
 * \brief Imprimir en pantalla
 * \param Estructura de Personas
 * \param Longitud de la estructura
 * \param Posicion del vector el cual buscar
 * \return null
 *
 */
void viewPerson(EPersona lasPersonas[], int tam, int positionView);

/** Genera una baja logica en el vector de estructuras igualando su estado a 0
 * \brief Baja Logica
 * \param Estructura de Personas
 * \param Longitud de la estructura
 * \param Mensaje emitido en caso de baja exitosa
 * \param Mensaje emitido en caso de error
 * \return null
 *
 */
void deletePerson(EPersona xPerson[],int position, char msgTrue[],char msgFalse[]);

/** Ordena el vector de estructura de la A a la Z
 * \brief Ordenamiento Alfabetico
 * \param Estructura de Personas
 * \param Longitud de la estructura
 * \return null
 *
 */
void personOrderByAZ(EPersona lasPersonas[], int tam);

/** Modidica una cadena de caracteres transformando a mayuscula la primer letra encontrada y la letra encontrada luego de un esapcio y minuscula el resto
 * \brief Modificacion de caracteres
 * \param Cadena de caracteres a estilisar
 * \return null
 *
 */
void styleVector(char cadena[]);

/** Imprime un mensaje en pantalla
 * \brief Imprimir en pantalla
 * \param Cadena de caracteres a imprimir en pantalla
 * \return null
 *
 */
void showMessage(char message[]);

/** Valida valores que antenceden al minimo y valores que le siguen al maximo
 * \brief Validacion por Rangos
 * \param Entero ingresado por teclado
 * \param Minumo admitido
 * \param Maximo admitido
 * \return Numero validado
 *
 */
int validMenu(int opcion, int min, int max);

/** Verifica en la estructura la cantidad de valores de estado iguales al dato de estado brindado
 * \brief Contador de estados
 * \param Estructura de Personas
 * \param Longitud de la estructura
 * \param Tipo de dato a buscar
 * \return La cantidad de datos iguales al tipo de datos a buscar, encontrados
 *
 */
int countState(EPersona lasPersonas[], int tam, int typeState);

/** Lee una cadena de caracteres por teclado
 *  \brief Lectura por Teclado
 * \param Vector de cadena de caracteres a cargar
 * \param Mensaje a mostrar
 * \return null
 *
 */
void readCharacter(char characters[], char msg[]);

/** Convierte un flag al valor requerido
 * \brief Convertidor
 * \param Flag a ser modificado
 * \return Flag modificado
 *
 */
int changeFlag(int flag);

/** Limpia la interfas de usuario
 * \brief Interfaz grafica
 * \return null
 *
 */
void clearView(void);

/** Valida el largo del dni
 * \brief Validacion por largo
 * \param Vector de caracteres que contiene el dni
 * \param Minimo largo posible
 * \param Maximo largo admitido
 * \return null
 *
 */
void validateDni(char buffer[],int length, int min, int max);

/** Cuenta la cantidad de valores entre el rango brindado
 * \brief Contador entre Rangos
 * \param Estructura de Personas
 * \param Longitud de la estructura
 * \param Minimo valor admitido
 * \param Maximo valor admitido
 * \return Cantidad de datos entre el minimo y el maximo permitido
 *
 */
int countEdad(EPersona lasPersonas[], int tam, int min, int max);

/** Imprime en pantall, en el eje Y un grafico de * en sentido vertical
 * \brief Imprimir en pantalla
 * \param Cantidad de * a imprimir en la primer vertical
 * \param Cantidad de * a imprimir en la segunda vertical
 * \param Cantidad de * a imprimir en la tercera vertical
 * \return null
 *
 */
void printGrafic(int count1, int count2, int count3);

/** Obtiene el primer indice libre del array.
 * \brief Buscador de posicion
 * \param lista el array se pasa como parametro.
 * \return el primer indice disponible
 *
*/
int shearchPosition(EPersona xPerson[], int tam);

/** Obtiene el indice que coincide con el dni pasado por parametro.
 * \brief Buscador por dato brindado
 * \param lista el array se pasa como parametro.
 * \param dni el dni a ser buscado en el array.
 * \param longitud del vector
 * \return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int searchDni(EPersona lista[], int dni, int tam);

#endif // FUNCIONES_H_INCLUDED

/*
  By Torrico Roberto Carlos 1H
*/

