#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "funcionesTP2.h"

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}ePersona;

/** \brief Inicializa el array
 * \param lista el array se pasa como parametro
 * \param tam el tamanio del array pasado como parametro
 * \param estado el valor pasado como parametro
 * \return retorna void
 */
void inicializarEstado(ePersona lista[], int tam, int estado);

/** \brief Despliega un menu de opciones por pantalla
 * \return la opcion elegida del menu
 */
int menuOpciones();

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro
 * @param tam el tamanio del array pasado como parametro
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona lista[], int tam);

/** \brief Pide numero de DNI por pantalla y lo valida
 * \return numValidado es el DNI validado
 */
int obtenerDNI();

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @param tam el tamanio del array pasado como parametro.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona lista[], int tam, int dni);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str el array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 */
int soloLetras(char str[]);

/** \brief Pide edad por pantalla y la valida
 * \return bunValidado es la edad validada
 */
int obtenerEdad();

/** \brief Muestra por pantalla el contenido de la estructura pasada por parametro
 * \param ePersona es la estructura a imprimir
 * \return imprime en pantalla los campos de la estructura
 */
void mostrarPersona(ePersona x);

/** \brief Muestra por pantalla una pregunta
 * \return respuesta es 1 si elimina o 0 si cancela
 */
int eliminarPersona();


/** \brief Ordena un vector pasado por parametro segun criterio tambien pasado por parametro
 * \param Vec. Es el vector a ordenar
 * \param tamanio. Es el tamanio de vector
 * \return retorna void
 */
void ordenar(ePersona lista[], int tamanio);

/** \brief Muestra un grafico por edades
 * \param lista el array se pasa como parametro
 * \param tam el tamanio del array pasado como parametro
 * \return retorna void
 */
void graficoEdades(ePersona lista[], int tam);

#endif // FUNCIONES_H_INCLUDED
