// Determinar si un número es par y positivo al mismo tiempo.

#include <stdio.h>

int main()
{
    int num;

    printf("Ingrese un numero: \n");
    scanf("%d", &num);

    if (num % 2 == 0 && num > 0)
    {
        printf("El numero %d es par y positivo! \n", num);
    }
    else
    {
        printf("El numero  %d no es par ni positivo!", num);
    }
    return 0;
}