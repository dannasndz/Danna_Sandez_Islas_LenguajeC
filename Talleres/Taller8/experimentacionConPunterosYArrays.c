#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define M 100
#define N 15

int solicitarNumero();
void llenarMatriz(int **q, int m, int n);

void imprimirMatriz_Metodo1(int *p, int m, int n);
void imprimirMatriz_Metodo2(int v[], int m, int n);
void imprimirMatriz_Metodo3(int A[][3], int m, int n);
void imprimirMatriz_Metodo4(int *p[], int m, int n);
void imprimirMatriz_Metodo5(int **q, int m, int n);

void busquedaLineal_Metodo1(int *p, int m, int n, int num);
void busquedaLineal_Metodo2(int v[], int m, int n, int num);
void busquedaLineal_Metodo3(int A[][3], int m, int n, int num);
void busquedaLineal_Metodo4(int *p[], int m, int n, int num);
void busquedaLineal_Metodo5(int **q, int m, int n, int num);

int main()
{
    srand(time(NULL));
    clock_t start, end;
    double tiempo_m1 = 0, tiempo_m2 = 0, tiempo_m3 = 0, tiempo_m4 = 0, tiempo_m5 = 0;

    int  num, i, k, n;
    int b[M][N];
    int *q[M];
    int **r = q;
    for (i = 0; i < M; i++)
    {
        q[i] = &b[i][0];
    }

    llenarMatriz(r, M, N);

    printf("Ingrese la cantidad de veces que desea iterar las busquedas: ");
    scanf("%d", &n);

    int num_busq[n];

    for (i = 0; i < n; i++)
    {
        num_busq[i] = rand() % 1000;
    }

    for (k = 0; k < n; k++)
    {
        num = num_busq[k];

        printf("Iteracion %d\n", k + 1);

        printf("Metodo 1\n");
        start = clock();
        imprimirMatriz_Metodo1(&b[0][0], M, N);
        busquedaLineal_Metodo1(&b[0][0], M, N, num);
        end = clock();
        tiempo_m1 += (double)(end - start) / CLOCKS_PER_SEC;

        printf("Metodo 2\n");
        start = clock();
        imprimirMatriz_Metodo2(&b[0][0], M, N);
        busquedaLineal_Metodo2(&b[0][0], M, N, num);
        end = clock();
        tiempo_m2 += (double)(end - start) / CLOCKS_PER_SEC;

        printf("Metodo 3\n");
        start = clock();
        imprimirMatriz_Metodo3(b, M, N);
        busquedaLineal_Metodo3(b, M, N, num);
        end = clock();
        tiempo_m3 += (double)(end - start) / CLOCKS_PER_SEC;

        printf("Metodo 4\n");
        start = clock();
        imprimirMatriz_Metodo4(q, M, N);
        busquedaLineal_Metodo4(q, M, N, num);
        end = clock();
        tiempo_m4 += (double)(end - start) / CLOCKS_PER_SEC;

        printf("Metodo 5\n");
        start = clock();
        imprimirMatriz_Metodo5(r, M, N);
        busquedaLineal_Metodo5(r, M, N, num);
        end = clock();
        tiempo_m5 += (double)(end - start) / CLOCKS_PER_SEC;

        printf("\n");
    }

    printf("Tiempo total Metodo 1: %f segundos\n", tiempo_m1);
    printf("Tiempo total Metodo 2: %f segundos\n", tiempo_m2);
    printf("Tiempo total Metodo 3: %f segundos\n", tiempo_m3);
    printf("Tiempo total Metodo 4: %f segundos\n", tiempo_m4);
    printf("Tiempo total Metodo 5: %f segundos\n", tiempo_m5);

    return 0;
}

void llenarMatriz(int **q, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            q[i][j] = rand() % 1000;
        }
    }
}

int solicitarNumero()
{
    int num;
    printf("Ingrese el numero que desea buscar: ");
    scanf("%d", &num);

    return num;
}

void imprimirMatriz_Metodo1(int *p, int m, int n)
{
    int i, j;
    printf("La matriz es: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", *(p + i * n + j));
        }
        printf("\n");
    }
    printf("\n");
}

void imprimirMatriz_Metodo2(int v[], int m, int n)
{
    int i, j;
    printf("La matriz es: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", v[i * n + j]);
        }
        printf("\n");
    }
    printf("\n");
}

void imprimirMatriz_Metodo3(int A[][3], int m, int n)
{
    int i, j;
    printf("La matriz es: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void imprimirMatriz_Metodo4(int *p[], int m, int n)
{
    int i, j;
    printf("La matriz es: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void imprimirMatriz_Metodo5(int **q, int m, int n)
{
    int i, j;
    printf("La matriz es: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", q[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void busquedaLineal_Metodo1(int *p, int m, int n, int num)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (*(p + i * n + j) == num)
            {
                printf("Numero %d encontrado en posicion [%d][%d]\n", num, i, j);
                return;
            }
        }
    }
    printf("Numero %d no encontrado\n", num);
}

void busquedaLineal_Metodo2(int v[], int m, int n, int num)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (v[i * n + j] == num)
            {
                printf("Numero %d encontrado en posicion [%d][%d]\n", num, i, j);
                return;
            }
        }
    }
    printf("Numero %d no encontrado\n", num);
}

void busquedaLineal_Metodo3(int A[][3], int m, int n, int num)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (A[i][j] == num)
            {
                printf("Numero %d encontrado en posicion [%d][%d]\n", num, i, j);
                return;
            }
        }
    }
    printf("Numero %d no encontrado\n", num);
}

void busquedaLineal_Metodo4(int *p[], int m, int n, int num)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (p[i][j] == num)
            {
                printf("Numero %d encontrado en posicion [%d][%d]\n", num, i, j);
                return;
            }
        }
    }
    printf("Numero %d no encontrado\n", num);
}

void busquedaLineal_Metodo5(int **q, int m, int n, int num)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (q[i][j] == num)
            {
                printf("Numero %d encontrado en posicion [%d][%d]\n", num, i, j);
                return;
            }
        }
    }
    printf("Numero %d no encontrado\n", num);
}