/*DEFINIR BIBLIOTECA*/
#ifndef FUNCIONES_H_   /* Include guard */
#define FUNCIONES_H_

//DEFINE PROTOTIPO PERSONA
typedef struct Persona
{
    char nombre[20];
    int edad;
    long int dni;
    int flag;
} ePersona;


void darAltaPersona(ePersona[], int);
void borrarPersona(ePersona[], int, long int);
void ordenarPersonaNombreMenorMayor(ePersona[], int);
void imprimirMatrizEdad3Col(ePersona[], int);




/**
*	La funcion getInt()
*	recibe un mensaje que lee el usuario
*	devuelve un numero ingresado por el usuario
*/
int getInt(char[]);

long int getLongInt(char text[]);
/** TODO
*	La funcion getFloat()
*	recibe un mensaje que lee el usuario
*	devuelve un numero con coma ingresado por el usuario
*/
float getFloat(char[]);

/**
*	La funcion getChar()
*	recibe un mensaje que lee el usuario
*	devuelve un caracter ingresado por el usuario
*/
char getChar(char[]);


//int sum(int num1, int num2); BORRAR
int sumar(int[], int length);
//int res(int num1, int num2); BORRAR
int restar(int[], int length);
//int mul(int num1, int num2); BORRAR
int multiplicar(int[], int length);
//float divi(int num1, int num2); BORRAR
void dividir(int[], int length);


/**
*	La funcion generarNumeroAleatorio()
*	devuelve un numero random entre 0 y 100
*/
int generarNumeroAleatorio(void);
/**
*	La funcion validarCaracter recibe:
*	1-	El texto que lee el usuario,
*	2-	Las opciones validas para el caracter,
*	3-	Y el caracter previamente leido
*
*	Devuelve el caracter validado
**/
char validarCaracter(char[], char[], char);

char validarSN(char, char[]);
int validarPositivo(int num, char[]);

/**
*	Calcula el factorial del numero pasado por argumento
**/
long int factorial(int num);

/**
*	Mantiene un bucle hasta el tiempo indicado
**/
void waitFor (unsigned int secs);

/**
*	CADENAS DE CARACTER
*
*
*
*
**/

/**
*	devuelve una cadena de caracteres con el tipo de cadena recibida
*	POR EJEMPLO: AL PASAR "123" POR ARGUMENTO DEVUELVE "NUMERICA" porque la cadena es de tipo numerica
**/
char * determinarCadena(char[]);
/**
*	Valida una cadena que solo tenga digitos del 0 al 9
*
**/
void validarCadenaNumerica(char[], char[]);
void validarCadenaTelefonica(char[], char[]);
void validarCadenaAlfabetica(char[], char[]);
void validarCadenaAlfaNumerica(char[], char[]);


/**
*	ordena un vector de cadenas de caracteres con un tamaño de 15 caracteres por vector
**/
void ordenarVectorCadenaQuinceMenorMayor(char [][15]);

void ordenarVectorCadenaQuinceMayorMenor(char cadena[][15]);
#endif // FOO_H_
