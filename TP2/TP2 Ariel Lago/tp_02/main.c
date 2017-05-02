/**************
2.1 Descripción
Definir una estructura que represente una persona, con los campos nombre, edad, dni y un
flag de estado.
Hacer un programa que defina un array de 20 ítems de esta estructura y con un menú como el
siguiente:
1. Agregar una persona
2. Borrar una persona
3. Imprimir lista ordenada por nombre
4. Imprimir gráfico de edades
Se utilizará el campo de estado para indicar si el ítem del array esta ocupado o no.
El gráfico deberá ser un gráfico de barras en donde se agruparán 3 barras:
• Menores de 18
• De 19 a 35
• Mayores de 35.
En el eje Y se marcarán la cantidad de personas en el grupo, y en el eje X el grupo
Ejemplo:
*
*    *
*    *      *
*    *      *
*    *      *
*    *      *
<18 19-35 >35
Gráfico para una estadística de 6 personas con edad menor a 18, 4 personas con edades entre
19 y 35, y 5 personas con edades mayores a 35.
UTN
**********************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define LENGTH 20
int main()
{
    //DECLARACION DE VARIABLES
    int opc, i, j, contadorPersona;
    long int dni;
    //NOMBRE, DNI, EDAD Y FLAG
    ePersona persona[LENGTH];

    //INICIALIZA LA VARIABLE FLAG DE PERSONA
    for(opc = 0; opc < LENGTH; opc++)
    {
        persona[opc].flag = 0;
    }
    do
    {
        contadorPersona = contarPersona(persona, LENGTH);
        printf("1- Agregar Persona (Cantidad de personas ingresadas = %d)\n2- Borrar persona\n3- imprimir lista ordenada por nombre\n4- Imprimir grafico de edades\n5- Salir\nElija una opcion: ", contadorPersona);
        scanf("%d", &opc);
        switch(opc)
        {
        case 1:
            darAltaPersona(persona, LENGTH);
            break;
        case 2:
            dni = getLongInt("Ingrese DNI de la persona a borrar: ");
            borrarPersona(persona, LENGTH, dni);
            break;
        case 3:
            ordenarPersonaNombreMenorMayor(persona, LENGTH);
            break;
        case 4:
            imprimirMatrizEdad3Col(persona, LENGTH);
            break;
        case 5:
            printf("CHAU!");
            waitFor(2);
            break;
        default:
            printf("Opción invalida!\n");
            system("pause");
            system("cls");
        }
    }
    while(opc != 5);
    return 0;
}

int contarPersona(ePersona persona[], int size)
{
    int i, cont = 0;
    for(i = 0; i < size; i++)
    {
        if(persona[i].flag == 1)
        {
            cont++;
        }
    }
    return cont;
}
