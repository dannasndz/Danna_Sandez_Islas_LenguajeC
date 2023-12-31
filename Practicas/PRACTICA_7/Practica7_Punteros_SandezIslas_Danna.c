/*
    Nombre del archivo: Practica7_Punteros_SandezIslas_Danna.c
    Autor: Danna Sandez Islas
    Fecha de creación: 08 de noviembre de 2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_PALABRAS 5

/* PROTOTIPO DE FUNCIONES */
void argumentos(char *argv[]);
void ordenacion(void);
void matriz(void);

int main(int argc, char *argv[])
{
    int op;
    do
    {
        system("CLS");
        printf("     ---- MENU ----\n");
        printf("1.- Operaciones con argumentos\n");
        printf("2.- Ordenacion de palabras\n");
        printf("3.- Analisis de matriz\n");
        printf("0.- Salir\n");
        scanf("%d", &op);
        system("CLS");
        switch (op)
        {
        case 1:
            argumentos(argv);
            system("PAUSE");
            break;
        case 2:
            ordenacion();
            system("PAUSE");
            break;
        case 3:
            matriz();
            system("PAUSE");
            break;
        }
    } while (op != 0);
    printf("Gracias por usar el programa. Hasta luego!\n");
    return 0;
}

/*
    Función: argumentos
    Descripción: Esta función toma dos numeros enteros como argumentos desde la linea de comandos para utilizarlos.
    Parámetros:
    - argv: los numeros que se ingrean en consola
    Valor de retorno: Sin valor.
*/

void argumentos(char *argv[])
{
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    printf("La suma de %d + %d = %d\n", num1, num2, num1 + num2);
    printf("La resta de %d - %d = %d\n", num1, num2, num1 - num2);
    printf("La multiplicacion de %d * %d = %d\n", num1, num2, num1 * num2);
    printf("La division de %d / %d = %d\n", num1, num2, num1 / num2);
}

/*
    Función: ordenacion
    Descripción: Funcion que ordena las palabras mediante apuntadores.
    Parámetros: Void.
    Valor de retorno: Sin valor de retonro.
*/
void ordenacion()
{
    char *palabras[NUM_PALABRAS] = {"manzana", "banana", "cereza", "uva", "naranja"};
    char *temp;
    int i, j;
    /* ordenar */
    for (i = 0; i < NUM_PALABRAS - 1; i++)
    {
        for (j = i + 1; j < NUM_PALABRAS; j++)
        {
            if (strcmp(palabras[i], palabras[j]) > 0)
            {
                temp = palabras[i];
                palabras[i] = palabras[j];
                palabras[j] = temp;
            }
        }
    }
    /* imprimir */
    for (i = 0; i < NUM_PALABRAS; i++)
    {
        printf("%s\n", palabras[i]);
    }
}

/*
    Función: matriz
    Descripción: Esta función utiliza una matriz con n elementos, para realizar una suma, utilizando punteros.
    Parámetros: Void.
    Valor de retorno: Sin valor de retonro.
*/
void matriz()
{
    int matriz[3][3] = {{9, 8, 7},
                        {4, 5, 6},
                        {3, 2, 1}};
    int max = 0, fila = 0, col = 0, suma = 0;
    int *ptr = &matriz[0][0];
    for (int i = 0; i < 3 * 3; i++)
    {
        suma += *ptr;
        if (*ptr > max)
        {
            max = *ptr;
            fila = i / 3;
            col = i % 3;
        }
        ptr++;
    }
    printf("\nSuma de la matriz: %d\n", suma);
    printf("Elemento mas grande: %d\n", max);
    printf("Fila: %d\nColumna: %d\n", fila, col);
}