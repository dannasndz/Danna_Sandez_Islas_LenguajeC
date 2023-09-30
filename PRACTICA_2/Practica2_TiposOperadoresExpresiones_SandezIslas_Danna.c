// Tipos de operadoes y expresiones 
// Danna G. Sandez Islas 373080
// no recuerdo cuando la cree
// Practica 2

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <conio.h>

int bits_posiciones();
void calificaciones();
void menu();
void ingresar();
void mostrar();
void eliminar();
int cap_inventario[10];  // declarar arreglo definido

int main()
{

    int opcion;
    printf("    SELECCIONA UNA OPCION \n");
    printf("1.- BITS \n");
    printf("2.- Calificacion numerica a letra \n");
    printf("3.- Gestion de inventario \n");
    printf("4.- Salir \n");
    scanf("%d", &opcion);

    switch (opcion) //Switch donde dependiendo de la opcion que escogio el usuario se mandan llamar las funciones donde se desarrollan los puntos.
    {
    case 1: // bits
        bits_posiciones();
        break;

    case 2: // calificacion numerica-letra
        calificaciones();
        break;

    case 3: // gestion de inventario
        menu();
        break;
    case 4: // salir del programa
        printf("Gracias! Nos vemos pronto! \n");
        break;
    default: // en caso de opcion incorrecta
        printf("OPCION INCORRECTA :( \n");
        break;
    }

    return 0;
}

int bits_posiciones() // funcion para la opcion bits
{

    int num_decimal;
    printf("Ingrese un numero en decimal: \n");
    scanf("%d", &num_decimal);

    // verificar si el numero es decimal y postivo
    if (num_decimal < 0)
    {
        printf("ERROR , Ingresa una opcion correcta! \n");
        return 1;
    }
    // calcular bits necesarios
    int num_bits = 0;
    int temp = num_decimal;
    while (temp > 0)
    {
        temp /= 2;
        num_bits++;
    }
    // generar arreglo
    int bits[num_bits];
    int indice;

    while (num_decimal > 0)
    {
        bits[indice] = num_decimal % 2;
        num_decimal /= 2;
        indice++;
    }

    // imprimir la cadena de bits
    printf("Numero de bits: \n");

    for (int i = indice - 1; i >= 0; i--)
    {
        printf("%d", bits[i]);
    }
    printf("\n");

    // Mostrar cantidad de bits encendidos

    int bit_encendido = -1;
    printf("Los bits encendidos estan en la posicion: \n");
    for (int i = 0; i < indice; i++)
    {
        if (bits[i] == 1)
        {
            bit_encendido = i;
            printf("%d", bit_encendido + 1);
        }
    }

    if (bit_encendido == -1)
    {
        printf("No se encontro ningun bit encendido \n");
    }
    getch();
    printf("\n");
    main();
}

void calificaciones()
{ // funcion de calificaciones numericas a letra
    int cal;

    printf("Ingresa tu calificacion: \n");  // Se le pide la calificacion al usuario
    scanf("%d", &cal);

    if (cal >= 90 && cal <= 100)  // dependiendo de su calificacion se desplegan los resultados equivalentes
    {
        printf("Tu calificacion es= %d , EQUIVALENTE= A \n", cal);
    }
    if (cal <= 89 && cal >= 80)
    {
        printf("Tu calificacion es= %d, EQUIVALENTE= B \n", cal);
    }
    if (cal >= 70 && cal <= 79)
    {
        printf("Tu calificacion es= %d, EQUIVALENTE= C \n", cal);
    }
    if (cal >= 60 && cal <= 69)
    {
        printf("Tu calificacion es= %d, EQUIVALENTE= D \n", cal);
    }
    if (cal >= 0 && cal <= 59)
    {
        printf("Tu calificacion es= %d, EQUIVALENTE= F \n", cal);
    }
    getch();  // espera a que el usuario teclee algo mas para continuar
    printf("\n");
    main();  // envia al usuario al main para que pueda seguir utilizando el menu hasta que desee salir
}

void menu()  // funcion void del menu para la gestion del inventario donde se le pide al usuario que seleccione una opcion dependiendo lo que desee hacer y se manda a llamar otra funcion con el desarrollo.
{
    int op;
    printf("     MENU\n");
    printf("1-Agregar elementos \n");
    printf("2-Retirar elementos \n");
    printf("3-Mostrar inventario \n");
    printf("4-Salir \n");
    printf("SELECCIONA UNA OPCION NUMERICA \n");
    scanf("%d", &op); // seleccion de opcion del usuario
    switch (op)
    {
    case 1:
        ingresar(); // funcion ingresar donde se le agregan datos al inventario 
        break;
    case 2:
        eliminar(); // funcion eliminar del inventario
        break;
    case 3:
        mostrar(); // funcion mostrar el inventario 
        break;
    case 4:
        printf("Gracias!, nos vemos pronto! \n");  // mensaje en caso de que el usuario desee salir del menu de inventario 
        getch();
        main(); // lo envia a la funcion main por si el usuario deseea seguir utilizando otras opciones
        break;
    default:
        printf("OPCION INCORRECTA, INTENTALO DE NUEVO! \n");  // mensaje en caso de que el usuario ingrese una opcion incorrecta
        break;
    }
    getch();
    printf("\n");
    main(); // envia al usuario a la funcion main por si deseea seguir utilizando el menu principal 
}

void ingresar()  // funcion donde el usuario ingresa numeros al inventario 
{
    int i;
    for (i = 0; i < 10; i++)  // ciclo para agregar datos al inventario
    {
        if (i == 0)
        {
            printf("El inventario esta vacio! \n"); // mensaje que avisa que el inventario esta lleno en caso de que el numero de elementos sea 0
        }
        printf("Agrega  unelemento en la posicion [%d]! : ", i);
        scanf("%d", &cap_inventario[i]); // scan de opcion que ingrese el usuario para guardarlo en el arreglo 
        if (i==9){ 
            printf("El inventario esta lleno! \n"); // mensaje que avisa sobre el inventario lleno en caso de que el numero de elementos dentro sean 10
        }
    }
    getch(); // deja mostrar lo que hay en la pantalla antes de saltar al menu
    menu(); // envia al usuario a la funcion menu para que pueda seguir seleccionando opciones 
}

void mostrar() // funcion donde muestra el inventario al usuario 
{
    for (int i = 0; i < 10; i++) // ciclo for para mostrar el arreglo 
    {
        printf(" \n Inventario posicion [%d] = %d", i, cap_inventario[i]); 
    }
    printf("\n");
    menu(); // envia al usuario a la funcion menu para que pueda seguir utilizando otras opciones
}

void eliminar() // funcion para eliminar datos del inventario que en este caso es un arreglo 
{
    int op;
    printf("Que posicion de inventario deseas eliminar? \n");
    scanf("%d", &op); // se lee la opcion del usuario donde selecciona la posicion del arreglo que desee eliminar 

    if (op < 10) // si la posicion que escogio es menor a 10 se puede eliminar la posicion en el arreglo 
    {
        cap_inventario[op] = 0; // la posicion en el arreglo se vuelve 0
        printf("Se ha eliminado el espacio de la posicion [%d] \n", op);
        getch();
        menu(); // envia al usuario a la opcion menu de gestion de inventario para que pueda seguir utilizando opciones 
    }
    else // si no se cumple el if arroja lo siguiente 
    {
        printf("ERROR, esa posicion no existe! \n"); // mensaje que avisa que la posicion que eligio no existe 
        getch();
        eliminar(); // envia al usuario a la funcion eliminar para que pueda seleccionar una posicion correcta 
    }
}