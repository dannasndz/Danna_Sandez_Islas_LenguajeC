/* 
    TALLER 6 
    Danna Sandez 
*/

#include "amor_amarillo.h"

int *multiplicarPorDos(int *ptr);
void sumarAElementos(int *ap, int num);

int main()
{
    srand(time(NULL));

    /*
        Apuntadores Básicos: Dado un entero x, crea un apuntador ptr que apunte a
        x. Luego, imprime el valor de x y el valor al que apunta ptr.
    */
    int x = 6;
    int *ptr = &x;
    printf("x= %d\nDireccion de &x= %p\n", x, &ptr);

    /*
        Pasar Apuntadores a una Función:Escribe una función llamada
        multiplicarPorDos que tome un apuntador a un entero como argumento. Dentro
        de la función, multiplica el valor al que apunta el apuntador por 2. Luego, llama
        a esta función desde main() y muestra el valor modificado.
    */
    multiplicarPorDos(ptr);
    printf("El resultado de X por 2 es: %d\n\n", x);

    /*
        Arreglos: Crea un arreglo de enteros de tamaño 7 (Los valores que genere
        sean random entre 1-50, y que los valores no sean repetidos). Luego, crea un
        apuntador que apunte al primer elemento del arreglo. Utiliza un bucle para
        imprimir todos los elementos del arreglo utilizando el apuntador.
    */
    int array[7];
    int num;
    for (int i = 0; i < 7; i++)
    {
        do
        {
            num = numAleatorio(1, 50);
        } while (repetidoVect(num, i, array) != 0);
        array[i] = num;
    }

    /*
        Modificar Elementos de un Arreglo: Escribe una función llamada
        sumarAElementos que tome un apuntador a un arreglo de enteros y un valor
        entero como argumentos. Dentro de la función, suma el valor entero a cada
        elemento del arreglo utilizando aritmética de direcciones. Llama a esta función
        desde main() y muestra el arreglo modificado.
    */

    int *ap = &array[0];
    for (int i = 0; i < 7; i++)
    {
        printf("Array[%d]: %d\n", i, *(ap + i));
    }
    int n = 4;
    printf("\nArray sumando %d\n", n);
    sumarAElementos(ap, n);

    return 0;
}

int *multiplicarPorDos(int *ptr)
{
    *ptr = (*ptr) * 2;

    return ptr;
}

void sumarAElementos(int *ap, int num)
{
    for (int j = 0; j < 7; j++)
    {
        *ap = (*ap) + num;
        printf("Array[%d]: %d\n", j, *ap);
        ap++;
    }
}