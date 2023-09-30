#include <stdio.h>

int main()
{
    int memb;
    float monto,total;

    printf("Cuentas con membresia?: \n1-Si\n2-No\n");
    printf("Ingresa una opcion NUMERICA: \n");
    scanf("%d",&memb);
    printf("Cual es su monto de compra?: ");
    scanf("%f",&monto);

    if (monto>=1000)
    {
        total=(memb==1) ? monto*0.85 : monto*.90;
        printf("Total: %.2f",total);
    }
    else
    {
        printf("Total: %.0f",monto);
    }

    return 0;
}