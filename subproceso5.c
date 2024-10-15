#include <stdio.h>

/*Realizar un programa que le pida al usuario que ingrese una lista de 10 alumnos y los resultados del examen final.
 Luego el programa llamará a una función que calcula el promedio de notas, a otra función que calcula la mayor nota,
 y otra que calcula la menor nota. Luego el sistema informará estos 3 valores al usuario.*/

int main()
{

    char alumnos[10][20];
    int notas[10], mayor = 0, menor = 0;
    float promedio = 0;
    float Promedio(int notas[]);
    int Mayor(int notas[]);
    int Menor(int notas[]);

    printf("Ingrese los nombres de los alumnos\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%s", &alumnos[i]);
    }

    printf("Ingrese las notas de los alumnos\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &notas[i]);
    }
    promedio = Promedio(notas);

    printf("El promedio es %.2f\n", promedio);

    mayor = Mayor(notas);
    printf("El mayor es %d\n", mayor);

    menor = Menor(notas);
    printf("El menor es %d\n", menor);

    return 0;
}

float Promedio(int notas[])
{

    int suma = 0, resultado = 0;

    for (int i = 0; i < 10; i++)
    {
        suma += notas[i];
    }
    resultado = suma / 10;
    return resultado;
}

int Mayor(int notas[])
{

    int mayor = 0;

    for (int i = 0; i < 10; i++)
    {
        if (notas[i] > mayor)
        {
            mayor = notas[i];
        }
    }
    return mayor;
}

int Menor(int notas[])
{

    int menor = 1000;

    for (int i = 0; i < 10; i++)
    {
        if (notas[i] < menor)
        {
            menor = notas[i];
        }
    }
    return menor;
}