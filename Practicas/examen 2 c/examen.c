#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tmascotas
{
    int num_masc;
    char nombre[20];
    char especie[20];
    char raza[20];
} Tmascotas;

Tmascotas agregar(int i);
void archivo(Tmascotas registro[], int i);
int busq_seq(Tmascotas registro[], int n, int num);
void consulta(Tmascotas registro[], int i);
void actualiza(Tmascotas registro[], int i);
void mostrar(Tmascotas registro[], int i);

int main()
{
    Tmascotas registro[20], animal;
    int op, i = 0;
    do
    {
        system("CLS");
        printf("1- Agregar mascota\n");
        printf("2- Historial medico\n");
        printf("3- Consulta de registros\n");
        printf("4- Almacenamiento de datos\n");
        printf("0- SALIR\n");
        printf("Ingresa una opcion numerica: ");
        scanf("%d", &op);
        system("CLS");
        switch (op)
        {
        case 1: // agregar datos al registro
            if (i < 20)
            {
                animal = agregar(i);
                registro[i++] = animal;
            }
            else
            {
                printf("Registro en su maxima capacidad\n");
            }
            break;
        case 2: // alamcenar datos en registro
            archivo(registro, i);
            break;
        case 3: // buscar datos
            consulta(registro, i);
            break;
        case 4: // actualiza y muestra
            actualiza(registro, i);
            mostrar(registro, i);
            break;
        }
        system("PAUSE");
    } while (op != 0);
    printf("Gracias por usar el programa. Hasta luego!");

    return 0;
}

Tmascotas agregar(int i)
{
    char nombre[20], esp[20], raza[20];
    Tmascotas datos;

    printf("Ingresa la especie de la mascota: \n");
    fflush(stdin);
    gets(esp);

    strcpy(datos.especie, esp);

    printf("Ingresa la raza de la mascota: \n");
    fflush(stdin);

    gets(raza);
    strcpy(datos.raza, raza);

    printf("Nombre de la mascota: \n");
    fflush(stdin);

    gets(nombre);
    strcpy(datos.nombre, nombre);

    datos.num_masc = i + 1;

    return datos;
}

void mostrar(Tmascotas registro[], int i)
{
    printf("No.   Nombre     Especie    Raza\n");
    for (int j = 0; j < i; j++)
    {
        printf("%-4d    %-4s    %-4s    %-4s\n", registro[j].num_masc, registro[j].nombre, registro[j].especie, registro[j].raza);
    }
}

void actualiza(Tmascotas registro[], int i)
{
    FILE *fa;
    char nom[20], nombre[20], raza[20], especie[20];
    int num, enc;
    printf("No. de mascota a editar: ");
    scanf("%d", &num);
    enc = busq_seq(registro, i, num);
    if (enc != -1)
    {
        printf("Nombre: \n");
        fflush(stdin);
        gets(nombre);
        strcpy(registro[enc].nombre, nombre);
        system("CLS");
        printf("Raza: \n");
        fflush(stdin);
        gets(raza);
        strcpy(registro[enc].raza, raza);
        system("CLS");
        printf("Especie: \n");
        fflush(stdin);
        gets(especie);
        strcpy(registro[enc].especie, especie);
    }
    system("CLS");
    printf("Nombre del archivo: ");
    fflush(stdin);
    gets(nom);
    strcat(nom, ".txt");
    fa = fopen(nom, "w");
    if (fa)
    {
        fprintf(fa, "No.   Nombre     Especie    Raza\n");
        for (int j = 0; j < i; j++)
        {
            fprintf(fa, "%-4d    %-4s    %-4s    %-4s\n", registro[j].num_masc, registro[j].nombre, registro[j].especie, registro[j].raza);
        }
        fclose(fa);
    }
    else
    {
        printf("A ocurrido un error\n");
    }
}

int busq_seq(Tmascotas registro[], int n, int num) // registro no ordenado
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (registro[i].num_masc == num)
        {
            return i;
        }
    }
    // no encontrado
    return -1;
}

void consulta(Tmascotas registro[], int i)
{
    int enc, op;
    printf("Numero de animal a buscar: \n");
    scanf("%d", &op);
    enc = busq_seq(registro, i, op);
    if (enc != -1)
    {
        printf("No:%d\nNombre: %s\nEspecie: %s\nRaza: %s\n", registro[enc].num_masc, registro[enc].nombre, registro[enc].especie, registro[enc].raza);
    }
    else
    {
        printf("Mascota no encontrada");
    }
}

void archivo(Tmascotas registro[], int i)
{
    char txt[20], nom[20];
    FILE *ap;
    printf("Ingrese el nombre del archivo: \n");
    fflush(stdin);
    gets(nom);

    strcpy(txt, nom);
    strcat(txt, ".txt");
    ap = fopen(txt, "w");

    if (ap)
    {
        fprintf(ap, "No.   Nombre     Especie    Raza\n");
        for (int j = 0; j < i; j++)
        {
            fprintf(ap, "%-4d    %-4s    %-4s    %-4s\n", registro[j].num_masc, registro[j].nombre, registro[j].especie, registro[j].raza);
        }

        fclose(ap);
    }
}