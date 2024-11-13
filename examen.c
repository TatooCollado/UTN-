#include <stdio.h>

int main()
{
    int opcion = 0;
    float n1 = 0, n2 = 0;
    float resultado;
    do
    {
        printf("Ingrese la opcion: \n");
        printf("1 Sumar\n");
        printf("2 Restar\n");
        printf("3 Multiplicar\n");
        printf("4 Dividir\n");
        printf("5 Salir\n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("Ingrese el primer numero a sumar: \n");
            scanf("%f", &n1);
            printf("Ingrese el segundo numero a sumar: \n");
            scanf("%f", &n2);
            resultado = n1 + n2;
            printf("El resultado es : %.0f\n", resultado);
            break;
        case 2:
            printf("Ingrese el primer numero a restar: \n");
            scanf("%f", &n1);
            printf("Ingrese el segundo numero a restar: \n");
            scanf("%f", &n2);
            resultado = n1 - n2;
            printf("El resultado es : %.0f\n", resultado);
            break;
        case 3:
            printf("Ingrese el primer numero a multiplicar: \n");
            scanf("%f", &n1);
            printf("Ingrese el segundo numero a multiplicar: \n");
            scanf("%f", &n2);
            resultado = n1 * n2;
            printf("El resultado es : %.2f\n", resultado);
            break;
        case 4:
            printf("Ingrese el primer numero a dividir: \n");
            scanf("%f", &n1);
            do
            {
                printf("Ingrese el segundo numero a dividir: \n");
                scanf("%f", &n2);
                if (n2 == 0)
                {
                    printf("No se puede dividir por cero, ingrese otro valor...\n");
                }
            } while (n2 == 0);
            resultado = n1 / n2;
            printf("El resultado es : %.2f\n", resultado);
            break;
        case 5:
            printf("Saliendo...\n");
            break;
        default:
            printf("Ingrese una opcion valida \n");
            break;
        }
    } while (opcion != 5);
    return 0;
}