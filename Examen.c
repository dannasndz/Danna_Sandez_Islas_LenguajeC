/*
    Danna Sandez Islas 
    373080
    Examen
*/

#include <stdio.h>
#include <stdlib.h>

int validar(char mensj[], int ri, int rf);

int main()
{
    int op;
    do
    {
        system("CLS");
        int n;
        n = validar("Ingresa un numero ENTERO positivo: ", 1, 100000);
        system("CLS");

        int divisores = 0;

        for (int i = 1; i < n; i++)  
        {
            if ((n % (n - i) == 0)) // verifica si el residuo es == 0, lo que signfica que su divisor es un entero
            {
                divisores += n - i; 
                printf("----Divisor---\n");
                printf("%d\n", (n - i));
            }
        }
        printf("La suma de los divisores propios positivos es: %d\n", divisores);
        if (divisores == n)
        {
            printf("El numero %d es perfecto\n", n);
        }
        else
        {
            printf("El numero %d no es perfecto\n", n);
        }
        system("PAUSE");
        system("CLS");

        printf("Te gustaria intentarlo de nuevo?\n 1-Si\n 2-No\n");
        printf("Ingresa una opcion: ");
        scanf("%d", &op);
    } while (op != 2);
    printf("Gracias por usar el programa. Hasta luego!");

    return 0;
}

int validar(char mensj[], int ri, int rf)
{
    // variables locales
    int num;
    char cadena[100];
    // desarrollo de funcion
    do
    {
        printf("%s", mensj);
        fflush(stdin);
        gets(cadena);
        num = atoi(cadena); // cambia a numeros la cadena

    } while (num < ri || num > rf);

    return num; // retorna el valor que haya tomado num, entre los rangos dados por el usuario
}