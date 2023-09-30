// El ejercicio debe permitir ingresar un año y determine si ese año es bisiesto o no.

#include <stdio.h>

int main()
{
    int año;
    printf("Ingrese el año: \n");
    scanf("%d", &año);

    if ((año % 4 == 0 && año % 100 != 0) || (año % 400 == 0))
    {
        printf("El año %d es bisiesto! \n", año);
    }
    else
    {
        printf("El año %d no es bisiesto! \n", año);
    }

    return 0;
}
