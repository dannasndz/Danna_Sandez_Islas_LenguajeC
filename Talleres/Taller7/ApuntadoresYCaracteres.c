/*
    Nombre del archivo: Taller7_ApuntadoresYCaracteres.c
    Autor: Danna Sandez Islas
    Fecha de creación: 25 de octubre de 2023
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void imprimirNombres(char *nombres[], int n);
void invertirCadena(char *cadena);
void ordenarPalabras(char *palabras[], int n);

int main()
{
    char *nombres[] = {"Danna", "Sandez", "Islas"};
    char *nombre[3][20];
    char cadena[] = {"Danna"};
    char *palabras[5][20];
    int j = 0,op;
    printf("Ingresa una opcion entre 1-5: ");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        for (int i = 0; i < 3; i++)
        {
            printf("%s\n", nombres[i]);
            system("PAUSE");
        }
        break;
    case 2:
        do
        {
            printf("Ingresa un nombre: ");
            scanf("%s", nombre[j]);
            j++;
        } while (j < 3);
        system("CLS");
        printf("---Nombres almacenados---\n");
        for (int i = 0; i < 3; i++)
        {
            printf("Nombre %d: %s\n", i + 1, nombre[i]);
        }
        break;
    case 3:
        imprimirNombres(cadena, 3);
        break;
    case 4:
        printf("Cadena original: %s\n", cadena);
        invertirCadena(cadena);
        printf("Cadena invertida: %s", cadena);
        break;
    case 5:
        for (int i = 0; i < 5; i++)
        {
            printf("Ingrese la palabra %d: ", i + 1);
            scanf("%s",palabras[i]);
        }

        ordenarPalabras(palabras, 5);
        system("PAUSE");
        break;
    }

    return 0;
}

void imprimirNombres(char *nombres[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Nombre %d: %s\n", i + 1, nombres[i]);
        system("PAUSE");
    }
}

void invertirCadena(char *cadena)
{
    int j = strlen(cadena) - 1;

    int i = 0;
    char temp;

    while (i < j)
    {
        temp = cadena[i];
        cadena[i] = cadena[j];
        cadena[j] = temp;
        i++;
        j--;
    }
}

void ordenarPalabras(char *palabras[], int n)
{
    int i, j;
    char *temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(palabras[i], palabras[j]) > 0)
            {
                temp = palabras[i];
                palabras[i] = palabras[j];
                palabras[j] = temp;
            }
        }
    }

    imprimirNombres(palabras,5);
}