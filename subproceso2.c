#include <stdio.h>

void Suma(int num1, int num2, int *resultado)
{
    *resultado = num1 + num2;
}

int main()
{
    int num1, num2, resultado;
    printf("Ingrese los numeros a sumar\n");
    scanf("%d %d", &num1, &num2);
    Suma(num1, num2, &resultado);
    printf("El resultado es: %d", resultado);

    return 0;
}