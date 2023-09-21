
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Prototipo de funciones

void calcularFibonacci(int n);
int calcularFibonacciR(int n);
int factorial(int n);
void generarTrianguloPascal(int n);

// Funcion main
int main()
{
    int n, op;
    do
    {
        system("CLS");
        printf("Que opcion te gustaria elegir?\n");
        printf("1- Fibonacci\n");
        printf("2- Fibonacci recursiva\n");
        printf("3- Triangulo de pascal\n");
        printf("4- Salir\n");
        printf("Ingresa una opcion numerica por favor: ");
        scanf("%d", &op);
        system("CLS");
        switch (op)
        {
        case 1:
            printf("Ingresa un numero: ");
            scanf("%d", &n);
            if (n <= 0)
            {
                printf("El numero debe ser postivo. Por favor intentalo de nuevo!\n");
                getch();
                break;
            }
            printf("El resultado de %d es: ", n);
            calcularFibonacci(n);
            printf("\n");
            system("PAUSE");
            break;
        case 2:
            printf("Ingresa un numero: ");
            scanf("%d", &n);
            if (n <= 0)
            {
                printf("El numero debe ser postivo. Por favor intentalo de nuevo!\n");
                getch();
                break;
            }
            int res = calcularFibonacciR(n - 1);
            printf("%d, su fibonacci es: %d", n, res);
            printf("\n");
            system("PAUSE");
            break;

        case 3:
            printf("Ingresa el numero de filas que desea: ");
            scanf("%d", &n);
            generarTrianguloPascal(n);
            break;
        }
    } while (op != 4);

    return 0;
}

// Desarrollo de funciones

void calcularFibonacci(int n)
{
    int a = -1, s = 1, res;
    for (int i = 0; i < n; i++)
    {
        res = a + s;
        printf("%d", res);
        a = s;
        s = res;
    }
}

int calcularFibonacciR(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return calcularFibonacciR(n - 1) + calcularFibonacciR(n - 2);
    }
}

// Funcion auxiliar para calcular factorial.
int factorial(int n)
{
    int i, res = 1;
    for (i = 1; i <= n; i++)
    {
        res *= i;
    }

    return res;
}

void generarTrianguloPascal(int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        printf("\nFila %d: ", i + 1);

        for (j = 0; j <= i; j++)
        {
            printf("%d ", (factorial(i) / (factorial(j) * factorial(i - j))));
        }
    }
}