#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Prototipo de funciones

void factorial();
int factorialR(int num);

// Funcion principal

int main()
{
    int op;

    printf("\nSelecciona una opcion numerica, por favor. \n");
    printf("1- Factorial Void \n");
    printf("2- Factorial Recursiva \n");
    printf("Ingresa la opcion: ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        factorial();
        break;

    case 2:
        int num, res;
        printf("Bienvenido al generador de factorial! \n Que numero deseas ingresar? \n");
        scanf("%d", &num);
        res = factorialR(num);
        printf("El factorial de %d es: %d",num, res);
        getch();
        break;

    default:
        printf("Lo siento, la opcion que elegiste es incorrecta, por favor intentalo de nuevo.\n");
        main();
        break;
    }
    return 0;
}

// Desarrollo de funciones

void factorial()
{
    int num;
    system("CLS");
    printf("Bienvenido al generador de factorial! \n Que numero deseas ingresar? \n");
    scanf("%d", &num);

    if (num <= 0)
    {
        system("CLS");
        printf("Oh parece que ha ocurrido un error. \n El numero que ingresaste no es correcto! \n Por favor intentalo de nuevo. \n");
        factorial();
    }
    else
    {
        int a, s;
        int i = 2;
        a = num * (num - 1);
        while (i < num)
        {
            s = a * (num - i);
            a = s;

            i++;
        }
        printf("El factorial de %d, es: %d \n", num, a);
        getch();
    }
    int op;
    system("CLS");
    printf("Te gustaria saber el factorial de otro numero? \n 1-Si \n 2-no \n");
    printf("Ingresa una opcion NUMERICA: ");
    scanf("%d", &op);

    if (op == 1)
    {
        system("CLS");
        factorial();
    }
    else
    {
        printf("Gracias, nos vemos pronto!");
    }
}

int factorialR(int num){
    if (num==0)
    {
        return 1;
    }
    else{
        return num*factorialR(num-1);
    }

}