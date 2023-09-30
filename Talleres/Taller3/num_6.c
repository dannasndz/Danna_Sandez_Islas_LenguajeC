#include <stdio.h>

// PROTOTIPO DE FUNCION
void conBin();

//  FUNCION PRINCIPAL
int main()
{
    conBin();
    return 0;
}

// DESARROLLO DE FUNCION

void conBin() // Funcion que convierte decimal binario
{
    int decimal, n_bits, temp, i, j, k;
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

        printf("\nComplemento: \n");
        for (k = i - 1; k >= 0; k--
        )
        {
            if (bit[k] == 1)
            {
                printf("0");
            }
            else
            {
                printf("1");
            }
        }


    }
    /*
    // Si no se encontraron bits
    if (bit_encendido == -1)
    {
        printf("No se encontraron bits encendidos\n");
    }
    */
}


