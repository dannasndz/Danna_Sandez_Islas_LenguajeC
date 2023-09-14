#include <stdio.h>

// Prototipo de funciones

void calcularFibonacci(int n);

int main()
{
    int n;
    printf("Cuantas veces quieres que se repita Fibonacci: \n");
    scanf("%d", &n);
    calcularFibonacci(n);

    return 0;
}

// Desarrollo de funciones

void calcularFibonacci(int n)
{
    int a=-1,s=1,res;
    for (int i = 0; i < n; i++)
    {
        res = a + s;
        printf("%d", res);
        a = s;
        s = res;
    }
}