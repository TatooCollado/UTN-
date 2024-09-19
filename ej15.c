#include <stdio.h>

int main()
{

    int nota1, nota2, nota3, acumulador;
    float promediototal;
    char alumnos[5][50];
    float promedioA[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese nombre del Alumno\n");
        scanf(("%49s"; alumnos[i]));
        printf("Ingrese primer nota del alumno:  %c", alumnos[i]);
        scanf("%i", &nota1);
        printf("Ingrese segunda nota del alumno:  %c", alumnos[i]);
        scanf("%i", &nota2);
        printf("Ingrese tercer nota del alumno:  %c", alumnos[i]);
        scanf("%i", &nota3);
        promedioA[i] = (nota1 + nota2 + nota3) / 3;
        promediototal += promedioA[i];
    }

    printf("El promedio de los alumnos es: \n");
    for (int t = 0; t < 5; t++)
    {
        printf("El promedio del alumno/a: %c", alumnos[t]);
        printf("%.2f", promedioA[t]);
        printf("\n");
    }
    printf("El promedio total del curso es de: %.2f", (promediototal / 5));

    return 0;
}