#include <stdio.h>

// PROTOTIPO DE FUNCIONES

void conBin();
void despBin();

// FUNCION PRINCIPAL

int main()
{
    int num = 5;
    conBin();
    num = num << 2;
    printf("\nNumero desplazado = %d\n",num);
    despBin(num);
    
    return 0;
}

// DESARROLLO DE FUNCIONES

void conBin() // Funcion que convierte decimal binario
{
    int decimal, n_bits, temp, i, j;
    printf("Ingresa un numero decimal: \n");
    scanf("%d", &decimal);

    // Validar numero positivo
    if (decimal < 0)
    {
        printf("\nO");
    }
    else
    {
        // Calcular bits necesarios
        temp = decimal;
        n_bits = 0;
        while (temp > 0)
        {
            temp /= 2;
            n_bits++;
        }

        // Crear arreglo
        int bit[n_bits];
        i = 0;
        while (decimal > 0)
        {
            bit[i] = decimal % 2;
            decimal /= 2;
            i++;
        }

        printf("Numero en binario:\n");
        for (j = i - 1; j >= 0; j--)
        {
            printf("%d", bit[j]);
        }
        
    }
}

void despBin(int a) // Funcion que convierte decimal binario
{
    int n_bits, temp, i, j;
    // Validar numero positivo
    if (a < 0)
    {
        printf("\nO");
    }
    else
    {
        // Calcular bits necesarios
        temp = a;
        n_bits = 0;
        while (temp > 0)
        {
            temp /= 2;
            n_bits++;
        }

        // Crear arreglo
        int bit[n_bits];
        i = 0;
        while (a > 0)
        {
            bit[i] = a % 2;
            a /= 2;
            i++;
        }

        printf("Numero desplazado en binario:\n");
        for (j = i - 1; j >= 0; j--)
        {
            printf("%d", bit[j]);
        }
        
    }
}


