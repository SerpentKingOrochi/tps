#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <time.h>

#include "utn.h"

/** \brief Carga los datos de una persona (DNI, Nombre y edad)
 *
 * \param Array de struct Persona
 * \param Length del array
 * \return void
 *
 */

void darAltaPersona(ePersona persona[], int size)
{
    int i, j, flag = 0;
    long int dni;
    for(i = 0; i < size; i++)
    {
        flag = 0;
        if(persona[i].flag == 0)
        {
            printf("Ingrese DNI: ");
            scanf("%ld", &dni);
            for(j = 0; j < size; j++)
            {
                if(persona[j].dni == dni && persona[j].flag == 1)
                {
                    printf("Esta persona ya existe\n");
                    flag = 2;
                    i--;
                }
            }
            if(flag != 2)
            {
                persona[i].dni = dni;
                printf("Ingrese nombre: ");
                fflush(stdin);
                gets(persona[i].nombre);
                printf("Ingrese edad: ");
                scanf("%d", &persona[i].edad);
                persona[i].flag = 1;
                flag = 1;
                break;
            }
        }
    }
    if(flag == 0)
    {
        printf("No quedan espacios disponibles\n");
        system("pause");
    }
    system("cls");
}

/** \brief Borra la persona que tenga determinado DNI
 *
 * \param  Array Persona
 * \param   Length del Array
 * \param  DNI de Persona a borrar
 * \return void
 *
 */


void borrarPersona(ePersona persona[], int size, long int dni)
{
    int i, flag = 0;
    for(i = 0; i < size; i++)
    {
        if(persona[i].dni == dni)
        {
            persona[i].flag = 0;
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("No hubo coincidencias\n");
        system("pause");
    }
    system("cls");
}


/** \brief Ordena y muestra Persona por nombre de a-z
 *
 * \param  Array Persona
 * \param   Length del Array
 * \return void
 *
 */

void ordenarPersonaNombreMenorMayor(ePersona persona[], int size)
{
    int i, j, dni, flag;
    long int edad;
    char nombre[255];
    for(i = 0; i < size-1; i++)
    {
        for(j = i+1; j < size; j++)
        {
            if(strcmp(persona[i].nombre, persona[j].nombre)>0 && persona[i].flag == 1 && persona[j].flag == 1)
            {
                strcpy(nombre, persona[i].nombre);
                strcpy(persona[i].nombre, persona[j].nombre);
                strcpy(persona[j].nombre, nombre);

                dni = persona[i].dni;
                persona[i].dni = persona[j].dni;
                persona[j].dni = dni;

                edad = persona[i].edad;
                persona[i].edad = persona[j].edad;
                persona[j].edad = edad;

                flag = persona[i].flag;
                persona[i].flag = persona[j].flag;
                persona[j].flag = persona[i].flag;
            }
        }
    }
    printf("\n");
    for(i = 0; i < size; i++)
    {
        if(persona[i].flag == 1)
        {
            printf("Nombre: %s, DNI: %ld, edad: %d\n", persona[i].nombre, persona[i].dni, persona[i].edad);
        }
    }
    printf("\n");
    system("pause");
    system("cls");
}

/** \brief Imprime grafico de edades discriminadas por  menores de 18 entre 18 y 35 y mayores que 35
 *
 * \param  Array Persona
 * \param   Length del Array
 * \return  void
 *
 */

void imprimirMatrizEdad3Col(ePersona persona[], int size)
{
    int i, j, acomodador;
    int edadMatriz[size][3];
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < 3; j++)
        {
            edadMatriz[i][j] = 0;
        }
    }
    for(j = 0; j < 3; j++)
    {
        acomodador = size - 1;
        for(i = 0; i < size; i++)
        {
            if(persona[i].edad < 18 && j == 0 && persona[i].flag != 0)
            {
                edadMatriz[acomodador][j] = 42;
                acomodador--;
            }
            else if(persona[i].edad >= 18 && persona[i].edad <= 35 && j == 1 && persona[i].flag != 0)
            {
                edadMatriz[acomodador][j] = 42;
                acomodador--;
            }
            else if(persona[i].edad > 35 && j == 2 && persona[i].flag != 0)
            {
                edadMatriz[acomodador][j] = 42;
                acomodador--;
            }
        }
    }

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%c\t", edadMatriz[i][j]);
        }
        printf("\n");
    }
    printf("<18\t18-35\t>35\n");
    system("pause");
    system("cls");
}














