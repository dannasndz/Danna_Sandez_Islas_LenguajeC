#include <stdio.h>
#include <stdlib.h>

/* TALLER 5 */
/* Danna Sandez */

// variable
float PI = 3.14159;

void autoFunction(void);
void staticFunction(void);
void registerFunction(void);
void globalFunction(void);

int main()
{
    int op;
    do
    {
        system("CLS");
        printf("       MENU \n\n");
        printf("1- Variable automatica\n");
        printf("2- Variable estatica\n");
        printf("3- Variable de registro y automatica\n");
        printf("4- Variable global y local\n");
        printf("0- SALIR\n");
        printf("Ingresa una opcion: ");
        scanf("%d", &op);
        system("CLS");
        switch (op)
        {
        case 1:
            for (int i = 0; i < 10; i++)
            {
                autoFunction();
            }
            system("PAUSE");
            break;
        case 2:
            for (int i = 0; i < 10; i++)
            {
                staticFunction();
            }
            system("PAUSE");
            break;
        case 3:
            registerFunction();
            system("PAUSE");
            break;
        case 4:
            printf("Variable global: %f\n", PI);
            globalFunction();
            printf("Variable global despues de variable local: %f\n", PI);
            system("PAUSE");
            break;
        }
    } while (op != 0);
    printf("Gracias por usar el programa. Hasta luego!");

    return 0;
}

void autoFunction(void)
{
    int counter = 0;
    counter++;
    printf("%d\n", counter);
}

void staticFunction(void)
{
    static int counter = 0;
    counter++;
    printf("%d\n", counter);
}

void registerFunction(void)
{
    register int temp;
    int valor;
    temp = 10;
    valor = 10;

    printf("El valor del temp es: %d\n", temp);
    printf("El valor de valor es: %d\n", valor);
}

void globalFunction(void)
{
    float PI = 3.1416;
    printf("Valor de la variable local: %f\n", PI);
}