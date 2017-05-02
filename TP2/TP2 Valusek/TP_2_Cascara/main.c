#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANT_PERSONAS 20

int main()
{
    // arrays de clientes
    ePersona arrayPersonas[CANT_PERSONAS];
    //_________________________________________________
    ePersona auxiliarCliente;

    char    auxNombreApellidoStr[50];
    char    auxEdadStr[50];
    int     auxEdad;
    char    auxDniStr[50];
    int     auxDni;


    int indiceLugarLibre;
    int indiceResultadoBusqueda;

    int i,j;

    int contMenores=0;
    int contEntre=0;
    int contMayores=0;
    int maxNumGraf=0;


    char seguir='s';
    int opcion;

    inicializarArrayPersonas(arrayPersonas,CANT_PERSONAS,-1);

    while(seguir=='s')
    {
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        while(opcion <0 || opcion > 5)
        {
            printf("El numero seleccionado no es un opcion, reingrese una opcion correcta.\n");
            scanf("%d",&opcion);
        }

        switch(opcion)
        {
        case 1:

            indiceLugarLibre = obtenerEspacioLibre(arrayPersonas,CANT_PERSONAS,-1);
            if(indiceLugarLibre == -1)
            {
                printf("\n\nNO QUEDAN LUGARES LIBRES PARA AGREGAR PERSONAS!!!\n");
                break;
            }

            printf("\n<<<<< ALTA DE PERSONA >>>>>\n");

            if (!getStringLetras("\nIngrese el Nombre Y Apellido: ",auxNombreApellidoStr))
            {
                printf ("\nEl nombre debe estar compuesto solo por letras\n");
                break;
            }

            if (!getStringNumeros("Ingrese la edad: ",auxEdadStr))
            {
                printf ("La edad debe ser numerica\n");
                break;
            }
            auxEdad = atoi(auxEdadStr);

            if (auxEdad<=0)
            {
                printf ("La edad debe ser mayor a cero\n");
                break;
            }
            else
            {
                if(auxEdad > 0 && auxEdad < 18)
                {
                    contMenores++;
                }
                else if (auxEdad >=18 && auxEdad <=35)
                {
                    contEntre++;
                }
                else
                {
                    contMayores++;
                }
            }

            if (!getStringNumeros("Ingrese el DNI sin puntos: \n",auxDniStr))
            {
                printf ("El DNI debe ingresarse sin puntos ni letras\n");
                break;
            }
            auxDni = atoi(auxDniStr);

            if (buscarPorDni(arrayPersonas,CANT_PERSONAS,auxDni)!=-1)
            {
                printf ("\nError, el DNI ingresado ya existe.\n");
                break;
            }

            strcpy(arrayPersonas[indiceLugarLibre].nombre,auxNombreApellidoStr);
            arrayPersonas[indiceLugarLibre].edad = auxEdad;
            arrayPersonas[indiceLugarLibre].dni = auxDni;
            arrayPersonas[indiceLugarLibre].estado = 1;

            break;


        case 2:
            printf("\n<<<<< BAJA DE UNA PERSONA POR DNI >>>>>\n");

            if (!getStringNumeros("Ingrese el DNI de la persona a dar de baja: ",auxDniStr))
            {
                printf ("El DNI debe ingresarse sin puntos ni letras\n");
                break;
            }
            indiceResultadoBusqueda = buscarPorDni(arrayPersonas,CANT_PERSONAS,atoi(auxDniStr));

            if(indiceResultadoBusqueda == -1)
            {
                printf("\nNO SE ENCUENTRA EL DNI SOLICITADO\n");
                break;
            }
            arrayPersonas[indiceResultadoBusqueda].estado=-1;
            arrayPersonas[indiceResultadoBusqueda].edad=-1;

            break;

        case 3:
            printf("\n<<<<< ORDENAMIENTO POR NOMBRE >>>>>\n");

            for(i=0; i < CANT_PERSONAS - 1; i++)
            {
                if(arrayPersonas[i].estado == -1)
                {
                    continue;
                }
                for(j=i+1; j < CANT_PERSONAS; j++)
                {
                    if(arrayPersonas[j].estado == -1)
                    {
                        continue;
                    }
                    if(strcmp(arrayPersonas[i].nombre,arrayPersonas[j].nombre) > 0)
                    {
                        auxiliarCliente = arrayPersonas[j];
                        arrayPersonas[j] = arrayPersonas[i];
                        arrayPersonas[i] = auxiliarCliente;
                    }
                }
            }

            printf("\nNombre\tEdad\tDni\n");

            for(i=0; i<CANT_PERSONAS; i++)
            {
                if(arrayPersonas[i].estado != -1)
                {
                    printf("%s\t%d\t%d\n", arrayPersonas[i].nombre, arrayPersonas[i].edad, arrayPersonas[i].dni);
                }
            }

            break;
        case 4:

            printf("\n<<<<< GRAFICO POR EDADES >>>>>\n");

            printf("\n1ra columna: Menores de 18, 2da columna De 18 a 35 y \n3ra comlumna Mayores de 35.\n\n");

            int grafico[]= {contMenores,contEntre,contMayores};

            for (i = 0; i < 3; i++)
            {
                if (grafico[i] > maxNumGraf)
                    maxNumGraf = grafico[i];
            }

            for (i = maxNumGraf; i > 0; i--)
            {
                for (j = 0; j < 3; j++)

                    if (grafico[j] >= i)
                        printf(" *");

                    else

                        printf("  ");
                putchar('\n');
            }
            break;
        case 5:
            seguir = 'n';
            break;
        }
    }

    return 0;
}
