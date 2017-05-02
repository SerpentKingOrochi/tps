/*******************************************************************
*Programa: Trabajo Práctico n°2 de Laboratorio.
*
*Objetivo: Ingresar datos de hasta 20 personas, poder darlas de alta o baja, mostrar una lista con estas y un gráfico de edades.
*
*Fecha de entrega: 28 de abril del 2017.
*
*Autor: Brian Ezequiel Pariz.
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define P 20

int main()
{
    char seguir = 's';
    int opcion, contFlag = 0, i;
    ePersona lista[P];
    for(i=0; i<P; i++)
        lista[i].estado = 0;

    while(seguir == 's')
    {
        printf("Elige una opcion:\n\n");
        printf("1- Agregar persona.\n");
        printf("2- Borrar persona.\n");
        printf("3- Imprimir lista ordenada por nombre.\n");
        printf("4- Imprimir grafico de edades.\n\n");
        printf("5- Salir.\n\n");

        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            if(cargarPersona(lista, P) == 1)
                contFlag++;
            system("pause");
            break;

        case 2:
            if(contFlag >= 1)
            {
                borrarPersona(lista, P);
                contFlag--;
            }
            else
                printf("\nPrimero agrege una persona.\n\n");
            system("pause");
            break;

        case 3:
            if(contFlag >= 1)
                ordenarLista(lista, P);
            else
                printf("\nPrimero agrege una persona.\n\n");
            system("pause");
            break;

        case 4:
            if(contFlag >= 1)
                GraficoEdades(lista, P);
            else
                printf("\nPrimero agrege una persona.\n\n");
            system("pause");
            break;

        case 5:
            seguir = 'n';
            break;

        default:
            printf("\nIngrese una opcion del 1 al 5.\n\n");
            system("pause");
            break;
        }

        system("cls");
    }

    return 0;
}

