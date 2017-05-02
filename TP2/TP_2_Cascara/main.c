#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define VECTOR 3
//VARIABLES
    int opcion=0;
    int i;
    int j;
    int contadorPersona;
    long int dni;

    //estructura
    Persona listaPersonas[VECTOR];

    // si esta en estado = 0 ==> no hay nada cargado
    // si esta en estado = 1 ==> carga exitosa
    // si esta en estado = 2 ==> usuario ya existente
    // si esta en estado = -1 ==> baja logica





int main()
{
    for(opcion = 0; opcion < VECTOR; opcion++)
    {
        listaPersonas[opcion].estado = 0;
    }

    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        //contadorPersona = contarPersona(listaPersonas, VECTOR);
        menuOpciones();
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:


                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
