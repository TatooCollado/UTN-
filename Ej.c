#include <stdio.h> // Ingresar los lados de un triángulo e informar si es equilátero, isósceles o escaleno.

int main()
{

    float ladoA, ladoB, ladoC;

    printf("ingrese lado A, lado B y lado C del triangulo ", ladoA, ladoB, ladoC);
    scanf("%f %f %f", &ladoA, &ladoB, &ladoC);

    if (ladoA == ladoB && ladoA == ladoC)
    {
        printf("el triangulo es EQUILATERO!");
    }
    else if (ladoA != ladoB && ladoA != ladoC)
    {

        printf("el triangulo es ESCALENO");
    }
    else
    {
        printf(" el trangulo es ISOSCELES");
    }
    return 0;
}