#include <stdio.h>
#include <string.h>

/*Desarrollar un programa que permita gestionar los sueldos de los empleados de una empresa.
 Se sabe que dicha empresa posee 40 empleados. De los empleados se conoce su:
   Legajo: Es un número entero entre 10000 y 99999.
   Nombre: Solo el primer nombre del empleado.
   Horas trabajadas: Un número entero positivo.
   Categoría: Un número 1, 2 o 3: o 1 - Planta. o 2 - Administrativo. o 3 - Vendedor.
  El precio de la hora es:
   Para un empleado de planta: $2000.  Para un administrativo: $1500.  Para un vendedor: $1000.
  Funcionalidades del programa El programa deberá presentar un menú con las siguientes opciones:
  1. Cargar empleados: Permite cargar los 40 empleados ingresando para cada uno:
  o Legajo. o Nombre. o Horas trabajadas. o Categoría.
  Validar que los datos ingresados (legajo, cantidad de horas y categoría) sean correctos.
  2. Mostrar empleados: Muestra en la consola el listado de empleados con:
  o Legajo. o Nombre. o Horas trabajadas. o Categoría.
  3. Mostrar el sueldo de un empleado: Debe pedir el legajo del empleado del cual se quiere mostrar el sueldo.
  En caso de encontrarlo, mostrar en la consola:
  o Legajo. o Nombre. o Sueldo del empleado, que será el resultado de multiplicar las horas trabajadas por el
  empleado por el precio de la hora según su categoría.
  4. Modificar la categoría de un empleado: Debe pedir el legajo del empleado al cual se le quiere modificar
  la categoría. En caso de encontrarlo: o Pedir la nueva categoría. o Modificar la categoría del empleado.
  o Mostrar el mensaje: “Dato modificado exitosamente”.
  5. Salir: Se saldrá de la aplicación solo si se selecciona esta opción*/

// ***** si pones letras en legajo !crash!

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
                printf("Nombre: %s\n", nombres[i]);
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

                    if (strlen(categoria[i]) == 6)
                    {
                        sueldo = hora_pla * cant_horas[i];
                        printf("Sueldo segun horas trabajadas: %d\n", sueldo);
                    }

                    else if (strlen(categoria[i]) == 5)
                    {
                        sueldo = hora_adm * cant_horas[i];
                        printf("Sueldo segun horas trabajadas: %d\n", sueldo);
                    }

                    else if (strlen(categoria[i]) == 8)
                    {
                        sueldo = hora_ven * cant_horas[i];
                        printf("Sueldo segun horas trabajadas: %d\n", sueldo);
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
                }
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