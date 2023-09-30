#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


float calculadora();
float adivina_elnum();
float calculadora_areas();
char decision[2];

int main () { //funcion principal

float resultado, res;
int opcion; 

printf ("SELECCIONA UNA OPCION: \n");
printf ("1- Calculadora \n");
printf ("2- Juego adivina el numero \n");
printf ("3- Calculadora de areas \n");
scanf ("%d", &opcion); //seleccion de opcion


switch (opcion) { //menu de opciones

    case 1:
    //calculadora 
    do{
        resultado=calculadora();
        printf("El resultado es= %.2f \n", resultado );
        printf ("Desea realizar otra operacion? Escribe si o no \n");
        scanf ("%s",decision);
        for (int i=0;decision[i];i++){
            decision[i]= tolower(decision[i]);
        }

    } while (strcmp(decision,"si")==0);
    printf("Gracias! \n");
    break;

    case 2:
    //juego
    do{
        adivina_elnum();
        printf ("Desea jugar de nuevo? Escribe si o no \n");
        scanf ("%s",decision);
        for (int i=0;decision[i];i++){
            decision[i]= tolower(decision[i]);
        }
    }while (strcmp(decision,"si")==0);
    printf("Gracias! \n");
    break;

    case 3:
    //calculadora areas
    do{
        res=calculadora_areas();
        printf ("El resultado es= %.2f \n" , res);
        printf ("Desea realizar otra operacion? Escribe si o no \n");
        scanf ("%s",decision);
        for (int i=0;decision[i];i++){
            decision[i]= tolower(decision[i]);
        }

    } while (strcmp(decision,"si")==0);
    printf("Gracias! \n");
    break;

    default: //mensaje en caso de opcion incorrecta
        printf("ERROR, INGRESA UNA OPCION CORRECTA");
    break;
}
return 0;

}

float calculadora() { //funcion de calculadora
    
    int op;
    float resultado, n1, n2;

    printf("QUE OPERACION DESEA?: \n");
    printf("1- Suma \n");
    printf("2- Resta \n");
    printf("3- Multiplicacion \n");
    printf("4- Division \n");
    scanf("%d", &op);
    printf ("Ingrese el primer numero: \n");
    scanf ("%f", &n1);
    printf ("Ingrese el segundo numero: \n");
    scanf ("%f", &n2);
    
    switch (op) {
    
        case 1: 
        //suma
        resultado= n1+n2;
        break;
        case 2:
        //resta 
        resultado=n1-n2;
        break;
        case 3:
        //multiplicacion
        resultado=n1*n2;
        break;
        case 4:
        //division
        resultado=n1/n2;
        break;
        default:
        printf ("ERROR");
        break;
    }  
    return resultado;
}

float adivina_elnum() { //funcion juego adivina el numero 

    int num, ad;

    srand(time(NULL)); //Para que el numero que se genere vaya cambiando 
    num= rand() % 101 +1;

    printf("Advina el numero del 1 al 100\n ");
    do{
        fflush(stdin);
        scanf("%d", &ad);
        if(num>ad){
            printf("Demasiado bajo :( \n Intentalo de nuevo: \n");
        }
        else if(num<ad){
            printf("Demasiado alto :( \n Intentalo de nuevo: \n ");
        } 
        else if(num==ad){
            printf("Has ganado :D \n");
        }
    }while(num!=ad);

    return 0;
}

float calculadora_areas(){  //funcion de calculadora de areas

    int op;
    float res,b,h,r;
    #define PI 3.141516

    printf("QUE OPERACION DESEA?: \n");
    printf("1- Area triangulo \n");
    printf("2- Area circulo \n");
    printf("3- Arrea rectangulo \n");
    printf("4- Area cubo \n");
    printf("5- Area cilindro \n");
    scanf("%d", &op);

    switch (op){

        case 1:
        //area del triangulo
        printf ("AREA DE UN TRIANGULO \n");
        printf ("Ingrese la base: \n");
        scanf("%f",&b);
        printf ("Ingrese la altura: \n");
        scanf("%f",&h);
        res= (b*h)/2;
        break;

        case 2:
        //area del circulo
        printf ("AREA DE UN CIRCULO \n");
        printf ("Ingrese el radio: \n");
        scanf("%f",&r);
        res= PI * pow(r,2);
        break;

        case 3:
        //area del rectangulo
        printf ("AREA DE UN RESCTANGULO \n");
        printf ("Ingrese la base: \n");
        scanf("%f",&b);
        printf ("Ingrese la altura: \n");
        scanf("%f",&h);
        res= b*h;
        break;

        case 4:
        //area dek cubo
        printf("AREA DE UN CUBO \n");
        printf("Ingrese un lado de 1 cara del cubo: \n");
        scanf("%f",&b);
        res= 6* pow(b,2);
        break;

        case 5:
        //area del cilindro 
        printf("AREA DE UN CILINDRO \n");
        printf ("Ingrese la altura: \n");
        scanf("%f",&h);
        printf("Ingrese el radio: \n");
        scanf("%f",&r);
        res=2*PI*r*(h+r);
        break;

        default:
        printf ("OPCION INCORRECTA :( \n");
        break;
    }

    return res;

}