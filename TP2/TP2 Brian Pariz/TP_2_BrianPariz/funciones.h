typedef struct {

    char nombre[30];
    int edad;
    int dni;
    int estado;

}ePersona;

/** \brief Carga datos de una persona.
 *
 * \param Estructura con los datos cargados o por cargar.
 * \param Tamaño de dicha estructura.
 * \return 0 si no hay espacio disponible, 1 si lo hay.
 *
 */

int cargarPersona(ePersona lista[], int);

/** \brief Busca un espacio libre por su DNI.
 *
 * \param Estructura con los datos cargados o por cargar.
 * \param Tamaño de dicha estructura.
 * \return Posicion dentro del array donde cargar datos de una persona.
 *
 */

int buscarLibre(ePersona lista[], int);

/** \brief Busca a una persona por su DNI para así borrarla.
 *
 * \param Estructura con los datos cargados o por cargar.
 * \param Tamaño de dicha estructura.
 * \return Null
 *
 */

void borrarPersona (ePersona lista[], int);

/** \brief Imprime en pantalla la lista con las personas ingresadas.
 *
 * \param Estructura con los datos cargados o por cargar.
 * \param Tamaño de dicha estructura.
 * \return Null
 *
 */

void imprimirLista (ePersona lista[], int);

/** \brief Ordena la lista de personas alfabeticamente y las muestra en pantalla.
 *
 * \param Estructura con los datos cargados o por cargar.
 * \param Tamaño de dicha estructura.
 * \return Null
 *
 */

void ordenarLista (ePersona lista[], int);

/** \brief Pide un nombre y valida que sus caracteres sean letras.
 *
 * \param Estructura con los datos cargados o por cargar.
 * \param Posición en dicha estructura.
 * \return Null
 *
 */

void pedirYValidarLetras(ePersona lista[], int);

/** \brief Pide una edad.
 *
 * \param Estructura con los datos cargados o por cargar.
 * \param Posición en dicha estructura.
 * \return Null
 *
 */

void pedirEdad(ePersona lista[], int);

/** \brief Pide un DNI.
 *
 * \param Estructura con los datos cargados o por cargar.
 * \param Posición en dicha estructura.
 * \return Null
 *
 */

void pedirDNI(ePersona lista[], int);

/** \brief Valida que lo ingresado sea un numero positivo.
 *
 * \param Caracteres ingresados.
 * \return Si no es un numero positivo retorna 0, caso contrario 1.
 *
 */

int validarNum(char[]);

/** \brief Separa a las personas ingresadas de acuerdo a sus edades e imprime un gráfico.(menores de 19, entre 19 y 35, mayores de 35).
 *
 * \param Estructura con los datos cargados o por cargar.
 * \param Tamaño de dicha estructura.
 * \return Null
 *
 */

void GraficoEdades (ePersona lista[], int);
