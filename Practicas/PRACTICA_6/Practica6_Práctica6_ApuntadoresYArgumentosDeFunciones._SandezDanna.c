/*
    Nombre del archivo: mi_programa.c
    Autor: Tu Nombre
    Fecha de creación: 12 de septiembre de 2023
    Descripción: Este archivo contiene el código principal de mi programa.
*/

#include "amor_amarillo.h"

/*** Prototipo de funciones ***/
int suma(int *ap, int n);
void copy_array(int *ap, int *un, int n);
void concatenar(int *ap, int *un, int *tador, int n);
int comparar(int *ap, int *un, int n);
int max(int *ap, int n);

int main()
{
    int cerati[] = {2, 4, 6, 8, 10};
    size_t n = sizeof(cerati) / sizeof(cerati[0]);
    int spinetta[5];
    int charly[10];
    int *tador = &charly[0];
    int *ap = &cerati[0];
    int *un = &spinetta[0];
    int res = 0;

    int op;
    do
    {
        system("CLS");
        printf("      ---- MENU ----\n\n");
        printf("1-Suma de elementos en un arreglo\n");
        printf("2-Copia de arreglos\n");
        printf("3-Concatenacion de arreglos\n");
        printf("4-Comparacion de arreglos\n");
        printf("5-Encontrar el elemento maximo\n");
        printf("0- SALIR\n");
        op = validar("Ingresa una opcion numerica: ", 0, 6);
        system("CLS");

        switch (op)
        {
        case 1:
            res = suma(ap, n);
            for (int i = 0; i < 5; i++)
            {
                printf("Cerati[%d]= %d\n", i, cerati[i]);
            }
            printf("Suma: %d\n", res);
            system("PAUSE");
            break;
        case 2:
            copy_array(ap, un, n);
            for (int i = 0; i < 5; i++)
            {
                printf("Spinetta[%d]=%d\n", i, spinetta[i]);
            }
            system("PAUSE");
            break;
        case 3:
            concatenar(ap, un, tador, n);
            for (int i = 0; i < 10; i++)
            {
                printf("Charly[%d]= %d\n", i, charly[i]);
            }
            system("PAUSE");
            break;
        case 4:
            res = comparar(ap, un, n);
            if (res != -1)
            {
                printf("Los arreglos Cerati y Spinetta, son exactamente iguales\n");
            }
            else
            {
                printf("Los arreglos Cerati y Spinetta, son diferentes\n");
            }
            system("PAUSE");
            break;
        case 5:
            res = max(ap, n);
            printf("El numero maximo del arreglo Cerati es: %d\n",res);
            system("PAUSE");
            break;
        }
    } while (op != 0);
    printf("Gracias por usar el programa. Hasta luego!");

    return 0;
}

/*** Desarrollo de funciones ***/

/*
    Función: suma
    Descripción: Esta función suma todos los valores de un array.
    Parámetros:
    - *ap= apuntador que apunta a los valores del array.
    - n= tamaño del array.
    Valor de retorno: res=la suma de todos los valores del array.
*/

int suma(int *ap, int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += *(ap + i);
    }
    return res;
}

/*
    Función: coy_array
    Descripción: copia los valores de un array y los pega en otro array diferente.
    Parámetros:
    - *ap= apuntador que apunta a los valores del primer array.
    - *un= apuntador que se dirige a los valores del segundo array.
    -   n= tamaño del array.
    Valor de retorno: Sin valor de retorno.
*/

void copy_array(int *ap, int *un, int n)
{
    for (int i = 0; i < n; i++)
    {
        *(un + i) = *(ap + i);
    }
}

/*
    Función: concatenar
    Descripción: copia los valores de dos arrays y los pega en un tercer array.
    Parámetros:
    - *ap= apuntador que apunta a los valores del primer array.
    - *un= apuntador que se dirige a los valores del segundo array.
    - *tador= apuntador que se dirige a los valores del tercer array.
    -   n= tamaño del array.
    Valor de retorno: Sin valor de retorno.
*/

void concatenar(int *ap, int *un, int *tador, int n)
{
    for (int i = 0; i < n; i++)
    {
        *(tador + i) = *(ap + i);
    }
    for (int i = 0; i < (n * 2); i++)
    {
        *(tador + n + i) = *(un + i);
    }
}

/*
    Función: comparar
    Descripción: compara los valores a los que se dirigen los apuntadores de un array.
    Parámetros:
    - *ap= apuntador que apunta a los valores del primer array.
    - *un= apuntador que se dirige a los valores del segundo array.
    -   n= tamaño del array.
    Valor de retorno: -1 si son diferentes, 1 si son iguales.
*/

int comparar(int *ap, int *un, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (*(ap + i) != *(un + i))
        {
            return -1;
        }
    }
    return 1;
}

/*
    Función: max
    Descripción: Busca el elemento mayor en un array mediante su apuntador
    Parámetros:
    - *ap= apuntador que apunta a los valores del primer array.
    -   n= tamaño del array.
    Valor de retorno: numero mayor del array.
*/

int max(int *ap, int n)
{
    int mayor;
    mayor = *ap;
    for (int i = 1; i < n; i++)
    {
        if (*(ap + i) > mayor)
        {
            mayor = *(ap+i);
        }
    }
    return mayor;
}