#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"

int cargarPersona(ePersona lista[], int tam)
{
    int posicion = buscarLibre(lista, tam);

    if(posicion != -1)
    {
        pedirYValidarLetras(lista, posicion);

        pedirEdad(lista, posicion);

        pedirDNI(lista, posicion);

        printf("\nCarga exitosa!\n\n");

        lista[posicion].estado = 1;

        return 1;
    }
    else
    {
        printf("\nNo hay espacio disponible\n\n");
        return 0;
    }
}

int buscarLibre(ePersona lista[], int tam)
{
    int i;
    int encontro = -1;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado == 0)
        {
            encontro = i;
            break;
        }
    }

    return encontro;
}

void borrarPersona (ePersona lista[], int tam)
{
    int flagEncontro = 0, i;

    int auxDni, respuesta;

    printf("Ingrese el DNI de la persona a borrar: \n");
    scanf("%d", &auxDni);

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado != 0 && auxDni == lista[i].dni)
        {
            printf("\n%s\t%d\t%d\n\n", lista[i].nombre, lista[i].edad, lista[i].dni);

            printf("Esta seguro de borrar esta persona? ingrese [s/n]: \n\n");
            respuesta = getche();

            if(respuesta == 's')
            {
                printf("\n\nPersona borrada con exito.\n\n");
                lista[i].estado = 0;
            }
            else
                printf("\n\nAccion cancelada por el usuario.\n\n");

            flagEncontro = 1;
            break;
        }
    }
    if(flagEncontro == 0)
        printf("Persona inexistente.\n\n");
}

void imprimirLista (ePersona lista[], int tam)
{
    int i;
    printf("\n*************************************\n\n");
    printf("Nombre\t\tEdad\tDNI\n\n");
    for(i=0; i<tam; i++)
        if(lista[i].estado == 1)
            printf("%s\t\t%d\t%d\n", lista[i].nombre, lista[i].edad, lista[i].dni);
    printf("\n*************************************\n\n");
}

void ordenarLista (ePersona lista[], int tam)
{
    int i, j, auxInt;
    char auxChar[30];

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(lista[i].nombre, lista[j].nombre)>0)
            {
                strcpy(auxChar, lista[i].nombre);
                strcpy(lista[i].nombre, lista[j].nombre);
                strcpy(lista[j].nombre, auxChar);

                auxInt = lista[i].edad;
                lista[i].edad = lista[j].edad;
                lista[j].edad = auxInt;

                auxInt = lista[i].dni;
                lista[i].dni = lista[j].dni;
                lista[j].dni = auxInt;

                auxInt = lista[i].estado;
                lista[i].estado = lista[j].estado;
                lista[j].estado = auxInt;
            }
        }
    }
    imprimirLista (lista, tam);
}

void pedirYValidarLetras(ePersona lista[], int posicion)
{
    int i, flag = 0;

    do
    {
        if(flag == 0)
        {
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(lista[posicion].nombre);
        }

        for (i=0; i<strlen(lista[posicion].nombre); i++)
        {
            if(! isalpha(lista[posicion].nombre[i]))
            {
                fflush(stdin);
                printf("Reingrese nombre: ");
                gets(lista[posicion].nombre);
                flag = 1;
            }
            else
                flag = 0;
        }
    }
    while(flag == 1);
}

void pedirEdad(ePersona lista[], int posicion)
{
    int esNum, auxEdad;
    char aux[10];

    printf("Ingrese edad: ");
    fflush(stdin);
    gets(aux);
    esNum = validarNum(aux);

    while (esNum == 0)
    {
        fflush(stdin);
        printf("Reingrese Edad: ");
        gets(aux);
        esNum = validarNum(aux);
    }
    auxEdad = atoi(aux);
    lista[posicion].edad = auxEdad;
}

void pedirDNI(ePersona lista[], int posicion)
{
    int esNum, auxDNI;
    char aux[10];

    printf("Ingrese DNI: ");
    fflush(stdin);
    gets(aux);
    esNum = validarNum(aux);

    while (esNum == 0)
    {
        printf("Reingrese DNI: ");
        fflush(stdin);
        gets(aux);
        esNum = validarNum(aux);
    }
    auxDNI = atoi(aux);
    lista[posicion].dni = auxDNI;

}


int validarNum(char num[])
{
    int i, flag = 0;

    for(i=0; i<strlen(num); i++)
    {
        if(! isdigit((num[i])))
            flag = 1;
    }
    if(flag == 1)
        return 0;
    else
        return 1;
}

void GraficoEdades (ePersona lista[], int tam)
{
    int i, cont1 = 0, cont2 = 0, cont3 = 0, mayor = 0, flag = 0;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado == 1)
        {
            if(lista[i].edad > 0 && lista[i].edad < 19)
                cont1++;
            else if(lista[i].edad > 18 && lista[i].edad < 36)
                cont2++;
            else if(lista[i].edad > 35 && lista[i].edad < 120)
                cont3++;
        }
    }


    if(cont1 >= cont2 && cont1 >= cont3)
        mayor = cont1;
    else if(cont2 >= cont1 && cont2 >= cont3)
        mayor = cont2;
    else
        mayor = cont3;

    for(i = mayor; i > 0; i--)
    {

        printf("%02d|",i);

        if(i <= cont1)
        {
            printf(" *");
        }
        if(i <= cont2)
        {
            flag = 1;
            printf("\t  *");
        }
        if(i <= cont3)
        {
            if(flag == 0)
                printf("\t\t *");
            if(flag == 1)
                printf("\t *");

        }
        printf("\n");
    }

    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n    %d  \t  %d\t %d \n\n", cont1, cont2, cont3);
}
