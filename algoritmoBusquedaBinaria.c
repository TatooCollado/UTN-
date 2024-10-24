#include <stdio.h>
#include <math.h>
void ordenar(int array[]);
void busqueda(int array[], int buscado, int dim);
int main()
{
    int arreglo[5] = {59, 38, 41, 22, 3};
    int buscado = 0, dim = 5;

    printf("Ingrese el valor a buscar: \n");
    scanf("%d", &buscado);

    ordenar(arreglo);
    busqueda(arreglo, buscado, dim);
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

void busqueda(int array[], int buscado, int dim)
{
    int i, centro, inferior, superior, flag = 0;
    inferior = 0;
    superior = dim - 1;

    do
    {
        centro = trunc((inferior + superior) / 2);
        if (array[centro] == buscado)
        {
            printf("Ha encontrado el valor %d en la posicion %d\n", buscado, centro + 1);
            flag = 1;
        }
        else
        {
            if (array[centro] < buscado)
            {
                inferior = centro + 1;
            }
            else
            {
                superior = centro - 1;
            }
        }
        if (inferior > superior)
        {
            printf("Numero no encontrado\n");
            flag = 1;
        }

    } while (flag == 0);
}