#include <stdio.h>

void busquedaS(char array[]);
int main()
{

    char arreglo[10];

    arreglo[0] = 'S';
    arreglo[1] = 'E';
    arreglo[2] = 'C';
    arreglo[3] = 'U';
    arreglo[4] = 'E';
    arreglo[5] = 'N';
    arreglo[6] = 'C';
    arreglo[7] = 'I';
    arreglo[8] = 'A';
    arreglo[9] = 'L';

    busquedaS(arreglo);

    return 0;
}

void busquedaS(char array[])
{
    int flag = 1, i = 0;

    while (flag == 1)
    {
        if (array[i] == 'N')
        {
            printf("Se encontro la letra N en la posicion: %d", i);
            flag = 0;
        }
        else
        {
            if (i > 9)
            {
                flag = 0;
                printf("No se encontro la letra");
            }
            i++;
        }
    }
}