#include <stdio.h>
int main()
{
    int num1;
    printf("ingrese el numero\n");
    scanf("%d", &num1);

    for (int i = 1; i <= 10; i++)
    {
        printf("el valor del numero %d\n", num1 * i);
    }

    return 0;
}