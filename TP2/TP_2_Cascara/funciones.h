#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}Persona;





void menuOpciones();
void alta(Persona[], int);


#endif // FUNCIONES_H_INCLUDED
