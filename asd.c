#include <stdio.h>
int main()
{

    int num;
    printf("ingrese el numero\n");
    scanf("%d", &num);
    for (int i = num; i > 0; i--)
    {
        for (int b = 1; b <= i; b++)
        {
            printf("%d", b);
        }
        printf("\n");
    }
    return 0;
}