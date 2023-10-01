#include <stdio.h>
// declaracion por cabecera
#include "archivo.h"

// prototipo de funcion
void sumaSaldo(int cantidad);

int main()
{
    // inicializacion de la variable externa
    saldo = 0;
    
    // invocacion de la funcioon
    // modificar Archivo.h desde archivosjuntos.c
    sumaSaldo(250);

    printf("Archivo.h --- archivosJuntos.c\n");
    printf("Saldo final: %d",saldo);
    return 0;
}

int saldo;

// definicion de la funcion
void sumaSaldo(int cantidad)
{
    saldo += cantidad; // modifica variable externa
}