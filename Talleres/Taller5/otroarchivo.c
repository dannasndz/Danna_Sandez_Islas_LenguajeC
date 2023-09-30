#include <stdio.h>
// declaracion por cabecera
#include "archivo.h"

// prototipo de funcon
void sumaSaldo(int cantidad);

int main()
{
    saldo = 0;

    // modificar archivo.c desde otroarchivo.c
    sumaSaldo(250);

    printf("Archivo.c --- otroarchivo.c\n");
    printf("Saldo final: %d", saldo);
    
    return 0;
}