#include <stdio.h>
int main()
{
    int dni = 38632584;
    float nota = 7;
    int dniIngresado = 0;
    int intentos = 1;
    int ingresaCorrectamente = 0;
    do
    {
        printf("Ingrese el dni:");
        scanf("%i", &dniIngresado);
        intentos++;
    } while (dniIngresado != dni && intentos < 4);
    if (intentos > 3)
    {
        printf("Se acabaron los intentos");
    }
    else
    {
        printf("La nota del alumno es: %f", nota);
    }
    return 0;
}