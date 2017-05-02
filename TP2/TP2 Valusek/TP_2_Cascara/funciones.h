#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define A 2

typedef struct
{

    char nombre[50];
    int edad;
    int dni;
    int estado;

}ePersona;


void inicializarArrayPersonas(ePersona arrayPersonas[],int cantidadDeElementos,int valor);
int obtenerEspacioLibre(ePersona arrayPersonas[],int cantidadDeElementos,int valor);
int buscarPorDni(ePersona arrayPersonas[],int cantidadDeElementos,int valor);

int esNumerico(char str[]) ;
int esSoloLetras(char str[]);
void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);


#endif // FUNCIONES_H_INCLUDED
