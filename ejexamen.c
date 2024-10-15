#include <stdio.h>
// Escriba un algoritmo donde se le pida al usuario que ingrese la cantidad de personas invitadas
//  a un evento, luego pedir que ingresé los nombres de la misma y el tipo de menú.
//  Al finalizar la carga mostrar al usuario la lista de invitados con el menú seleccionando. El menú puede ser "tradicional", "vegano" y "Sin TACC".
int main()
{
    int cantInvitados;
    char nombres[cantInvitados][30];
    char menu[cantInvitados][40];
    printf("Ingrese los invitados: \n");
    scanf("%d", &cantInvitados);

    for (int i = 1; i <= cantInvitados; i++)
    {
        printf("Ingrese el nombre del invitado:%d \n", i);
        scanf("%s", &nombres[i]);
        printf("Ingrese el menu: Tradicional, Vegano, Sin TACC: \n");
        scanf(" %[^\n]s", &menu[i]);
    }
    printf("Los invitados son: \n");
    for (int j = 1; j <= cantInvitados; j++)
    {
        printf("%s: %s\n", nombres[j], menu[j]);
    }

    return 0;
}