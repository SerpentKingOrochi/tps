#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <time.h>

#include "funciones.h"



void menuOpciones()
{

    printf("1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- Imprimir lista ordenada por  nombre\n");
    printf("4- Imprimir grafico de edades\n\n");
    printf("5- Salir\n");
    printf("Ingresar una opcion...");
}



void alta(Persona listaPersonas[], int largo)
{

    int i;
    int j;
    long int dni;
    int  estado=0;

    for(i=0; i<largo; i++)
    {
        estado=0;
        if(listaPersonas[i].estado==0)
        {
            printf("Ingresar DNI: ");
            scanf("%ld", dni);
            for(j=0; j<largo; j++)
            {
                if(listaPersonas[j].dni== dni && listaPersonas[j].estado==1)
                {
                    printf("Usuario ya cargado!");
                    estado=2;
                    i--;
                }
            }
            if(estado!=2)
            {
                listaPersonas[i].dni=dni;
                printf("ingresar nombre: ");
                fflush(stdin);
                gets(listaPersonas[i].nombre);

                printf("Ingresar Edad: ");
                scanf("%i", listaPersonas[i].edad);

                //como el usuario no esta repetido, se carga exitosamente, estado pasa a 1
                listaPersonas[i].estado= 1
                estado=1;


            }

        }

    }

}

