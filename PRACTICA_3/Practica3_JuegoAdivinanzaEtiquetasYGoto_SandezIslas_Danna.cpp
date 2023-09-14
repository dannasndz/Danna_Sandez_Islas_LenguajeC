/*
Nombre del archivo: Pracctica3_JuegoAdivinanzaEtiquetasYGoto_SandezIslas_Danna.cpp
Autor: Danna Guadalupe Sandez Islas
Fecha de creación: 12 de septiembre de 2023
Descripción: Este archivo contiene el código principal de mi programa.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

// Funcion principal

int main()
{
    int secretNum;
    srand(time(NULL));
    secretNum = rand() % 100 + 1;

    int tries = 0;

start:
    printf("               Bienvenido a Adivina el numero! \nEl juego consiste en ir ingresando una cifra entre 1 y 100. Podras ganar cuando adivines el numero en el que estoy pensando, estas listo? \n");

guess:
    int num;

    while (tries < 100) // ciclo donde se realiza el juego
    {
        printf(" \nEn que numero crees que estoy pensando? \n");
        printf("\nIngresa el numero: ");
        scanf("%d", &num);
        tries++;
        getch();
        printf("\e[1;1H\e[2J");
        if (num == secretNum)
        {
            printf("\nHas ganado :D Exactamente estaba pensando en el numero %d \n", secretNum);
            break;
        }
        if (num > secretNum)
        {
            printf("\nDemasiado alto :( \nIntentalo de nuevo! \n ");
            goto guess;
        }
        else
        {
            printf("\nDemasiado bajo :( \nIntentalo de nuevo: \n");
            goto guess;
        }
    }
// Etiqueta para reiniciar el juego donde se le pide al usuario que ingrese una opcion entre 1 y 2
restart:

    int op;

    printf("Desea jugar de nuevo? \n 1- Si \n 2- No \n");
    printf("Ingresa la opcion NUMERICA:");
    scanf("%d", &op);
    printf("\e[1;1H\e[2J");
    
    switch (op)
    {
    case 1:
        tries = 0;
        secretNum = rand() % 100 + 1;
        goto start;
        break;
    case 2:
        printf("Gracias por jugar! Nos vemos pronto :D");
        break;

    default:
        printf("La opcion que escogiste no es valida! Por favor ingresa una opcion correcta \n");
        goto restart;
        break;
    }

    return 0;
}