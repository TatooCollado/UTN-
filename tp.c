#include <stdio.h>
int main()
{
    int legajos[40];
    int cantHoras[40];
    int categoria[40];
    char nombres[40][30];
    for (int i = 0; i < 40; i++)
    {
        printf("Ingrese los datos del empleado %d\n", i + 1);
        do
        {
            printf("Legajo:\n");
            scanf("%d", &legajos[i]);
            if (legajos[i] < 10000 || legajos[i] > 99999)
            {
                printf("Legajo no válido\n");
            }
        } while (legajos[i] < 10000 || legajos[i] > 99999);

        printf("Nombre\n");
        scanf("%s", &nombres[i]);
        do
        {
            printf("Cantidad de horas:\n");
            scanf("%d", &cantHoras[i]);
            if (cantHoras[i] < 0)
            {
                printf("Ingresaste una hora no valida\n");
            }
        } while (cantHoras[i] < 0);

        do
        {
            printf("Categoria:\n 1-planta\n2- Admini\n3- Vendedor\n");
            scanf("%d", &categoria[i]);

            if (categoria[i] < 1 || categoria[i] > 3)
            {
                printf("Ingresaste una categoria no valida\n");
            }
        } while (categoria[i] < 1 || categoria[i] > 3);

        return 0;
    } // todo eso en el case 1 del switch