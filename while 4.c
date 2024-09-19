#include <stdio.h>
int main()
{
    int alumnos;
    int parciales;
    float notas = 0;
    float nota_individual;
    float prom_alumno = 0;
    float resultado_promedios;
    float promedio_general_notas;

    printf("ingrese cant alumnos \n");
    scanf("%d", &alumnos);
    printf("ingrese la cant de parciales \n");
    scanf("%d", &parciales);
    for (int i = 0; i < alumnos; i++)
    {
        for (int j = 0; j < parciales; j++)
        {
            do
            {
                printf("Ingrese notas\n");
                scanf("%f", &nota_individual);
                if (nota_individual <= 0 || nota_individual > 10)
                {
                    printf("Ingrese una nota valida \n ");
                }
            } while (nota_individual <= 0 || nota_individual > 10);
            notas = notas + nota_individual;
        }
        resultado_promedios = notas / parciales;
        printf("El promedio del alumno es: %.2f\n", resultado_promedios);
        prom_alumno += notas;
        notas = 0;
    }
    promedio_general_notas = prom_alumno / (alumnos * parciales);
    printf(" El promedio general de notas es: %.2f\n", promedio_general_notas);
    return 0;
}