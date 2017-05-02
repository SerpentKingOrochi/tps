#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#define LENGT_VECTOR 20

int main()
{
    EPersona Person[LENGT_VECTOR];

    char seguir = 's', opcionChar[20], dniCharacter[12];
    int opcionInt, flagFields = 0, positionSearch, dniInt = 0, countMin18 = 0,count19a30 = 0, countMax30 = 0, countDisponible = LENGT_VECTOR;

    while(seguir == 's')
    {
        printf("-----------------------------------------------------------------\n");
        printf("------------------------- System Persons ------------------------\n");
        printf("-----------------------------------------------------------------\n");
        printf("-                                                               -\n");
        printf("-                      1- Agregar persona                       -\n");
        printf("-                       2- Borrar persona                       -\n");
        printf("-            3- Imprimir lista ordenada por  nombre             -\n");
        printf("-                 4- Imprimir grafico de edades                 -\n");
        printf("-                           5- Salir                            -\n");
        printf("-                                                               -\n");
        if(countDisponible < 10){
        printf("-                                        Espacio Disponible: 0%d -\n",countDisponible);
        }else{
        printf("-                                        Espacio Disponible: %d -\n",countDisponible);
        }
        printf("-----------------------------------------------------------------\n");
        printf("-------------------------------------- Torrico Roberto 1H -------\n");
        printf("-----------------------------------------------------------------\n");
        printf("Ingrese una opcion: ");

        fflush(stdin);
        scanf("%s", opcionChar);
        opcionInt = atoi(opcionChar);

        opcionInt = validMenu(opcionInt, 1, 5);

        switch(opcionInt){
            case 1:

                if(newPerson(Person, LENGT_VECTOR)){
                  flagFields = changeFlag(1);
                  countDisponible --;
                }else{
                  showMessage("El sistema se encuantra cargado en su totalidad.\n");
                }

                break;
            case 2:

                if(flagFields){
                  readCharacter(dniCharacter,"Ingrese el dni que desea eliminar: ");

                  dniInt = atoi(dniCharacter);
                  positionSearch = searchDni(Person,dniInt,LENGT_VECTOR);

                  viewPerson(Person,LENGT_VECTOR,positionSearch);

                  deletePerson(Person,positionSearch,"Conjunto de datos eliminados.\n","ERROR, el dni no figura en el sistema.\n");
                  flagFields = countState(Person,LENGT_VECTOR,1);
                  countDisponible ++;
                }else{
                  showMessage("Sistema vacio.\n");
                }

                break;
            case 3:
                if(flagFields){
                  personOrderByAZ(Person,LENGT_VECTOR);
                  viewPersons(Person, LENGT_VECTOR);
                }else{
                  showMessage("Sistema vacio\n");
                }
                break;
            case 4:
                if(flagFields){

                    countMin18 = countEdad(Person,LENGT_VECTOR,1,18);
                    count19a30 = countEdad(Person,LENGT_VECTOR,19,35);
                    countMax30 = countEdad(Person,LENGT_VECTOR,36,99);
                    printGrafic(countMin18, count19a30, countMax30);

                }else{
                  showMessage("Sistema vacio\n");
                }
                break;
            case 5:
                seguir = 'n';
                break;
        }
        clearView();
    }
    return 0;
}
