/*
    Nombre del archivo: Practica8_SistemaMejoradoDeGestiónDeInventarioConStructs_SandezIslas_Danna.c
    Autor: Danna Sandez Islas
    Fecha de creación: 22 de noviembre de 2023
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _producto
{
    char nombre[40];
    int cantidad;
    int precio;
    int ID;
    int existe;
} Tproducto;

#define N 100

/*****************  Prototipo de funciones *******************/
Tproducto agregar(void);
void retirar(Tproducto registro[], int i);
void imprimir(Tproducto registro[], int i);
void valor_total(Tproducto registro[], int i);
int busq_seq(Tproducto registro[], int n, int num);
int burbuja(Tproducto registro[], int n);

/*****************  Funcion principal *******************/
int main()
{
    Tproducto inventario[N], producto;
    int op, i = 0, ord = 0;
    do
    {
        system("CLS");
        printf("     -----  MENU  ----\n");
        printf("1- Agregar al inventario\n");
        printf("2- Retirar elemento del inventario\n");
        printf("3- Mostrar inventario\n");
        printf("4- Ordenar inventario\n");
        printf("5- Valor total de inventario\n");
        printf("0- SALIR\n");
        printf("Ingresa una opcion numerica: ");
        scanf("%d", &op);
        system("CLS");

        switch (op)
        {
        case 1:
            if (i < 200)
            {
                producto = agregar();
                inventario[i++] = producto;
            }
            else
            {
                printf("El inventario llego a su maxima capacidad\n");
            }
            ord = 0;
            break;
        case 2:
            retirar(inventario, i);
            break;
        case 3:
            imprimir(inventario, i);
            break;
        case 4:
            if (ord == 1)
            {
                printf("El inventario ya estaba ordenado\n");
            }
            else
            {
                ord = burbuja(inventario, i);
                printf("Inventario ordenado por medio de las ID\n");
            }
            break;
        case 5:
            valor_total(inventario, i);
            break;
        }
        system("PAUSE");
    } while (op != 0);
    printf("Gracias por usar el programa. Hasta luego\n");

    return 0;
}

/*
    Función: metodo de ordenamiento burbujar
    Descripción: Esta función ordena los elementos del inventario de menor a mayor.
    Parámetros:
    - registro: Los registros que almacena el inventario.
    - n: Cantidad de registros en el inventario.
    Valor de retorno: 1 en el caso donde se ordene correctamente.
*/
int burbuja(Tproducto registro[], int n)
{
    int i, j;
    Tproducto temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (registro[j].ID < registro[i].ID)
            {
                temp = registro[i];
                registro[i] = registro[j];
                registro[j] = temp;
            }
        }
    }
    return 1;
}

/*
    Función: valor_total
    Descripción: Esta función calcula el valor total del inventario en base a su cantidad de productos y el precio.
    Parámetros:
    - registro: Los registros que almacena el inventario.
    - i: Cantidad de registros en el inventario.
    Valor de retorno: Sin valor de retorno.
*/
void valor_total(Tproducto registro[], int i)
{
    int suma_total = 0, suma_temp = 0;
    for (int j = 0; j < i; j++)
    {
        suma_temp = (registro[j].precio * registro[j].cantidad);
        suma_total += suma_temp;
    }

    printf("El valor actual del inventario es: %d\n", suma_total);
}

/*
    Función: Imprimir
    Descripción: Esta función imprime todos los registros que contiene el inventario.
    Parámetros:
    - registro: Los registros que almacena el inventario.
    - i: Cantidad de registros en el inventario.
    Valor de retorno: Sin valor de retorno.
*/
void imprimir(Tproducto registro[], int i)
{
    printf("-----------------------------------------------------\n");
    printf("|   ID      NOMBRE      CANTIDAD        PRECIO      |\n");
    printf("-----------------------------------------------------\n");
    for (int j = 0; j < i; j++)
    {
        if (registro[j].existe == 1)
        {
            printf("%-4d        %-4s        %-4d        %-4d\n", registro[j].ID, registro[j].nombre, registro[j].cantidad, registro[j].precio);
        }
    }
}
/*
    Función: busq_seq
    Descripción: Esta función busca un valor en todo el vector de registros.
    Parámetros:
    - registro: Los registros que almacena el inventario.
    - i: Cantidad de registros en el inventario.
    - num: identificacion del producto a buscar
    Valor de retorno: -1 si no encontro el registro, i si lo encontro(i es la posicion o el ID en este caso del producto)
*/
int busq_seq(Tproducto registro[], int n, int num) // registro no ordenado
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (registro[i].ID == num)
        {
            return i;
        }
    }
    // no encontrado
    return -1;
}

/*
    Función: retirar
    Descripción: Esta función retira un producto del inventario.
    Parámetros:
    - registro: Los registros que almacena el inventario.
    - i: Cantidad de registros en el inventario.
    Valor de retorno: Sin valor de retorno.
*/
void retirar(Tproducto registro[], int i)
{
    int clave, enc, op;
    printf("Clave del producto a eliminar: ");
    scanf("%d", &clave);
    enc = busq_seq(registro, i, clave);

    if (enc != -1)
    {
        printf("Seguro que deseea eliminar el producto: %s con clave: %d?\n1-Si\n2-No\n", registro[enc].nombre, registro[enc].ID);
        scanf("%d", &op);
        if (op == 1)
        {
            registro[enc].existe = 0;
        }
        else
        {
            printf("Registro no eliminado\n");
        }
    }
    else
    {
        printf("Producto no encontrado. Verifique si escribio correctamente la clave\n");
    }
}

/*
    Función: agrefar
    Descripción: Esta función llena los datos necesarios del struc.
    Parámetros: Sin parametros
    Valor de retorno: datos de tipo Tproducto.
*/
Tproducto agregar(void)
{
    Tproducto datos;
    int cant, precio, clave;
    char nom[40];

    datos.existe = 1;
    printf("Clave del producto: ");
    scanf("%d", &clave);
    datos.ID = clave;
    system("CLS");

    printf("Nombre del producto: ");
    fflush(stdin);
    gets(nom);
    strcpy(datos.nombre, nom);

    system("CLS");
    printf("Cantidad de producto: ");
    scanf("%d", &cant);
    datos.cantidad = cant;

    system("CLS");
    printf("Precio del producto: ");
    scanf("%d", &precio);
    datos.precio = precio;

    return datos;
}