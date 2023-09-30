// El ejercicio debe permitir ingresar grados Celsius y debe convertirlos a grados Fahrenheit.

#include <stdio.h>

int main()
{
    float gC, gF;
    printf("Ingrese los grados Celsius: \n");
    scanf("%f", &gC);
    // ºF = ºC x 1.8 + 32  | Formula
    gF = ((gC*(1.8)) + 32);
    printf("Grados Celsius a Fahrenheit \n");
    printf("Grados Celsius: %.2f \n", gC);
    printf("Grados Fahrenheti: %.2f \n", gF);
    return 0;
}