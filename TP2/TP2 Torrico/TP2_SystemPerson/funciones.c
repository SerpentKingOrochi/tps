
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#include "funciones.h"

int shearchPosition(EPersona xPerson[], int tam){
  int i, position = -1;

  for(i = 0; i<tam; i++){
    if(xPerson[i].estado != 1){
      position = i;
      break;
    }
  }

  return position;
}

int newPerson(EPersona xPerson[], int tam){

  int flagResult, position, dniLengt, edadLengt;
  char bufferNombre[50], bufferDni[50], bufferEdad[50];

  position = shearchPosition(xPerson, tam);

  if(position != -1){

    readCharacter(bufferNombre, "Ingrese Nombre: ");
    styleVector(bufferNombre);
    strcpy(xPerson[position].nombre, bufferNombre);


    readCharacter(bufferDni, "Ingrese Dni: ");
    dniLengt = strlen(bufferDni);

    validateDni(bufferDni, dniLengt,1,6);
    while(searchDni(xPerson, atoi(bufferDni), tam) != -1){
      readCharacter(bufferDni, "DNI existente.\nReingrese: ");
      dniLengt = strlen(bufferDni);
      validateDni(bufferDni,dniLengt,1,6);
    }

    xPerson[position].dni = atoi(bufferDni);


    readCharacter(bufferEdad, "Ingrese Edad: ");
    edadLengt = strlen(bufferEdad);

    while(edadLengt < 1 || edadLengt > 2){
      readCharacter(bufferEdad, "Formato de edad incorrecto.\nReingrese: ");
      edadLengt = strlen(bufferEdad);
    }
    xPerson[position].edad = atoi(bufferEdad);
    xPerson[position].estado = 1;

    flagResult = 1;

  }else{

    flagResult = 0;

  }

  return flagResult;
}

void validateDni(char buffer[],int length, int min, int max){
  while(length < min || length < max){
    readCharacter(buffer, "Formato de DNI incorrecto.\nReingrese: ");
    length = strlen(buffer);
  }
}

void styleVector(char cadena[]){
    int i;
    strlwr(cadena);

    cadena[0] = toupper(cadena[0]);

    for(i = 0; i < strlen(cadena); i ++){

      if(cadena[i] == ' '){

        cadena[i + 1] = toupper(cadena[i + 1]);
      }
    }
}

void viewPersons(EPersona lasPersonas[], int tam){

  int i;
  /*printf("--         Nombre           ----- Edad -----         DNI       --\n");
  printf("--                          -----      -----                   --\n");*/
  for(i=0; i<tam; i++){
      if(lasPersonas[i].estado == 1){
          printf("-----------------------------------------------------------------\n");
          printf("-- %s --  %d  --  %d  --\n", lasPersonas[i].nombre, lasPersonas[i].edad, lasPersonas[i].dni);
          printf("-----------------------------------------------------------------\n");
      }
  }
}

void viewPerson(EPersona lasPersonas[], int tam, int positionView){

  int i;

  /*printf("--         Nombre           ----- Edad -----         DNI       --\n");
  printf("--                          -----      -----                   --\n");*/
  for(i=0; i<tam; i++){
      if(lasPersonas[i].estado == 1 && positionView != -1 && i == positionView){
          printf("-----------------------------------------------------------------\n");
          printf("-- %s --  %d  --  %d  --\n", lasPersonas[i].nombre, lasPersonas[i].edad, lasPersonas[i].dni);
          printf("-----------------------------------------------------------------\n");
      }
  }
}


int searchDni(EPersona lista[], int dni, int tam){
    int i, position = -1;
    for(i = 0; i < tam; i++){
      if(lista[i].dni == dni && lista[i].estado == 1){
        position = i;
        break;
      }
    }
    return position;
}


int validMenu(int opcion, int min, int max){

  char opcionChar[20];

  while(opcion < min || opcion > max){
    printf("ERROR, Reingrese: ");
    fflush(stdin);
    scanf("%s",opcionChar);
    opcion = atoi(opcionChar);
  }

  return opcion;
}


void readCharacter(char characters[], char msg[]){
  showMessage(msg);
  fflush(stdin);
  gets(characters);
}


int changeFlag(int flag){
  int flagFunction;
  flagFunction = flag;

  return flagFunction;
}

void clearView(void){
  system("pause");
  system("cls");
}

void showMessage(char message[]){
  printf("%s", message);
}


int countState(EPersona lasPersonas[], int tam, int typeState){
  int i, count = 0;
  for(i = 0; i < tam; i++){
    if(lasPersonas[i].estado == typeState){
      count ++;
    }
  }
  return count;
}



void deletePerson(EPersona xPerson[],int position, char msgTrue[],char msgFalse[]){
  char option;

  if(position > -1){
    showMessage("Eliminar? <S/N>");
    option = tolower(getche());

    while(option !='s' && option !='n'){

      showMessage("\nERROR, Eliminar? <S/N>");
      option = tolower(getche());
    }
    printf("\n");
    if (option == 's'){

        xPerson[position].estado = 0;
        showMessage(msgTrue);

    }else{
      showMessage("Baja cancelada.\n");
    }
  }else{
    showMessage(msgFalse);
  }

}

void printGrafic(int count1, int count2, int count3){

    int grafico[] = {count1,count2, count3}, flag=0, maxNumGrafic, c, f, i;

    for(i = 0; i < 3; i ++){
        if(flag== 0 ||grafico[i] > maxNumGrafic){
            maxNumGrafic = grafico[i]; flag=1;
        }
    }
    putchar('\n');
    printf("-----------------------------------------------------------------\n");
    for(c = maxNumGrafic; c > 0; c--){
        for(f = 0; f < 3; f++){
            if(grafico[f] >= c){
                printf(" *\t");
            }else{
                printf("  \t");
            }

        }
        putchar('\n');
    }
    printf("<18\t19-35\t>35\n");
    printf(" %d\t  %d\t %d\n",count1, count2, count3);
    printf("-----------------------------------------------------------------\n");
}

void personOrderByAZ(EPersona lasPersonas[], int tam){
  char auxNombre[50];
  int i, j, auxInt = 0;

  for(i=0; i < tam-1; i++){
      if(lasPersonas[i].estado != 1){
        continue;
      }
      for(j=i+1; j <tam; j++){
          if(lasPersonas[j].estado != 1){
            continue;
          }
          if(strcmp(lasPersonas[i].nombre, lasPersonas[j].nombre)>0){
            strcpy(auxNombre,lasPersonas[i].nombre);
            strcpy(lasPersonas[i].nombre, lasPersonas[j].nombre);
            strcpy(lasPersonas[j].nombre,auxNombre);

            auxInt = lasPersonas[i].dni;
            lasPersonas[i].dni = lasPersonas[j].dni;
            lasPersonas[j].dni = auxInt;

            auxInt = lasPersonas[i].edad;
            lasPersonas[i].edad = lasPersonas[j].edad;
            lasPersonas[j].edad = auxInt;

          }
        }
  }
}

int countEdad(EPersona lasPersonas[], int tam, int min, int max){
  int i, count = 0;
  for(i = 0; i < tam; i ++){
    if(lasPersonas[i].estado == 1){
      if(lasPersonas[i].edad >= min && lasPersonas[i].edad <= max){
        count ++;
      }
    }
  }
  return count;
}
