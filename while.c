#include <stdio.h>

int main()
{

    int prom = 0, num, contador = 0, bandera = 1;
    float resultado;

    while (bandera == 1)
    {
        printf("Ingrese un numero");
        scanf("%d", &num);
        if (num >= 0)
        {
            prom += num;
            contador++;
        }
        else
        {
            bandera = 0;
        }
    }
    if (contador == 0)
    {
        printf("No se ingresaron numeros positivos");
    }
    else
    {
        resultado = prom / contador;
        printf("El promedio es %d", resultado);
    }

    return 0;
}