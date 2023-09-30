//Cuanto daría la siguiente expresión aritmética resultado = (a * b + c) / (b - a), si a=5 , b =3 y c=7. (Realiza el procedimiento realizado)

#include <stdio.h>

int main (){

    float res;
    int a=5, b=3, c=7;
    res=(a*b+c)/(b-a);
    printf("El resultado es: %.2f", res);

    return 0;
}