/**
*	La funcion getInt recibe una cadena de caracteres
*	de la cual el usuario puede determinar que dato ingresar
*
*	Devuelve un numero entero tipo int
**/
int getInt(char text[])
{
	int num, resultado;
	printf("%s", text);
	resultado = scanf("%d", &num);
	while(resultado<=0)
    {
        printf("(NUMEROS ENTEROS UNICAMENTE), %s", text);
        fflush(stdin);
        resultado = scanf("%d", &num);
    }
	return num;
}

/**
*	La funcion getLongInt recibe una cadena de caracteres
*	de la cual el usuario puede determinar que dato ingresar
*
*	Devuelve un numero entero tipo long int
**/
long int getLongInt(char text[])
{
	long int num;
	int resultado;
	printf("%s", text);
	resultado = scanf("%ld", &num);
	while(resultado<=0)
    {
        printf("(NUMEROS ENTEROS UNICAMENTE), %s", text);
        fflush(stdin);
        resultado = scanf("%ld", &num);
    }
	return num;
}
/**
*	La funcion getFloat recibe una cadena de caracteres
*	de la cual el usuario puede determinar que dato ingresar
*
*	Devuelve un numero decimal con coma tipo float
**/
float getFloat(char text[])
{
	float num;
	int resultado;
	printf("%s", text);
    resultado = scanf("%f", &num);
    while(resultado<=0)
    {
        printf("(NUMEROS UNICAMENTE), %s", text);
        fflush(stdin);
        resultado = scanf("%f", &num);
    }
	return num;
}

/**
*	La funcion getChar recibe una cadena de caracteres
*	de la cual el usuario puede determinar que dato ingresar
*
*	Devuelve un caracter tipo char
**/
char getChar(char texto[])
{
	char letra;
	printf("%s", texto);
	scanf("%c", &letra);
	return letra;
}

/**
*   Recibe un vector de enteros y el tamaño del vector
*   devuelve la suma de todos sus elementos
**/
int sumar(int num[], int length)
{
    int suma = 0;
    int i;
    for(i = 0; i < length; i++)
    {
        suma += num[i];
    }
    return suma;
}

/**
*   Recibe un vector de enteros y el tamaño del vector
*   devuelve la resta de todos sus elementos
**/
int restar(int num[], int length)
{
    int resta = num[0];
    int i;
    for(i = 1; i < length; i++)
    {
        resta -= num[i];
    }
    return resta;
}

/**
*   Recibe un vector de enteros y el tamaño del vector
*   devuelve la multiplicacion de todos sus elementos
**/

int multiplicar(int num[], int length)
{
    int multiplicacion = 1;
    int i;
    for(i = 0; i < length; i++)
    {
        multiplicacion = multiplicacion * num[i];
    }
    return multiplicacion;
}

/**
*   Recibe un vector de enteros y el tamaño del vector
*   devuelve la division del primer numero del arreglo por el resto
**/
void dividir(int num[], int length)
{
    int flag = 0;
    int i;
    float division =(float) num[0];
    for(i = 1; i < length; i++)
        {
            if(num[i] == 0)
            {
                flag++;
                perror("MATH ERROR: No se permite divisor cero");
                break;
            }
        }
        if(flag == 0)
        {
            for(i = 1; i < length; i++)
            {
                division = division / num[i];
            }
            printf("La division de ambos numeros es %f\n", division);
        }



}




