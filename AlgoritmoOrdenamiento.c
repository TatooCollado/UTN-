#include <stdio.h>

void ordenar(int array[]);
int main()
{
    int arreglo[5] = {59, 38, 41, 22, 3};
    printf("El arreglo sin acomodar: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d \n", arreglo[i]);
    }

    ordenar(arreglo);
    printf("------------------------------\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d \n", arreglo[i]);
    }

    return 0;
}

void ordenar(int array[])
{
    int i, j, aux, posMenor;

    for (i = 0; i < (5 - 1); i++)
    {
        posMenor = i;

        for (j = i + 1; j < 5; j++)
        {
            if (array[j] < array[posMenor])
            {
                posMenor = j;
            }
        }
        aux = array[i];
        array[i] = array[posMenor];
        array[posMenor] = aux;
    }
}