#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funcionesTP2.h"

void inicializarEstado(ePersona lista[], int tam, int estado)
{
    for(int i=0; i<tam; i++)
    {
        lista[i].estado = estado;
    }
}

int menuOpciones()
{
    int opcion, aux;

    printf("\n--=--=--=--=--=-- MENU --=--=--=--=--=--\n\n");
    printf("1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- Imprimir lista ordenada por nombre\n");
    printf("4- Imprimir grafico de edades\n");
    printf("5- Salir\n");
    printf("\nOPCION: ");
    scanf("%d", &aux);
    while(aux<1 || aux>5)
    {
        printf("\nERROR. Opcion no valida. Reingrese: ");
        scanf("%d", &aux);
    }
    opcion=aux;

    return opcion;
}

int obtenerEspacioLibre(ePersona lista[], int tam)
{
    int index=-1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].estado==-1)
        {
            index=i;
            break;
        }
    }
    return index;
}

int obtenerDNI()
{
    int num, numValidado;

    printf("\nIngrese numero de DNI: ");
    fflush(stdin);
    scanf("%d", &num);
    while(num<1000000 || num>99999999)
    {
        printf("\nERROR. DNI no valido. Reingrese: ");
        scanf("%d", &num);
    }
    numValidado=num;
    return numValidado;
}

int buscarPorDni(ePersona lista[], int tam, int dni)
{
    int index=-1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].dni==dni && lista[i].estado!=-1)
        {
            index=i;
            break;
        }
    }
    return index;
}

int soloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

int obtenerEdad()
{
    int num, numValidado;

    printf("Ingrese edad: ");
    fflush(stdin);
    scanf("%d", &num);
    while(num<1 || num>120)
    {
        printf("\nERROR. Edad no invalida. Reingrese: ");
        scanf("%d", &num);
    }
    numValidado=num;
    return numValidado;
}

void mostrarPersona(ePersona x)
{
    printf("\nDNI: %d", x.dni);
    printf("\nNombre: %s", x.nombre);
    printf("\nEdad: %d\n", x.edad);
}

int eliminarPersona()
{
    int respuesta=0;

    printf("\nConfirma eliminar persona?: ");
    fflush(stdin);
    respuesta=getche();
    printf("\n");
    if(respuesta=='s')
    {
        respuesta=-1;
    }
    return respuesta;
}

void ordenar(ePersona lista[], int tamanio)
{
    int auxEdad, auxDNI, aux;
    char auxNombre[50];

    for(int i=0; i<tamanio-1; i++)
    {
        for(int j=i+1; j<tamanio; j++)
        {
            if(strcmp(lista[i].nombre, lista[j].nombre)>0)
            {
                aux=lista[i].estado;
                lista[i].estado=lista[j].estado;
                lista[j].estado=aux;

                auxEdad=lista[i].edad;
                lista[i].edad=lista[j].edad;
                lista[j].edad=auxEdad;

                auxDNI=lista[i].dni;
                lista[i].dni=lista[j].dni;
                lista[j].dni=auxDNI;

                strcpy(auxNombre, lista[i].nombre);
                strcpy(lista[i].nombre, lista[j].nombre);
                strcpy(lista[j].nombre, auxNombre);
            }
            if(strcmp(lista[i].nombre, lista[j].nombre)==0)
            {
                if(lista[i].dni>lista[j].dni)
                {
                    aux=lista[i].estado;
                    lista[i].estado=lista[j].estado;
                    lista[j].estado=aux;

                    auxEdad=lista[i].edad;
                    lista[i].edad=lista[j].edad;
                    lista[j].edad=auxEdad;

                    auxDNI=lista[i].dni;
                    lista[i].dni=lista[j].dni;
                    lista[j].dni=auxDNI;

                    strcpy(auxNombre, lista[i].nombre);
                    strcpy(lista[i].nombre, lista[j].nombre);
                    strcpy(lista[j].nombre, auxNombre);
                }
            }
        }
    }
}

void graficoEdades(ePersona lista[], int tam)
{
    int flag=0, mayor, hasta18=0, de19a35=0, mayorDe35=0;

    for (int i=0; i<tam; i++)
    {
        if(lista[i].estado!=-1)
        {
            if(lista[i].edad<=18)
            {
                hasta18++;
            }
            else if(lista[i].edad>18 && lista[i].edad<36)
            {
                de19a35++;
            }
            else
            {
                mayorDe35++;
            }
        }
    }

    if(hasta18 >= de19a35 && hasta18 >= mayorDe35)
    {
        mayor = hasta18;
    }
    else
    {
        if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
        {
            mayor = de19a35;
        }
        else
        {
            mayor = mayorDe35;
        }
    }

    for(int i=mayor; i>0; i--)
    {
        if(i<10)
        {
            printf("%02d|",i);
        }
        else
            printf("%02d|",i);

        if(i<= hasta18)
        {
            printf(" *");
        }
        if(i<= de19a35)
        {
            flag=1;
            printf("\t*");
        }
        if(i<= mayorDe35)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t *");

        }
        //Bajo una linea luego de cada iteracion
        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35\n\n");



}