/**
*	La funcion validarCaracter recibe:
*	1-	El texto que lee el usuario,
*	3-	Y el caracter previamente leido
*
*	Devuelve el caracter validado solo para 's' o 'n'
**/
char validarSN(char caracter, char texto[])
{
	printf("caracter es %d", caracter);
	while(caracter != 'n' && caracter !='s')
	{
		printf("Valor invalido! ");
		caracter = getChar(texto);
	}
	return caracter;
}

/**
*	La funcion validarCaracter recibe:
*	1-	El texto que lee el usuario,
*	2-	Las opciones validas para el caracter,
*	3-	Y el caracter previamente leido
*
*	Devuelve el caracter validado
**/
char validarCaracter(char texto[], char opciones[], char caracter)
{
	char mensaje[] = {"Valor invalido! "};
	int length;
	length = strlen(opciones);
	int flag = 0;
	do
	{
	    int i;
		for(i = 0; i < length; i++)
		{
			if(caracter == opciones[i])
			{
				flag = 0;
				break;
			}
			flag = 1;
		}
		if(flag == 1)
		{
			 printf(mensaje);
			 caracter = getChar(texto);
		}
	}while(flag != 0);
	return caracter;
}

/**
*	Recibe un entero el cual debe ser negativo (cero inclusive) para retornar de la funcion
**/
int validarNegativo(int num, char texto[])
{
	while(num > 0)
	{
		printf("Valor invalido! Por favor ");
		num = getInt(texto);
	}
}

/**
*	Recibe un numero con coma el cual debe ser negativo (cero inclusive) para retornar de la funcion
**/
float validarComaNegativo(float num, char texto[])
{
	while(num > 0)
	{
		printf("Valor invalido! Por favor ");
		num = getFloat(texto);
	}
}

/**
*	Recibe un entero el cual debe ser positivo (cero inclusive) para retornar de la funcion
**/
int validarPositivo(int num, char texto[])
{
	while(num < 0)
	{
		printf("Valor invalido! Por favor ");
		num = getInt(texto);
	}
}

/**
*	Recibe un numero con coma el cual debe ser positivo (cero inclusive) para retornar de la funcion
**/
float validarComaPositivo(float num, char texto[])
{
	while(num < 0)
	{
		printf("Valor invalido! Por favor ");
		num = getFloat(texto);
	}
}


int validarDistintoCero(int num, char texto[])
{
	while(num == 0)
	{
		printf("Valor invalido! Por favor ");
		num = getInt(texto);
	}
}
/**
*	Devuelve el factorial del numero recibido
**/
long int factorial(int num)
{
	if(num == 1)
	{
		return 1;
	}
	num = num * factorial(num - 1);
}


/**
*	Genera un numero aleatorio entre 0 y 100 y lo devuelve para asignar
**/
int generarNumeroAleatorio(void)
{
	srand((unsigned)time(NULL));
	return rand()%100;
}

void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;
    while (time(0) < retTime);
}

/**
*	CADENAS DE CARACTER
*
**/

/**
*	devuelve una cadena de caracteres con el tipo de cadena recibida
*	POR EJEMPLO: AL PASAR "123" POR ARGUMENTO DEVUELVE "NUMERICA" porque la cadena es de tipo numerica
**/
char * determinarCadena(char cadena[])
{
	int length, i;
    int numerica = 0;
    int alfabetica = 0;
    int telefonica = 0;
    char * tipoCadena;
    length = strlen(cadena);
    for(i = 0; i < length; i++)
    {
        if(cadena[i] >= '0' && cadena[i] <= '9')
        {
            numerica++;
        }
        else
        {
            if((cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= 'a' && cadena[i] <= 'z'))
            {
              alfabetica++;
            }
            else
            {
                if(cadena[i] == '-')
                {
                    telefonica++;
                }
            }
        }
    }
    if(alfabetica > 0)
    {
        if(numerica > 0)
        {
            tipoCadena = "alfanumerica";
        }
        else
        {
            tipoCadena = "alfabetica";
        }
    }
    if(numerica > 0)
    {
        if(telefonica > 0)
        {
            tipoCadena = "telefonica";
        }
        else
        {
            tipoCadena = "numerica";
        }
    }
    return tipoCadena;
}

