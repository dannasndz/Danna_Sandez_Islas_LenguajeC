/*
Nombre del archivo: Practica5_ClasesDeAlmacenamiento_SandezIslas_Danna.c
Autor: Danna Sandez Islas
Fecha de creación: 30 de septiembre de 2023
Descripción: Programa completo de la practica 5. Clases de almacenamiento
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*** Prototipo de funcion ***/
int generadorNum(void);
void iniciarCarrera(void);

int main()
{
    int op;
    srand(time(NULL));
    static int numGanador = rand() % 100 + 1;
    do
    {
    restart:
        system("CLS");
        printf("---- MENU ----\n\n");
        printf("1- Loteria.\n");
        printf("2- Carrera de coches.\n");
        printf("0- SALIR.\n");
        printf("Ingrese una opcion NUMERICA por favor: ");
        scanf("%d", &op);
        system("CLS");
        switch (op)
        {
        case 1:
            int num;
            printf("---LOTERIA---\n");
            num = generadorNum();
            if (num == numGanador)
            {
                printf("Tu numero es: %d\nFelicidades, ganaste la loteria!!!\n",num);
            }
            else
            {
                printf("Tu numero es: %d\nLo siento, no ganaste esta vez.\n",num);
            }
            system("PAUSE");
            break;
        case 2:
            iniciarCarrera();
            system("PAUSE");
            break;

        default:
            if (op != 0)
            {
                printf("Por favor ingresa un numero correcto.\n");
                system("PAUSE");
                goto restart;
            }
            break;
        }
    } while (op != 0);
    printf("Gracias por usar el programa. Hasta luego!");

    return 0;
}

/*** Desarrollo de funcion ***/

/*
Función: generador de numero aleatorio entre 1-100
Descripción: genera un numero aleatorio
Parámetros: Sin parametros
Valor de retorno: Numero aleatorio 'num'.
*/
int generadorNum(void)
{
    int num;
    num = rand() % 100 + 1;
    return num;
}

/*
Función:  iniciarCarrera
Descripción: Simula una carrera de coches.
Parámetros: Sin parametros
Valor de retorno: Sin valor de retorno
*/
void iniciarCarrera(void)
{
    int dist = 1000;
    // mensaje de introduccion
    printf("   *** CARRERA DE COCHES ***\n");
    printf("--- Coches partificapentes ---\n");
    printf("~Toretto\n");
    printf("~Paul Walker\n");
    printf("~Suki\n");
    system("PAUSE");
    system("CLS");

    /* variables de registro con velocidades entre 100-200 */
    register int toretto = rand() % (200 - 100)+100;
    register int paulWalker = rand() % (200 - 100)+100;
    register int suki = rand() % (200 - 100)+100;

    /* generar tiempo recorrido */
    float tt= dist/toretto;
    float tp= dist/paulWalker;
    float ts= dist/suki;

    //  Verificar coche ganador 
    if (tt<tp)
    {
        if (tt<ts)
        {
            printf("Toretto es el ganador de la carrera!!\n\n");
        }
        else
        {
            printf("Suki es la ganadora de la carrera!!\n\n");
        }
    }
    else
    {
        if (tp<ts)
        {
            printf("Paul es el ganador de la carrera!!\n\n");
        }
        else
        {
            printf("Suki es la ganadora de la carrera!!\n\n");
        }
    }
    // imprimir resultados 
    printf("    --- RESULTADOS ---\n");
    printf("Toreto--> %d km/h -- %.2f seg. \n",toretto, tt);
    printf("Paul Walker--> %d km/h -- %.2f seg. \n",paulWalker, tp);
    printf("Suki--> %d km/h -- %.2f seg. \n",suki, ts);
    
}