#include <stdio.h>
#include <math.h>
int main()
{

    int num, i, j;
    printf("Ingrese un numero y el programa iterará hasta llegar a 0.\n");
    scanf("%i", &num);
    if (num == 0)
    {
        printf("El numero es %d", num);
    }
    else if (num < 0)
    {
        for (i = num; i <= 0; i++)
        {
            printf("%d ", i);
            printf("\n");
        }
    }
    else if (num > 0)
    {
        for (j = num; j >= 0; j--)
        {
            printf("%d ", j);
            printf("\n");
        }
    }
    return 0;
}