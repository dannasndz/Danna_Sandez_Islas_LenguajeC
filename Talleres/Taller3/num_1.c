// Determinar si un número es positivo, negativo o cero.

#include <stdio.h>

int main()
{
    float num;
    printf("Ingrese un numero: \n");
    scanf("%f", &num);

    if (num > 0 && num != 0)
    {
        printf("El numero %.2f es positivo! \n", num);
    }
    else
    {
        if (num < 0 && num != 0)
        {
            printf("El numero %.2f es negativo! \n", num);
        }
        else
        {
            printf("El numero %.2f es cero! \n", num);
        }
    }

    return 0;
}