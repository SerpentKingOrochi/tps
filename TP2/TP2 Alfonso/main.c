#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funcionesTP2.h"

#define TAM 20

int main()
{
    ePersona gente[TAM];
    int opcion, auxDNI, indice;
    char auxNombre[50];

    inicializarEstado(gente, TAM, -1);
    do
    {
        opcion=menuOpciones();
        switch(opcion)
        {
        case 1:
            indice=obtenerEspacioLibre(gente, TAM);
            if(indice==-1)
            {
                printf("\nNO HAY LUGAR DISPONIBLE.\n");
            }
            else
            {
                auxDNI=obtenerDNI();
                if(buscarPorDni(gente, TAM, auxDNI)==-1)
                {
                    gente[indice].dni=auxDNI;
                }
                else
                {
                    printf("\nEL DNI INGRESADO YA EXISTE\n");
                    break;
                }

                printf("Ingrese nombre: ");
                fflush(stdin);
                gets(auxNombre);
                while(strlen(auxNombre)>49 || (soloLetras(auxNombre)!=1))
                {
                    printf("ERROR. Nombre no valido. Reingrese: ");
                    fflush(stdin);
                    gets(auxNombre);
                }
                strcpy(gente[indice].nombre, auxNombre);

                gente[indice].edad=obtenerEdad();
                gente[indice].estado=0;
            }
            break;
        case 2:
            auxDNI=obtenerDNI();
            if(buscarPorDni(gente, TAM, auxDNI)==-1)
            {
                printf("\nEL DNI INGRESADO NO EXISTE\n");
            }
            else
            {
                for(int i=0; i<TAM; i++)
                {
                    if(gente[i].dni==auxDNI)
                    {
                        mostrarPersona(gente[i]);
                        if(eliminarPersona()==-1)
                        {
                            gente[i].estado=-1;
                        }
                        else
                        {
                            printf("Accion cancelada por el usuario!\n");
                        }
                    }
                }
            }
            break;
        case 3:
            ordenar(gente, TAM);
            for(int i=0; i<TAM; i++)
            {
                if(gente[i].estado!=-1)
                {
                    mostrarPersona(gente[i]);
                }
            }
            break;
        case 4:
            graficoEdades(gente, TAM);
            break;
        case 5:
            printf("\nSALIENDO...\n\n");
            break;
        default:
            break;
            }
            system("pause");
            system("cls");
    }while(opcion!=5);

    return 0;
}
