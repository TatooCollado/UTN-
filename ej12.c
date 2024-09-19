#include <stdio.h>
int main()
{

    for (int i = 0; i < 10; i++)
    {

        for (int t = 0; t < i; t++)
        {
            printf("@");
        }
        printf("\n");
    }

    return 0;
}