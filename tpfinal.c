#include <stdio.h>
#include <string.h>

// Integrantes: Leonel Millanes, Paula Rivero, Jenifer Díaz, Carlos Jabazze, Florencia Di Mónaco, Ignacio Collado

int main()
{
    int legajos[40];
    int cant_horas[40];
    char categoria[40][10];
    char nombres[40][30];
    int hora_pla = 2000, hora_adm = 1500, hora_ven = 1000;
    int cant = 0, cont = 0;
    int categ, leg, sueldo, opcion;
    char sn;

    printf("Ingrese la cantidad del empleados\n");
    scanf("%d", &cant);

    do
    {

        printf("\nMENU:\n");
        printf("1. Cargar empleados\n");
        printf("2. Mostrar empleados\n");
        printf("3. Mostrar sueldo\n");
        printf("4. Modificar categoria del empleado\n");
        printf("5. Salir\n\n");
        printf("Seleccione una opcion:\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            for (int i = 0; i < cant; i++)
            {
                printf("\nIngrese los datos del empleado %d\n", i + 1);
                do
                {
                    printf("Legajo:\n");
                    scanf("%d", &legajos[i]);
                    if (legajos[i] < 10000 || legajos[i] > 99999)
                    {
                        printf("Legajo no valido\n");
                    }
                } while (legajos[i] < 10000 || legajos[i] > 99999);

                printf("Nombre\n");
                scanf("%29s", &nombres[i]);
                do
                {
                    printf("Cantidad de horas:\n");
                    scanf("%d", &cant_horas[i]);
                    if (cant_horas[i] < 0)
                    {
                        printf("Ingresaste una cantidad no valida\n");
                    }
                } while (cant_horas[i] < 0);

                do
                {
                    printf("Categoria:\n1- Planta\n2- Admin\n3- Vendedor\n");
                    scanf("%d", &categ);
                    if (categ == 1)
                    {
                        strcpy(categoria[i], "Planta");
                    }
                    if (categ == 2)
                    {
                        strcpy(categoria[i], "Admin");
                    }
                    if (categ == 3)
                    {
                        strcpy(categoria[i], "Vendedor");
                    }
                    if (categ < 1 || categ > 3)
                    {
                        printf("Ingresaste una categoria no valida\n");
                    }
                } while (categ < 1 || categ > 3);
            }
            break;
        case 2:
            for (int i = 0; i < cant; i++)
            {
                printf("Legajo: %d\n", legajos[i]);
                printf("Nombre: %29s\n", nombres[i]);
                printf("Horas trabjadas: %d\n", cant_horas[i]);
                printf("Categoria: %s\n\n", categoria[i]);
            }
            break;

        case 3:
            printf("Ingrese legajo: ");
            scanf("%d", &leg);

            while (leg < 10000 || leg > 99999)
            {
                printf("Legajo no valido\n");
                printf("Ingresa un legajo valido\n");
                scanf("%d", &leg);
            }

            for (int i = 0; i < cant; i++)
            {
                // do
                //  {
                if (legajos[i] == leg)
                {
                    printf("Legajo: %d\n", legajos[i]);
                    printf("Nombre: %s\n", nombres[i]);
                    printf("Categoria: %s\n", categoria[i]);

                    if (strcmp(categoria[i], "Planta") == 0)
                    {
                        sueldo = hora_pla * cant_horas[i];
                    }
                    else if (strcmp(categoria[i], "Admin") == 0)
                    {
                        sueldo = hora_adm * cant_horas[i];
                    }
                    else if (strcmp(categoria[i], "Vendedor") == 0)
                    {
                        sueldo = hora_ven * cant_horas[i];
                    }

                    break;
                }
                //} while (legajos[i] != leg);
            }
            break;

        case 4:
            printf("Ingrese legajo: \n");
            scanf("%d", &leg);

            while (leg < 10000 || leg > 99999)
            {
                printf("Legajo no valido\n");
                printf("Ingresa un legajo valido\n");
                scanf("%d", &leg);
            }

            for (int i = 0; i < cant; i++)
            {

                if (legajos[i] == leg)

                {
                    printf("Ingrese la nueva categoria:\n 1-Planta  2-Admin  3-Vendedor\n");

                    scanf("%d", &categ);

                    printf("Desea realmente cambiar la categoria? s/n ");
                    scanf(" %c", &sn);

                    if (sn == 's')
                    {
                        switch (categ)
                        {
                        case 1:
                            strcpy(categoria[i], "Planta");
                            break;
                        case 2:
                            strcpy(categoria[i], "Admin");
                            break;
                        case 3:
                            strcpy(categoria[i], "Vendedor");
                            break;
                        default:
                        {
                            printf("Categoria invalida!");
                        }
                        break;
                        }

                        printf("Modificaste la categoria con exito!\n\n");
                    }
                    break;
                }
                        }

            break;
        case 5:
            printf("Ha salido satisfactoriamente");
            break;
        default:
            printf("Ingrese una opcion valida");

            break;
        }

    } while (opcion != 5);
    return 0;
}