/**
*	Valida solo las cadenas formadas por digitos del 0 al 9
**/
void validarCadenaNumerica(char mensaje[], char cadena[])
{
    int i, len, flag;
    flag = 0;
    len = strlen(cadena);
    for(i = 0; i < len; i++)
    {
        if(!(cadena[i] == ' ' || (cadena[i] >= '0' && cadena[i] <= '9')))
        {
            flag++;
        }
        if(flag == 1)
        {

            printf("Error, debe ingresar solo numeros, %s", mensaje);
            gets(cadena);
            validarCadenaNumerica(mensaje, cadena);
            break;
        }
    }
}

/**
*	Valida solo las cadenas formadas por digitos del 0 al 9 y caracteres especificos
**/
void validarCadenaTelefonica(char mensaje[], char cadena[])
{
    int i, len, flag;
    flag = 0;
    len = strlen(cadena);
    for(i = 0; i < len; i++)
    {
        if(!((cadena[i]=='(')||(cadena[i] == ')')||(cadena[i] == '-') || cadena[i] >= '0' && cadena[i] <= '9'))
        {
            flag++;
        }
        if(flag == 1)
        {

            printf("Error, debe ingresar un el giguiente formato de numero (011)15-3433-1251, %s", mensaje);
            gets(cadena);
            validarCadenaTelefonica(mensaje, cadena);
            break;
        }
    }
}

/**
*	Valida solo las cadenas formadas por letras
**/
void validarCadenaAlfabetica(char mensaje[], char cadena[])
{
    int i, len, flag;
    flag = 0;
    len = strlen(cadena);
    for(i = 0; i < len; i++)
    {
        if(!((cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] == ' ')))
        {
            flag++;
        }
        if(flag == 1)
        {

            printf("Error, debe ingresar solo letras, %s", mensaje);
            gets(cadena);
            validarCadenaAlfabetica(mensaje, cadena);
            break;
        }
    }
}


/**
*	Valida solo las cadenas formadas por digitos del 0 al 9 y letras
**/
void validarCadenaAlfaNumerica(char mensaje[], char cadena[])
{
    int i, len, flag;
    flag = 0;
    len = strlen(cadena);
    for(i = 0; i < len; i++)
    {
        if(!((cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] == ' ') || cadena[i] >= '0' && cadena[i] <= '9'))
        {
            flag++;
        }
        if(flag == 1)
        {

            printf("Error, debe ingresar solo letras y numeros, %s", mensaje);
            gets(cadena);
            validarCadenaAlfaNumerica(mensaje, cadena);
            break;
        }
    }
}

/**
*	ordena un vector de cadenas de caracteres con un tamaño de 15 caracteres por vector
**/
void ordenarVectorCadenaQuinceMenorMayor(char cadena[][15])
{
	int len, i, j, c;
    char aux[15];
    len = strlen(cadena);
    for(i = 0; i < len-1; i++)
    {
        j = i + 1;
        for(j ; j < len; j++)
        {
            c = stricmp(cadena[i], cadena[j]);
            if(c > 0)
            {
                strcpy(aux, cadena[i]);
                strcpy(cadena[i], cadena[j]);
                strcpy(cadena[j], aux);
            }
        }
    }
}

void ordenarVectorCadenaQuinceMayorMenor(char cadena[][15])
{
    int len, i, j, c;
    char aux[15];
    len = strlen(cadena);
    for(i = 0; i < len-1; i++)
    {
        j = i + 1;
        for(j ; j < len; j++)
        {
            c = stricmp(cadena[i], cadena[j]);
            if(c < 0)
            {
                strcpy(aux, cadena[i]);
                strcpy(cadena[i], cadena[j]);
                strcpy(cadena[j], aux);
            }
        }
    }
}
