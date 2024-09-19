#include <stdio.h>
int main()
{
    int num = 0;

    for (int i = 0; i < 20; i++)
    {
        if (i % 2 == 1)
        {
            num += i;
        }
    }
    printf("la suma de los primeros 20 numeros impares es: %d\n", num);
    return 0;
}